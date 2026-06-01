// this file creates a 2d plot of a brain slice

{
TFile *f = new TFile("fmri_val1_t42.root");
TTree *tree = (TTree*)f->Get("brain");
TCanvas *c = new TCanvas("c","fMRI", 800,700);

gStyle->SetPadLeftMargin(0.15);
c-> SetRightMargin(0.18);

// Get global mean via a temporary histogram
tree->Draw("intensity>>htemp", "", "goff");
TH1F *htemp = (TH1F*)gDirectory->Get("htemp");
Double_t mean = htemp->GetMean();
cout << "Global mean intensity: " << mean << endl;

//choose slice of even number (due to downsampling)
int slice;
cout << "Enter z-slice to plot (even number 0-76): ";
cin >> slice;

// create histogram
tree->Draw(
    "y:x >> h(32,-10,100,32,-5,120)",
    Form("abs((intensity-%f)/%f) *(abs(z-%d)<2 && t==0)", mean, mean, slice),
    "colz"
);

TH2F *h = (TH2F*)gDirectory->Get("h");

h->SetTitle(Form("Brain Slice z=%d",slice));

h->GetXaxis()->SetTitle("x");
h->GetYaxis()->SetTitle("y");
h->GetZaxis()->SetTitle("Intensity - Absolute Relative Deviation");

h->Smooth();
h->SetStats(0);
h->Draw("colz");

}