#pragma once
#include "precompiled.hpp"
class Git_Index:public Provider<git_index>
{
public:
	Git_Index(git_index*);
	Git_Index();
	LIBGIT2_INDEX_INTERFACE
	void add(Git_Index_Entry&);
	void add_bypath(const path_name_t&);
	void add_from_buffer(const Git_Index_Entry& indexEntry, const Git_Buf& buffer);
	int caps()const;
	shared_ptr_t<const Git_Object_ID> checksum()const;
	void clear();
	void conflict_add(const Git_Index_Entry& ancestor_entry, const Git_Index_Entry& our_entry, const Git_Index_Entry& their_entry);
	void conflict_cleanup();
	vector_t<shared_ptr_t<Git_Index_Entry>> Git_Index::conflict_get(const path_name_t& path) ;
	void conflict_remove(const path_name_t& path);
	bool entry_is_conflict(const Git_Index_Entry&)const;
	int entry_stage(const Git_Index_Entry&)const;
	size_t entry_count()const;
	size_t find(const path_name_t& path)const;
	size_t find_prefix(const string_t& prefix)const;
	shared_ptr_t<Git_Index_Entry> get_by_index(const size_t inx)const;
	shared_ptr_t<Git_Index_Entry> Git_Index::get_by_path(const path_name_t & path, const int stage) const;
	bool has_conflicts()const;
	shared_ptr_t<Git_Index> open(const string_t& indexPath);
	shared_ptr_t<Git_Repo> owner()const;
	string_t path()const;
	void read(bool force = false)const;
	void read_tree(const Git_Tree&)const;
	void remove(const string_t& path, int stage) const;
	void remove_by_path(const string_t& path)const;
	void remove_directory(const path_name_t&,const int)const;
	void set_caps(int caps)const;
	void write()const;
	shared_ptr_t<Git_Object_ID> write_tree()const;
	shared_ptr_t<Git_Object_ID> write_tree_to(Git_Repo&)const;
	
#ifdef GIT_INDEX_SET_VERSION
	unsigned version()const;
	void set_version(unsigned)const;
#endif
#ifdef _FULL_IMPLEMENTATION_
	git_index_add_all
		git_index_conflict_iterator_free
		git_index_conflict_iterator_new 	
		git_index_conflict_next
		git_index_remove_all
		git_index_update_all
#endif
};

