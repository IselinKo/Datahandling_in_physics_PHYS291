{
// even - odd decide    - stop on zero
int k;
int L;
cout << "To stop, enter a zero\n";
while(1) {
     cout << "Enter an integer --> ";
     cin >> k;  if( !L ) break;
     cout << "You entered " << k <<" which is ";
     if (L%2) cout << "an odd number\n "; else cout << "an even number\n ";
  }
gROOT->ProcessLine(".q");
}

