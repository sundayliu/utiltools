#ifndef UNIT_TEST_SDT_H_
#define UNIT_TEST_SDT_H_

#include "unittest_config.h"

#if defined(__UNITTEST_PLATFORM_WINDOWS__)
#include "../../sdt/tss_sdt.h"
#elif defined(__UNITTEST_PLATFORM_LINUX__)
#include "../sdt/tss_sdt.h"
#endif

using namespace TssSdk;


#if defined(__UNITTEST_PLATFORM_WINDOWS__)
#	ifdef DEBUG 
#		pragma comment(lib,"../bin/Debug/sdt.lib")
#	else
#		pragma comment(lib,"../bin/Release/sdt.lib")
#	endif
#endif


namespace unittest{

	void test_sdt(unsigned int count=10000);
	
	/************************************************************************/
	/* 不支持浮点类型                                                       */
	/************************************************************************/
	template <typename T1,typename T2>
	void test_sdt_v1(){
		T1 a = 0;
		T1 b = 0;
		T2 raw_a = 0;
		T2 raw_b = 0;
		a = b;

		// TODO
		// %=
		T2 r = __random();
		if ( r != 0)
		{		
			b = r;
			raw_b = r;
			a %= b;
			raw_a %= raw_b;
			UNITTEST_ASSERT(a == raw_a);
			UNITTEST_ASSERT(b == raw_b);
			a %= r;
			raw_a %= r;
			UNITTEST_ASSERT(a == raw_a);
			UNITTEST_ASSERT(b == raw_b);
		}
		// &=
		r = __random();
		b = r;
		raw_b = r;
		a &= b;
		raw_a &= raw_b;
		UNITTEST_ASSERT(a == raw_a);
		UNITTEST_ASSERT(b == raw_b);
		a &= r;
		raw_a &= r;
		UNITTEST_ASSERT(a == raw_a);
		UNITTEST_ASSERT(b == raw_b);

		// |=
		r = __random();
		b = r;
		raw_b = r;
		a |= b;
		raw_a |= raw_b;
		UNITTEST_ASSERT(a == raw_a);
		UNITTEST_ASSERT(b == raw_b);
		a |= r;
		raw_a |= r;
		UNITTEST_ASSERT(a == raw_a);
		UNITTEST_ASSERT(b == raw_b);
		// ^=
		r = __random();
		b = r;
		raw_b = r;
		a ^= b;
		raw_a ^= raw_b;
		UNITTEST_ASSERT(a == raw_a);
		UNITTEST_ASSERT(b == raw_b);
		a ^= r;
		raw_a ^= r;
		UNITTEST_ASSERT(a == raw_a);
		UNITTEST_ASSERT(b == raw_b);

		// <<=
		r = __random();
		b = r;
		raw_b = r;
		a <<= b;
		raw_a <<= raw_b;
		UNITTEST_ASSERT(a == raw_a);
		UNITTEST_ASSERT(b == raw_b);
		a <<= r;
		raw_a <<= r;
		UNITTEST_ASSERT(a == raw_a);
		UNITTEST_ASSERT(b == raw_b);
		// >>=
		r = __random();
		b = r;
		raw_b = r;
		a >>= b;
		raw_a >>= raw_b;
		UNITTEST_ASSERT(a == raw_a);
		UNITTEST_ASSERT(b == raw_b);
		a >>= r;
		raw_a >>= r;
		UNITTEST_ASSERT(a == raw_a);
		UNITTEST_ASSERT(b == raw_b);

		//%
		r = __random();
		if (r != 0) {
			b = r;
			raw_b = r;
			a = a % b;
			raw_a = raw_a % raw_b;
			UNITTEST_ASSERT(a == raw_a);
			UNITTEST_ASSERT(b == raw_b);
			a = (a % r);
			raw_a = raw_a % r;
			UNITTEST_ASSERT(a == raw_a);
			UNITTEST_ASSERT(b == raw_b);
		}

		// &
		b = r;
		raw_b = r;
		a = a & b;
		raw_a = raw_a & raw_b;
		UNITTEST_ASSERT(a == raw_a);
		UNITTEST_ASSERT(b == raw_b);
		a = (a & r);
		raw_a = raw_a & r;
		UNITTEST_ASSERT(a == raw_a);
		UNITTEST_ASSERT(b == raw_b);

		// |
		b = r;
		raw_b = r;
		a = a | b;
		raw_a = raw_a | raw_b;
		UNITTEST_ASSERT(a == raw_a);
		UNITTEST_ASSERT(b == raw_b);
		a = (a | r);
		raw_a = raw_a | r;
		UNITTEST_ASSERT(a == raw_a);
		UNITTEST_ASSERT(b == raw_b);
		// ^
		b = r;
		raw_b = r;
		a = a ^ b;
		raw_a = raw_a ^ raw_b;
		UNITTEST_ASSERT(a == raw_a);
		UNITTEST_ASSERT(b == raw_b);
		a = (a ^ r);
		raw_a = raw_a ^ r;
		UNITTEST_ASSERT(a == raw_a);
		UNITTEST_ASSERT(b == raw_b);
		// <<
		b = r;
		raw_b = r;
		a = a << b;
		raw_a = raw_a << raw_b;
		UNITTEST_ASSERT(a == raw_a);
		UNITTEST_ASSERT(b == raw_b);
		a = (a << r);
		raw_a = raw_a << r;
		UNITTEST_ASSERT(a == raw_a);
		UNITTEST_ASSERT(b == raw_b);
		// >>
		b = r;
		raw_b = r;
		a = a >> b;
		raw_a = raw_a >> raw_b;
		UNITTEST_ASSERT(a == raw_a);
		UNITTEST_ASSERT(b == raw_b);
		a = (a >> r);
		raw_a = raw_a >> r;
		UNITTEST_ASSERT(a == raw_a);
		UNITTEST_ASSERT(b == raw_b);
	}

	/************************************************************************/
	/* 支持浮点类型                                                         */
	/************************************************************************/
	template<typename T1, typename T2>
	void test_sdt_v0()
	{
		T1 a = 0;
		T1 b = 0;
		UNITTEST_ASSERT(a == b);
		T2 raw_a = 0;
		T2 raw_b = 0;
		
		//+=
		T1 r = __random();
		b = r;
		raw_b = r;
		a += b;
		raw_a += raw_b;
		UNITTEST_ASSERT(a == raw_a);
		UNITTEST_ASSERT(b == raw_b);
		a += r;
		raw_a += r;
		UNITTEST_ASSERT(a == raw_a);
		UNITTEST_ASSERT(b == raw_b);

		T2 r1 = __random_float();
		b = r1;
		raw_b = r1;
		a += b;
		raw_a += raw_b;
		UNITTEST_ASSERT(a == raw_a);
		UNITTEST_ASSERT(b == raw_b);
		a += r1;
		raw_a += r1;
		UNITTEST_ASSERT(a == raw_a);
		UNITTEST_ASSERT(b == raw_b);

		T2 r2 = __random_double();
		b = r2;
		raw_b = r2;
		a += b;
		raw_a += raw_b;
		UNITTEST_ASSERT(a == raw_a);
		UNITTEST_ASSERT(b == raw_b);
		a += r2;
		raw_a += r2;
		UNITTEST_ASSERT(a == raw_a);
		UNITTEST_ASSERT(b == raw_b);



		// -=
		r = __random();
		b = r;
		raw_b = r;
		a -= b;
		raw_a -= raw_b;
		UNITTEST_ASSERT(a == raw_a);
		UNITTEST_ASSERT(b == raw_b);
		a -= r;
		raw_a -= r;
		UNITTEST_ASSERT(a == raw_a);
		UNITTEST_ASSERT(b == raw_b);

		r1 = __random_float();
		b = r1;
		raw_b = r1;
		a -= b;
		raw_a -= raw_b;
		UNITTEST_ASSERT(a == raw_a);
		UNITTEST_ASSERT(b == raw_b);
		a -= r1;
		raw_a -= r1;
		UNITTEST_ASSERT(a == raw_a);
		UNITTEST_ASSERT(b == raw_b);

		r2 = __random_double();
		b = r2;
		raw_b = r2;
		a -= b;
		raw_a -= raw_b;
		UNITTEST_ASSERT(a == raw_a);
		UNITTEST_ASSERT(b == raw_b);
		a -= r2;
		raw_a -= r2;
		UNITTEST_ASSERT(a == raw_a);
		UNITTEST_ASSERT(b == raw_b);

		// *=
		r = __random();
		b = r;
		raw_b = r;
		a *= b;
		raw_a *= raw_b;
		UNITTEST_ASSERT(a == raw_a);
		UNITTEST_ASSERT(b == raw_b);
		a *= r;
		raw_a *= r;
		UNITTEST_ASSERT(a == raw_a);
		UNITTEST_ASSERT(b == raw_b);

		r1 = __random_float();
		b = r1;
		raw_b = r1;
		a *= b;
		raw_a *= raw_b;
		UNITTEST_ASSERT(a == raw_a);
		UNITTEST_ASSERT(b == raw_b);
		a *= r1;
		raw_a *= r1;
		UNITTEST_ASSERT(a == raw_a);//
		UNITTEST_ASSERT(b == raw_b);

		r2 = __random_double();
		b = r2;
		raw_b = r2;
		a *= b;
		raw_a *= raw_b;
		UNITTEST_ASSERT(a == raw_a);//
		UNITTEST_ASSERT(b == raw_b);
		a *= r2;
		raw_a *= r2;
		UNITTEST_ASSERT(a == raw_a);//
		UNITTEST_ASSERT(b == raw_b);

		// /=
		r = __random();
		if (r != 0)
		{
			b = r;
			raw_b = r;
			a /= b;
			raw_a /= raw_b;
			UNITTEST_ASSERT(a == raw_a);//
			UNITTEST_ASSERT(b == raw_b);
			a /= r;
			raw_a /= r;
			UNITTEST_ASSERT(a == raw_a);
			UNITTEST_ASSERT(b == raw_b);
		}

		r1 = __random_float()+1;
		if (r1 != 0)
		{
			b = r1;
			raw_b = r1;
			a /= b;
			raw_a /= raw_b;
			UNITTEST_ASSERT(a == raw_a);
			UNITTEST_ASSERT(b == raw_b);
			a /= r1;
			raw_a /= r1;
			UNITTEST_ASSERT(a == raw_a);
			UNITTEST_ASSERT(b == raw_b);
		}


		r2 = __random_double()+1;
		if (r2 != 0)
		{
			b = r2;
			raw_b = r2;
			a /= b;
			raw_a /= raw_b;
			UNITTEST_ASSERT(a == raw_a);
			UNITTEST_ASSERT(b == raw_b);
			a /= r2;
			raw_a /= r2;
			UNITTEST_ASSERT(a == raw_a);
			UNITTEST_ASSERT(b == raw_b);
		}

		// TODO
		// %=
		// &=
		// |=
		// ^=
		// ~

		// /
		// -
		r = __random();
		if (r != 0) {
			b = r;
			raw_b = r;
			a = a / b;
			raw_a = raw_a / raw_b;
			UNITTEST_ASSERT(a == raw_a);
			UNITTEST_ASSERT(b == raw_b);
			a = (a / r);
			raw_a = raw_a / r;
			UNITTEST_ASSERT(a == raw_a);
			UNITTEST_ASSERT(b == raw_b);
		}
		//++
		a++;
		raw_a++;
		b++;
		raw_b++;
		UNITTEST_ASSERT(a == raw_a);
		UNITTEST_ASSERT(b == raw_b);

		// --
		a--;
		raw_a--;
		b--;
		raw_b--;
		UNITTEST_ASSERT(a == raw_a);
		UNITTEST_ASSERT(b == raw_b);

		//NOTIFY_UI("sdt_type done.");
	}
}

#endif
