#include <stdio.h>
#include <stdlib.h>
#include "lib/lib.h"


  ssize_t fuzz_len;
  #define __AFL_FUZZ_TESTCASE_LEN fuzz_len
  unsigned char fuzz_buf[1024000];
  #define __AFL_FUZZ_TESTCASE_BUF fuzz_buf
  #define __AFL_FUZZ_INIT() void sync(void);
  #define __AFL_LOOP(x) ((fuzz_len = read(0, fuzz_buf, sizeof(fuzz_buf))) > 0 ? 1 : 0)
  #define __AFL_INIT() sync()


__AFL_FUZZ_INI();

int main()
{
	  __AFL_INIT();


	unsigned char *buf = __AFL_FUZZ_TESTCASE_BUF;

	while (__AFL_LOOP(10000)) 
	{
		int len = __AFL_FUZZ_TESTCASE_LEN;
         	int return_code = array_fill(buf, len);
		    return_code = array_print(buf, len);	
		int secret = rand();
//		array_push(buf, len, secret);

	}
	return 0;
}




