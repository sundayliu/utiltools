#ifndef TPERF_CONFIG_H_
#define TPERF_CONFIG_H_

#if defined(WIN32)
#	define __TPERF_PLATFORM_WINDOWS__
#endif

#if defined(ANDROID)||defined(__ANDROID__)
#	define __TPERF_PLATFORM_ANDROID__
#endif

#if defined(__APPLE__)
#	include<TargetConditionals.h>
#	if TARGET_OS_IPHONE
#		define __TPERF_PLATFORM_IOS__
#	else
#		define __TPERF_PLATFORM_OSX__
#	endif
#endif

#if defined(__TPERF_PLATFORM_ANDROID__) || defined(__TPERF_PLATFORM_IOS__)
#	define __TPERF_PLATFORM_LINUX__
#endif

#endif // end of define TPERL_CONFIG_H_