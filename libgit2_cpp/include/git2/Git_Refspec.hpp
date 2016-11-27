#pragma once
#include "precompiled.hpp"
class Git_Refspec : public Provider<git_refspec>
{
public:
	Git_Refspec();
	Git_Refspec(const git_refspec*);
	~Git_Refspec()=default;
	LIBGIT2_REFSPEC_INTERFACE
		string_t get_string()const;
		string_t get_surce()const;
		string_t get_destination()const;
		bool is_force()const;
		git_direction direction()const;
		bool is_source_matching(const string_t&)const;
		bool is_destination_matching(const string_t&)const;
		Git_Buf transform(const string_t&)const;
		Git_Buf rtransform(const string_t&)const;
		//unsigned int force : 1,
		//	push : 1,
		//	pattern : 1,
		//	matching : 1;
};

