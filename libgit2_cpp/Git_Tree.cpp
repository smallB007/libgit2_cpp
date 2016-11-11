#include "Git_Tree.hpp"



Git_Tree::Git_Tree(git_tree * c_git_tree):Provider(c_git_tree,git_tree_free)
{
	
}

