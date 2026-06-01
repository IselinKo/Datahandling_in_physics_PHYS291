
{   //  A little program combining terminal input and graphics
	//  Normally, graphics will not show until all terminal input is done
	//  You need to add  c1->Modified();c1->Update();gSystem->ProcessEvents();
	//  Where c1 is the canvas you are using
	TF1 *plotFun;
	TString Sfun="sin(x)"; string line;
	plotFun=new TF1(Sfun,Sfun,0.0,12.0); 
	plotFun->Draw(); c1->Modified();	c1->Update();   gSystem->ProcessEvents();
    while(1){
         cout << "Enter a formula, as e.g.       sin(x)*exp(-0.3*x)   or type q to exit\n--> ";
         getline (cin,line);                 //  using getline - to allow for spaces in formula
         Sfun=line;
         if(!strcmp(Sfun.Data(),"q")) break;    //   To end, enter    q
         if(!strcmp(Sfun.Data(),".q")) break;   //   or .q
	     plotFun=new TF1(Sfun,Sfun,0.0,12.0);   // Function plotFun
	     plotFun->Draw("SAME");
	     c1->Modified();	c1->Update(); // gSystem->ProcessEvents();
	}
//	gROOT->ProcessLine(".q");
}
