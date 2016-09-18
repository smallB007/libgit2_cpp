#pragma once
#include <string>
typedef NMS::string repo_path_t;
typedef NMS::string branch_name_t;
typedef NMS::string namespace_name_t;
typedef NMS::string file_path_t;

template<class c_git_class>
using deleter_t = NMS::function<void(c_git_class*)>;