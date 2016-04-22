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


void read(char *, ppmPic *);
void write();
void copy();
void grow();
void shrink();

