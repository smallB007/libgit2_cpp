#pragma once
#include "stdafx.h"

/***
This macro is used in each class that inherits from Singleton
*/
#define BEFRIEND_SINGLETON(x) friend class Singleton<x>

#define UNUSED(x) __pragma(warning(suppress:4100)) x