// file run in ROOT
// this file converts text file .cvs to root file .root

{
TTree *tree = new TTree("brain","fmri");

tree->ReadFile(
    "../fmri_val1_t42.csv",
    "x/I:y/I:z/I:t/I:intensity/F",
    ','
);

TFile f("fmri_val1_t42.root","RECREATE");

tree->Write();

f.Close();

    cout << "Done!" << endl;
}