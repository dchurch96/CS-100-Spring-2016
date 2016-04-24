#include <stdio.h>
#include "scanner.h"
#include <stdlib.h>
#include "ppm.h"

int main (int argc, char **argv){
    ppmPic *head = NULL;

    if(strcmp(argv[1], "read")==0){
        head = read(argv[2]);
        printf("col = %d", head->cols);
    }
    
    if(strcmp(argv[1], "write")==0){
        head = read(argv[2]);

        write(argv[2], argv[3], head);
    }
    
    if(strcmp(argv[1], "copy")==0){
        copy(argv[2], head);
    }
    
    if(strcmp(argv[1], "grow")==0){
        grow();
    }
    
    if(strcmp(argv[1], "shrink")==0){
        shrink();
    }
    
    return 0;
}