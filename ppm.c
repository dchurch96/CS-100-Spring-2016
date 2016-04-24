#include "ppm.h"
#include "scanner.h"

ppmPic *read(char *name){
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
    
    ptr->pixels = pix;
    
    fclose(fp);
    return ptr;
}

void write(char *name, char *name2, ppmPic *head){
    FILE *fp = fopen(name2, "w");
    
    ppmPic *ptr = head;
    
    fprintf(fp, "P3\n%d %d %d\n", ptr->cols, ptr->rows, ptr->colors);
    Pixel **pix;
    pix = ptr->pixels;
    printf("hello\n");
    printf("%d\n", pix[1][1].blue);
    printf("hello\n");
    int i, j;
    for (i = 0; i<ptr->rows; i++){
        for (j=0; j<ptr->cols; j++){
            fprintf(fp, "%d\n%d\n%d\n", pix[i][j].red, pix[i][j].blue, pix[i][j].green);
            printf("%d %d %d    ", pix[i][j].red, pix[i][j].blue, pix[i][j].green);
        }
        printf("\n");
    }
    
    return;
}

void copy(char *name, ppmPic *head){
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