// file     comp.c
// compile with   
//             gcc -o C_comp comp.c
// run by
//             ./C_comp
//
#include <stdio.h>
int main(void)
{
  int i;
  for(i=0;i<20;i++)
printf("%d  %d \n", i, i*i);
return 0;
}

