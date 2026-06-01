
int Global;  int  Unused;          // Global variables

void Do_some_assigns(int Num1);    // Function prototype
TString Do_String();               // Function prototype

void main_program_example()
{   
	int Num=3;

    // main_program_example  needs to functions 

    Do_some_assigns( 15 );   //  Assigns number to global Global
    cout << "calling Do_String(): returns this ==> " <<  Do_String()  << endl;
    cout << "  and Do_some_assigns(15) assigned  Global = " << Global << endl;
}

void Do_some_assigns(int Num1) {
             Global = Num1;
}
TString Do_String() {
      TString inside="A TString defined in an example";
      return( inside );
}
