{
//   fitting_graph.C  save as fitting_graph.C run as : root fitting_graph.C 
//   example of fitting a graph
//
float xx[50], yy[50];
int n=25; int i;  
//    try  n=25; and modify below 2*(0.5+gRand ... and cos(0.2*i) 
//    Could add   gRandom->SetSeed();  // now allways the same sequence
cout << "\n\nFitting a randomly displaced  cos(0.1*x)\n";
//
   xx[0]=0.0; yy[0]=1.0;
   for(i=1;i<n;i++){
     xx[i]=xx[i-1]+2*(0.5+gRandom->Rndm());
     yy[i]=(1.0+0.1*gRandom->Rndm())*cos(0.2*i);
   }
gRandom->SetSeed();
TGraph * grcos = new TGraph(n,xx,yy);
grcos->SetTitle("Randomly displaced points of cos(0.1*x)");
grcos->SetMarkerStyle(5);
grcos->SetMarkerSize(1);
TCanvas *cfit = new TCanvas("cfit","Fit Graph",700,150,600,400);
TCanvas *Cpoint = new TCanvas("Cpoint","Data Graph",50,150,600,400);
Cpoint->cd();
grcos->Draw("AP");

TF1 *ffunc = new TF1("ffunc","[0]*cos([1]*x)",0,50.0);
ffunc->SetParameter(0,0.001);   // Fit needs any NONZERO value !! TRY (0,0.0)
cout << "\n----------------------------------------\n";
cout << "\nStarting values for p0 and p1 are: \n";
cout<<"p0="<<ffunc->GetParameter(0)<<"  p1="<<ffunc->GetParameter(1)<<endl;

TGraph * grcosf = new TGraph(n,xx,yy);
grcosf->SetTitle("The points fitted by p0 * cos(p1*x)");
grcosf->SetMarkerStyle(4);
grcosf->SetMarkerSize(1);

cfit->cd();
grcosf->Draw("AP");
grcosf->Fit("ffunc");
cout << "\n----------------------------------------\n";
cout << "\nFinal  values for p0 and p1 are: \n";
cout<<"p0="<<ffunc->GetParameter(0)<<"  p1="<<ffunc->GetParameter(1)<<endl;
// Cpoint->cd();  Cpoint->Print("Cpoint.png"); 
//  cfit->cd();    cfit->Print("fit.png"); // for pictures
}

