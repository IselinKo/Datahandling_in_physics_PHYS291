  /// Main file, run this to produce plots.
  
  { 
   TString filname[100];        //  Many files
   TString Histname[1000];      //  and same number Histograms
   int NFound;                  //  Total count of histo
   TFile   *rfile[100];
   TString canvname[1000];      //  Many more TCanvases
   TH1F * Nhist[1000];          //  (pointers to them)
   double MaxVal[1000];         // At present the only value fetched from Hist

   TString ObjName;     // only one 
   TString ObjTitle;    // OBJect treated
   TString ObjClass;    // only one  ObjName, ObjTitle, ObjClass
   TList *LKEYS;        // list of KEYs in a file - only one list is needed    
   TKey * mykey;        // LKEYS  and mykey are there to handle KEY in the list  
   ifstream instr;      // only one input list is needed  
   int N_of_keys;       // The number of entries in the given file
   int N_of_hist;       // The number of entries which are histograms
   int Isleep=1;   
   int Nsecs=1;         //       if (Isleep) sleep(Nsecs);
   int hitKEY=0;  
   string line;         //       if (hitKEY) getline(cin,line);
     
 
   system("ls *.root > rootfileslist.txt");   // make the list of root files
   instr.open("rootfileslist.txt");           // open for reading
   int nfiles = 0;  int i=0; int kk=0;        // kk - histograms
   

   while (1)  {               // root files obtained from rootfileslist.txt
      instr >> filname[i]; if (!instr.good()) break;nfiles++; i++;}

   for (i=0;i<nfiles;i++) {    //  i=0;
      cout << "====================================================\n";
      cout << "file No. " << i << "  filename: "<< filname[i] << endl;    
      rfile [i] = new TFile (filname[i]);    //  rfile[i]->ls();  not needed
      LKEYS = (TList*) rfile[i]->GetListOfKeys();
      N_of_keys =  LKEYS->GetEntries();  N_of_hist=0;
      for (int k=0; k < N_of_keys; k++ ) {
           mykey = (TKey*) LKEYS->At(k) ;
           ObjClass=mykey->GetClassName();
           ObjName=mykey->GetName();
           ObjTitle=mykey->GetTitle();
           cout << " Class string: " << ObjClass;
           cout << " Obj Name: " << ObjName;
           cout << " Title: " << ObjTitle ;
           cout << " File: " << filname[i] << endl;
         if (   ObjClass=="TH1F"  ) {
             canvname[kk] = filname[i]+"____"+ObjName;
             Histname[kk]=ObjName;
             Nhist[kk] = (TH1F*) rfile[i]->Get(Histname[kk]);
             Nhist[kk]->SetTitle(canvname[kk]);    
             MaxVal[kk]=Nhist[kk]->GetMaximum();  
		
		//call on hist_fit func to create plots
	   	hist_fit(filname[i],ObjName);  

             if (Isleep) sleep(Nsecs);  
             if (hitKEY) getline(cin,line);

             N_of_hist++; kk++;  // increase the count of histograms in this file         
           }        //  if the class  is a histogram TH1F
      }    // ends loop over  the KEYs in the file
      cout << "In No. " << i << " name: "<< filname[i]<<" found "<< N_of_hist << " histograms\n";     
 
    }   // ends loop over files   for(i=0;i<nfiles;i++) 
  NFound=kk;   //  Total number of TH1F histograms
  
  //    OUTPUT   

  cout << "\n=========================================================\n";
  cout << nfiles << " files processed  " <<  NFound << "histograms TH1F  found\n";
  cout << "=========================================================\n";

   for( int kk=0; kk<NFound; kk=kk+1) {
       printf("%4d  %30s   max:  %13.2f\n",kk+1, canvname[kk].Data(), MaxVal[kk]); 

   }
}

// ------------------------------------
// Fitting histograms
// ------------------------------------

void hist_fit(TString filenam, TString histnam, int printfl = 0) 
{    

// get the city name from the filename
TString cityname = filenam;
cityname.ReplaceAll(".root", "");

TFile *ff= new TFile(filenam); //  Opening the file.root in filenam 

int h=gRandom->Integer(100);
TCanvas *cfuncn = new TCanvas(histnam+"fun",histnam+" Fitting Functions",h+400,500-h,700,500);
TCanvas *chistn = new TCanvas(histnam+"main",histnam+" Histogram from file",h+30,h+30,700,500);
TCanvas *chist2 = new TCanvas(histnam+"his2",histnam+" Cloned Histogram",h+600,h+30,700,500);

int printFL=0;         // Do not print PNG  printFL 0   Do print PNG  1
TH1F *hh1 = (TH1F*) ff->Get(histnam);     // Histogram get from file 
chistn->cd();  
    hh1->SetMinimum(0);
    hh1->Draw();

TH1F *hh2 = (TH1F*) hh1->Clone("hh2");    // Histogram cloned

chist2->cd();  
    TString Titl= cityname; //hh2->GetTitle(); cout << Titl<< endl;
    hh2->SetTitle(Titl+" - Cloned Histogram");
    hh2->Draw();

//  This is exactly copied from p1_hist.C   - Linear background and Gauss Peak

TF1 *fitFun=new TF1("fitFun","[0]-x*[1]+[2]*exp(-(x-[4])*(x-[4])*[3])",0,8);
fitFun->SetParameter(0,4.0);      // Background linear const
fitFun->SetParameter(1,0.4);      // Background steep
fitFun->SetParameter(2,5.0);      // Peak size
fitFun->SetParameter(3,2.0);      // reverse peak width
fitFun->SetParameter(4,5.0);      // Peak position

TF1 *tryFun = (TF1*) fitFun->Clone("tryFun");   //  Need 2 functions 
tryFun->SetLineColor(kOrange);
tryFun->SetLineWidth(5);
  

chistn->cd(); 
hh1->Fit("tryFun"); 
tryFun=hh1->GetFunction("tryFun");   // assuring the fit
hh1->SetMinimum(0);


                   //  This not done for hh1 - Fit fails
chist2->cd();      //  fitFun() parameters "guessed" from the plot
fitFun->SetParameter(0, hh2->GetBinContent(1));
fitFun->SetParameter(2, hh2->GetMaximum() - hh2->GetBinContent(1));
hh2->Fit("fitFun");
fitFun=hh2->GetFunction("fitFun");   // assuring the fit

//  Optional: axis labels
chist2->cd();  
hh2->GetXaxis()->SetTitle("Values"); hh2->GetXaxis()->CenterTitle(true);
hh2->GetYaxis()->SetTitle("Counts"); hh2->GetYaxis()->CenterTitle(true);

//   Get and Draw the PEAK only - clone fit, set backgr zero
TF1 *peakOnly = (TF1*) fitFun->Clone("peakOnly"); 
peakOnly->SetParameter(0,0.0);           //  set backgr zero
peakOnly->SetParameter(1,0.0);
peakOnly->SetLineColor(kBlue); peakOnly->SetLineWidth(3); 
peakOnly->Draw("same");	


//        Get and Draw the BACKGROUND  only
TF1 *backgrnd = (TF1*) fitFun->Clone("backgrnd"); 
backgrnd->SetParameter(2,0.0);   //  Set the peak part  zero
backgrnd->SetLineColor(kOrange); backgrnd->SetLineWidth(4); 
backgrnd->Draw("same");	

cfuncn->cd();
tryFun=hh1->GetFunction("tryFun");
tryFun->SetMinimum(0); tryFun->SetLineColor(kOrange);tryFun->SetLineWidth(5);
tryFun->SetMaximum(hh1->GetMaximum());
tryFun->SetTitle(Titl +"     Fit Functions");
tryFun->Draw();
fitFun->Draw("SAME");

printf("\n-------------------------------------------------\n");
printf("Reporting the results\n");
printf("-------------------------------------------------\n");
double p0,p1,p2,p3,p4;
p0=fitFun->GetParameter(0); p1=fitFun->GetParameter(1);
p2=fitFun->GetParameter(2); p3=fitFun->GetParameter(3);
p4=fitFun->GetParameter(4);

//   Peak without background 
double peakPos; double peakVal; double width; double sigma;
peakPos=fitFun->GetParameter(4);
peakVal=fitFun->GetParameter(2);
sigma=1.0/sqrt(2.0*fitFun->GetParameter(3));
width=2.0*sqrt(2.0*log(2.0))*sigma;
printf("Peak position     %12.4lf \n", peakPos);
printf("Peak Value        %12.4lf \n", peakVal);
printf("Peak Width (FWHM) %12.4lf \n", width);


//   Fit parameters
printf("-------------------------------------------------\n");
printf("%12s %12s ","Filename", "histogram");
printf("%10s %10s %10s %10s %10s\n"," p0 "," p1 "," p2 "," p3 "," p4 ");
printf("%12s %12s ",filenam.Data(), histnam.Data());
printf("%10.2lf %10.2lf %10.2lf %10.2lf %10.2lf\n",p0,p1,p2,p3,p4);


//  output append to a file report.txt
FILE *Fo=fopen("report.txt","a");
fprintf(Fo,"%s \n",cityname.Data());
fprintf(Fo, "Peak position     %12.2lf \n", peakPos);
fprintf(Fo, "Peak Value        %12.2lf \n", peakVal);
fprintf(Fo, "Peak Width (FWHM) %12.2lf \n", width);
fprintf(Fo,"\n");
fclose(Fo);
chistn->Update();  chistn->Modified();  cfuncn->Update();  cfuncn->Modified();
chist2->Update();chist2->Modified();gSystem->ProcessEvents(); 
sleep(1);
//gROOT->ProcessLine(".x extragr_p2.C"); 
chist2->Update();chist2->Modified();gSystem->ProcessEvents(); 
sleep(1);
chistn->Close();  cfuncn->Close(); 
if(printFL) chist2->Print(filenam+"HIST_1.png");
if(printFL) chistn->Print(filenam+"nhist.png");
if(printFL) cfuncn->Print(filenam+"func.png");

//  To be run after the  p2_hist_fit.C 
//
// extra 4 plot  - adding the  FWHM  demonstration
// using the  Peak position, Peak Width (FWHM) 
// and the Peak Value - half   (Full Width at Half Maximum)

//chist2->cd();                           //   Make sure to plot in TCanvas chist2
double xa[2]; double ya[2];	
xa[0]=peakPos-width/2.0;  xa[1]=xa[0]; //    peakPos-width/2.0
ya[0]=0;  ya[1]=peakVal/2.0;           //    vertical

TGraph *gr1=new TGraph(2,xa,ya);
chist2->cd();        // assuring that we plot in the right TCanvas

gr1->Draw("same");

double xb[2]; 
xb[0]=peakPos+width/2.0;  xb[1]=xb[0];  //    peakPos+width/2.0
TGraph *gr2=new TGraph(2,xb,ya);        //    vertical
gr2->Draw("same");

double xc[2]; double yc[2];	             //        horizontal
xc[0]=peakPos-width/2.0;  xc[1]=peakPos+width/2.0;
yc[0]=peakVal/2.0;  yc[1]=peakVal/2.0;   //        peakVal/2.0

TGraph *gr3=new TGraph(2,xc,yc);
gr3->Draw("same");

double xm[2]; double ym[2];	
xm[0]=peakPos;  xm[1]=xm[0];   //    peakPosition, peakValue
ym[0]=0;  ym[1]=peakVal;       //    vertical

TGraph *gr4=new TGraph(2,xm,ym);
gr4->Draw("same");

  }
