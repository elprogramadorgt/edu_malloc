#include <assert.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>

void *eduMalloc(size_t size);

int main(){

    void *initial_break = sbrk(0);

    printf("Initial break: %p\n", initial_break);

    void *ptr = eduMalloc(40);

    void *final_break = sbrk(0);

    printf("Final break: %p\n", final_break);

    printf("Final Memory %td\n", (short *)final_break - (short *)initial_break); 

}


void *eduMalloc(size_t size){

    void *ptr = sbrk(40);

    if(ptr == (void *)-1){
        return NULL;
    }

    return ptr;



}