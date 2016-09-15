#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int p3top3(FILE *input, int width, int height, FILE *output);
int p3top6(FILE *input, int width, int height, FILE *output);
int p6top6(FILE *input, int width, int height, FILE *output);
int p6top3(FILE *input, int width, int height, FILE *output);

typedef struct ImageData{
  unsigned char R, G, B;
}

//fread for bits
//for loops widthxheight for ascii

ImageData;
ImageData *pixbuff;

int p3top3(FILE *input, int width, int height, FILE *output){
  char p3pixelbuffer[0x1000];
  char p3eof;
  while (p3eof = fgetc(input)){
    if(p3eof != EOF){
      ungetc(p3eof, input);
      fgets(p3pixelbuffer, sizeof(p3pixelbuffer), input);
      fprintf(output, "%s", p3pixelbuffer);
    }
  }
  fclose(output);
  return(0);

}

int p3top6(FILE *input, int width, int height, FILE *output){}

int p6top6(FILE *input, int width, int height, FILE *output){
  pixbuff = malloc(sizeof(ImageData) * width * height);
  fread(pixbuff, sizeof(ImageData), width*height, input);
  fwrite(pixbuff, width*height, sizeof(ImageData), output);
  fclose(output);
  return(0);
}

int p6top3(FILE *input, int width, int height, FILE *output){}

int main(int argc, char *argv[]){
  if (argc != 4) {
    printf("usage: magicnumber input.ppm output.ppm\n");
    return(1);
  }
  FILE *inputfile = fopen(argv[2], "r");
  FILE *outputfile = fopen(argv[3], "w");
  char c = fgetc(inputfile);
  int i = atoi (argv[1]);
  if (c != 'P'){
    fprintf(stderr, "Error: Not a supported file format\n");
    return(1);
  }
  char d = fgetc(inputfile);
  if (d != '3' && d != '6'){
    fprintf(stderr, "Error: Not a supported file format\n");
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

  if (maxval > 255 || maxval < 128){
    fprintf(stderr, "Error: Max color value incorrect");
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
  fclose(outputfile);
  fclose(inputfile);
  return(0);
}
