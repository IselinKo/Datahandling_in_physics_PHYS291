// usetime3.cpp -- use fourth draft of Time class

// compile usetime3.cpp and mytime3.cpp together
//
//    g++ -o utime usetime3.cpp mytime3.cpp
//

#include <iostream>
#include "mytime3.h"
using namespace std;

int main()
{
    Time A;
    Time B(5, 40);
    Time C(2, 55);
	cout << "\n-----------\nFirst statements:\n\n";
    cout << "    Time A;\n" << "    Time B(5, 40);\n" << "    Time C(2, 55);\n";
    cout << "time interval A is: " << A << endl;
    cout << "time interval B is: " << B << endl;
	cout << "time interval C is: " << C << endl;
	
    A = B + C;     // operator+()   sum of two Time objects
	
    cout << "sum of intervals A = B + C: " << A << endl;
	
	cout << "-------------\n   A = B * 2.75;   ::  member operator*()\n-------------\n";
    A = B * 2.75;  // member operator*()

    cout << "time interval A = B * 2.75: " << A << endl;

	cout << "-------------\n   A = 2.75 * B;   ::  friend operator*()\n-------------\n";	
	A = 2.75 * B;
	
    cout << "time interval A = 2.75 * B: " <<  A  << endl;
	cout << "-----------\n\n";
    return 0;
}

