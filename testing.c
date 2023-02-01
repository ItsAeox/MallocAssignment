#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include "header.h"

void* MyMalloc(size_t size){
    mem_block *curr, *prev;
    void *output = NULL;

    if(!(free_mem->size)){
        free_mem->size = 25000 - sizeof(mem_block);
        free_mem->free = 1;
        free_mem->next = NULL;  
        printf("\nMemory Initialization Successful.");
    }

    curr = free_mem;

    while(curr){
        printf("\tChecked\t");
        if(curr->size >= size && curr->free == 1){
            break;
        }
        curr = curr->next;
    }

    if((curr->size < size || curr->free == 0) && (curr->next == NULL)){
        printf("\nMemory Alloaction Unsuccessful. Not enough Memory in the heap.");
        output = NULL;
        return output;
    }
    else if(curr->size == size){
        curr->free = 0;
        curr->size = size;
        output = (void*)(curr + sizeof(mem_block));
        printf("\nMemory Allocation Successful. Memory is full.");
        printf("\nReturned Pointer with the address of : %x", output);
        return output;
    }
    else{
        mem_block *free_block = (void*)((void*)curr + size + sizeof(mem_block));
        free_block->size = curr->size - (size + sizeof(mem_block));
        free_block->free = 1;
        free_block->next = curr->next;
        curr->size = size;
        curr->free = 0;
        curr->next = free_block;
        output = (void*)(curr + sizeof(mem_block));
        printf("\nMemory Allocation Successful.");
        printf("\nReturned Pointer with the address of : %x", output);
        return output;
    }
}

int main(){
    MyMalloc(20000);
    MyMalloc(3000);
    MyMalloc(400);
    MyMalloc(2000);

    return 0;
}