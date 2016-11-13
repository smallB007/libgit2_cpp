#pragma once
#include "stdafx.h"
class Git_C_Object :  public Guts_Provider<git_object>
{
public:
	Git_C_Object(git_object*);
	~Git_C_Object();
#pragma message("ToDo implement it asap")
};

