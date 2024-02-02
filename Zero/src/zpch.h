#pragma once

#include "Zero/Core/PlatformDetection.h"

#ifdef ZERO_PLATFORM_WINDOWS
	#ifndef NOMINMAX
		// See github.com/skypjack/entt/wiki/Frequently-Asked-Questions#warning-c4003-the-min-the-max-and-the-macro
		#define NOMINMAX
	#endif
#endif

#include <iostream>
#include <memory>
#include <utility>
#include <algorithm>
#include <functional>

#include <string>
#include <sstream>
#include <array>
#include <vector>
#include <unordered_map>
#include <unordered_set>

#include "Zero/Core/Base.h"

#include "Zero/Core/Log.h"

#include "Zero/Debug/Instrumentor.h"

#ifdef ZERO_PLATFORM_WINDOWS
	#include <Windows.h>
#endif