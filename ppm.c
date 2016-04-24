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
        }
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
    
    int i, j;
    for (i = 0; i<ptr->rows; i++){
        for (j=0; j<ptr->cols; j++){
            fprintf(fp, "%d\n%d\n%d\n", pix[i][j].red, pix[i][j].blue, pix[i][j].green);
        }
    }
    
    fclose (fp);
    return;
}

void copy(char *name, char *name2){
    ppmPic *head = read(name);
    write(name, name2, head);
    return;
}

void grow(char *name, char *name2, ppmPic *head){
    int col = head->cols;
    int row = head->rows;
    
    FILE *fp = fopen(name2, "w");
    ppmPic *ptr = head;
    
    ptr->cols = col*2;
    ptr->rows = row*2;
    
    fprintf(fp, "P3\n%d %d %d\n", ptr->cols, ptr->rows, ptr->colors);
    Pixel **pix;
    pix = ptr->pixels;
    printf("hello\n");
    int i, j;
    for (i = 0; i<row; i++){
        for (j=0; j<col; j++){
            fprintf(fp, "%d\n%d\n%d\n", pix[i][j].red, pix[i][j].blue, pix[i][j].green);
            fprintf(fp, "%d\n%d\n%d\n", pix[i][j].red, pix[i][j].blue, pix[i][j].green);
        }
        j = 0;
        for (j=0; j<col; j++){
            fprintf(fp, "%d\n%d\n%d\n", pix[i][j].red, pix[i][j].blue, pix[i][j].green);
            fprintf(fp, "%d\n%d\n%d\n", pix[i][j].red, pix[i][j].blue, pix[i][j].green);
        }
    }
    
    
    fclose(fp);
    return;
}

void shrink(char *name, char *name2, ppmPic *head){
    printf("shrink");
    return;
}