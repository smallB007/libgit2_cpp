#pragma once
#include "precompiled.hpp"
class Git_Indexer : Provider<git_indexer>
{
public:
	Git_Indexer(const path_name_t& path, unsigned int mode, Git_ODB& odb, git_transfer_progress_cb progress_cb, void *progress_cb_payload);

	~Git_Indexer() = default;
	LIBGIT2_INDEXER_INTERFACE
		void Git_Indexer::commit(Git_Transfer_Progress& stats) const;
		Git_Object_ID hash()const;
#ifdef _FULL_IMPLEMENTATION_
	void append(const Git_Indexer&,findisih shat artie)const;
#endif
};

