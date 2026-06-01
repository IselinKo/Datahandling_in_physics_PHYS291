{
//================  read, plot and make  basic.root basicX.root basicY.root basicZ.root
//   This should  be entered  - when you have written it  - into  
//                               readBasics.C
//
//                     work with this in   gedit  readBasics.C
// First try these lines in  a root session to check how it works

   TFile *fold = new TFile("basic.root");   // Note: NO RECREATE, default is READ
   fold->ls();

//  THIS IS MOST IMPORTANT
//         Get the objects from the file ( refer by their name )
//  get the ntuple   and try  simple histograms

   TNtuple *ntp  = (TNtuple*) fold->Get("ntuple"); 

//  each of these lines show a single histogram

      ntp->Draw("x");
      ntp->Draw("y");
      ntp->Draw("z");

//  But each  overwrites the previous

// We can have three windows  and change focus to them by c1->cd()  etc

TCanvas *c1= new TCanvas("c1","Canv 1",30,30,600,400);
TCanvas *c2= new TCanvas("c2","Canv 2",500,30,600,400);
TCanvas *c3= new TCanvas("c3","Canv 3",50,200,600,400);

c1->cd();   ntp->Draw("x>>hx","","HIST");
c2->cd();   ntp->Draw("y>>hy","","HIST");
c3->cd();   ntp->Draw("z>>hz","","HIST"); 

}
