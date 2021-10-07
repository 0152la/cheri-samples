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
	uint8_t* c1 = malloc(4096);
	uint8_t* c2 = cheri_bounds_set(c1, 1024); 
	uint8_t* c2_offset = c2 + 256;
	*c2_offset = 42;
	assert(*(c2 + 256) == 42);
}
