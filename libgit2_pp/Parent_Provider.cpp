#include "Parent_Provider.hpp"
#include "Git_Repo.hpp"
#include "Git_Root.hpp"

NMS::shared_ptr<Git_Repo> Parent_Provider::parent_{};

NMS::shared_ptr<Git_Repo> Parent_Provider::get_parent()const
{
	parent_ = Git_Root::GetInstance()->get_active_repo();
	return parent_;
}

git_repository* Parent_Provider::c_parent_guts()const
{
	return parent_->c_guts();
}

