#include "tperf_config.h"
#include "tperf_util.h"

#if defined(__TPERF_PLATFORM_ANDROID__) || defined(__TPERF_PLATFORM_LINUX__) || defined(__TPERF_PLATFORM_IOS__)
#include <sys/time.h>
#include <unistd.h>
#elif defined(__TPERF_PLATFORM_WINDOWS__)
#include <windows.h>
#endif

#include <time.h>
#include <stdio.h>
#include <stdlib.h>

namespace tperf{

	// Get current system time
	// unit is ms
	unsigned long get_current_time(){
#if defined(__TPERF_PLATFORM_ANDROID__) || defined(__TPERF_PLATFORM_LINUX__) || defined(__TPERF_PLATFORM_IOS__)
		struct timeval tv;
		if (gettimeofday(&tv,NULL) != 0){
			return 0;
		}
		return (tv.tv_sec * 1000) + (tv.tv_usec / 1000);
#elif defined(__TPERF_PLATFORM_WINDOWS__)
		return GetTickCount();
#else
#error "Undefined platform!";
#endif
	}

	// assert tools
	void __test_assert__(int express, const char* filename,int line){
		if (!express){
			printf("!!!ASSERT ERROR:%s:%d\n",filename,line);
		}
	}

	// get random
	int random()
	{
		static char flag = 0;
		if (flag == 0){
			srand((unsigned int)time(NULL));
			flag = 1;
		}
		
		unsigned int key = rand();
		return ++key;
	}

	float random_f()
	{
		float result = 123.0123f;
		int a = random();
		return a / result;
	}

	double random_d()
	{
		double result = 123.0123;
		int a = random();
		return a / result;
	}

	int sleep(unsigned int microseconds){
#ifdef __TPERF_PLATFORM_WINDOWS__
		Sleep(microseconds);
#elif defined(__TPERF_PLATFORM_LINUX__)
		usleep(microseconds);
#endif
		return 0;
	}

} // end of namespace TPERF
