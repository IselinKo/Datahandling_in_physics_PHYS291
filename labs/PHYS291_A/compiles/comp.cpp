// file     comp.cpp
// This file is identical with comp.c except of these notes
// compile with   
//             g++ -o Cpp_comp comp.cpp
// run by
//             ./Cpp_comp
//
#include <stdio.h>

int main(void)
{
  int i;
  for(i=0;i<10;i++)
printf("%d  %d \n", i, i*i);
return 0;
}


