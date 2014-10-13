#ifndef TPERF_SYSTEM_INFO_H_
#define TPERF_SYSTEM_INFO_H_

#include "tperf_util.h"

namespace tperf{
	class SystemInfo{
	public:
		struct cpu_info_t{
			unsigned int usage;
		};

		struct mem_info_t{
			unsigned int mem;  // 物理内存包括共享内存
			unsigned int vmem; // 虚拟内存
		};

		struct io_info_t{
			u64 read_bytes;
			u64 write_bytes;
		};
	public:
		static int get_cpu_usage(cpu_info_t& info);
		static int get_mem_usage(mem_info_t& info);
		static int get_io_usage(io_info_t& info);

		static int get_processor_number();

		static unsigned int get_page_size();

	};// end of class SystemInfo
} // end of namespace tperl

#endif  // end of define TPERL_SYSTEM_INFO_H_
