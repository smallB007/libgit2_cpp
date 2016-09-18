#pragma once
#include "stdafx.h"
#include "Provider.hpp"
/*c++ class needs to inherit from Provider giving an c_git_type as a template parameter,
and then in the ctor of Provider give c_git_type_deleter fnc*/


class Git_ODB : public Provider<git_odb>
{
	
public:
	Git_ODB();
	
};

