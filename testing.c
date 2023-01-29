#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MEM_SIZE 25000

int memory[MEM_SIZE];

typedef struct mem_block{
    size_t size;
    int free;
    mem_block *next;
}mem_block;

mem_block free_mem;

mem_block *start = (mem_block*)memory;

void ini_mem(){
    free_mem.size = 25000 - sizeof(mem_block);
    free_mem.free = 1;
    free_mem.next = NULL;  
}

void* MyMalloc(size_t size){
    if(!(free_mem.size)){
        ini_mem();
        printf("Memory Initialization Succesful!");
    }
}