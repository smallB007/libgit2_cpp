#include "Git_Refspec.hpp"
#include "Git_Buf.hpp"


Git_Refspec::Git_Refspec():Provider(c_guts_,nullptr)
{
#pragma message("Warning nullptr passed as a deleter")
}

Git_Refspec::Git_Refspec(const git_refspec* c_git_refspec):Provider(c_git_refspec,nullptr)
{
#pragma message("Warning nullptr passed as a deleter")
}



string_t Git_Refspec::get_string()const
{
	return git_refspec_string(c_guts_);
#pragma message("Idea that's the way to deal with the using of undefined type problem")
}
string_t Git_Refspec::get_surce()const
{
	return git_refspec_src(c_guts_);
}
string_t Git_Refspec::get_destination()const
{
	return git_refspec_dst(c_guts_);
}

bool Git_Refspec::is_force() const
{
	return git_refspec_force(c_guts_);
}

git_direction Git_Refspec::direction() const
{
	return git_refspec_direction(c_guts_);
}

bool Git_Refspec::is_source_matching(const string_t& refname) const
{
	return git_refspec_src_matches(c_guts_, refname.c_str());
}

bool Git_Refspec::is_destination_matching(const string_t &refname) const
{
	return git_refspec_dst_matches(c_guts_, refname.c_str());
}

Git_Buf Git_Refspec::transform(const string_t &name) const
{
	Git_Buf _git_buf_;
	git_refspec_transform(_git_buf_, c_guts_, name.c_str());

	return Git_Buf(_git_buf_);
}

Git_Buf Git_Refspec::rtransform(const string_t &name) const
{
	Git_Buf _git_buf_;
	check_for_error(git_refspec_rtransform(_git_buf_, c_guts_, name.c_str()));

	return Git_Buf(_git_buf_);
#pragma message("ToDo check if ctor won't leak")
}
