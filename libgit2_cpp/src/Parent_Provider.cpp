#include "Parent_Provider.hpp"
#include "Git_Repo.hpp"
#include "Git_Root.hpp"
shared_ptr_t<Git_Repo> Parent_Provider::parent_{};

shared_ptr_t<Git_Repo> Parent_Provider::get_parent()
{
	parent_ = Git_Root::GetInstance()->get_active_repo();
	return parent_;
}
git_repository* Parent_Provider::c_parent_guts()
{
	return get_parent()->c_guts();
}

