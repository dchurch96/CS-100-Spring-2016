#include "ppm.h"
#include "scanner.h"

void read(char *name, ppmPic *head){
    ppmPic *ptr = malloc(sizeof(ppmPic));
    FILE *fp = fopen(name, "r");
    
    readToken(fp);
    ptr->cols = readInt(fp);
    ptr->rows = readInt(fp);
    ptr->colors = readInt(fp);
    int i, j;
    
    int a;
	Pixel **pix;
	pix = malloc(sizeof(Pixel *) * ptr->rows);
	for (a=0; a<ptr->rows; a++)
        pix[a] = malloc(sizeof(Pixel) * ptr->cols);
   
    
    for (i = 0; i<ptr->rows; i++){
        for (j=0; j<ptr->cols; j++){
        pix[i][j].red = readInt(fp);
        pix[i][j].blue = readInt(fp);
        pix[i][j].green = readInt(fp);
        printf("%d %d %d    ", pix[i][j].red, pix[i][j].blue, pix[i][j].green);
        }
        printf("\n");
    }
    
    fclose(fp);
    return;
}

void write(){
    printf("write");
    return;
}

void copy(){
    printf("copy");
    return;
}

void grow(){
    printf("grow");
    return;
}

void shrink(){
    printf("shrink");
    return;
}