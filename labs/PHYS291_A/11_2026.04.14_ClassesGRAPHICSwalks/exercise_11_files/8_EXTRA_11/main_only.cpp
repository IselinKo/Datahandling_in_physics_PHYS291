/****************************************************************
*                                                               *
*         Typical C / C++ program  to compile in g++ or gcc     *
*         or run in root     - but might crash in some versions *
*         compile with    g++ -o honly main_only.cpp            *
*         to run, type    ./honly                               *
*                                                               *
*         root                                                  *
*         .L  main_only.cpp                                     *
*         main();                                               *
*                                                               *
* !!!!!!    MODIFIED FOR ROOT 6 2015 and again 2019   !!!!!!!   *
*                                                               *
*****************************************************************/

#include <iostream>
#include <stdio.h>
using namespace std;

// GLOBALS
int K;
void hello();       // so called prototype
 
//   Here is as normally   int main(), that will not run in
//   some versions of root; thus smain() and  main()

int main ()
{
	  K=1000;
	  cout << "K is " << K << endl;
      hello();   
      return 0;
} 
void hello(){
	 printf ("\n\n     Hello, ROOT. Root might crash !!! \n\n");
}
