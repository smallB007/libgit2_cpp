#pragma once
#include "precompiled.hpp"
class Git_Diff_Similarity_Metric : public Provider<git_diff_similarity_metric>
{
public:
	Git_Diff_Similarity_Metric(git_diff_similarity_metric*);
	~Git_Diff_Similarity_Metric()=default;
#pragma message("ToDo finish it")
};

