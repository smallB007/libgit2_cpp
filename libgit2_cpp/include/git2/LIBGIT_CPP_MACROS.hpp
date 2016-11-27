#pragma once
#include "precompiled.hpp"

#ifdef LIBGIT2_CPP_EXPORTS  
#define LIBGIT2_CPP_API __declspec(dllexport)   
#else  
#define LIBGIT2_CPP_API __declspec(dllimport)   
#endif

/***
This macro is used in each class that inherits from Singleton
*/
#define BEFRIEND_SINGLETON(x) friend class Singleton<x>

#define UNUSED(x) __pragma(warning(suppress:4100)) x