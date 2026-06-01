#define CANVASES canvs=(TList*)gROOT->GetListOfCanvases();
#define MODIFS for(int i=0;i<canvs->GetEntries();i++) ( (TCanvas*) canvs->At(i) )->Modified();
#define UPDATE for(int i=0;i<canvs->GetEntries();i++) ( (TCanvas*) canvs->At(i) )->Update();
#define PROCESS gSystem->ProcessEvents();
#define  DrawNow() CANVASES; MODIFS; UPDATE; PROCESS;

  TCanvas*c1; TCanvas*c7;   TList *canvs;
  TF1 f1("f1","4/(4+x**2)",-5,5);
  TF1 f2("f2","1/(2+2*x**2)",-5,5);
  TF1 f3("f3","exp(-0.2*x**2)",-5,5);

void vgraph_interacDEF(){

  int Idec; char Cdec;

  c1=new TCanvas("c1","prim",50,100,600,400); 
  f1.SetMinimum(0);  f1.Draw(); 
  
  DrawNow();   // Do the graphics

cout << "\n\n    Shown is function 1/(4+x**2)\n  which of the 2 following is closest?\n";
cout << "    enter 2 for 1/(2+2*x**2)     or       enter 3 for  exp(-2*x**2)    : ";
cin >> Idec;

    if(Idec<2 || Idec>3 ) {
	cout << "you entered a wrong number == " << Idec << "  I set it to 2 \n";
	Idec=2;          }

   if(Idec==2) f2.Draw("same"); else f3.Draw("same");

   DrawNow();   // Do the graphics

   cout << "Do you want to see the other comparison? - enter y or n  :  ";
   cin >> Cdec;
if (Cdec=='y'){ c7=new TCanvas("c7","comp",600,100,600,400);
                c7->cd();f1.Draw();               
                if(Idec==3) f2.Draw("same"); else f3.Draw("same");}
   DrawNow();   // Do the graphics               
}

