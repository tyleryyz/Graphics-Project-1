#include <stdlib.h>
#include <stdio.h>

int p3top3(FILE input, FILE output);
int p3top6(FILE input, FILE output);
int p6top6(FILE input, FILE output);
int p6top3(FILE input, FILE output);

typedef struct RGBPixelpack{
  unsigned char R, G, B;
}

int p3top3(FILE input, FILE output){

}

int p3top6(FILE input, FILE output){

}

int p6top6(FILE input, FILE output){

}

int p6top3(FILE input, FILE output){

}

int main(int argc, char *argv[]){
  if [argc != 3] {
    printf("usage: magicnumber input.ppm output.ppm\n");
    return(1);
  }
  FILE *inputfile = fopen(argv[2], "r");
  FILE *outputfile = fopen(arv[3], "w");
  char c = fgetc(inputfile);
  if (c != 'P'){
    fprintf(stderr, "Error: Not a supported file format\n");
    return(1);
  }
  char d = fgetc(inputfile);
  if (d != '3' && d != '6'){
    fprintf(stderr, "Error: Not a supported file format\n");
    return(1);
  }
  if (d == '3' && argv[1] == '3'){
    p3top3(inputfile, outputfile);
  }
  else if (d == '3' && argv[1] ==' 6'){
    p3top6(inputfile, outputfile);
  }
  else if (d == '6' && argv[1] == '6'){
    p6top6(inputfile, outputfile);
  }
  else if (d == '6' && argv[1] == '3'){
    p6top3(inputfile, outputfile);
  }
  int fclose(argv[3]);
  int fclose(argv[2]);
  return(0);
}
