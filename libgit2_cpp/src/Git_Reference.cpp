#include "Git_Reference.hpp"
#include "Git_Object_ID.hpp"
#include "Scoped_Deleter_Buf.hpp"
#include "Git_Repo.hpp"
#include "Git_Object.hpp"
Git_Reference::Git_Reference(git_reference*c_git_reference):Provider(c_git_reference,git_reference_free)
{

}

shared_ptr_t<Git_Reference> Git_Reference::reference_from_id(const string_t & name, const Git_Object_ID & oid, const Git_Object_ID & peel) const
{
	git_reference * c_git_reference = git_reference__alloc(name.c_str(), oid.c_guts(), peel.c_guts());
	check_for_nullptr(c_git_reference);
	return make_shared_ver<Git_Reference>(c_git_reference);
}

shared_ptr_t<Git_Reference> Git_Reference::symbolic_reference_from_id(const string_t &name, const string_t &target) const
{
	git_reference * c_git_reference = git_reference__alloc_symbolic(name.c_str(), target.c_str());
	check_for_nullptr(c_git_reference);
	return make_shared_ver<Git_Reference>(c_git_reference);
}

bool Git_Reference::compare(const Git_Reference & left, const Git_Reference & right)
{
	return 0 == git_reference_cmp(left.c_guts_, right.c_guts_) ? true : false;
}

shared_ptr_t<Git_Reference> Git_Reference::create(const string_t& name, const Git_Object_ID& id,bool force, const string_t& logMessage) const
{
	git_reference * c_git_reference_out;
	check_for_error(git_reference_create(&c_git_reference_out, c_parent_guts(), name.c_str(), id.c_guts(), force, logMessage.c_str()));

	return make_shared_ver<Git_Reference>(c_git_reference_out);
}

shared_ptr_t<Git_Reference> Git_Reference::create_matching(const string_t & name, const Git_Object_ID & id, bool force, const Git_Object_ID&currentId, const string_t & logMessage) const
{
	git_reference * c_git_reference_out;

	check_for_error(git_reference_create_matching(&c_git_reference_out, c_parent_guts(), name.c_str(), id.c_guts(), force, currentId.c_guts(), logMessage.c_str()));

	return make_shared_ver<Git_Reference>(c_git_reference_out);

}

void Git_Reference::delete_reference(const Git_Reference & ref) const
{
#pragma message("ToDo what will happed with the argument? Will it be valid? It certainly shouldn't be.")
	check_for_error(git_reference_delete(ref.c_guts()));
	/*This method works for both direct and symbolic references. The reference will be immediately removed on disk but the memory will not be freed. Callers must call git_reference_free.*/
}
shared_ptr_t<Git_Reference> Git_Reference::dwim_reference(const string_t& shorthand) const
{
	git_reference * c_git_reference_out;
	check_for_error(git_reference_dwim(&c_git_reference_out, c_parent_guts(), shorthand.c_str()));
	
	return make_shared_ver<Git_Reference>( c_git_reference_out);
}
void Git_Reference::ensure_log(const string_t & refname) const
{
	check_for_error(git_reference_ensure_log(c_parent_guts(), refname.c_str()));
}
bool Git_Reference::has_log(const string_t& refname) const
{
	return git_reference_has_log(c_parent_guts(), refname.c_str());
}

bool Git_Reference::is_local_branch() const
{
	return git_reference_is_branch(c_guts_);
}

bool Git_Reference::is_note() const
{
	return git_reference_is_note(c_guts_);
}

bool Git_Reference::is_remote() const
{
	return git_reference_is_remote(c_guts_);
}

bool Git_Reference::is_tag() const
{
	return git_reference_is_tag(c_guts_);
}

bool Git_Reference::is_valid_name(const string_t& refname) const
{
	return git_reference_is_valid_name(refname.c_str());
}

std::set<string_t> Git_Reference::list() const
{
	git_strarray c_git_array_out;
	check_for_error(git_reference_list(&c_git_array_out, c_parent_guts()));

	typedef std::set<string_t> set_t;
	set_t result;
	for (size_t beg{ 0 }, end{c_git_array_out.count}; beg!=end; ++beg)
	{
		result.insert(c_git_array_out.strings[beg]);
	}
	git_strarray_free(&c_git_array_out);
#pragma message("ToDo after implementing conversion optor in Git_Strarray there will be no need to call free")
	return result;
}

shared_ptr_t<Git_Reference> Git_Reference::lookup(const string_t & refname) const
{
	git_reference * c_git_reference_out;
	check_for_error(git_reference_lookup(&c_git_reference_out, c_parent_guts(), refname.c_str()));

	return make_shared_ver<Git_Reference>(c_git_reference_out);
}

string_t Git_Reference::name() const
{
	return git_reference_name(c_guts_);
}

shared_ptr_t<Git_Object_ID> Git_Reference::name_to_id(const string_t & name) const
{
	git_oid c_git_oid_out;
	check_for_error(git_reference_name_to_id(&c_git_oid_out, c_parent_guts(),name.c_str()));

	return Factory_Git_Object<Git_Object_ID>::create_ptr(std::move(c_git_oid_out));
#pragma message("ToDo maybe move this c_git_oid_out?")
}
string_t Git_Reference::normalize_name(const string_t& name, int flags) const
{
	Scoped_Deleter_Buf<char> buf(256);
	check_for_error(git_reference_normalize_name(buf, buf.size(), name.c_str(), flags));
	return buf.get_string();
}

shared_ptr_t<Git_Repo> Git_Reference::owner() const
{
	git_repository * c_git_repository = git_reference_owner(c_guts_);

	return Factory_Git_Object<Git_Repo>::create_ptr(c_git_repository);
}
template<class T>
shared_ptr_t<Git_Object<T>> Git_Reference::peel(git_otype type) const
{
	git_object* c_git_object_out;
	check_for_error(git_reference_peel(&c_git_object_out, c_guts_, type));

	return make_shared_ver<Git_Object<T>>(c_git_object_out);
}

void Git_Reference::remove(const string_t &name) const
{
	check_for_error(git_reference_remove(c_parent_guts(), name.c_str()));
}

shared_ptr_t<Git_Reference> Git_Reference::rename(const string_t& newName, int force, const string_t& logMessage) const
{
	git_reference* c_git_reference_out;
	check_for_error(git_reference_rename(&c_git_reference_out, c_guts_, newName.c_str(), force, logMessage.c_str()));

	return make_shared_ver<Git_Reference>(c_git_reference_out);
}

shared_ptr_t<Git_Reference> Git_Reference::resolve() const
{
	git_reference* c_git_reference_out;
	check_for_error(git_reference_resolve(&c_git_reference_out, c_guts_));

	return make_shared_ver<Git_Reference>(c_git_reference_out);
}

shared_ptr_t<Git_Reference> Git_Reference::set_target(const Git_Object_ID& id, const string_t& logMessage) const
{
	git_reference* c_git_reference_out;
	check_for_error(git_reference_set_target(&c_git_reference_out, c_guts_, id.c_guts(), logMessage.c_str()));
	
	return make_shared_ver<Git_Reference>(c_git_reference_out);
}

string_t Git_Reference::shorthand() const
{
	return git_reference_shorthand(c_guts_);
}

shared_ptr_t<Git_Reference> Git_Reference::create_symbolic_reference(const string_t& name, const string_t& target, int force, const string_t& logMessage) const
{
	git_reference* c_git_reference_out;
	check_for_error(git_reference_symbolic_create(&c_git_reference_out, c_parent_guts(), name.c_str(), target.c_str(), force, logMessage.c_str()));

	return make_shared_ver<Git_Reference>(c_git_reference_out);
}

shared_ptr_t<Git_Reference> Git_Reference::create_symbolic_reference_matching(const string_t & name, const string_t & target, int force,const string_t& currentValue, const string_t & logMessage) const
{
	git_reference* c_git_reference_out;

	check_for_error(git_reference_symbolic_create_matching(&c_git_reference_out, c_parent_guts(), 
																name.c_str(), target.c_str(), force, currentValue.c_str(), logMessage.c_str()));
	return make_shared_ver<Git_Reference>(c_git_reference_out);
}

shared_ptr_t<Git_Reference> Git_Reference::set_target(const string_t & target, const string_t & logMessage) const
{
	git_reference* c_git_reference_out;
	check_for_error(git_reference_symbolic_set_target(&c_git_reference_out, c_guts_, target.c_str(), logMessage.c_str()));

	return make_shared_ver<Git_Reference>(c_git_reference_out);
}

string_t Git_Reference::symbolic_target() const
{
	return git_reference_symbolic_target(c_guts_);
}

shared_ptr_t<Git_Object_ID> Git_Reference::target() const
{
	const git_oid * c_git_oid = git_reference_target(c_guts_);
	check_for_nullptr(c_git_oid);

	return Factory_Git_Object<Git_Object_ID>::create_ptr(c_git_oid);
}

shared_ptr_t<Git_Object_ID> Git_Reference::target_peel() const
{
	const git_oid * c_git_oid = git_reference_target_peel(c_guts_);
	check_for_nullptr(c_git_oid);
	
	return Factory_Git_Object<Git_Object_ID>::create_ptr(c_git_oid);
}

git_ref_t Git_Reference::type() const
{
	return git_reference_type(c_guts_);
}


#ifdef GIT_REFERENCE_DUP
shared_ptr_t<Git_Reference> Git_Reference::duplicate_reference(const Git_Reference & source) const
{
	git_reference *c_git_reference_out;
	check_for_error(git_reference_dup(&c_git_reference_out, source.c_guts()));

	return make_shared_ver<Git_Reference>(c_git_reference_out);
}
#endif
