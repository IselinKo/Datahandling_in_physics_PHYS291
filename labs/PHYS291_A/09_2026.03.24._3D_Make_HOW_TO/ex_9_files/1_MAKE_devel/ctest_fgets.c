//  How to read input from terminals efficiently
//
//  gcc -o ffgets ctest_fgets.c
//
#include <stdio.h>
#include <string.h>

int main(){
char inpt[255];

fgets(inpt, 255, stdin); 

//  strcpy(inpt,"Hello world");
printf("%s\n",inpt);
return 0;
}
