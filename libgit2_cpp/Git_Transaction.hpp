#pragma once
#include "stdafx.h"

class Git_Transaction : public Provider<git_transaction>
{
#pragma message("ToDo Maybe the other functionality needs to be implemented as well?")
	Git_Transaction(git_transaction*);
};