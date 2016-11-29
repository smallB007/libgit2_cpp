#include "Git_Index_Entry.hpp"



Git_Index_Entry::Git_Index_Entry(git_index_entry c_git_index_entry)
{
	c_guts_ = c_git_index_entry;
}


git_index_time 	Git_Index_Entry::ctime()const
{
	return c_guts_.ctime;
}
git_index_time 	Git_Index_Entry::mtime()const
{
	return c_guts_.mtime;
}
uint32_t 	Git_Index_Entry::dev()const
{
	return c_guts_.dev;
}
uint32_t 	Git_Index_Entry::ino()const
{
	return c_guts_.ino;
}

uint32_t 	Git_Index_Entry::mode()const
{
	return c_guts_.mode;
}
uint32_t 	Git_Index_Entry::uid()const
{
	return c_guts_.uid;
}
uint32_t 	Git_Index_Entry::gid()const
{
	return c_guts_.gid;
}
uint32_t 	Git_Index_Entry::file_size()const
{
	return c_guts_.file_size;
}
git_oid 	Git_Index_Entry::id()const
{
	return c_guts_.id;
}

uint16_t 	Git_Index_Entry::flags()const
{
	return c_guts_.flags;
}
uint16_t 	Git_Index_Entry::flags_extended()const
{
	return c_guts_.flags_extended;
}
string_t 	Git_Index_Entry::path()const
{
	return c_guts_.path;
}