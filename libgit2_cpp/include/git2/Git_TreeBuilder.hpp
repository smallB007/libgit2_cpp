#pragma once
#include "precompiled.hpp"
class Git_TreeBuilder :  public Provider<git_treebuilder>
{
public:
	Git_TreeBuilder(git_treebuilder*);
	~Git_TreeBuilder()=default;
	LIBGIT2_TREEBUILDER_INTERFACE
		void clear();
	unsigned entrycount()const;
	Git_Tree_Entry get(const file_name_t&)const;
	Git_Tree_Entry insert(const file_name_t&, const Git_Object_ID&, const git_filemode_t)const;
	void remove(const file_name_t&)const;
	Git_Object_ID write()const;
#ifdef _FULL_IMPLEMENTATION_
	git_treebuilder_filter
#endif
};

