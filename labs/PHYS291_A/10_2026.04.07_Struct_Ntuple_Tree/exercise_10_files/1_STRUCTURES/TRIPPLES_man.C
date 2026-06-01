{
// Both this script,  TRIPPLES_man.C and the tripples.C
// can be run as:  root TRIPPLES_man.C
// and you can then continue by entering line-commnds
// as e.g.    cout << K.S2.addr << endl;
// This running checks that there are no misprints
/*
struct tstst {int  i; int k; char nam[10]; char addr[20];};

Visualize this:   tstst:   ( INT  INT  CHARxxxxxx    CHARyyyyyyyyyyyy )

struct dobstr { tstst S1; tstst S2;};     

                  dobstr:  ( S1: INT  INT  CHARxxxxxx    CHARyyyyyyyyyyyy
                             S2: INT  INT  CHARxxxxxx    CHARyyyyyyyyyyyy  )

struct trippl {dobstr Comp; tstst Simp;};

                  trippl:  Comp: ( S1: INT  INT  CHARxxxxxx    CHARyyyyyyyyyyyy
                                   S2: INT  INT  CHARxxxxxx    CHARyyyyyyyyyyyy  )
                           Simp:  (    INT  INT  CHARxxxxxx    CHARyyyyyyyyyyyy  )

tstst A;
has these 4 elements named as:   
             A.i   A.k    A.nam   A.addr

dobstr K;
has these 8 elements named and structured as:   
             K.S1.i  K.S1.k    K.S1.nam   K.S1.addr
             K.S2.i  K.S2.k    K.S2.nam   K.S2.addr

trippl TTri;
has these  12 elements  named and structured as:
             TTri.Comp.S1.i  TTri.Comp.S1.k    TTri.Comp.S1.nam   TTri.Comp.S1.addr
             .....  fill in the rest
             TTri.Simp.i   ....  fll in the rest           
*/
//  int -> simple assignments  strings: use  strcpy(element,c-string)
//                                   or use  sprintf(element,formatstr,possible_data)
struct tstst {int  i; int k; char nam[10]; char addr[20];};
struct dobstr { tstst S1; tstst S2;};
struct trippl {dobstr Comp; tstst Simp;};
tstst A;
A.i=5; A.k=25; strcpy(A.nam,"AAA BBB");
strcpy(A.addr,"AAA BBB 45 N-5009");

tstst B;
B=A;                   //  does it work? YES; copying the whole structure - its elements
cout << B.addr << endl;

//         struct dobstr { tstst S1; tstst S2;};
dobstr K;
K.S1=A; K.S2=B;       // Try also  dobstr Zz;  Zz=K; and check all eight Zz.S2.i etc
cout << K.S2.addr << endl;

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


