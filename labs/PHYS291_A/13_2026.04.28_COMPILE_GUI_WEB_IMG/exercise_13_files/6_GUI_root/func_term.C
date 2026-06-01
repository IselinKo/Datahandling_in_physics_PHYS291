{   
	//    The purpose of this is to show how to 
	//    change a termina based program
	//    to a GUI based program
	//    An original version (not included was organised differently)
	//    It has been re-organized - while checking that it works
	//    at every change - into this form
	//    Where parts   with  // Tr  have been collected to be transfered

	// THE GLOBAL VARIABLES - MUST BE COPIED TO THE GUI VERSION
    //
	TF1 *plotFun;                                                // Tr
	TF1 *plotFun0;                                               // Tr	
	TString Sfun;                                                // Tr
    TString funcs[15];                                           // Tr
	void assign_funcs();  // These are the function TStrings     // Tr
    int toplot[15];       // which functions to plot             // Tr
    //                                                           // Tr
    assign_funcs();                                              // Tr
 
	TCanvas * LocC=new TCanvas("LocC","A",30,30,400,300); 
	     // This might be changed in the GUI version	
    int n;

	//   THIS IS THE TERMINAL VERSION ADMINISTRATION - START
 
         for (int i=0;i<15;i++){
              printf("%2d %s", i+1, funcs[i].Data());
              if(!((i+1)%3) ) printf("\n");               
         }         
         cout << "Enter number of functions      --> ";
         cin >> n;
         cout << "enter their numbers from the table one on each line \n";
         for (int i=0;i<n;i++){
              cout << "--> ";
              cin >> toplot[i];  toplot[i]--;
         }
	//   ABOVE IS THE TERMINAL VERSION ADMINISTRATION - ends here

    // THIS IS THE ACTUAL FUNCTIONALITY                              // Tr   
        //  it needs the selected function indices toplot[i]         // Tr
        for (int i=0;i<n;i++){                                       // Tr
             Sfun=funcs[toplot[i]].Data();                           // Tr
                // funcs from assign_funcs(); Sfun a local TString   // Tr
             cout << Sfun << endl;                                   // Tr
             if(i==0) {  plotFun0=new TF1(Sfun,Sfun,0.0,12.0);       // Tr
                         plotFun0->Draw();                           // Tr 
                      }                                              // Tr                      
             else  {   plotFun=new TF1(Sfun,Sfun,0.0,12.0);          // Tr
                       plotFun->Draw("SAME"); 
                   }                                                 // Tr
	         //LocC->Modified();	LocC->Update();                      // Tr
            }                                                        // Tr
            // LocC->Print("func_term.png");
       plotFun0->SetTitle("Combined Plot of selected");
    // THE PART ABOVE ONLY IS THE ACTUAL FUNCTIONALITY               // Tr
}                                                                    // Tr      
void assign_funcs(){                                                  // Tr
  funcs[0] ="sin(x)*exp(-0.3*x)     ";                             // Tr
  funcs[1] ="cos(x)*exp(-0.3*x)     ";                             // Tr
  funcs[2] ="0.7*cos(x)*exp(-0.01*x)";                             // Tr
  funcs[3] ="0.9*cos(x*x)           ";                             // Tr
  funcs[4] ="exp(-0.7*x)            ";                             // Tr
  funcs[5] ="exp(-0.1*x*x)          ";                             // Tr
  funcs[6] ="0.95/(1.0+x*x)         ";                             // Tr
  funcs[7] ="0.95/(1.0+x*x)*cos(x)  ";                             // Tr
  funcs[8] ="cos(0.5*x)*exp(-0.2*x) ";                             // Tr
  funcs[9] ="cos(2*x)*exp(-0.5*x)   ";                             // Tr
  funcs[10]="exp(-0.1*x*x)*cos(x*x) ";                             // Tr
  funcs[11]="0.2*cos(x)*exp(0.3*x)  ";                             // Tr
  funcs[12]="0.08*x                 ";                             // Tr
  funcs[13]="0.05*x*x               ";                             // Tr
  funcs[14]="0.2+0.05*x-0.005*x*x   ";                             // Tr
                                                                      // Tr  
}                                                                     // Tr      