#pragma once
#include "stdafx.h"

class Git_Tree : public Provider<git_tree>
{
public:
	Git_Tree(git_tree * c_git_tree);
	~Git_Tree()=default;
};

