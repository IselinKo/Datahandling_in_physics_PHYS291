{
  TF1 efunc("efunc","exp(-[0]*(x-[1])**2)",0.,5.);
  efunc.SetParameter(0,1.0);      efunc.SetParameter(1,3.0);

  double values[1000];
  for (int i=0;i<1000;i++) {
     values[i]=efunc.GetRandom();
     } 

  TCanvas * C0=new TCanvas("C0","C0 canvas");
  TH1F * h = new TH1F("h","histogram 100",100,0.,5.);
  for (int i=0;i<1000;i++) {h->Fill(values[i]);}
  C0->cd();  h->Draw();

  TCanvas * C1=new TCanvas("C1","C1 canvas");
  TH1F *h1 = new TH1F("h1","histogram 15 bins",15,0.,5.);
  for (int i=0;i<1000;i++) {h1->Fill(values[i]);}
  C1->cd(); h1->Draw();

  TCanvas * C2=new TCanvas("C2","C2 canvas");
  TH1F *h2 = new TH1F("h2","histogram 40 bins",40,0.,5.);
  for (int i=0;i<1000;i++) {h2->Fill(values[i]);}
  C2->cd(); h2->Draw();

/*   Alternative
for (int i=0;i<1000;i++) {h->Fill(efunc.GetRandom());}
*/
}
