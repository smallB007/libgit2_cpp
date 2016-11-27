#include "Git_Transfer_Progress.hpp"



Git_Transfer_Progress::Git_Transfer_Progress()
{
}


inline unsigned int Git_Transfer_Progress::total_objects()const
{
	return c_guts_.total_objects;
}

unsigned int 	Git_Transfer_Progress::indexed_objects()const
{
	return c_guts_.indexed_objects;
}
unsigned int 	Git_Transfer_Progress::received_objects()const
{
	return c_guts_.received_objects;
}
unsigned int 	Git_Transfer_Progress::local_objects()const
{
	return c_guts_.local_objects;
}
unsigned int 	Git_Transfer_Progress::total_deltas()const
{
	return c_guts_.total_deltas;
}
unsigned int 	Git_Transfer_Progress::indexed_deltas()const
{
	return c_guts_.indexed_deltas;
}
size_t 	Git_Transfer_Progress::received_bytes()const
{
	return c_guts_.received_bytes;
}