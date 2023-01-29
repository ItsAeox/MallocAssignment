#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MEM_SIZE 25000

char memory[MEM_SIZE];

typedef struct mem_block{
    size_t size;
    int free;
    struct mem_block *next;
}mem_block;

mem_block *free_mem = (void*)memory;

mem_block *start = (mem_block*)memory;

void* MyMalloc(size_t size){

    mem_block *temp;
    void *output;

    if(!(free_mem->size)){
        free_mem->size = 25000;
        free_mem->free = 1;
        free_mem->next = NULL;  
        printf("\nMemory Initialization Succesful!");
    }

    temp = free_mem;

    if(temp->size < (size + sizeof(mem_block))){
        printf("\nError! Memory Allocation Unsuccesful. Not Enough Memory Available.");
        output = NULL;
        return output;
    }
    else if(temp->size == (size + sizeof(mem_block))){
        temp->free = 0;
        output = (void*)(temp + sizeof(mem_block));
        printf("\nMemory Allocation Succesful! No Memory Left In The Heap.");
        return output;
    }
    else{
        mem_block *temp_2 = (void*)(temp+size+sizeof(mem_block));
        temp->free = 0;
        temp->size = size + sizeof(mem_block);
        temp->next = temp_2;
        output = (void*)(temp +sizeof(mem_block));
        printf("\nMemory Allocation Succesful!");
        return output;
    }
}