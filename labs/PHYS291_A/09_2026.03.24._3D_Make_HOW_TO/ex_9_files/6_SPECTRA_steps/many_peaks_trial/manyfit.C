{
TCanvas * Tc2=new TCanvas("Tc2","Tc2",500,10,600,300);

TF1 *Fitf2= new TF1("Fitf2",BigFun,0,20);
for(i=0;i<2+3*np;i++) {  Fitf2->SetParameter(i,0);}
for(i=0;i<np;i++) { v=2+3*i; Fitf2->SetParameter(v,800.0); }
for(i=0;i<np;i++) { v=4+3*i; Fitf2->SetParameter(v,1.5+2.7*i); }
for(i=0;i<np;i++) { v=3+3*i; Fitf2->SetParameter(v,1.0); }

Fitf2->SetParameter(19,18.0);
Fitf2->SetParameter(0,400.0);
Fitf2->SetParameter(1,20.0);

TF1 *remf2= new TF1("remf2",BigFun,0,20);
for(i=0;i<2+3*np;i++) {  remf2->SetParameter(i,0);}
for(i=0;i<np;i++) { v=2+3*i; remf2->SetParameter(v,800.0); }
for(i=0;i<np;i++) { v=4+3*i; remf2->SetParameter(v,1.5+2.7*i); }
for(i=0;i<np;i++) { v=3+3*i; remf2->SetParameter(v,1.0); }


remf2->SetParameter(0,400.0);
remf2->SetParameter(1,20.0);
remf2->SetParameter(19,18.0);

remf2->SetMinimum(0);
Tc2->cd();remf2->Draw();

Tc->cd(2);
his->Fit(Fitf2);




//==================================================
// TCanvas * Tc3=new TCanvas("Tc3","Tc3");


TF1 *Fitf= new TF1("Fitf",BigFun,0,20);
for(i=0;i<2+3*np;i++) {  Fitf->SetParameter(i,0);}
for(i=0;i<np;i++) { v=2+3*i; Fitf->SetParameter(v,800.0); }
for(i=0;i<np;i++) { v=4+3*i; Fitf->SetParameter(v,1.5+2.7*i); }
for(i=0;i<np;i++) { v=3+3*i; Fitf->SetParameter(v,1.0); }

Fitf->SetParameter(19,18.0);
Fitf->SetParameter(0,400.0);

TF1 *remf= new TF1("remf",BigFun,0,20);
for(i=0;i<2+3*np;i++) {  remf->SetParameter(i,0);}
for(i=0;i<np;i++) { v=2+3*i; remf->SetParameter(v,800.0); }
for(i=0;i<np;i++) { v=4+3*i; remf->SetParameter(v,1.5+2.7*i); }
for(i=0;i<np;i++) { v=3+3*i; remf->SetParameter(v,1.0); }


remf->SetParameter(0,400.0);
remf->SetParameter(1,20.0);


Tc->cd(2);
his->Fit(Fitf);
Tc->Show();


}





