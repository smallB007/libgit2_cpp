#pragma once
#ifndef EASTL
#include <vector>
#include <set>
#include <string>
#include <memory>
#include <utility>
#include <array>
#include <algorithm>
#include <iterator>
#define NMS std
#else
#include <EASTL\vector.h>
#include <EASTL\set.h>
#include <EASTL\string.h>
#include <EASTL\memory.h>
#include <EASTL\shared_ptr.h>
#include <EASTL\utility.h>
#include <EASTL\array.h>
#include <EASTL\algorithm.h>
#include <EASTL\iterator.h>
#define NMS eastl
#endif
