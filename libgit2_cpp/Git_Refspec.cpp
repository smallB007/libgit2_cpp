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
	git_buf c_git_buf_out;
	git_refspec_transform(&c_git_buf_out, c_guts_, name.c_str());

	return Git_Buf(c_git_buf_out);
}

Git_Buf Git_Refspec::rtransform(const string_t &name) const
{
	git_buf c_git_buf_out;
	check_for_error(git_refspec_rtransform(&c_git_buf_out, c_guts_, name.c_str()));

	return Git_Buf(c_git_buf_out);
}
