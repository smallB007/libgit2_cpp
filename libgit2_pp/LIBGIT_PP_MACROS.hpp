#pragma once
template<class T>
class Singleton;

/***
This macro is used in each class that inherits from Singleton
*/
#define BEFRIEND_SINGLETON(x) friend class Singleton<x>