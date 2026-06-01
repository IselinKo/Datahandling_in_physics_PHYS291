//
//  Binary to Decimal to Binary
//  gcc -o binar binar.c
//
#include <stdio.h>
#include <string.h>

int main()
{
unsigned char Z=0b00000111;
unsigned char byt1, ddd;
int num1, k;
// printf("  0b00000111  is %d \n", Z);

char bin1[10];   char bin2[10];  // must be longer because sprintf

//  Binary string to unsigned Number    /////////////////////////////

printf("\nFrom binary string to number\n");
printf("\nEnter 8 bits in the form e.g. \n01010101\n");
scanf("%s",bin1);
if (strlen(bin1)<8) printf("Wrong length %d. Should be 8\n",(int)strlen(bin1));
printf("%s\n",bin1);
//  String to number
Z=0; byt1=1;
   for (k=7;k>(-1);k--){
   	    if ( bin1[k]=='1' ){
   	    	Z=Z+(byt1<<(7-k));
   	    }
   }
printf("%d\n",Z);

//  Number to binary string   /////////////////////////////

printf("\nFrom unsigned byte number to a binary string\n");

printf("\nEnter number between 0 and 255 \n");
scanf("%d",&num1);
if (num1<0 || num1>255  ) printf("Wrong length %d \n", num1);
Z=(unsigned char)num1;
sprintf(bin2,"00000000");
   for (k=7;k>(-1);k--){
   	    ddd=Z&(byt1<<(7-k));
   	    if ( ddd ){
   	    	bin2[k]='1';
   	    }
   	}
printf("%d   is  %s\n",num1, bin2);
}
