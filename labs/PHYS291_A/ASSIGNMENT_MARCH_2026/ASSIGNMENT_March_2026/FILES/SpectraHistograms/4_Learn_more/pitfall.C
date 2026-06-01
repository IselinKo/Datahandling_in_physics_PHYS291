//  void pitfall()  
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

TCanvas *cst0 = new TCanvas("cst0","Comparing Fits",200,10,800,700);
cst0->Divide(2,2);


cst0->cd(1);
plotFun->Draw();
cst0->Modified();cst0->Update();
gSystem->ProcessEvents();cout << "Hit enter to continue\n"; getline(cin,dummy);

//   end part 1

TH1F *hB = new TH1F("hB","Broad_peak",100,0,8);
plotFun->SetParameter(3,0.5);
hB->FillRandom("plotFun",30000);
hB->SetMinimum(0);
cst0->cd(3);
hB->Draw();
cst0->Modified();cst0->Update();
gSystem->ProcessEvents();cout << "Hit enter to continue\n"; getline(cin,dummy);


plotFun->SetParameter(2,400.0);
plotFun->SetParameter(0,400.0);
hB->Fit(plotFun);
cst0->Modified();cst0->Update();
gSystem->ProcessEvents();cout << "Hit enter to continue\n"; getline(cin,dummy);

cst0->Modified();cst0->Update();


//   end part 2

plotFun->SetParameter(0,2.0);
plotFun->SetParameter(1,-0.3);
plotFun->SetParameter(2,4.0);
plotFun->SetParameter(3,4.8);
plotFun->SetParameter(4,2.0);

cst0->cd(2);
plotFun->Draw();
cst0->Modified();cst0->Update();
gSystem->ProcessEvents();cout << "Hit enter to continue\n"; getline(cin,dummy);


TH1F *hA = new TH1F("hA","Narrow_Peak",100,0,8);
hA->FillRandom("plotFun",50000);
cst0->cd(4);
hA->SetMinimum(0);
hA->Draw();

plotFun->SetParameter(0,400.0);
plotFun->SetParameter(2,400.0);

plotFun->SetMinimum(0);

hA->Fit(plotFun);
cst0->Modified();cst0->Update();
gSystem->ProcessEvents();cout << "Hit enter to continue\n"; getline(cin,dummy);

cst0->Modified();cst0->Update();

cst0->Print("fits_6ALL.png");

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

cout << "\n\n        Try to click in top left graph \n\n";

}
