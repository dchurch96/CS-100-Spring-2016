#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct pixel {
  int red; // red value
  int green; // green value
  int blue; // blue value
} Pixel;

typedef struct ppm { 
 int rows; // number of rows
 int cols; // number of columns 
 int colors; // number of colors 
 Pixel **pixels; // actual pixel data 
} ppmPic;


ppmPic *read(char *);
void write(char *, char *, ppmPic *);
void copy(char *, char *);
void grow(char *, char *, ppmPic *head);
void shrink(char *, char *, ppmPic *head);

