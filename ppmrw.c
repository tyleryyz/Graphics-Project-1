#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int p3top3(FILE *input, int width, int height, FILE *output);
int p3top6(FILE *input, int width, int height, FILE *output);
int p6top6(FILE *input, int width, int height, FILE *output);
int p6top3(FILE *input, int width, int height, FILE *output);

typedef struct ImageData{
  unsigned char r, g, b;
}
ImageData;
int p3top3(FILE *input, int width, int height, FILE *output){
  ImageData pixbuff[height][width];
  char next;
  int rows;
  int cols;
  int redi;
  int greeni;
  int bluei;
  for (rows = 0; rows < height; rows++){
    for (cols = 0; cols < width; cols++){
      char r[4] = {"\0"};
      char g[4] = {"\0"};
      char b[4] = {"\0"};
      next = fgetc(input);
      for (redi = 0; redi < 3; redi++){
        if (isspace(next) || next == '\n'){
          break;
        }
        r[redi] = next;
        next = fgetc(input);
      }
      while (isspace(next) || next == '\n'){
        next = fgetc(input);
      }
      for (greeni = 0; greeni < 3; greeni++){
        if (isspace(next) || next == '\n'){
          break;
        }
        g[greeni] = next;
        next = fgetc(input);
      }
      while (isspace(next) || next == '\n'){
        next = fgetc(input);
      }
      for (bluei = 0; bluei < 3; bluei++){
        if (isspace(next) || next == '\n'){
          break;
        }
        b[bluei] = next;
        next = fgetc(input);
      }
      while (isspace(next) || next == '\n'){
        next = fgetc(input);
      }
      ungetc(next, input);
      int red = atoi(r);
      int green = atoi(g);
      int blue = atoi(b);

      pixbuff[rows][cols].r = red;
      pixbuff[rows][cols].g = green;
      pixbuff[rows][cols].b = blue;
    }
  }
  for (rows = 0; rows < height; rows++){
    for (cols = 0; cols < width; cols++){
      int redout = pixbuff[rows][cols].r;
      int greenout = pixbuff[rows][cols].g;
      int blueout = pixbuff[rows][cols].b;
      fprintf(output, " %i %i %i ", redout, greenout, blueout);
    }
  }

  fclose(input);
  fclose(output);
  return(0);
  exit(0);
}

int p3top6(FILE *input, int width, int height, FILE *output){
  ImageData pixbuff[height][width];
  char next;
  int rows;
  int cols;
  int redi;
  int greeni;
  int bluei;
  for (rows = 0; rows < height; rows++){
    for (cols = 0; cols < width; cols++){
      char r[4] = {"\0"};
      char g[4] = {"\0"};
      char b[4] = {"\0"};
      next = fgetc(input);
      for (redi = 0; redi < 3; redi++){
        if (isspace(next) || next == '\n'){
          break;
        }
        r[redi] = next;
        next = fgetc(input);
      }
      while (isspace(next) || next == '\n'){
        next = fgetc(input);
      }
      for (greeni = 0; greeni < 3; greeni++){
        if (isspace(next) || next == '\n'){
          break;
        }
        g[greeni] = next;
        next = fgetc(input);
      }
      while (isspace(next) || next == '\n'){
        next = fgetc(input);
      }
      for (bluei = 0; bluei < 3; bluei++){
        if (isspace(next) || next == '\n'){
          break;
        }
        b[bluei] = next;
        next = fgetc(input);
      }
      while (isspace(next) || next == '\n'){
        next = fgetc(input);
      }
      ungetc(next, input);
      int red = atoi(r);
      int green = atoi(g);
      int blue = atoi(b);

      pixbuff[rows][cols].r = red;
      pixbuff[rows][cols].g = green;
      pixbuff[rows][cols].b = blue;
    }
  }
  for (rows = 0; rows < height; rows++){
    for (cols = 0; cols < width; cols++){
        int p6redout[1] = {pixbuff[rows][cols].r};
        int p6greenout[1] = {pixbuff[rows][cols].g};
        int p6blueout[1] = {pixbuff[rows][cols].b};

        fwrite(p6redout, 1, 1, output);
        fwrite(p6greenout, 1, 1, output);
        fwrite(p6blueout, 1, 1, output);
    }
  }
  fclose(input);
  fclose(output);
  exit(0);
}

int p6top6(FILE *input, int width, int height, FILE *output){
  ImageData pixbuff[height][width];
  int rows;
  int cols;
  for (rows = 0; rows < height; rows++){
    for (cols = 0; cols < width; cols++){
      int p6redout[1];
      int p6greenout[1];
      int p6blueout[1];

      fread(p6redout, 1, 1, input);
      fread(p6greenout, 1, 1, input);
      fread(p6blueout, 1, 1, input);

      pixbuff[rows][cols].r = p6redout[0];
      pixbuff[rows][cols].g = p6greenout[0];
      pixbuff[rows][cols].b = p6blueout[0];
    }
  }
  for (rows = 0; rows < height; rows++){
    for (cols = 0; cols < width; cols++){
        int p6redout[1] = {pixbuff[rows][cols].r};
        int p6greenout[1] = {pixbuff[rows][cols].g};
        int p6blueout[1] = {pixbuff[rows][cols].b};

        fwrite(p6redout, 1, 1, output);
        fwrite(p6greenout, 1, 1, output);
        fwrite(p6blueout, 1, 1, output);
    }
  }
  fclose(input);
  fclose(output);
  exit(0);
}

int p6top3(FILE *input, int width, int height, FILE *output){
  ImageData pixbuff[height][width];
  int rows;
  int cols;
  for (rows = 0; rows < height; rows++){
    for (cols = 0; cols < width; cols++){
      int p6redout[1];
      int p6greenout[1];
      int p6blueout[1];

      fread(p6redout, 1, 1, input);
      fread(p6greenout, 1, 1, input);
      fread(p6blueout, 1, 1, input);

      pixbuff[rows][cols].r = p6redout[0];
      pixbuff[rows][cols].g = p6greenout[0];
      pixbuff[rows][cols].b = p6blueout[0];
    }
  }
  for (rows = 0; rows < height; rows++){
    for (cols = 0; cols < width; cols++){
      int redout = pixbuff[rows][cols].r;
      int greenout = pixbuff[rows][cols].g;
      int blueout = pixbuff[rows][cols].b;
      fprintf(output, " %i %i %i ", redout, greenout, blueout);
    }
  }
  fclose(input);
  fclose(output);
  exit(0);
}


int main(int argc, char *argv[]){
  if (argc != 4) {
    printf("usage: magicnumber input.ppm output.ppm\n");
    return(1);
  }
  FILE *inputfile = fopen(argv[2], "r");
  FILE *outputfile = fopen(argv[3], "w");
  char c = fgetc(inputfile);
  int i = atoi (argv[1]);
  if (i != 3 && i != 6){
    fprintf(stderr, "%s\n", "Error: Attempting to write to unsupported file format\n");
    return(1);
  }
  if (c != 'P'){
    fprintf(stderr, "%s\n", "Error: Not a supported file format\n");
    return(1);
  }
  char d = fgetc(inputfile);
  if (d != '3' && d != '6'){
    fprintf(stderr, "%s\n", "Error: Not a supported file format\n");
    return(1);
  }

  if (i == 3){
    fprintf(outputfile, "%s", "P3\n");
    }

  else if (i == 6){
    fprintf(outputfile, "%s", "P6\n");
  }

  rewind(inputfile);
  char throwawaybuff[0x1000];
  fgets(throwawaybuff, sizeof(throwawaybuff), inputfile);
  char e;
  while(e=fgetc(inputfile)){
    if (e == '#' || e == '\n'){
      ungetc(e, inputfile);
      fgets(throwawaybuff, sizeof(throwawaybuff), inputfile);
      fprintf(outputfile, "%s", throwawaybuff);
    }
    else if(e != '#')
      break;
  }
  char widthxheightbuff[0x1000];
  ungetc(e, inputfile);
  fgets(widthxheightbuff, sizeof(widthxheightbuff), inputfile);
  fprintf(outputfile, "%s", widthxheightbuff);
  char widtharr[0x100];
  char heightarr[0x100];

  strcpy(widtharr, strtok(widthxheightbuff, " "));
  strcpy(heightarr, strtok(NULL, " "));

  int width;
  int height;

  sscanf(widtharr, "%i", &width);
  sscanf(heightarr, "%i", &height);


  char maxvalbuff[0x1000];
  fgets(maxvalbuff, sizeof(maxvalbuff), inputfile);
  fprintf(outputfile, "%s", maxvalbuff);

  int maxval;
  sscanf(maxvalbuff, "%i", &maxval);

  if (maxval != 255){
    fprintf(stderr, "Error: Max color value incorrect");
    fclose(inputfile);
    return(1);
  }
  if (d == '3' && i == 3){
    p3top3(inputfile, width, height, outputfile);
  }
  else if (d == '3' && i == 6){
    p3top6(inputfile, width, height, outputfile);
  }
  else if (d == '6' && i == 6){
    p6top6(inputfile, width, height, outputfile);
  }
  else if (d == '6' && i == 3){
    p6top3(inputfile, width, height, outputfile);
  }
  return(0);
}
