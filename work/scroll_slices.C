{
    TFile *f = new TFile("fmri_val1_t42.root");
    TTree *tree = (TTree*)f->Get("brain");
    TCanvas *c = new TCanvas("c","fMRI",800,700);

    // Get global mean via a temporary histogram
    tree->Draw("intensity>>htemp", "", "goff");
    TH1F *htemp = (TH1F*)gDirectory->Get("htemp");
    Double_t mean = htemp->GetMean();
    cout << "Global mean intensity: " << mean << endl;

    c-> SetRightMargin(0.18);

    //gStyle->SetPadRightMargin(1);
    //gStyle->SetPadLeftMargin(1);

    for (int slice=0; slice<78; slice += 2)
    {
        tree->Draw(
            "y:x>>h(32,-10,100,32,-5,120)",
            Form("abs((intensity-%f)/%f) *(abs(z-%d)<2 && t==0)", mean, mean, slice), //relative deviation from the global mean intensity
            "colz"
        );

        TH2F *h = (TH2F*)gDirectory->Get("h");

        h->SetMinimum(0);
        h->SetMaximum(1);

        h->SetTitle(Form("Brain Slice z=%d",slice));
        h->GetXaxis()->SetTitle("x");
        h->GetYaxis()->SetTitle("y");
        h->GetZaxis()->SetTitle("Intensity - Absolute Relative Deviation");

        h->Smooth();
        h->SetStats(0);
        h->Draw("colz");

        gPad->Update();

        gSystem->Sleep(70);
    }
}