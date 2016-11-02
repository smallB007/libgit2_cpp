#include "Git_Describe.hpp"


Git_Describe::Git_Describe(git_describe_result* c_git_describe_result):Provider(c_git_describe_result,git_describe_result_free)
{
}
