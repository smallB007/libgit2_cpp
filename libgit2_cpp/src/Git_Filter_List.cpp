#include "Git_Filter_List.hpp"
#include "Git_Blob.hpp"
#include "Git_Buf.hpp"
#include "Git_Filter.hpp"
#include "Git_Filter_Source.hpp"
Git_Filter_List::Git_Filter_List(git_filter_list* c_git_filter_list):Provider(c_git_filter_list,git_filter_list_free)
{
}

Git_Filter_List::~Git_Filter_List()
{
}

shared_ptr_t<Git_Buf> Git_Filter_List::apply_to_blob(const Git_Filter_List & filters, const Git_Blob & blob) const
{
	git_buf c_git_buf_out;
	check_for_error(git_filter_list_apply_to_blob(&c_git_buf_out, filters.c_guts_, blob.c_guts()));
	return make_shared_ver<Git_Buf>(c_git_buf_out);
}

shared_ptr_t<Git_Buf> Git_Filter_List::apply_to_data(const Git_Buf & gitBuf) const
{
	git_buf c_git_buf_out;

	check_for_error(git_filter_list_apply_to_data(&c_git_buf_out, c_guts_, gitBuf.c_guts()));

	return make_shared_ver<Git_Buf>(c_git_buf_out);
}

shared_ptr_t<Git_Buf> Git_Filter_List::apply_to_file(const string_t& path) const
{
	git_buf c_git_buf_out;

	check_for_error(git_filter_list_apply_to_file(&c_git_buf_out, c_guts_, c_parent_guts(), path.c_str()));

	return make_shared_ver<Git_Buf>(c_git_buf_out);
}

bool Git_Filter_List::contains(const string_t & name) const
{
	return (1 == git_filter_list_contains(c_guts_, name.c_str()));
}

size_t Git_Filter_List::length() const
{
	return git_filter_list_length(c_guts_);
}
shared_ptr_t<Git_Filter_List> Git_Filter_List::load(const Git_Blob& blob, const string_t& relative_path, git_filter_mode_t filterMode, uint32_t flags) const
{
#pragma message("Warning Native libgit2 enum used")
	git_filter_list* c_git_filter_list_out;
	check_for_error(git_filter_list_load(&c_git_filter_list_out, c_parent_guts(), blob.c_guts(), relative_path.c_str(), filterMode, flags));
	
	return make_shared_ver<Git_Filter_List>(c_git_filter_list_out);
}

shared_ptr_t<Git_Filter> Git_Filter_List::lookup(const string_t & filterName) const
{
	git_filter* c_git_filter_out = git_filter_lookup(filterName.c_str());

	return make_shared_ver<Git_Filter>(*c_git_filter_out);
}

void Git_Filter_List::register_filter(const string_t & filterName, Git_Filter & filter, int priority) const
{
	check_for_error(git_filter_register(filterName.c_str(), filter.c_guts(), priority));
}


uint16_t Git_Filter_List::filter_source_filemode(const Git_Filter_Source&  filterSrc)const
{
	return filterSrc.filemode();
}

uint32_t Git_Filter_List::filter_source_flags(const Git_Filter_Source & filterSrc)const
{
	return filterSrc.flags();
}

shared_ptr_t<const Git_Object_ID> Git_Filter_List::filter_source_id(const Git_Filter_Source& filterSrc) const
{
	return filterSrc.id();
}

git_filter_mode_t Git_Filter_List::filter_source_mode(const Git_Filter_Source & fileSrc) const
{
	return fileSrc.mode();
}

string_t Git_Filter_List::filter_source_path(const Git_Filter_Source & fileSrc) const
{
	return fileSrc.path();
}

shared_ptr_t<Git_Repo> Git_Filter_List::filter_source_repo(const Git_Filter_Source& fileSrc) const
{
	return fileSrc.repo();
}

void Git_Filter_List::unregister(const string_t & filterName) const
{
	check_for_error(git_filter_unregister(filterName.c_str()));
}

