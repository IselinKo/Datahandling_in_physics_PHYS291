{
   TH1F *h2 = (TH1F*)h->Clone("h2");
   //Use TSpectrum to find the peak candidates
   TSpectrum *s = new TSpectrum(2*npeaks);
   Int_t nfound = s->Search(h,2,"",0.10);
   printf("Found %d candidate peaks to fit\n",nfound);
   //Estimate background using TSpectrum::Background
   TH1 *hb = s->Background(h,20,"same");
   if (hb) c1->Update();
   if (np <0) return;
   //estimate linear background using a fitting method
   c1->cd(2);
   TF1 *fline = new TF1("fline","pol1",0,1000);
   h->Fit("fline","qn");
   par[0] = fline->GetParameter(0);
   par[1] = fline->GetParameter(1);
cout<<"\nContinue by:\n  .x Pspectra_2.C \n";
}



