#pragma once
#include "stdafx.h"
class Git_Reference : public Provider<git_reference>
{
public:
	Git_Reference(git_reference*);
	~Git_Reference()=default;
	LIBGIT2_REFERENCE_INTERFACE
		shared_ptr_t<Git_Reference> reference_from_id(const string_t&, const Git_Object_ID&, const Git_Object_ID&)const;
		shared_ptr_t<Git_Reference> symbolic_reference_from_id(const string_t&, const string_t&)const;
		bool compare(const Git_Reference& left, const Git_Reference& right);
		shared_ptr_t<Git_Reference> create(const string_t& name, const Git_Object_ID& id, bool force, const string_t& logMessage) const;
		shared_ptr_t<Git_Reference> create_matching(const string_t & name, const Git_Object_ID & id, bool force, const Git_Object_ID&currentId, const string_t & logMessage) const;
		void delete_reference(const Git_Reference&)const;
		shared_ptr_t<Git_Reference> dwim_reference(const string_t& shorthand)const;
		void ensure_log(const string_t& shorthand)const;
		bool has_log(const string_t& refname) const;
		bool is_local_branch()const;
		bool is_note()const;
		bool is_remote()const;
		bool is_tag()const;
		bool is_valid_name(const string_t& refname)const;
		std::set<string_t> list()const;
		shared_ptr_t<Git_Reference> lookup(const string_t& refname)const;
		string_t name()const;
		shared_ptr_t<Git_Object_ID> name_to_id(const string_t&)const;
		string_t normalize_name(const string_t& name, int flags) const;
		shared_ptr_t<Git_Repo> owner()const;
		template<class T>
		shared_ptr_t<Git_Object<T>> peel(git_otype type) const;
		void remove(const string_t&)const;
		shared_ptr_t<Git_Reference> rename(const string_t& newName, int force, const string_t& logMessage) const;
		shared_ptr_t<Git_Reference> resolve()const;
		shared_ptr_t<Git_Reference> set_target(const Git_Object_ID& id, const string_t& logMessage) const;
		string_t shorthand()const;
		shared_ptr_t<Git_Reference> create_symbolic_reference(const string_t& name, const string_t& target, int force, const string_t& logMessage) const;
		shared_ptr_t<Git_Reference> create_symbolic_reference_matching(const string_t & name, const string_t & target, int force, const string_t& currentValue, const string_t & logMessage) const;
		shared_ptr_t<Git_Reference> set_target(const string_t& target, const string_t& logMessage)const;
		string_t symbolic_target()const;
		shared_ptr_t<Git_Object_ID> target()const;
		shared_ptr_t<Git_Object_ID> target_peel()const;
		git_ref_t type()const;
#ifdef GIT_REFERENCE_DUP
		shared_ptr_t<Git_Reference> duplicate_reference(const Git_Reference&)const;
#endif
#ifdef _FULL_IMPLEMENTATION_
		git_reference_foreach
			git_reference_foreach_glob
			git_reference_foreach_name
			git_reference_iterator_free
			git_reference_iterator_glob_new
			git_reference_iterator_new
			git_reference_next
			git_reference_next_name
#endif
};

