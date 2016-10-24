#pragma once
#include "stdafx.h"
class Git_Blob : public Provider<git_blob>
{

private:
public:
	Git_Blob();
	Git_Blob(git_blob*);
LIBGIT2_BLOB_INTERFACE
	shared_ptr_t<Git_Object_ID> create_from_buffer(const NMS::vector<char>& buffer);
	shared_ptr_t<Git_Object_ID> create_from_disk(const file_path_t&);
	shared_ptr_t<Git_Object_ID> create_from_workdir(const file_path_t&);
	shared_ptr_t<Git_Repo> owner()const;
	shared_ptr_t<Git_Object_ID> id()const;
	bool is_binary()const;
	shared_ptr_t<Git_Blob> duplicate()const;
	shared_ptr_t<Git_Blob> lookup(const Git_Object_ID&)const;
	const NMS::vector<char> raw_content()const;
	const NMS::size_t raw_size()const;
#ifdef _FULL_IMPLEMENTATION_
	git_blob_create_fromchunks

		git_blob_create_fromstream
		git_blob_create_fromstream_commit
		git_blob_filtered_content
		git_blob_lookup_prefix
#endif
};

