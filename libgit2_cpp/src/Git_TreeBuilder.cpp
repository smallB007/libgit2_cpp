#include "Git_TreeBuilder.hpp"
#include "Git_Tree_Entry.hpp"
#include "Git_Object_ID.hpp"

Git_TreeBuilder::Git_TreeBuilder(git_treebuilder* c_git_treebuilder):Provider(c_git_treebuilder,git_treebuilder_free)
{
	
}

void Git_TreeBuilder::clear()
{
	git_treebuilder_clear(c_guts_);
}

unsigned Git_TreeBuilder::entrycount() const
{
	return git_treebuilder_entrycount(c_guts_);
}

Git_Tree_Entry Git_TreeBuilder::get(const string_t &filename) const
{
	const git_tree_entry * c_git_tree_entry = git_treebuilder_get(c_guts_, filename.c_str());
	check_for_nullptr(c_git_tree_entry);

	return Git_Tree_Entry(c_git_tree_entry);
}

Git_Tree_Entry Git_TreeBuilder::insert(const string_t &filename, const Git_Object_ID &id, const git_filemode_t filemode) const
{
	const git_tree_entry *c_git_tree_entry_out;
	check_for_error(git_treebuilder_insert(&c_git_tree_entry_out, c_guts_, filename.c_str(), id.c_guts(), filemode));

	return Git_Tree_Entry(c_git_tree_entry_out);
}

void Git_TreeBuilder::remove(const string_t &filename) const
{
	check_for_error(git_treebuilder_remove(c_guts_, filename.c_str()));
}

Git_Object_ID Git_TreeBuilder::write() const
{
	git_oid* id{};
	check_for_error(git_treebuilder_write(id, c_guts_));

	return Git_Object_ID(id);
}
