#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include "MyMalloc.h"

void* MyMalloc(size_t size){
    mem_block *curr;
    void *output = NULL;

    if(!(free_mem->size)){
        free_mem->size = 25000 - sizeof(mem_block);
        free_mem->free = 1;
        free_mem->next = NULL;  
        printf("\n*** Memory Initialization Successful. Capacity : %d\n", MEM_SIZE-sizeof(mem_block));
    }

    curr = free_mem;

    while(1){
        if(curr->size >= size && curr->free == 1){
            break;
        }
        if(curr->next == NULL){
            break;
        } 
        curr = curr->next;
    }

    if(curr->size < size || curr->free == 0){
        printf("\nMemory Alloaction Unsuccessful. Requested %d Bytes. %d Bytes remaining out of %d Bytes\n", size, free_cap,  MEM_SIZE-sizeof(mem_block));
        output = NULL;
        return output;
    }
    else if(curr->size == size){
        curr->free = 0;
        curr->size = size;
        output = (void*)(curr + sizeof(mem_block));
        printf("\n%d Bytes Allocated. Memory is at Capacity", size);
        printf("\nReturned Pointer with the address of : %x\n", output);
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
        free_cap -= size + sizeof(mem_block);
        output = (void*)(curr + sizeof(mem_block));
        printf("\n%d Bytes Allocated. %d Bytes remaining out of %d Bytes.", size, free_cap, MEM_SIZE-sizeof(mem_block));
        printf("\nReturned Pointer with the address of : %x\n", output);
        return output;
    }
}

void MyFree(void* used_block){
    if(((void*)memory <= used_block) && (used_block <= (void*)(memory + 25000))){
        mem_block* curr = used_block;
        curr -= sizeof(mem_block);
        curr->free = 1;
        free_cap += curr->size + sizeof(mem_block);
        printf("\n%d Bytes Freed. %d Bytes remaining out of %d Bytes.\n", curr->size, free_cap, MEM_SIZE-sizeof(mem_block));
        curr = free_mem;
        while((curr ->next) != NULL){
            if((curr->free == 1) && (curr->next->free == 1)){
                curr->size = curr->size + curr->next->size + sizeof(mem_block);
                curr->next = curr->next->next;
            }
            curr = curr->next;
        }
    }
    else {
        printf("The given pointer is not in the valid range of Memory.");
    }
}