#pragma once
#include "STD_Variants.hpp"
typedef NMS::string repo_path_t;
typedef NMS::string branch_name_t;
typedef NMS::string namespace_name_t;
typedef NMS::string path_name_t;
typedef NMS::string file_name_t;
typedef NMS::string filter_name_t;
typedef NMS::string string_t;

template<class T>
using vector_t = NMS::vector<T>;

template<class _Kty,
	class _Pr = std::less<_Kty>,
	class _Alloc = std::allocator<_Kty> >
using set_t = NMS::set<_Kty,_Pr,_Alloc>;

template<class T,class Y>
using pair_t = NMS::pair<T,Y>;

template<class T>
using shared_ptr_t = NMS::shared_ptr<T>;

template<class T>
using unique_ptr_t = NMS::unique_ptr<T>;

template<class c_git_class>
using c_git_deleter_t = NMS::function<void(c_git_class*)>;


