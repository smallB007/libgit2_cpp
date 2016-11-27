#pragma once
#include "precompiled.hpp"
class Git_Annotated_Commit : public Provider<git_annotated_commit>
{
public:
	Git_Annotated_Commit(git_annotated_commit*);
	~Git_Annotated_Commit()=default;

	shared_ptr_t<Git_Annotated_Commit> commit_from_fetchhead(const branch_name_t& branchName, const string_t& remoteUrl, const Git_Object_ID& objectID) const;
	shared_ptr_t<Git_Annotated_Commit> commit_from_ref(const Git_Reference&) const;
	shared_ptr_t<Git_Annotated_Commit> commit_from_revspec(const string_t&) const;
	shared_ptr_t<Git_Object_ID> commit_id()const;
	shared_ptr_t<Git_Annotated_Commit> commit_lookup(const Git_Object_ID&)const;


};

