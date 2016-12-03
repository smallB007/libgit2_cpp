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

//#define UNUSED(x) __pragma(warning(suppress:4100)) x

/***This macro is used in every Git class that is exposed to 3rd user
	so that the user can only create it via Factory_Git_Object and may not destroy it*/
#define DECLARE_CREATION_AND_DESTRUCTION_PRIVILEGES template<class Git_Class> \
													friend class Factory_Git_Object;\
													friend typename Provider<typename Provider::c_git_class>::Git_Deleter;