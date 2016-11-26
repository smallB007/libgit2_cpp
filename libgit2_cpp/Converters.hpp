#pragma once
#include "stdafx.h"

inline void git_strarray_to_imp_(vector_t<string_t>& result, const git_strarray* c_git_strarray_out)
{
	for (int i{ 0 }; i < c_git_strarray_out->count; ++i)
	{
		string_t str(c_git_strarray_out->strings[i]);
		result.emplace_back(str);
	}
}

inline void git_strarray_to_imp_(set_t<string_t>& result, const git_strarray* c_git_strarray_out)
{
	for (int i{ 0 }; i < c_git_strarray_out->count; ++i)
	{
		string_t str(c_git_strarray_out->strings[i]);
		result.insert(str);
	}
}

template<class Container>
inline Container git_strarray_to(const git_strarray* c_git_strarray_out)
{
	Container result;
	git_strarray_to_imp_(result, c_git_strarray_out);

	return result;
}

template<class Container>
inline Git_Strarray convert_to_git_strarray(const Container& cont)
{
	Git_Strarray result;
	for (string_t& str : cont)
	{
		result.push_back(str);
	}

	return result;
}

template<class Git_Type>
inline vector_t<typename Git_Type::c_git_class*> convert_to_libgit2_type(const vector_t<Git_Type>& vec)
{
	typedef typename Git_Type::c_git_class return_type;
	vector_t<return_type*> vec_libgit2_type;
	vec_libgit2_type.reserve(vec.size());
	for (const Git_Type& item : vec)
	{
		vec_libgit2_type.emplace_back(item.c_guts());
	}

	return vec_libgit2_type;
}