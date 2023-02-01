#include <stdio.h>
#include <stddef.h>

#define MEM_SIZE 25000

char memory[MEM_SIZE];

typedef struct mem_block{
    size_t size;
    int free;
    struct mem_block *next;
}mem_block;

mem_block *free_mem = (void*)memory;

void* MyMalloc(size_t size);

