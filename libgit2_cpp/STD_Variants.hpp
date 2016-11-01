#pragma once
#ifndef USE_EASTL
#include <vector>
#include <set>
#include <string>
#include <memory>
#include <utility>
#include <array>
#include <algorithm>
#include <iterator>
#include <functional>
#define NMS std
#elif defined USE_EASTL
#include <EASTL\vector.h>
#include <EASTL\set.h>
#include <EASTL\string.h>
#include <EASTL\memory.h>
#include <EASTL\shared_ptr.h>
#include <EASTL\unique_ptr.h>
#include <EASTL\utility.h>
#include <EASTL\array.h>
#include <EASTL\algorithm.h>
#include <EASTL\iterator.h>
#include <EASTL\functional>
#define NMS eastl
#endif

#define make_shared_ver NMS::make_shared