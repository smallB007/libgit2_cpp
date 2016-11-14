#pragma once
#include "Git_Object_iface.hpp"

template<class T>
inline Git_Object<T>::Git_Object(T * c_git_object, c_git_deleter_t<T> c_git_class_deleter):Guts_Provider(c_git_object,NMS::move(c_git_class_deleter))
{
	/*c_guts_ = c_git_object ;*/
}
template<class T>
shared_ptr_t<Git_Object<T>> Git_Object<T>::duplicate() const
{
	git_object *c_git_object_out;
	check_for_error(git_object_dup(&c_git_object_out, c_guts_));

	return make_shared_ver<Git_Object<T>>(c_git_object_out);
}

template<class T>
shared_ptr_t<Git_Object_ID> Git_Object<T>::id() const
{
	const git_oid * c_git_oid = git_object_id(c_guts_);
	check_for_nullptr(c_git_oid);

	return make_shared_ver<Git_Object_ID>(c_git_oid);
}

template<class T>
shared_ptr_t<Git_Object<T>> Git_Object<T>::lookup(const Git_Object_ID& id,git_otype type) const
{
	git_object* c_git_object_out;
	check_for_error(git_object_lookup(&c_git_object_out, c_parent_guts(), id.c_guts(), type));

	return make_shared_ver<Git_Object<T>>(c_git_object_out);
}
template<class T>
shared_ptr_t<Git_Object<T>> Git_Object<T>::lookup_by_path(const Git_Object& treeish, const file_path_t& path, git_otype type)const
{
	git_object* c_git_object_out;
	check_for_error(git_object_lookup_bypath(&c_git_object_out, treeish.c_guts(), path.c_str(), type));

	return make_shared_ver<Git_Object<T>>(c_git_object_out);
}

template<class T>
shared_ptr_t<Git_Object<T>> Git_Object<T>::lookup_by_prefix(const Git_Object_ID& id, size_t len, git_otype type)const
{
	git_object* c_git_object_out;
	int git_object_lookup_prefix(&c_git_object_out, c_parent_guts(), id.c_guts(), len, type);
	
	return make_shared_ver<Git_Object<T>>(c_git_object_out);
}
template<class T>
shared_ptr_t<Git_Repo> Git_Object<T>::owner()const
{
	git_repository * c_git_repository = git_object_owner(c_guts_);
	check_for_nullptr(c_git_repository);

	return make_shared_ver<Git_Repo>(c_git_repository);
}


template<class T>
shared_ptr_t<Git_Object<T>> Git_Object<T>::peel(git_otype target_type)const
{
	git_object* c_git_object_out;
	check_for_error(git_object_peel(&c_git_object_out, c_guts_, target_type));

	return make_shared_ver<Git_Object<T>>(c_git_object_out);
}


template<class T>
shared_ptr_t<Git_Buf> Git_Object<T>::short_id()const
{
	git_buf c_git_buf_out;
	check_for_error(git_object_short_id(&c_git_buf_out, const git_object *obj));

	return make_shared_ver<Git_Buf>(std::move(c_git_buf_out));
}

template<class T>
git_otype Git_Object<T>::string_2_type(const string_t& str)const
{
	return git_object_string2type(str.c_str());
}

template<class T>
git_otype Git_Object<T>::type()const
{
	return git_object_type(c_guts_);
}

template<class T>
string_t Git_Object<T>::type_2_string()const
{
	return git_object_type2string(type());
}

template<class T>
bool Git_Object<T>::is_loose_type()const
{
	return git_object_typeisloose(type());
}

