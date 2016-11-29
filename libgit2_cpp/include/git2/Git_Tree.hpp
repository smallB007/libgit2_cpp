#pragma once
#include "precompiled.hpp"

class Git_Tree : public Provider<git_tree>
{
public:
	Git_Tree(const git_tree * c_git_tree);
	~Git_Tree()=default;
	LIBGIT2_TREE_INTERFACE
		Git_Tree duplicate(const Git_Tree&)const;
	Git_Tree_Entry entry_by_id(const Git_Object_ID&)const;
	Git_Tree_Entry entry_by_index(const size_t)const;
	Git_Tree_Entry entry_by_index(const string_t&)const;
	Git_Tree_Entry entry_by_path(const string_t&)const;
	int compare_tree_entries(const git_tree_entry *e1, const git_tree_entry *e2)const;
	Git_Tree_Entry duplicate_tree_entry(const Git_Tree_Entry&)const;
	git_filemode_t tree_entry_filemode(const Git_Tree_Entry&)const;
	git_filemode_t tree_entry_filemode_raw(const Git_Tree_Entry&)const;
	Git_Object_ID tree_entry_id(const Git_Tree_Entry&)const;
	string_t tree_entry_name(const Git_Tree_Entry&)const;
	Git_Object<git_object> tree_entry_to_object(const Git_Tree_Entry&);
	git_otype tree_entry_type(const Git_Tree_Entry&);
	size_t tree_entry_count()const;
	Git_Object_ID id()const;
	Git_Tree lookup(const Git_Object_ID&)const;
#ifdef _FULL_IMPLEMENTATION_
		git_tree_create_updated
			git_tree_lookup_prefix
			git_tree_walk
#endif
		
};

