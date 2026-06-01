{
// Both this script, tripples.C and the  TRIPPLES_man.C 
// can be run as:  root tripples.C 
// and you can then continue by entering line-commnds
// as e.g.    cout << K.S2.addr << endl;
// This running checks that there are no misprints

struct tstst {int  i; int k; char nam[10]; char addr[20];};

tstst A;
A.i=5; A.k=25; strcpy(A.nam,"AAA BBB");
strcpy(A.addr,"AAA BBB 45 N-5009");

tstst B;
B=A;                   //  does it work?
cout << B.addr << endl;

struct dobstr { tstst S1; tstst S2;};
dobstr K;
K.S1=A; K.S2=B;
cout << K.S2.addr << endl;
struct trippl {dobstr Comp; tstst Simp;};
trippl TTri;
TTri.Comp=K;
TTri.Simp=A;
cout << "TTri.Comp.S1.i is: " << TTri.Comp.S1.i << endl;
cout << "TTri.Comp.S1.addr is " << TTri.Comp.S1.addr  << endl;
cout << "TTri.Simp.addr is " << TTri.Simp.addr  << endl;
cout << "TTri.Simp.i    is " << TTri.Simp.i     << endl;
trippl TWWW;
TWWW=TTri;
cout << "TWWW.Comp.S1.i is: " << TWWW.Comp.S1.i << endl;
}
