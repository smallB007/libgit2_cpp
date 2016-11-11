#pragma once
#include "stdafx.h"

struct Git_Diff_Callback_Pack
{
	git_diff_file_cb file_cb_;
	git_diff_binary_cb binary_cb_;
	git_diff_hunk_cb hunk_cb_;
	git_diff_line_cb line_cb_;
	void* payload_;
};

class Git_Diff : public Provider<git_diff>
{
public:
	Git_Diff(git_diff*);
	~Git_Diff()=default;
	LIBGIT2_DIFF_INTERFACE
		shared_ptr_t<Git_Buf>	diff_blob_to_buffer(const Git_Blob& gitBlob,
													const string_t& old_blob_as_path,
													const Git_Buf& gitBuf,
													const string_t& buffer_as_path,
													const Git_Diff_Options& diff_options, Git_Diff_Callback_Pack callback_pack);

	shared_ptr_t<Git_Buf> diff_blobs(const Git_Blob& gitBlob_Old,
									 const string_t& old_blob_as_path,
									 const Git_Blob& gitBlob_New,
									 const string_t& new_blob_as_path,
									 const Git_Diff_Options& diff_options, Git_Diff_Callback_Pack callback_pack);

	shared_ptr_t<Git_Buf> diff_buffers(const Git_Buf& gitBuf_Old,
										const string_t& old_buffer_as_path, 
										const Git_Buf& gitBuf_New,
										const string_t& new_buffer_as_path,
										const Git_Diff_Options& diff_options, Git_Diff_Callback_Pack callback_pack);
	void find_similar(Git_Diff& gitDiff, const Git_Diff_Find_Options& gitDiffFingOptions);
	void diff_foreach(const Git_Diff& gitDiff, const Git_Diff_Callback_Pack callback_pack);
#ifdef GIT_DIFF_FROM_BUFFER
	shared_ptr_t<Git_Diff> diff_from_buffer(const string_t&)const;
#endif
	Git_Diff_Delta get_delta(const Git_Diff&,const size_t)const;
	Git_Diff_Perfdata get_perfdata(const Git_Diff&)const;
	shared_ptr_t<Git_Diff_Stats> get_stats(const Git_Diff&)const;
	shared_ptr_t<Git_Diff> diff_index_to_index(const Git_Index&, const Git_Index&, const Git_Diff_Options&);
	shared_ptr_t<Git_Diff> diff_index_to_workdir(const Git_Index&, const Git_Diff_Options&);
	bool is_sorted_icase(const Git_Diff&)const;
	shared_ptr_t<Git_Diff> diff_merge(const Git_Diff&);
	size_t number_of_deltas(const Git_Diff&)const;
	size_t number_of_deltas_of_type(const Git_Diff&,const Git_Delta&)const;
	size_t deletions()const;
	size_t files_changed()const;
	size_t insertions()const;
	shared_ptr_t<Git_Buf> stats_to_buf(git_diff_stats_format_t statsFormat, size_t width)const;
	char status_char(git_delta_t status)const;
#ifdef GIT_DIFF_TO_BUFFER
	shared_ptr_t<Git_Buf> diff_to_buf(const Git_Diff&, git_diff_format_t)const;
#endif
	shared_ptr_t<Git_Diff> diff_tree_to_index(const Git_Tree& oldTree, const Git_Index& index, const Git_Diff_Options& diffOptions)const;
	shared_ptr_t<Git_Diff> diff_tree_to_tree(const Git_Tree& oldTree, const Git_Tree& newTree, const Git_Diff_Options& diffOptions)const;
	shared_ptr_t<Git_Diff> diff_tree_to_workdir(const Git_Tree& oldTree, const Git_Diff_Options& diffOptions)const;
	shared_ptr_t<Git_Diff> diff_tree_to_workdir_with_index(const Git_Tree& oldTree, const Git_Diff_Options& diffOptions)const;

#ifdef _FULL_IMPLEMENTATION_
	git_diff_commit_as_email
		git_diff_find_init_options

		git_diff_format_email
		git_diff_format_email_init_options
		git_diff_print
		git_diff_print_callback__to_buf
		git_diff_print_callback__to_file_handle
#endif
	
};

