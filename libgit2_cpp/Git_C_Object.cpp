#include "Git_C_Object.hpp"



Git_C_Object::Git_C_Object(git_object* c_git_object):Guts_Provider(c_git_object,git_object_free)
{
}


Git_C_Object::~Git_C_Object()
{
}
