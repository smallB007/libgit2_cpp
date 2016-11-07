#include "Git_Diff.hpp"
#include "Git_Blob.hpp"
#include "Git_Buf.hpp"

Git_Diff::Git_Diff(git_diff *c_git_diff):Provider(c_git_diff,git_diff_free)
{
}

//LIBGIT2_DIFF_INTERFACE shared_ptr_t<Git_Buf> Git_Diff::blob_to_buffer(const Git_Buf& git_buf, const string_t& old_as_path)
//{
//	
//	check_for_error(git_diff_blob_to_buffer(git_buf.c_guts(), old_as_path.c_str(), const char *buffer, size_t buffer_len, const char *buffer_as_path, const git_diff_options *options, git_diff_file_cb file_cb, git_diff_binary_cb binary_cb, git_diff_hunk_cb hunk_cb, git_diff_line_cb line_cb, void *payload));
//	return shared_ptr_t<Git_Buf>();
//}
