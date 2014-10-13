#include "tperf_config.h"
#include "tperf_system_info.h"

#ifdef __TPERF_PLATFORM_WINDOWS__
#include <windows.h>
#include <psapi.h>
#pragma comment(lib,"psapi")
#endif

#ifdef __TPERF_PLATFORM_LINUX__
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#endif

namespace tperf{
	int SystemInfo::get_cpu_usage(cpu_info_t& info){
		//FILETIME creation_t;
		//FILETIME kernel_t;
		//FILETIME user_t;
		//FILETIME exit_t;


		return -1;
	}

	int SystemInfo::get_mem_usage(mem_info_t& info){
#	ifdef __TPERF_PLATFORM_WINDOWS__
		PROCESS_MEMORY_COUNTERS mem;
		if (GetProcessMemoryInfo(GetCurrentProcess(),&mem, sizeof(mem))){
			info.mem = mem.WorkingSetSize;
			info.vmem = mem.PagefileUsage;
			return 0;
		}
		return -1;
#   elif defined(__TPERF_PLATFORM_ANDROID__)
		//char* statm_path = "/proc/self/statm";
		FILE* fp = fopen("/proc/self/statm","rb");
		if (fp != NULL){
		    char line[128] = {0};
		    fgets(line,sizeof(line),fp);
		    unsigned int len = strlen(line);
		    if (len > 0 && line[len-1]=='\n'){
		        line[--len] = '\0';
		    }

		    unsigned int vss = 0;
		    unsigned int pss = 0;
		    unsigned int shared = 0;
		    if (sscanf(line,"%u %u %u",&vss,&pss,&shared)==3)
		    {
		        unsigned int pagesize = get_page_size();
		        info.mem = pss * pagesize;
		        info.vmem = vss * pagesize;
		    }
		    fclose(fp);
		    return 0;
		}
		return -1;
#	else
		return -1;
#endif
	}

	int SystemInfo::get_io_usage(io_info_t& info){
#	ifdef __TPERF_PLATFORM_WINDOWS__
		IO_COUNTERS io;
		if (GetProcessIoCounters(GetCurrentProcess(),&io)){
			info.read_bytes = io.ReadOperationCount;
			info.write_bytes = io.WriteTransferCount;
		}
		return -1;
#	else
		return -1;
#endif 
	}

	int SystemInfo::get_processor_number(){
#	ifdef __TPERF_PLATFORM_WINDOWS__
		SYSTEM_INFO info;
		GetSystemInfo(&info);
		return info.dwNumberOfProcessors;
#	else
		return 1;
#	endif
	}

	unsigned int SystemInfo::get_page_size(){
#ifdef __TPERF_PLATFORM_ANDROID__
	    return sysconf(_SC_PAGE_SIZE);
#endif
	    return 4*1024;
	}

} // end of namespace tperf

