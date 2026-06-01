/****************************************************************
*                                                               *
*         Typical C / C++ program  to compile in g++ or gcc     *
*         or run in root                                        *
*         compile with    g++ -o hey main_smain.cpp             *
*         to run, type    ./hey                                 *
*                                                               *
*         root                                                  *
*         .L  main_smain.cpp                                    *
*         smain();                                              *
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
 
//   Here will normally be int main(), that will not run in
//   some versions of root; thus smain() and  main()

          #if defined(__CLING__)
int main_smain ()             
		  #else
int main ()
          #endif
{
	  K=1000;
	  cout << "K is " << K << endl;
      hello();   
      return 0;
} 
void hello(){
	 printf ("\n\n              Hello, world.\n\n");
}
