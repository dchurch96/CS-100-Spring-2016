#include <stdio.h>
#include "scanner.h"
#include <stdlib.h>
#include "ppm.h"

int main (int argc, char **argv){
    ppmPic *head = NULL;

    if(strcmp(argv[1], "copy")==0){
        copy(argv[2], argv[3]);
    }
    
    if(strcmp(argv[1], "grow")==0){
        head = read(argv[2]);
        grow(argv[2], argv[3], head);
    }
    
    if(strcmp(argv[1], "shrink")==0){
        head = read(argv[2]);
        shrink(argv[2], argv[3], head);
    }
    
    return 0;
}