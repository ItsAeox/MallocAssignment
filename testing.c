#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MEM_SIZE 1000

int memory[MEM_SIZE], metadata[MEM_SIZE];

/*struct metadata{
    int from;
    int to;
    struct metadata* next;
};*/

int* MyMalloc(){

}

int main(){

    for(int i = 0; i < MEM_SIZE; i++){
        metadata[i] = 0;
        memory[i] = 0;
    }



    return 0;
}