#include <stdio.h>
#include "mymalloc.h"

int main() {
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