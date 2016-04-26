#include "ppm.h"
#include "scanner.h"

ppmPic *read(char *name){
    ppmPic *ptr = malloc(sizeof(ppmPic));
    FILE *fp = fopen(name, "r");
    
    
    //These four commands make the initial reads that provide the array of colors
    //the number of columns and the number of rows.
    readToken(fp);
    ptr->cols = readInt(fp);
    ptr->rows = readInt(fp);
    ptr->colors = readInt(fp);
    
    //These few commands allocate the matrix of pixels that will hold teh picture data
    int a;
	Pixel **pix;
	pix = malloc(sizeof(Pixel *) * ptr->rows);
	for (a=0; a<ptr->rows; a++)
        pix[a] = malloc(sizeof(Pixel) * ptr->cols);
   
   //Here we read in all of the pixels colors to the locations where they belong.
    int i, j;
    for (i = 0; i<ptr->rows; i++){
        for (j=0; j<ptr->cols; j++){
            pix[i][j].red = readInt(fp);
            pix[i][j].blue = readInt(fp);
            pix[i][j].green = readInt(fp);
        }
    }
    
    //Assign the pixel matrix to the ppmPic structure.
    ptr->pixels = pix;
    
    fclose(fp);
    return ptr;
}

void write(char *name, char *name2, ppmPic *head){
    FILE *fp = fopen(name2, "w");
    
    ppmPic *ptr = head;
    
    //Print the number of colors columns and rows.
    fprintf(fp, "P3\n%d %d %d\n", ptr->cols, ptr->rows, ptr->colors);
    Pixel **pix;
    pix = ptr->pixels;
    
    //Print into the file the values of the pixels at those points
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
    //Copy can basically be written by reading in teh first file and writing
    //that data to the second file.
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
    
    //Print the number of colors columns and rows.
    fprintf(fp, "P3\n%d %d %d\n", ptr->cols, ptr->rows, ptr->colors);
    Pixel **pix;
    pix = ptr->pixels;

    int i, j;
    for (i = 0; i<row; i++){
        //This first for loop prints two pixels each itteration on the row.
        for (j=0; j<col; j++){
            fprintf(fp, "%d\n%d\n%d\n", pix[i][j].red, pix[i][j].blue, pix[i][j].green);
            fprintf(fp, "%d\n%d\n%d\n", pix[i][j].red, pix[i][j].blue, pix[i][j].green);
        }
        j = 0;
        //This for loop prints a second row and two pixels for each itteration.
        for (j=0; j<col; j++){
            fprintf(fp, "%d\n%d\n%d\n", pix[i][j].red, pix[i][j].blue, pix[i][j].green);
            fprintf(fp, "%d\n%d\n%d\n", pix[i][j].red, pix[i][j].blue, pix[i][j].green);
        }
    }
    
    fclose(fp);
    return;
}

void shrink(char *name, char *name2, ppmPic *head){
    int col = head->cols;
    int row = head->rows;
    
    FILE *fp = fopen(name2, "w");
    ppmPic *ptr = head;
    
    //If the number of columns or rows is odd we need to cut off the last
    //one so the average is correct.
    if(col%2 != 0) col = col - 1;
    if(row%2 != 0) row = row - 1;
    
    //We divide by two to get our final number of columns after the shrink.
    ptr->cols = col/2;
    ptr->rows = row/2;
    
    col = col/2;
    row = row/2;
    
    //Print the number of colors columns and rows into the file.
    fprintf(fp, "P3\n%d %d %d\n", ptr->cols, ptr->rows, ptr->colors);
    Pixel **pix;
    pix = ptr->pixels;

    //This for loop prints the average pixel value of the four surrounding pixels
    //into the file.
    int i, j;
    for (i = 0; i<row; i++){
        for (j=0; j<col; j++){
            int red = (pix[i*2][j*2].red + pix[i*2 + 1][j*2].red + pix[i*2][j*2 + 1].red + pix[i*2 + 1][j*2 + 1].red)/4;
            int blue = (pix[i*2][j*2].blue + pix[i*2 + 1][j*2].blue + pix[i*2][j*2 + 1].blue + pix[i*2 + 1][j*2 + 1].blue)/4;
            int green = (pix[i*2][j*2].green + pix[i*2 + 1][j*2].green + pix[i*2][j*2 + 1].green + pix[i*2 + 1][j*2 + 1].green)/4;
            fprintf(fp, "%d\n%d\n%d\n", red, blue, green);

        }
    }
    
    fclose(fp);
    return;
}