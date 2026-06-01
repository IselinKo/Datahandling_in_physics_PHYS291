#include <iostream>
#include <ctime>
//
//     compile by       g++ time.cpp -o mytime
//     run by           ./mytime
//
using namespace std;

int main()
{
   time_t tt;
   
   time( &tt );
   
   cout << asctime( localtime( &tt ) );
   return 0;
}

