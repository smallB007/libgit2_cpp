#pragma once
#include "stdafx.h"
class Git_Strarray : Provider<git_strarray>
{
public:
	Git_Strarray(git_strarray*);
	Git_Strarray(const git_strarray&);
	~Git_Strarray()=default;
	size_t size()const;
#pragma message("ToDo implement iterator")
#pragma message("Idea implement conversion operator to the most common containers")
};

