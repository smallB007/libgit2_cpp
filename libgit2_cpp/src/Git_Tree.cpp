#include "Git_Tree.hpp"
#include "Git_Object_ID.hpp"
#include "Git_Tree_Entry.hpp"

#pragma message("Warning perhaps the return type here will have to be changed to shared_ptr_t")
Git_Tree::Git_Tree(const git_tree * c_git_tree):Provider(c_git_tree,git_tree_free)
{
#pragma message("ToDo make every Git ctor take its args by const")
}

Git_Tree Git_Tree::duplicate(const Git_Tree& source) const
{
	git_tree* c_git_tree_out;
#ifdef _GIT_TREE_DUP_IMPLEMENTED_
	check_for_error(git_tree_dup(&c_git_tree_out, source.c_guts_));
#else
	check_for_error(git_object_dup((git_object**)&c_git_tree_out, (git_object*)source.c_guts_));
#endif
	return Git_Tree(c_git_tree_out);
#pragma message("Idea why not just pass it by value, dropping shared_ptr_t altogheter?")
#pragma message("Idea because perhaps the ptr will get deleted as soon as the object will seize to exist?")
}

Git_Tree_Entry Git_Tree::entry_by_id(const Git_Object_ID & id) const
{
	const git_tree_entry * c_git_entry = git_tree_entry_byid(c_guts_, id.c_guts());
	check_for_nullptr(c_git_entry);

	return Git_Tree_Entry(c_git_entry);
}

Git_Tree_Entry Git_Tree::entry_by_index(const size_t idx) const
{
	const git_tree_entry * c_git_entry = git_tree_entry_byindex(c_guts_, idx);
	check_for_nullptr(c_git_entry);

	return Git_Tree_Entry(c_git_entry);
}

Git_Tree_Entry Git_Tree::entry_by_index(const file_name_t & filename) const
{
	const git_tree_entry * c_git_entry = git_tree_entry_byname(c_guts_, filename.c_str());
	check_for_nullptr(c_git_entry);

	return Git_Tree_Entry(c_git_entry);
}

Git_Tree_Entry Git_Tree::entry_by_path(const path_name_t & path) const
{
	git_tree_entry* c_git_tree_entry;
	check_for_error(git_tree_entry_bypath(&c_git_tree_entry, c_guts_, path.c_str()));

	return Git_Tree_Entry(c_git_tree_entry);
}

int Git_Tree::compare_tree_entries(const git_tree_entry * e1, const git_tree_entry * e2) const
{
	return git_tree_entry_cmp(e1, e2);
}

Git_Tree_Entry Git_Tree::duplicate_tree_entry(const Git_Tree_Entry &source) const
{
	git_tree_entry *c_git_tree_entry_out;
	check_for_error(git_tree_entry_dup(&c_git_tree_entry_out, source.c_guts()));

	return Git_Tree_Entry(c_git_tree_entry_out);
}



git_filemode_t Git_Tree::tree_entry_filemode(const Git_Tree_Entry & entry)const
{
	return git_tree_entry_filemode(entry.c_guts());
#pragma message("Warning native libgit2 type used")
}

git_filemode_t Git_Tree::tree_entry_filemode_raw(const Git_Tree_Entry & entry) const
{
	return git_tree_entry_filemode_raw(entry.c_guts());
}

Git_Object_ID Git_Tree::tree_entry_id(const Git_Tree_Entry &entry) const
{
	const git_oid * c_git_oid = git_tree_entry_id(entry.c_guts());

	return Git_Object_ID(c_git_oid);
}

string_t Git_Tree::tree_entry_name(const Git_Tree_Entry & entry) const
{
	return git_tree_entry_name(entry.c_guts());
}

Git_Object<git_object> Git_Tree::tree_entry_to_object(const Git_Tree_Entry &entry)
{
	git_object* c_git_object_out;
	check_for_error(git_tree_entry_to_object(&c_git_object_out, c_parent_guts(), entry.c_guts()));

	return Git_Object<git_object>(c_git_object_out,git_object_free);
}

git_otype Git_Tree::tree_entry_type(const Git_Tree_Entry &entry)
{
	return git_tree_entry_type(entry.c_guts());
#pragma message("Warning native libgit2 type used")
}

size_t Git_Tree::tree_entry_count() const
{
	return git_tree_entrycount(c_guts_);
}

Git_Object_ID Git_Tree::id() const
{
	const git_oid * c_git_oid = git_tree_id(c_guts_);

	return Git_Object_ID(c_git_oid);
}

Git_Tree Git_Tree::lookup(const Git_Object_ID &id) const
{
	git_tree* c_git_tree_out;
	check_for_error(git_tree_lookup(&c_git_tree_out, c_parent_guts(), id.c_guts()));

	return Git_Tree(c_git_tree_out);
}
