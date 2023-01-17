#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MEM_SIZE 25000

int memory[MEM_SIZE], metadata[MEM_SIZE];

int check_free(int size){
    int temp = size;
    for(int i = 0; i < MEM_SIZE; i++){
        if(metadata[i] == 0){

        }
    }
}

int* MyMalloc(int size){
    
}

int main(){
    for(int i = 0; i < MEM_SIZE; i++){
        metadata[i] = 0;
        memory[i] = 0;
    }



    return 0;
}