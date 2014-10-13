#include "unittest_config.h"
#include "unittest.h"
#include "unittest_sdt.h"
#include <string.h>
#include <stdlib.h>

namespace unittest{
	void run_test(unsigned int count){
		test_sdt(count);
	}
}

int main(int argc,char* argv[]){
    unsigned int count = atoi(argv[1]);
    unittest::run_test(count);
    return 0;
}
