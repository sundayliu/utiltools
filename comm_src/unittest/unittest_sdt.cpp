#include "unittest_config.h"
#include "unittest_sdt.h"

#include <stdio.h>



namespace unittest{


	void test_sdt(unsigned int count){

		unsigned int a = 1;
		double x = (double)a/2;
		DEBUG_LOG("%f\n",x);
		DEBUG_LOG("page size:%08x\n",tperf::SystemInfo::get_page_size());
		//unsigned int count = 10000;
		//unsigned int count = 100000;
		//unsigned int count = 1000000;
		unsigned int i;
		unsigned long start_t = tperf::get_current_time();
		double mem = 0;
		double vmem = 0;
		unsigned int mem_start = 0;
		unsigned int vmem_start = 0;

        tperf::SystemInfo::mem_info_t mem_info;
        if (tperf::SystemInfo::get_mem_usage(mem_info) == 0){
            mem_start = mem_info.mem;
            vmem_start = mem_info.vmem;
        }

		for (i = 0; i < count; i++){
			test_sdt_v0<TssSdk::sdt_char, char>();
			test_sdt_v0<TssSdk::sdt_uchar, unsigned char>();
			test_sdt_v0<TssSdk::sdt_short, short>();
			test_sdt_v0<TssSdk::sdt_ushort, unsigned short>();
			test_sdt_v0<TssSdk::sdt_int, int>();
			test_sdt_v0<TssSdk::sdt_uint, unsigned int>();
			test_sdt_v0<TssSdk::sdt_long, long>();
			test_sdt_v0<TssSdk::sdt_ulong, unsigned long>();
			test_sdt_v0<TssSdk::sdt_float, float>();
			test_sdt_v0<TssSdk::sdt_double, double>();

			test_sdt_v1<TssSdk::sdt_char, char>();
			test_sdt_v1<TssSdk::sdt_uchar, unsigned char>();
			test_sdt_v1<TssSdk::sdt_short, short>();
			test_sdt_v1<TssSdk::sdt_ushort, unsigned short>();
			test_sdt_v1<TssSdk::sdt_int, int>();
			test_sdt_v1<TssSdk::sdt_uint, unsigned int>();
			test_sdt_v1<TssSdk::sdt_long, long>();
			test_sdt_v1<TssSdk::sdt_ulong, unsigned long>();

//			tperf::SystemInfo::mem_info_t mem_info;
//			if (tperf::SystemInfo::get_mem_usage(mem_info) == 0){
//				mem += ((double)mem_info.mem)/count;
//				vmem += ((double)mem_info.vmem) / count;
//
//			}
		}



		unsigned long end_t = tperf::get_current_time();
		unsigned int mem_end = 0;
		unsigned int vmem_end = 0;
        if (tperf::SystemInfo::get_mem_usage(mem_info) == 0){
            mem_end = mem_info.mem;
            vmem_end = mem_info.vmem;
        }

        DEBUG_LOG("mem:%u,%u\n",mem_start,mem_end);
        DEBUG_LOG("vmem:%u,%u\n",vmem_start,vmem_end);

		DEBUG_LOG("time:%lu\n",end_t-start_t);
		DEBUG_LOG("mem:%f,vmem:%f\n",mem,vmem);
	}
}
