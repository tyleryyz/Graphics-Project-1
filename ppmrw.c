#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int p3top3(FILE input, int width, int height, FILE output);
int p3top6(FILE input, int width, int height, FILE output);
int p6top6(FILE input, int width, int height, FILE output);
int p6top3(FILE input, int width, int height, FILE output);

typedef struct RGBPixelpack{
  unsigned char R, G, B;
}

//fread for bits
//for loops widthxheight for ascii

RGBPixelpack;

int p3top3(FILE input, int width, int height, FILE output){

  pixelbuffer = malloc(sizeof(RGBPixelpack)*width*height);
  rewind(input);
  char headerdatabuffer[0x1000];
  fgets(headerdatabuffer, sizeof(headerdatabuffer), input);
  char e;
  while(e=fgetc(input)){
    if (e == '#' || e == '\n'){
      fgets(headerdatabuffer, sizeof(headerdatabuffer), input);
    }
    else if(e != '#')
      break;
  }
  ungetc(e, inputfile);
  fgets(headerdatabuffer, sizeof(headerdatabuffer), input);
  fgets(headerdatabuffer, sizeof(headerdatabuffer), input);


}

//int p3top6(FILE input, int width, int height, FILE output){}

//int p6top6(FILE input, int width, int height, FILE output){}

//int p6top3(FILE input, int width, int height, FILE output){}

int main(int argc, char *argv[]){
  if (argc != 3) {
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

  if (i == "3"){
    fprintf(outputfile, "%s", "P3");
    }
  }

  else if (i == "6"){
    fprintf(outputfile, "%s", "P6");
  }
  rewind(inputfile);
  char throwawaybuff[0x1000];
  fgets(throwawaybuff, sizeof(throwawaybuff), inputfile);
  char e;
  while(e=fgetc(inputfile)){
    if (e == '#' || e == '\n'){
      ungetc(e, inputfile);
      fgets(throwawaybuff, sizeof(throwawaybuff), inputfile);
    }
    else if(e != '#')
      break;
  }
  char widthxheightbuff[0x1000];
  ungetc(e, inputfile);
  fgets(widthxheightbuff, sizeof(widthxheightbuff), inputfile);
  fprintf(outprint, "%s", widthxheightbuff);
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
  if (d == '3' && i == '3'){
    p3top3(inputfile, width, height, outputfile);
  }
  else if (d == '3' && i == '6'){
    p3top6(inputfile, width, height, outputfile);
  }
  else if (d == '6' && i == '6'){
    p6top6(inputfile, width, height, outputfile);
  }
  else if (d == '6' && i == '3'){
    p6top3(inputfile, width, height, outputfile);
  }
  fclose(outputfile);
  fclose(inputfile);
  return(0);
}
