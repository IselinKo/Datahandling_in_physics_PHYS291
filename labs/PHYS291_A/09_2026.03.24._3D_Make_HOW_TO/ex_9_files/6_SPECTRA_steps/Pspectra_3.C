{
   fit->GetParameters(Spar);
   for(N=0;  N<nfound;  N++) {
      fitvec[N] = new TF1("fitvec",fpeaks,0,1000,2+3*npeaks);
      fitvec[N]->SetNpx(1000);
      fitvec[N]->SetParameters(Zeros);   
      for(K=0;K<3;K++) fitvec[N]->SetParameter(2+3*N+K,Spar[2+3*N+K]);
      fitvec[N]->Draw("same");
    }
cout<<"\nThis is the last component Pspectra_3.C\n"; 
}

