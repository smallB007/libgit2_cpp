#pragma once
#include "stdafx.h"
class Git_Blob : public Provider<git_blob>
{
	/*Those three friend declarations below have the solely purpose of allowing to create a shared ptr with private Git_Blob ctor*/
	friend class NMS::shared_ptr<Git_Blob>;
	
	template<class _Ty,
	class... _Types>
	friend inline
	NMS::shared_ptr<_Ty> make_shared(_Types&&... _Args);
	
	template<class _Ty>
	friend class NMS::_Ref_count_obj;

private:
	Git_Blob(git_blob*);
public:
	Git_Blob();
LIBGIT2_BLOB_INTERFACE
	NMS::shared_ptr<Git_Object_ID> create_from_buffer(const NMS::vector<char>& buffer);
	NMS::shared_ptr<Git_Object_ID> create_from_disk(const file_path_t&);
	NMS::shared_ptr<Git_Object_ID> create_from_workdir(const file_path_t&);
	NMS::shared_ptr<Git_Repo> owner()const;
	NMS::shared_ptr<Git_Object_ID> id()const;
	bool is_binary()const;
	NMS::shared_ptr<Git_Blob> duplicate()const;
	NMS::shared_ptr<Git_Blob> lookup(const Git_Object_ID&)const;
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

