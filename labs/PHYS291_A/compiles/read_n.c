#include <stdio.h>
// compile with   
//             gcc read_n.c -o read_n
// run by
//             ./read_n
//
int main(void)
{
  int i;
  for(;;) {
   printf("Enter a number:  >>  "); 
   scanf("%d", &i);
   printf("\t\t\t%d\t  %d \n", i, i*i);
   }
return 0;
}

