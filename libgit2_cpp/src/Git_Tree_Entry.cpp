#include "Git_Tree_Entry.hpp"
#include "Git_Object_ID.hpp"

Git_Tree_Entry::Git_Tree_Entry(const git_tree_entry* c_git_tree_entry):Provider(c_git_tree_entry,git_tree_entry_free)
{
}


uint16_t Git_Tree_Entry::attr()const
{
	//c_guts_->attr;
#pragma message("Error what in hell is that")
	return -1;
#pragma message("Error f")
}
uint16_t Git_Tree_Entry::filename_len()const
{
#pragma message("Error f")
	return -1;
}
const Git_Object_ID Git_Tree_Entry::oid()const
{
#pragma message("Error f ")
	return Git_Object_ID(nullptr);
}
string_t Git_Tree_Entry::filename()const
{
#pragma message("Error f")
	return "";
}