#include "Git_Indexer.hpp"
#include "Git_Transfer_Progress.hpp"
#include "Git_Object_ID.hpp"
#include "Git_ODB.hpp"

Git_Indexer::Git_Indexer(const string_t& path, unsigned int mode, Git_ODB& odb, git_transfer_progress_cb progress_cb, void *progress_cb_payload):Provider(c_guts_,git_indexer_free)
{
	check_for_error(git_indexer_new(&c_guts_, path.c_str(), mode, odb.c_guts(), progress_cb, progress_cb_payload));
}

void Git_Indexer::commit( Git_Transfer_Progress& stats) const
{
	check_for_error(git_indexer_commit(c_guts_, stats.c_guts()));
}

Git_Object_ID Git_Indexer::hash() const
{
	const git_oid * c_git_oid = git_indexer_hash(c_guts_);
	check_for_nullptr(c_git_oid);

	return Factory_Git_Object<Git_Object_ID>::create(c_git_oid);
}

