{
struct demstruct {  int    Num; 
	                double Val; 
	                char   labeL[30]; };
demstruct exampl;                                //  Note the syntax of ; }; in struct above
//
system("clear");   //  useful trick;
exampl.Num=11; exampl.Val=1.0; strcpy(exampl.labeL,"Study_me");
cout << "\n\nThis line is a copy of the actual assignement in the code \n";
cout << "exampl.Num=11; exampl.Val=1.8; strcpy(exampl.labeL,\"Study_me\"); \n"; // print the code
cout << "\ncheck it:                                      <===============\n";
cout << "exampl.Num: "<< exampl.Num << "    exampl.Val: "<<exampl.Val;
cout << "   labeL: "<< exampl.labeL <<endl;                    // this continues the above print
cout << "\ndefine:  demstruct Twin;   assign: Twin=exampl; \n";
//
demstruct Twin;
//
//              Copy the structure object exampl   into a new object Twin
Twin=exampl;
cout << "Twin.Num: "<< Twin.Num << "    Twin.Val: "<<Twin.Val;
cout << "  Twin.labeL: "<< Twin.labeL <<endl;                  // this continues the above print
//
//       Using pointer to a structure;  using new (in root and C++ only, not in C)
//
cout << "\nUse pointer: demstruct *Spoint; Spoint=new demstruct; \n";
demstruct *Spoint;
Spoint=new demstruct;       //  The structure pointed to by Spoint created by new
*Spoint=Twin;               //  Filled by copy as Twin above
cout << "\n*Spoint=Twin , Spoint->labeL is " << Spoint->labeL << endl;
//   Spoint will now point to the original exampl 
Spoint=&exampl;
strcpy(Spoint->labeL, "OtherText");     Spoint->Val=333.33; 
cout << "\npointer Spoint now points to demstruct exampl\n";
cout << "code does:   strcpy(Spoint->labeL, \"OtherText\");      Spoint->Val=333.33;       \n";
cout << "\ncheck it:     (as in above, look at exampl )   <===============\n";
cout << "exampl.Num: "<< exampl.Num << "    exampl.Val: "<<exampl.Val;
cout << "   labeL: "<< exampl.labeL <<endl;                    // this continues the above print
//    
cout << "\n\nConstruct an array of  structs  - for your further experiments      \n";
//
demstruct ManyStructs[300];
ManyStructs[100].Val=123.456;     strcpy(ManyStructs[100].labeL,"Number 100");
cout<<ManyStructs[100].Num << " " <<ManyStructs[100].Val<< " " << ManyStructs[100].labeL<< endl;
// experiment with this:
ManyStructs[55]=exampl; 
cout<<ManyStructs[55].Num << " " <<ManyStructs[55].Val<< " " << ManyStructs[55].labeL<< endl;

}

