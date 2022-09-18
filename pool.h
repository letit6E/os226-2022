#pragma once

#include "util.h"

struct pool {
	size_t blocks_per_pool;
	size_t block_size;
	struct block {
		struct block *next;
	} *mem;
};

#define POOL_INITIALIZER(_mem, _nmemb, _membsz) { \
    _nmemb,                                       \
    _membsz,                                      \
    (struct block *) (_mem)                	      \
}

#define POOL_INITIALIZER_ARRAY(_array) \
    POOL_INITIALIZER(_array, ARRAY_SIZE(_array), sizeof((_array)[0]));

void pool_init(struct pool *p, void *mem, unsigned long nmemb, unsigned long membsz);

void *pool_alloc(struct pool *p);

void pool_free(struct pool *p, void *ptr);
