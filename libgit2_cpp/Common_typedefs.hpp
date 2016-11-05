#pragma once
#include "STD_Variants.hpp"
typedef NMS::string repo_path_t;
typedef NMS::string branch_name_t;
typedef NMS::string namespace_name_t;
typedef NMS::string file_path_t;
typedef NMS::string file_name_t;
typedef NMS::string string_t;

template<class T>
using vector_t = NMS::vector<T>;

template<class T>
using shared_ptr_t = NMS::shared_ptr<T>;

template<class T>
using unique_ptr_t = NMS::unique_ptr<T>;

template<class c_git_class>
using c_git_deleter_t = NMS::function<void(c_git_class*)>;


