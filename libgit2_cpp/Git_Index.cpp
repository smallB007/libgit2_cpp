#include "Git_Index.hpp"
#include "Git_Index_Entry.hpp"
#include "Git_Buf.hpp" 
#include "Git_Object_ID.hpp"
#include "Git_Repo.hpp"
#include "Git_Tree.hpp"
Git_Index::Git_Index(git_index* c_git_index): Provider(c_git_index,git_index_free)
{
}

Git_Index::Git_Index():Provider(c_guts_,git_index_free)
{
#pragma message("Idea THIS^^^ is something REALLY INTERESTING")
	git_index *c_git_index_out;
	check_for_error(git_index_new(&c_git_index_out));
	c_guts_ = c_git_index_out;
}

void Git_Index::add(Git_Index_Entry & indexEntry)
{
	check_for_error(git_index_add(c_guts_, indexEntry.c_guts()));
}

void Git_Index::add_bypath(const file_path_t & path)
{
	check_for_error(git_index_add_bypath(c_guts_, path.c_str()));
}

void Git_Index::add_from_buffer(const Git_Index_Entry& indexEntry, const Git_Buf& buffer)
{
	check_for_error(git_index_add_frombuffer(c_guts_, indexEntry.c_guts(), buffer.c_guts(), buffer.size()));
}

int Git_Index::caps() const
{
	return git_index_caps(c_guts_);
}

shared_ptr_t<const Git_Object_ID> Git_Index::checksum() const
{
	const git_oid * c_git_oid = git_index_checksum(c_guts_);
	return make_shared_ver<Git_Object_ID>(const_cast<git_oid*>(c_git_oid));
}

void Git_Index::clear()
{
	check_for_error(git_index_clear(c_guts_));
}

void Git_Index::conflict_add(const Git_Index_Entry& ancestor_entry, const Git_Index_Entry& our_entry, const Git_Index_Entry& their_entry)
{
	check_for_error(git_index_conflict_add(c_guts_, ancestor_entry.c_guts(), our_entry.c_guts(), their_entry.c_guts()));
}

void Git_Index::conflict_cleanup()
{
	check_for_error(git_index_conflict_cleanup(c_guts_));
}

vector_t<shared_ptr_t<Git_Index_Entry>> Git_Index::conflict_get(const file_path_t& path) 
{
	const git_index_entry* c_git_index_entry_ancestor_out{};
	const git_index_entry* c_git_index_entry_our_out{};
	const git_index_entry* c_git_index_entry_their_out{};

	check_for_error(git_index_conflict_get(&c_git_index_entry_ancestor_out, &c_git_index_entry_our_out, &c_git_index_entry_their_out, c_guts_, path.c_str()));

	typedef vector_t<shared_ptr_t<Git_Index_Entry>> vector_result_t;

	vector_result_t vec_result{make_shared_ver<Git_Index_Entry>(*c_git_index_entry_ancestor_out),
							   make_shared_ver<Git_Index_Entry>(*c_git_index_entry_our_out),
							   make_shared_ver<Git_Index_Entry>(*c_git_index_entry_their_out) };
	return vec_result;
}

void Git_Index::conflict_remove(const file_path_t& path)
{
	check_for_error(git_index_conflict_remove(c_guts_, path.c_str()));
}

bool Git_Index::entry_is_conflict(const Git_Index_Entry & entry) const
{
	return git_index_entry_is_conflict(entry.c_guts());
}

int Git_Index::entry_stage(const Git_Index_Entry & entry) const
{
	return git_index_entry_stage(entry.c_guts());
}

size_t Git_Index::entry_count() const
{
	return git_index_entrycount(c_guts_);
}

size_t Git_Index::find(const file_path_t & path) const
{
	size_t inx;
	check_for_error(git_index_find(&inx, c_guts_, path.c_str()));

	return inx;
}

size_t Git_Index::find_prefix(const string_t & prefix) const
{
	size_t inx;
	check_for_error(git_index_find_prefix(&inx, c_guts_, prefix.c_str()));
	
	return inx;
}

shared_ptr_t<Git_Index_Entry> Git_Index::get_by_index(const size_t inx) const
{
	const git_index_entry * c_git_index_entry = git_index_get_byindex(c_guts_, inx);
	
	return make_shared_ver<Git_Index_Entry>(*c_git_index_entry);
}

shared_ptr_t<Git_Index_Entry> Git_Index::get_by_path(const file_path_t & path, const int stage) const
{
	const git_index_entry * c_git_index_entry = git_index_get_bypath(c_guts_, path.c_str(), stage);

	return make_shared_ver<Git_Index_Entry>(*c_git_index_entry);
}

bool Git_Index::has_conflicts() const
{
	return git_index_has_conflicts(c_guts_);
}

shared_ptr_t<Git_Index> Git_Index::open(const string_t & indexPath)
{
#pragma message("ToDo most likey need to be in different class")
	git_index* c_git_index_out;
	check_for_error(git_index_open(&c_git_index_out, indexPath.c_str()));

	return make_shared_ver<Git_Index>(c_git_index_out);
}

shared_ptr_t<Git_Repo> Git_Index::owner() const
{
	git_repository * c_git_repository = git_index_owner(c_guts_);
	
	return make_shared_ver<Git_Repo>(c_git_repository);
}

string_t Git_Index::path() const
{
	return git_index_path(c_guts_);
}

void Git_Index::read(bool force) const
{
	check_for_error(git_index_read(c_guts_, force));
}

void Git_Index::read_tree(const Git_Tree & tree) const
{
	check_for_error(git_index_read_tree(c_guts_, tree.c_guts()));
}

void Git_Index::remove(const string_t& path, int stage) const
{
	check_for_error(git_index_remove(c_guts_, path.c_str(), stage));
}

void Git_Index::remove_by_path(const string_t & path) const
{
	check_for_error(git_index_remove_bypath(c_guts_, path.c_str()));
}

void Git_Index::remove_directory(const file_path_t & dir, const int stage) const
{
	check_for_error(git_index_remove_directory(c_guts_, dir.c_str(), stage));
}

void Git_Index::set_caps(int caps) const
{
	check_for_error(git_index_set_caps(c_guts_, caps));
}
void Git_Index::write() const
{
	check_for_error(git_index_write(c_guts_));
}

shared_ptr_t<Git_Object_ID> Git_Index::write_tree() const
{
	git_oid * c_git_out;
	check_for_error(git_index_write_tree(c_git_out,c_guts_));
	
	return make_shared_ver<Git_Object_ID>(c_git_out);
}

shared_ptr_t<Git_Object_ID> Git_Index::write_tree_to(Git_Repo & repoOut) const
{
	git_oid * c_git_out;
	check_for_error(git_index_write_tree_to(c_git_out, c_guts_, repoOut.c_guts()));

	return make_shared_ver<Git_Object_ID>(c_git_out);
}


#ifdef GIT_INDEX_SET_VERSION
unsigned Git_Index::version() const
{
	return git_index_version(c_guts_);
}
void Git_Index::set_version(unsigned version) const
{
	check_for_error(git_index_set_version(c_guts_, version));
}
#endif

