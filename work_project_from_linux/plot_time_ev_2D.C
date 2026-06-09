{
// this file creates a time evolution of one brain slice
// RUN IN ROOT

TFile *f = new TFile("fmri_val1_t42.root");
TTree *tree = (TTree*)f->Get("brain");
TCanvas *c = new TCanvas("c","fMRI",800,700);
gStyle->SetPadRightMargin(0.15);
gStyle->SetPadLeftMargin(0.15);
c-> SetRightMargin(0.18);

// Get global mean via a temporary histogram
tree->Draw("intensity>>htemp", "", "goff");
TH1F *htemp = (TH1F*)gDirectory->Get("htemp");
Double_t mean = htemp->GetMean();
cout << "Global mean intensity: " << mean << endl;

// choose even slice (must match downsampling)
int slice;
cout << "Enter z-slice to plot (even number 0-78): ";
cin >> slice;

// loop over time 
for (int t = 0; t < 42; t++)
{
    delete gDirectory->Get("h"); // to prevent memory buildup


    tree->Draw(
        "y:x>>h(32,-10,100,32,-5,120)",
        Form("abs((intensity-%f)/%f) *(abs(z-%d)<2 && t==%d)", mean, mean, slice, t),
        "colz"
    );

    TH2F *h = (TH2F*)gDirectory->Get("h");

    h->SetTitle(
        Form("Brain Slice z=%d   t=%d   (%.2f sec)",
        slice,
        t,
        t*0.72)
    );
    
    h->SetMinimum(0);
    h->SetMaximum(1);

    h->GetXaxis()->SetTitle("x");
    h->GetYaxis()->SetTitle("y");
    h->GetZaxis()->SetTitle("Intensity - Absolute Relative Deviation");
    h->GetZaxis()->SetTitleOffset(1.6);
    h->SetStats(0);
    
    h->Smooth();
    h->Draw("colz");

    gPad->Update();
    gSystem->Sleep(200);
}
}