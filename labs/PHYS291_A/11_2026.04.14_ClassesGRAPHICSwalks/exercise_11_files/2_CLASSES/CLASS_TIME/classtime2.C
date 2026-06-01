//
//    All the Time files merged
//
//    classtime.cpp
//
//    compile by   g++ -o ctime classtime.cpp
//
/////////////////////////////////////////////////////////////////////////////
//
// this was mytime3.h -- Time class with friends

#include <iostream>
using namespace std;

class Time
{
private:
    int hours;
    int minutes;
public:
    Time();
    Time(int h, int m = 0);
    void AddMin(int m);
    void AddHr(int h);
    void Reset(int h = 0, int m = 0);
    Time operator+(const Time & t) const;
    bool operator==(const Time & t) const;
	void Set(int h, int m);	
	int Hours();		
	int Minutes();
	
    Time operator-(const Time & t) const;
    Time operator*(double n) const;
    friend Time operator*(double m, const Time & t)
           { return t * m; }    // inline definition
    friend ostream & operator<<(ostream & os, const Time & t);
};

/////////////////////////////////////////////////////////////////////////////

//this was  mytime3.cpp  -- implement Time methods
//
//

Time::Time()
{
    hours = minutes = 0;
}

Time::Time(int h, int m )
{
    hours = h;
    minutes = m;
}

void Time::AddMin(int m)
{
    minutes += m;
    hours += minutes / 60;
    minutes %= 60;
}
void Time::AddHr(int h)
{
    hours += h;
}

void Time::Reset(int h, int m)
{
    hours = h;
    minutes = m;
}

void Time::Set(int h, int m)
{
    hours = h;
    minutes = m;
}

int Time::Hours()
{
    return hours; 
}


int Time::Minutes()
{
    return minutes; 
}

Time Time::operator+(const Time & t) const
{
    Time sum;
    sum.minutes = minutes + t.minutes;
    sum.hours = hours + t.hours + sum.minutes / 60;
    sum.minutes %= 60;
    return sum;
}
bool Time::operator==(const Time & t) const
   {  if ((minutes==t.minutes)&& (hours==t.hours)) return true;
      else return false;}

Time Time::operator-(const Time & t) const
{
    Time diff;
    int tot1, tot2;
    tot1 = t.minutes + 60 * t.hours;
    tot2 = minutes + 60 * hours;
    diff.minutes = (tot2 - tot1) % 60;
    diff.hours = (tot2 - tot1) / 60;
    return diff;
}

Time Time::operator*(double mult) const
{
    Time result;
    long totalminutes = hours * mult * 60 + minutes * mult;
    result.hours = totalminutes / 60;
    result.minutes = totalminutes % 60;
    return result;
}

ostream & operator<<(ostream & os, const Time & t)
{
    os << t.hours << " hours, " << t.minutes << " minutes";
    return os;
}

Time A, B, C ;
/////////////////////////////////////////////////////////////////////////////


void  classtime2()
{
    A.Reset();
    B.Set(5, 40);
    C.Set(2, 55);
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
}


