#ifndef TPERL_UTIL_H_
#define TPERL_UTIL_H_

#include "tperf_config.h"
#ifdef __TPERF_PLATFORM_LINUX__
#include <unistd.h>
#endif

namespace tperf{
    // type define
#ifdef __TPERF_PLATFORM_LINUX__
    typedef long long s64;
    typedef unsigned long long u64;
#elif defined(__TPERF_PLATFORM_WINDOWS__)
    typedef __int64 s64;
    typedef unsigned __int64 u64;
#endif

	// Get current system time
	// unit is ms
	unsigned long get_current_time();

	// assert tools
	void __test_assert__(int express, const char* filename,int line);

#	define TPERF_ASSERT (express) __test_assert__((express),__FILE__,__LINE__)

	// get random
	int random();

	float random_f();
	double random_d();

	int sleep(unsigned int microseconds);


} // end of namespace tperl

#endif
