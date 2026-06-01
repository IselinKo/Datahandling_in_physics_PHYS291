{
   npeaks = 0;

   Double_t *xpeaks = s->GetPositionX();
   for (p=0;p<nfound;p++) {
      Double_t xp = xpeaks[p];
      Int_t bin = h->GetXaxis()->FindBin(xp);
      Double_t yp = h->GetBinContent(bin);
      if (yp-TMath::Sqrt(yp) < fline->Eval(xp)) continue;
      par[3*npeaks+2] = yp;
      par[3*npeaks+3] = xp;
      par[3*npeaks+4] = 3;
      npeaks++;
   }
   printf("Found %d useful peaks to fit\n",npeaks);
   printf("Now fitting: Be patient\n");
   TF1 *fit = new TF1("fit",fpeaks,0,1000,2+3*npeaks);
   //we may have more than the default 25 parameters
   TVirtualFitter::Fitter(h2,10+3*npeaks);
   fit->SetParameters(par);
   fit->SetLineColor(kGreen);
   fit->SetLineWidth(5);
   fit->SetNpx(1000);
   h2->Fit("fit");
cout<<"\nContinue by:\n  .x Pspectra_3.C \n"; 
}



