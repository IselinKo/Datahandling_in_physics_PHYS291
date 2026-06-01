
{   //  A little program combining terminal input and graphics
	//  Normally, graphics will not show until all terminal input is done
	//  You need to add  c1->Modified();c1->Update();gSystem->ProcessEvents();
	//  Where c1 is the canvas you are using
	using namespace TMath;
	TF1 *plotFun;     TF1 *archFun; 
	double OldMax=0; double OldMin=0; double NewMax, NewMin;
	TString Archiv[200]; int N_arch=0;
	TString Sfun="sin(x)"; string line; 
	plotFun=new TF1(Sfun,Sfun,0.0,12.0); 
	OldMax=plotFun->GetMaximum();  OldMin=plotFun->GetMinimum(); 
	plotFun->Draw(); c1->Modified();	c1->Update();   gSystem->ProcessEvents();
    while(1){
    	 Archiv[N_arch]=Sfun; N_arch=N_arch+1;
         cout << "Enter a formula, as e.g.       6*sin(x)*exp(-0.3*x)   or type q to exit\n--> ";
         getline (cin,line);                 //  using getline - to allow for spaces in formula
         Sfun=line;
         if(!strcmp(Sfun.Data(),"q")) break;    //   To end, enter    q
         if(!strcmp(Sfun.Data(),".q")) break;   //   or .q
	     plotFun=new TF1(Sfun,Sfun,0.0,12.0);   // Function plotFun
	     NewMax=plotFun->GetMaximum();  NewMin=plotFun->GetMinimum(); 
	     plotFun->SetMaximum(Max(OldMax,NewMax)); plotFun->SetMinimum(Min(OldMin,NewMin));
	     plotFun->Draw(); plotFun->SetLineColor(3);plotFun->SetLineWidth(3);
	     for (int ind=0;ind<N_arch;++ind){
            archFun=new TF1(Archiv[ind],Archiv[ind],0.0,12.0); 
            archFun->Draw("SAME"); 
	     }
	     c1->Modified();	c1->Update();  gSystem->ProcessEvents();
	     OldMax=plotFun->GetMaximum();  OldMin=plotFun->GetMinimum();    	     
	}
	//gROOT->ProcessLine(".q");
}
