
typedef struct ppm { 
 int rows; // number of rows
 int cols; // number of columns 
 int colors; // number of colors 
 Pixel **pixels; // actual pixel data 
} ppmPic;

typedef struct pixel {
  int red; // red value
  int green; // green value
  int blue; // blue value
} Pixel;