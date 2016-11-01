#pragma once
#include "stdafx.h"

class Git_Tree
{
	const git_tree * c_git_tree_{ nullptr };
public:
	Git_Tree(const git_tree * c_git_tree);
	~Git_Tree();
};

