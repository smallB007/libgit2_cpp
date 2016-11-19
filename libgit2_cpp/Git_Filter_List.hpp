#pragma once
#include  "stdafx.h"
class Git_Filter_List : public Provider<git_filter_list>
{
public:
	Git_Filter_List(git_filter_list*);
	~Git_Filter_List();
	LIBGIT2_FILTER_LIST_INTERFACE
		shared_ptr_t<Git_Buf> apply_to_blob(const Git_Filter_List&,const Git_Blob&)const;
	shared_ptr_t<Git_Buf> apply_to_data(const Git_Buf&)const;
	shared_ptr_t<Git_Buf> apply_to_file(const path_name_t&)const;
	bool contains(const string_t& name)const;
	size_t length()const;
	shared_ptr_t<Git_Filter_List> load(const Git_Blob& blob, const path_name_t& relative_path, git_filter_mode_t filterMode, uint32_t flags) const;
	shared_ptr_t<Git_Filter> lookup(const filter_name_t&)const;
	void register_filter(const filter_name_t&,Git_Filter&, int priority)const;

	uint16_t filter_source_filemode(const Git_Filter_Source& src)const;
	uint32_t filter_source_flags(const Git_Filter_Source& src)const;
	shared_ptr_t<const Git_Object_ID> filter_source_id(const Git_Filter_Source& src)const;
	git_filter_mode_t filter_source_mode(const Git_Filter_Source& src)const;
	path_name_t filter_source_path(const Git_Filter_Source& src)const;
	shared_ptr_t<Git_Repo> filter_source_repo(const Git_Filter_Source& src)const;
	void unregister(const filter_name_t&)const;
#ifdef _FULL_IMPLEMENTATION_
	git_filter_list_push
		git_filter_list_stream_blob
		git_filter_list_stream_data
		git_filter_list_stream_file
#endif
};

