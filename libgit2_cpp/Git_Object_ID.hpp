#pragma once
#include "stdafx.h"
class Git_Object_ID : public Provider<git_oid>
{
public:
	Git_Object_ID( git_oid* c_git_oid);
};

