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
	size_t size = 4096;
	size_t offset = 1024;
	assert(0 <= offset < size - sizeof(size_t));
	uint8_t* ptr = malloc(size);
	printf("ptr[offset] == %d\n", *(ptr + size + offset));
	assert(0 && "Expected failure state not triggered.");
}
