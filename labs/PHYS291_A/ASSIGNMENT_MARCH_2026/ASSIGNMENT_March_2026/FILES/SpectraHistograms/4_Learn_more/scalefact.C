{
//    For functions defined by string (gfun3)
//    Make a function  behaving as a multiple 
//          gfun3      ->     Const * gfun3
//    The solution
//                "[5]*(" + gfun3 + ")"
//
    TString gfun1 = "[0]-[1]*x";
    TString gfun2 = "[2] * exp(- (x-[4])*(x-[4]) * [3] )";
    TString gfun3 = gfun1 + "+" + gfun2;
    TF1 *bckgaus=new TF1("bckgaus",gfun3,-4.0,4.0);

    bckgaus->SetParameter(0,3);
    bckgaus->SetParameter(1,0.4);
    bckgaus->SetParameter(2,3);
    bckgaus->SetParameter(3,3.0);    
    bckgaus->SetParameter(4,-2.0);

cout << "Function bckgaus\n " << gfun3 <<endl;

TString  multip;
multip = "[5]*(" + gfun3 + ")";
cout << "Function multiply\n " << multip <<endl;

TF1 *multiply=new TF1("multiply",multip,-4.0,4.0);

//  copy parameters  of  funct. bckgaus  to  funct multiply
for (int k=0; k<5; k++){    
    multiply->SetParameter( k,  bckgaus->GetParameter(k)  );
}
    multiply->SetParameter( 5, 0.5);
TCanvas *cfunSB = new TCanvas("cfunSB","Function",10,50,600,400);
TCanvas *cfunSC = new TCanvas("cfunSC","Function",350,50,600,400);

cfunSB->cd();
bckgaus->Draw();
bckgaus->SetMinimum(0);   // to start plot from y=0
multiply->Draw("SAME");
cfunSB->Modified();

cfunSC->cd();     //  Need more Curves ->  Make Clones
    multiply->Draw();
    multiply->SetMinimum(0);   // to start plot from y=0
    TF1 *extraF=(TF1*)multiply->Clone("extraF");
    TF1 *extraG=(TF1*)multiply->Clone("extraG");
    extraF->SetParameter( 5, 0.4);
    extraG->SetParameter( 5, 0.3);
    extraF->Draw("SAME");
    extraG->Draw("SAME");
cfunSC->Modified();
cout << "Use FuncPointer->GetFormula()->Print() \n";
extraG->GetFormula()->Print();
cout << "Used extraG->GetFormula()->Print() \n";
}