//  void pittfall()  
{
//     pitfall.C   - pitfalls and surprises
//     Compare with cloned.C  - where all is cloned
//
//     But note   - at the end - histograms keep own copy of the fit function
//     access by:  hB->GetFunction("plotFun")->GetParameter(3) 
//            or   hB->GetFunction("plotFun")->Eval(1.35)
//
TString backfunc = "[0]-x*[1]";   //  parameters  p0 .... p4  as [0],[1]....[4]
TString gausfunc = "+[2]*exp(-(x-[4])*(x-[4])*[3])"; // [2] size, [4] position

TF1 *plotFun=new TF1("plotFun",backfunc+gausfunc,0.0,8.0);   // Function plotFun
string dummy;    //  for ENTER
plotFun->SetParameter(0,4.0);
plotFun->SetParameter(1,0.3);
plotFun->SetParameter(2,4.0);
plotFun->SetParameter(3,6.0);
plotFun->SetParameter(4,4.0);

//  TCanvas *C0 = new TCanvas("C0","Comparing Fits",200,10,800,700);
//  C0->Divide(2,2);

TCanvas *C1 = new TCanvas("C1","Function start",50,50,400,350);
TCanvas *C2 = new TCanvas("C2","Histo 1",50,400,400,350);
TCanvas *C3 = new TCanvas("C3","Functions after",450,50,400,350);
TCanvas *C4 = new TCanvas("C4","Histo 2",450,400,400,350);

C1->cd();
plotFun->Draw();
C1->Modified();C1->Update();C2->Modified();C2->Update();
C3->Modified();C3->Update();C4->Modified();C4->Update();
gSystem->ProcessEvents();cout << "Hit enter to continue\n"; getline(cin,dummy);

//   end part 1

TH1F *hB = new TH1F("hB","Broad_peak",100,0,8);
plotFun->SetParameter(3,0.5);
hB->FillRandom("plotFun",30000);
hB->SetMinimum(0);
C2->cd();
hB->Draw();
C1->Modified();C1->Update();C2->Modified();C2->Update();
C3->Modified();C3->Update();C4->Modified();C4->Update();
gSystem->ProcessEvents();cout << "Hit enter to continue\n"; getline(cin,dummy);


plotFun->SetParameter(2,400.0);
plotFun->SetParameter(0,400.0);
hB->Fit(plotFun);
C1->Modified();C1->Update();C2->Modified();C2->Update();
C3->Modified();C3->Update();C4->Modified();C4->Update();
gSystem->ProcessEvents();cout << "Hit enter to continue\n"; getline(cin,dummy);

C1->Modified();C1->Update();C2->Modified();C2->Update();
C3->Modified();C3->Update();C4->Modified();C4->Update();


//   end part 2

plotFun->SetParameter(0,2.0);
plotFun->SetParameter(1,-0.3);
plotFun->SetParameter(2,4.0);
plotFun->SetParameter(3,4.8);
plotFun->SetParameter(4,2.0);

C3->cd();
plotFun->Draw();
C1->Modified();C1->Update();C2->Modified();C2->Update();
C3->Modified();C3->Update();C4->Modified();C4->Update();
gSystem->ProcessEvents();cout << "Hit enter to continue\n"; getline(cin,dummy);


TH1F *hA = new TH1F("hA","Narrow_Peak",100,0,8);
hA->FillRandom("plotFun",50000);
C4->cd();
hA->SetMinimum(0);
hA->Draw();

plotFun->SetParameter(0,400.0);
plotFun->SetParameter(2,400.0);

plotFun->SetMinimum(0);

hA->Fit(plotFun);
C1->Modified();C1->Update();C2->Modified();C2->Update();
C3->Modified();C3->Update();C4->Modified();C4->Update();
gSystem->ProcessEvents();cout << "Hit enter to continue\n"; getline(cin,dummy);

C1->Modified();C1->Update();C2->Modified();C2->Update();
C3->Modified();C3->Update();C4->Modified();C4->Update();


/////////////////////////////////////////////////////
//
//          Obtaining the FIT PARAMETERS
//          From the fitting function
//          Each histogram has a copy of the fit function
//
cout << "Each histogram keeps private clone of the fitting function\n\n";
cout << "Broad peak histogram hB      Narrow peak histogram hA\n\n";

cout <<  "Narrow inv_width: hA->GetFunction(\"plotFun\")->GetParameter(3) ";
cout << hA->GetFunction("plotFun")->GetParameter(3) << endl;

cout <<  "Broad  inv_width: hB->GetFunction(\"plotFun\")->GetParameter(3) ";
cout << hB->GetFunction("plotFun")->GetParameter(3) << endl;

cout << "Outer plotFun->GetParameter(3) " << plotFun->GetParameter(3) << endl;

cout << "\nNow type in  \n.x destroy_distrib.C \n which disturbes the good fits\n";
cout << "Hist hB:        hB->GetFunction(\"plotFun\")->GetParameter(3); \n";
cout << "modify it  and  hB->GetFunction(\"plotFun\")->SetParameter(3,mod); \n";
cout << "\n.x destroy_distrib.C \n";

/*
double p3=hB->GetFunction("plotFun")->GetParameter(3)
hB->GetFunction("plotFun")->SetParameter(3,2*p3)
p3=hA->GetFunction("plotFun")->GetParameter(3)
hA->GetFunction("plotFun")->SetParameter(3,0.3*p3)

C2->cd();hB->Fit(plotFun);
C4->cd();hA->Fit(plotFun);

*/
}
