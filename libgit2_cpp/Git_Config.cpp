#include "Git_Config.hpp"

#include <type_traits>
#include <boost/algorithm/string/predicate.hpp>

#include "Git_Config_Backend.hpp"
#include "Git_Config_Entry.hpp"
#include "Scoped_Deleter_Buf.hpp"
#include "Git_CVar_Map.hpp"



Git_Config::Git_Config(git_config* c_git_config):Provider(c_git_config,git_config_free)
{
}

//Git_Config::Git_Config():Provider(git_config_free)
//{
//	int res = git_config_new(&c_git_guts_);
//	/*
//	This object is empty, so you have to add a file to it before you can do anything with it.
//	*/
//	if (FAILED(res) || FAILED(c_git_guts_))
//	{
//		throw - 1;
//	}
//}

void Git_Config::add_backend(const Git_Config_Backend& config_backend, const Git_Config_Level& config_level, bool force)
{
	int res = git_config_add_backend(c_git_guts_, const_cast<git_config_backend*>(&config_backend.c_git_config_backend_), config_level, force);
	
	if (FAILED(res) || GIT_EEXISTS == res)
	{
		throw - 1;
	}
}

void Git_Config::add_file_on_disk(const file_path_t& path, const Git_Config_Level& config_level, bool force)
{
	int res = git_config_add_file_ondisk(c_git_guts_, path.c_str(), config_level, force);

	if (FAILED(res) 
		||	GIT_EEXISTS == res 
		||	GIT_ENOTFOUND == res)
	{
		throw - 1;
	}
}

void Git_Config::delete_entry(const string_t & name)
{
	int res = git_config_delete_entry(c_git_guts_, name.c_str());
	if (FAILED(res))
	{
		throw - 1;
	}
}

template<Git_Config::E_Path_Type e_path>
file_path_t Git_Config::find_path_helper_() const
{
	typedef int(*git_config_find_t)(git_buf*);
	git_config_find_t git_config_find{};
	switch (e_path)
	{
	case GLOBAL:
		git_config_find = git_config_find_global;
		break;
	case PROGRAM:
		git_config_find = git_config_find_programdata;
		break;
	case SYSTEM:
		git_config_find = git_config_find_system;
		break;
	case XDG:
		git_config_find = git_config_find_xdg;
		break;
	}

	size_t file_path_length{ 256 };
	Scoped_Deleter_Buf<git_buf> c_git_buf_out(file_path_length);
	check_for_error(git_config_find(c_git_buf_out));

	file_path_t file_path(c_git_buf_out.get_string());
	return file_path;
}





file_path_t Git_Config::find_global_path() const
{
	return find_path_helper_<GLOBAL>();
}

file_path_t Git_Config::find_program_data_path() const
{
	return find_path_helper_<PROGRAM>();
}

file_path_t Git_Config::find_system_path() const
{
	return find_path_helper_<SYSTEM>();
}
#ifdef I_NEED_THIS
template<class T>
struct Any
{
	T val_;
	void put(T val)
	{
		val_ = val;
	}
	T get()const
	{
		return val_;
	}
};

class Return_Type
{
	
	Git_Config::E_Entity_Type e_type_;
	union any
	{
		bool bool_val;
		int32_t int32_t_val;
		git_config_entry* c_git_config_entry;
	};
	any union_;
public:
		
};

template<class T>
using git_config_get_fnc = int(*)(T*, const git_config*, const char*);

template<class Out,Git_Config::E_Entity_Type entity_t>
void Git_Config::get_entity_helper_impl_(Return_Type& result,const string_t& varName)
{
	Out out_var;
	typedef int(*tp_t)(Out*, const git_config*, const char*);
	void* vp;

	switch (entity_t)
	{
	case BOOL:
		{
		git_config_get_fnc<int> f = (git_config_get_bool);
		vp = &f;
			//int out;
			//check_for_error{ git_config_get_bool(&out, c_git_guts_, varName.c_str()) };
			//result.put_bool(out);
		}
		break;
	case ENTRY:
		{
		git_config_get_fnc<git_config_entry*> f = (git_config_get_entry);
		vp = &f;
			//git_config_entry* out;
			//check_for_error{ git_config_get_entry(&out, c_git_guts_, varName.c_str()) };
			//result.put_git_config_entry(out);
		}
		break;
	case INT32:
		git_config_get_fnc<int32_t> f = (git_config_get_int32);
		vp = &f;
		//int32_t out;
		//check_for_error{git_config_get_int32(&out, c_git_guts_, varName.c_str())};
		//result.put_int32_t(out);
		break;
	}
	reinterpret_cast<tp_t>(vp)(&out_var,c_git_guts_,varName.c_str());
	result.put<entity_t>(out_var);
}


template<Git_Config::E_Entity_Type entity_t>
Return_Type Git_Config::get_entity_helper_(const string_t& varName) 
{
	Return_Type return_type{};

	switch (entity_t)
	{
	case BOOL:
		get_entity_helper_impl_<BOOL>(return_type, varName);
	case INT32:
		get_entity_helper_impl_<INT32>(return_type, varName);
	case ENTRY:
		get_entity_helper_impl_<ENTRY>(return_type, varName);
	}

	return return_type;

}
#endif

template<class T, int(*c_git_function)(T*,const git_config*,const char*)>
class Caller
{
#pragma message("ToDo Perhaps better name for this class Artie?")
	T val_;
public:
	Caller(const git_config* c_git_config, const char* varName)
	{
		check_for_error( c_git_function(&val_, c_git_config, varName) );
	}
	T get_val()const
	{
		return val_;
	}
};

#pragma message("ToDo  make this templatized and refactored so there is no code duplication")
bool Git_Config::get_bool(const string_t& varName)
{
	//return get_entity_helper_<BOOL>(varName).get_val();
	Caller<int, git_config_get_bool> al(c_git_guts_,varName.c_str());
	return al.get_val();
	//int out;
	//check_for_error{ git_config_get_bool(&out, c_git_guts_, varName.c_str()) };
	//
	//return out;
}

shared_ptr_t<Git_Config_Entry> Git_Config::get_entry(const string_t& varName) 
{
	Caller<git_config_entry*, git_config_get_entry> al(c_git_guts_, varName.c_str());
	return make_shared_ver<Git_Config_Entry>(al.get_val());

	//git_config_entry* c_git_config_entry_out;
	//check_for_error{ git_config_get_entry(&c_git_config_entry_out, c_git_guts_, varName.c_str()) };
	//return make_shared_ver<Git_Config_Entry>(c_git_config_entry_out);
}

int32_t Git_Config::get_int32(const string_t & varName)
{
	Caller<int32_t, git_config_get_int32> al(c_git_guts_, varName.c_str());
	return al.get_val();
}

int64_t Git_Config::get_int64(const string_t & varName)
{
	Caller<int64_t, git_config_get_int64> al(c_git_guts_, varName.c_str());
	return al.get_val();
}

int Git_Config::get_mapped(const string_t & varName) const
{
	int out;
	Git_CVar_Map maps_in;
	check_for_error( git_config_get_mapped(&out, c_git_guts_, varName.c_str(), maps_in, maps_in.size()) );
	return out;
}

file_path_t Git_Config::get_path(const string_t & varName) const
{
	//git_buf* c_git_buf_out;
	//check_for_error( git_config_get_path(c_git_buf_out, c_git_guts_, varName.c_str()));
	//return file_path_t();

	size_t file_path_length{ 256 };
	Scoped_Deleter_Buf<git_buf> c_git_buf_out(file_path_length);
	check_for_error( git_config_get_path(c_git_buf_out, c_git_guts_, varName.c_str()));
	return c_git_buf_out.get_string();
}

string_t Git_Config::get_string(const string_t & varName)const
{
	Caller<const char*, git_config_get_string> al(c_git_guts_, varName.c_str());
	return al.get_val();
}

string_t Git_Config::get_string_buf(const string_t & varName)const
{
#pragma message("ToDo GIT_EXTERN(void) git_buf_free(git_buf *buffer);")

	Caller<git_buf, git_config_get_string_buf> al(c_git_guts_, varName.c_str());
	git_buf* c_git_buf = &al.get_val();
	char* char_ptr = reinterpret_cast<char*>(c_git_buf);
	return char_ptr;
}

void Git_Config::init_backend()
{
	git_config_backend* c_git_backend_out{};
	
	check_for_error( git_config_init_backend(c_git_backend_out,git_config_backend_.version()));
	git_config_backend_ = c_git_backend_out;
}

Git_Config::Git_Config_Iterator Git_Config::begin() const
{
	git_config_iterator_ = &Git_Config_Iterator(*this);
	return *git_config_iterator_;
}
Git_Config::Git_Config_Iterator Git_Config::Git_Config_Iterator::operator++()const
{
	git_config_entry* c_git_config_entry_out;
#pragma message("ToDo What to do with this^^^ ? Most likely member of an iterator")
	check_for_error(git_config_next(&c_git_config_entry_out, c_git_config_iterator_));
	return Git_Config_Iterator(c_git_config_iterator_,git_config_parent_);
}

Git_Config::Git_Config_Iterator::Git_Config_Iterator(const Git_Config& gitConfig) :git_config_parent_{ gitConfig }
{
	check_for_error( git_config_iterator_new(&c_git_config_iterator_, gitConfig.c_guts()));
}

Git_Config::Git_Config_Iterator::Git_Config_Iterator(git_config_iterator* c_git_config_iterator, const Git_Config& gitConfig) :c_git_config_iterator_{ c_git_config_iterator },
git_config_parent_{gitConfig}
{
}

Git_Config::Git_Config_Iterator::~Git_Config_Iterator()
{
	git_config_iterator_free(c_git_config_iterator_);
}

void Git_Config::lock()
{
	git_transaction* c_git_transaction_out;
#pragma message("ToDo What to do with this^^^ ")
	check_for_error(git_config_lock(&c_git_transaction_out, c_git_guts_));
}

Git_Config::Git_Config_Iterator Git_Config::next() const
{
	if (git_config_iterator_)
	{
 		git_config_iterator_ = &git_config_iterator_->operator++();
		return *git_config_iterator_;
	}
	else
	{
		throw - 1;
	}
	
}

shared_ptr_t<Git_Config> Git_Config::open_default() const
{
	git_config* c_git_config_out;
	check_for_error(git_config_open_default(&c_git_config_out));
	return make_shared_ver<Git_Config>(c_git_config_out);
}

shared_ptr_t<Git_Config> Git_Config::open_global() const
{
	git_config* c_git_config_out;
	check_for_error(git_config_open_global(&c_git_config_out, c_git_guts_));
	return make_shared_ver<Git_Config>(c_git_config_out);
}

shared_ptr_t<Git_Config> Git_Config::open_level(const Git_Config_Level& configLevel) const
{
	git_config* c_git_config_out;
	check_for_error(git_config_open_level(&c_git_config_out, c_git_guts_, configLevel));
	return make_shared_ver<Git_Config>(c_git_config_out);
}

shared_ptr_t<Git_Config> Git_Config::open_on_disk(const file_path_t& configOnHDD) const
{
	git_config* c_git_config_out;
	check_for_error(git_config_open_ondisk(&c_git_config_out, configOnHDD.c_str()));
	return make_shared_ver<Git_Config>(c_git_config_out);
}

bool Git_Config::parse_bool(const string_t& bool_val) const
{
	int out;
	if (boost::iequals(bool_val, "true") || boost::iequals(bool_val, "yes") || boost::iequals(bool_val, "on") || boost::iequals(bool_val, "1"))
	{
		check_for_error(git_config_parse_bool(&out, bool_val.c_str()));
	}
	else if (boost::iequals(bool_val, "false") || boost::iequals(bool_val, "no") || boost::iequals(bool_val, "off") || boost::iequals(bool_val, "0"))
	{
		check_for_error(git_config_parse_bool(&out, bool_val.c_str()));
	}
	else
	{
		throw - 1;
	}
	
	return out;
}



template<>
class Git_Config::parse_int_helper_<int32_t>
{
	static int32_t parse(const string_t& int_t_val)
	{
		int32_t out;
		check_for_error(git_config_parse_int32(&out, int_t_val.c_str()));

		return out;
	}
};

template<>
class Git_Config::parse_int_helper_<int64_t>
{
	static int64_t parse(const string_t& int_t_val)
	{
		int64_t out;
		check_for_error(git_config_parse_int64(&out, int_t_val.c_str()));

		return out;
	}
};

template<class T>
T Git_Config::parse_int(const string_t & int_val) const
{
	static_assert(std::is_integral<T>::value,"Type must be integral value");
	return parse_int_helper_<T>::parse(int_val);
}

file_path_t Git_Config::parse_path(const string_t & path) const
{
	size_t file_path_length{ 256 };
	Scoped_Deleter_Buf<git_buf> c_git_buf_out(file_path_length);
	check_for_error( git_config_parse_path(const_cast<git_buf*>(c_git_buf_out.get_type()),path.c_str()));
	return c_git_buf_out.get_string();
}

void Git_Config::set(const string_t & varName, const bool val)
{
	check_for_error(git_config_set_bool(c_git_guts_, varName.c_str(), val));
}


void Git_Config::set(const string_t& varName, const int32_t val)
{
	check_for_error(git_config_set_int32(c_git_guts_, varName.c_str(), val));
}

void Git_Config::set(const string_t& varName, const int64_t val)
{
	check_for_error(git_config_set_int64(c_git_guts_, varName.c_str(), val));
}

void Git_Config::set(const string_t & varName, const string_t & val)
{
	check_for_error(git_config_set_string(c_git_guts_, varName.c_str(), val.c_str()));
}

shared_ptr_t<Git_Config> Git_Config::snapshot() const
{
	git_config* c_git_config_out;
	check_for_error(git_config_snapshot(&c_git_config_out, c_git_guts_));

	return make_shared_ver<Git_Config>(c_git_config_out);
}
