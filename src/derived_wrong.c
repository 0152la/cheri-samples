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
	size_t max_size = 4096;
        size_t derived_size = 1024;
	size_t offset = 256;
	uint8_t* c1 = malloc(max_size);
	uint8_t* c2 = cheri_bounds_set(c1, derived_size); 
	assert(derived_size + offset < max_size);
	printf("c2[offset] = %d\n", *(c2 + derived_size + offset));
	assert(0 && "Expected failure state not triggered.");
}
