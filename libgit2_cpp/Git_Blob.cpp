#include "Git_Blob.hpp"
#include "Git_Object_ID.hpp"
#include "Git_Root.hpp"

Git_Blob::Git_Blob(git_blob * c_git_blob):Provider(c_git_blob,git_blob_free)
{
	c_guts_ = c_git_blob;
}

shared_ptr_t<Git_Object_ID> Git_Blob::create_from_buffer(const NMS::vector<char>& buffer)
{
	git_oid* c_git_oid_out{};
	check_for_error(git_blob_create_frombuffer(c_git_oid_out, c_parent_guts(), &buffer, NMS::size(buffer)));

	return make_shared_ver<Git_Object_ID>(c_git_oid_out);
}

shared_ptr_t<Git_Object_ID> Git_Blob::create_from_disk(const path_name_t& file_path)
{
	git_oid* c_git_oid_out{};
	check_for_error(git_blob_create_fromdisk(c_git_oid_out, c_parent_guts(), file_path.c_str()));

	return make_shared_ver<Git_Object_ID>(c_git_oid_out);
}

shared_ptr_t<Git_Object_ID> Git_Blob::create_from_workdir(const path_name_t& relative_file_path)
{
	git_oid* c_git_oid_out{};
	check_for_error(git_blob_create_fromworkdir(c_git_oid_out, c_parent_guts(), relative_file_path.c_str()));
	
	return make_shared_ver<Git_Object_ID>(c_git_oid_out);
}


shared_ptr_t<Git_Repo> Git_Blob::owner()const
{
	git_repository* c_git_repo = git_blob_owner(c_guts_);
	if (FAILED(c_git_repo))
	{
		throw - 1;
	}

	return Git_Root::GetInstance()->find_c_git_repository(c_git_repo);

}


shared_ptr_t<Git_Object_ID> Git_Blob::id()const
{

	const git_oid* c_git_oid = git_blob_id(c_guts_);
	return make_shared_ver<Git_Object_ID>(/*const_cast<git_oid*>*/(c_git_oid));

}

const NMS::vector<char> Git_Blob::raw_content() const
{
	const void* c_git_raw_content = git_blob_rawcontent(c_guts_);
	const size_t c_git_raw_size = git_blob_rawsize(c_guts_);
	char* not_raw_content = (char*)c_git_raw_content;
	return NMS::vector<char>(not_raw_content, not_raw_content + c_git_raw_size);
}

const NMS::size_t Git_Blob::raw_size()const
{
	const size_t c_git_raw_size = git_blob_rawsize(c_guts_);
	return c_git_raw_size;
}

bool Git_Blob::is_binary()const
{
	int res = git_blob_is_binary(c_guts_);
	
	return res;
}

shared_ptr_t<Git_Blob> Git_Blob::duplicate() const
{
	git_blob* c_git_blob_out;
#ifdef LIBGIT2_DUPLICATION_IMPLEMENTED
	int res = git_blob_dup(&c_git_blob_out,c_guts_);
#else
	int res = git_object_dup((git_object**)&c_git_blob_out,(git_object*)c_guts_);
#endif
	if (FAILED(res))
	{
		throw - 1;
	}
	shared_ptr_t<Git_Blob> duplicated = make_shared_ver<Git_Blob>(c_git_blob_out);
	return duplicated;
}

shared_ptr_t<Git_Blob> Git_Blob::lookup(const Git_Object_ID& oid) const
{
	git_blob* c_git_blob_out{};
	check_for_error(git_blob_lookup(&c_git_blob_out, c_parent_guts(), oid.c_guts()));

	return make_shared_ver<Git_Blob>(c_git_blob_out);
}
