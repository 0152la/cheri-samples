#include <assert.h>
#include <cheriintrin.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#if !defined(__CHERI_PURE_CAPABILITY__) || __CHERI_CAPABILITY_WIDTH__ != 128
#  error This example must be run on a CHERI purecap system with 128 bit capabilities
#endif

int
main()
{
	uint8_t* ptr = malloc(4096);
	uint8_t* ptr_offset = ptr + 1024;
	*(ptr_offset) = 42;
	assert(*(ptr + 1024) == 42);
}
