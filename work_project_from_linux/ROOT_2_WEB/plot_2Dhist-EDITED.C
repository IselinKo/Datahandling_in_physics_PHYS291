// this file creates a 2d plot of a brain slice
void plot_2Dhist(TCanvas* c, TTree* tree, Double_t mean, int slice = 40)
{
gStyle->SetPadLeftMargin(0.15);
c-> SetRightMargin(0.18);

// create histogram
tree->Draw(
    "y:x >> h(32,-10,100,32,-5,120)",
    Form("abs((intensity-%f)/%f) *(abs(z-%d)<2 && t==0)", mean, mean, slice),
    "colz"
);

TH2F *h = (TH2F*)gDirectory->Get("h");

h->SetTitle(Form("Brain Slice z=%d",slice));
h->SetMinimum(0);
h->SetMaximum(1);

h->GetXaxis()->SetTitle("x");
h->GetYaxis()->SetTitle("y");
h->GetZaxis()->SetTitle("Intensity - Absolute Relative Deviation");

h->Smooth();
h->SetStats(0);
h->Draw("colz");

}
