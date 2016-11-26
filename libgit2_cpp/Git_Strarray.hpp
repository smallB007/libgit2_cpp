#pragma once
#include "stdafx.h"
class Git_Strarray : public Provider<git_strarray>
{
public:
	Git_Strarray(git_strarray*);
	Git_Strarray(const git_strarray&);
	template<class Container>
	Git_Strarray(const Container&);
	~Git_Strarray()=default;
	size_t size()const;
	void push_back(const string_t&);
#pragma message("ToDo implement iterator")
#pragma message("Idea implement conversion operator to the most common containers")
#pragma message("Idea implement converstion from most common containers")
};


