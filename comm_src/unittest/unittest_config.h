#ifndef UNIT_TEST_CONFIG_H_
#define UNIT_TEST_CONFIG_H_

#if defined(WIN32)
#	define __UNITTEST_PLATFORM_WINDOWS__
#endif

#if defined(ANDROID)||defined(__ANDROID__)
#	define __UNITTEST_PLATFORM_ANDROID__
#endif

#if defined(__APPLE__)
#	include<TargetConditionals.h>
#	if TARGET_OS_IPHONE
#		define __UNITTEST_PLATFORM_IOS__
#	else
#		define __UNITTEST_PLATFORM_OSX__
#	endif
#endif

#if defined(__UNITTEST_PLATFORM_ANDROID__) || defined(__UNITTEST_PLATFORM_IOS__)
#	define __UNITTEST_PLATFORM_LINUX__
#endif

#include "../tperf/tperf_util.h"
#include "../tperf/tperf_system_info.h"

#if defined(__UNITTEST_PLATFORM_LINUX__)
//#include "../SdkInterfaceChecker.h"
#endif

namespace unittest{
#define UNITTEST_ASSERT(express) tperf::__test_assert__((express),__FILE__,__LINE__)

#define NOTIFY_UI printf

#	define __random tperf::random
#	define __random_float	tperf::random_f
#	define __random_double	tperf::random_d

#if defined(__UNITTEST_PLATFORM_LINUX__)
#   define DEBUG_LOG(...) printf(__VA_ARGS__)
#else
#   define DEBUG_LOG(...) printf(__VA_ARGS__)
#endif

}
#endif
