#include <stddef.h>
#include <stdio.h>
#include "mymalloc.h"

#define MEM_SIZE 25000

char memory[MEM_SIZE];

struct mem_block{
    size_t size;
    int free;
    struct mem_block *next;
};

struct mem_block *first_mem_block = (struct mem_block *)memory;

void *MyMalloc(size_t size){
    struct mem_block *current = first_mem_block;
    while(current && !(current->free && current->size >= size)){
        current = current->next;
    }

    if (!current){
        return NULL;
    }

    if (current->size > size + sizeof(struct mem_block)){
        struct mem_block *new_mem_block = (struct mem_block *)((char *)current + sizeof(struct mem_block) + size);
        new_mem_block->size = current->size - sizeof(struct mem_block) - size;
        new_mem_block->free = 1;
        new_mem_block->next = current->next;
        current->size = size;
        current->next = new_mem_block;
    }

    current->free = 0;
    return (char *)current + sizeof(struct mem_block);
}

void MyFree(void *ptr){
    if (!ptr){
        return;
    }

    struct mem_block *current = first_mem_block;
    while(current && (char *)current + sizeof(struct mem_block) != ptr){
        current = current->next;
    }

    if (!current){
        return;
    }

    current->free = 1;

    if (current->next && current->next->free){
        current->size += sizeof(struct mem_block) + current->next->size;
        current->next = current->next->next;
    }
}

int main(){
    printf("Allocating memory block of size 10...\n");
    void *ptr1 = MyMalloc(10);
    printf("Allocated memory block at %p\n", ptr1);

    printf("Allocating memory block of size 20...\n");
    void *ptr2 = MyMalloc(20);
    printf("Allocated memory block at %p\n", ptr2);

    printf("Freeing memory block at %p...\n", ptr1);
    MyFree(ptr1);

    printf("Allocating memory block of size 15...\n");
    void *ptr3 = MyMalloc(15);
    printf("Allocated memory block at %p\n", ptr3);

    printf("Freeing memory block at %p...\n", ptr2);
    MyFree(ptr2);

    printf("Freeing memory block at %p...\n", ptr3);
    MyFree(ptr3);

    return 0;
}



