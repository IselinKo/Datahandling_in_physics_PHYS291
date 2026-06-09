
{

TCanvas* c500 = new TCanvas("c500","Drawing to the WEB",10,10,600,600);

   char * fnames[100];      
   for(int k=0;k<100;k++) fnames[k]=new char[30];
   for(int k=0;k<100;k++) sprintf(fnames[k],"pict%d.png",k);

///////////////

FILE *outfil;
outfil=fopen("index.html","w");   //   opening   index.html   
   fprintf(outfil,"<html>\n");       //    starting HTML  printout    
   fprintf(outfil,"<head>\n");       //    head and title
   fprintf(outfil,"<title>\n");
   fprintf(outfil,"PHYS291 Project Spring 2026");
   fprintf(outfil,"</title>\n");

fclose(outfil);                             // close - to insert mathJax

system("cat mathjax.fil >>  index.html");

outfil=fopen("index.html","a");      //  reopen index.html
   fprintf(outfil,"</head>\n");

   fprintf(outfil,"<body style=");  //  specify the font and colors

   fprintf(outfil,"\"font-family:monospace; font-size: 14pt; "); 
   fprintf(outfil," color:#000000; background-color:#cbddf5\"> \n");

fprintf(outfil,"<br><b><big>Project PHYS291 - Iselin Kongsmark</big></b> \n");

// Text width fixed by a TABLE TRICK 

   fprintf(outfil,"<br><table width=1100><tr><td style=");
   fprintf(outfil,"\"font-family:monospace; font-size: 14pt\"> \n");

   fprintf(outfil,"<br>The purpose of this project is to visualize fMRI data representing brain activity in the Default Mode Network (DMN). This report presents two main visualizations: one where time is held constant while varying spatial coordinates, and one where spatial coordinates are held constant while varying time.\n");
   fprintf(outfil, "<br><br>\n");

   fprintf(outfil,"<br><b>Brief theory </b> \n");
   fprintf(outfil,"<br><br>\n");

   fprintf(outfil,"Magnetic Resonance Imaging (MRI) is a medical imaging technique that utilizes strong electromagnetic fields to produce detailed images of the body's internal structure, with excellent contrast between different tissue types [1]. In functional MRI (fMRI), a series of scans are collected over time to measure changes in blood flow and oxygenation levels related to neural activity [1], known as the BOLD signal.\n");
   fprintf(outfil,"<br><br>\n");

   fprintf(outfil,"From fMRI data, distinct networks of brain regions can be identified, each associated with different types of activity. One network of particular significance is the Default Mode Network (DMN), which is active during rest, daydreaming, and mind wandering. Research on the DMN has revealed a great deal about how large-scale functional brain networks are organized [2].\n");
   fprintf(outfil,"<br><br>\n");

   fprintf(outfil,"This project presents some simple visualizations of DMN fMRI data. The visualization will illustrate both how MRI produces images of the brain's internal structure and how the BOLD signal varies over time within the DMN. \n");
   fprintf(outfil,"<br><br>\n");

   fprintf(outfil,"<br><b>Preprocessing steps </b> \n");
   fprintf(outfil,"<br><br>\n");

   fprintf(outfil,"The raw fMRI data is stored in a NIfTI (.nii) file, with dimensions x, y, z, and t. Each voxel contains the recorded activity level at a given spatial location and time point. The voxels represent a spatial resolution of 2 mm$^3$ and the time resolution is 0.72 seconds between each scan. \n");
   fprintf(outfil, "<br><br>\n");

   fprintf(outfil,"Using the Python package NiBabel, the data was sampled and converted to a text file (CSV). Including all data points would result in a file of several GB, which is excessive for this project. A sampling interval of 2 was therefore applied along the x, y, and z axes, and the time axis was truncated to the first 42 time points. This corresponds to approximately 30 seconds of scan data.\n");
   fprintf(outfil, "<br><br>\n");

   fprintf(outfil,"The text file was next converted into a ROOT file, using the TTree structure which is efficient for plotting in ROOT. \n");
   fprintf(outfil, "<br><br>\n");

   fprintf(outfil, "<br><b> Histograms at constant time </b> \n");
   fprintf(outfil, "<br><br>\n");

   fprintf(outfil,"This section presents two-dimensional histograms of brain slices, where color encodes activity level. Three representative z-values are shown before a scrolling animation is displayed. The x, y, and t coordinates are held constant throughout. The script plot_2Dhist.C allows the user to input a z-value interactively; however, for the purpose of generating this report, fixed z-values were used.\n");
   fprintf(outfil, "<br><br>\n");

//                           Making the graphics

   int I=0;
   TF1 *func;  TString FUNC;
   
//////// from plot_2Dhist.C
TFile *f = new TFile("fmri_val1_t42.root");
TTree *tree = (TTree*)f->Get("brain");
//Find global mean intensity
tree->Draw("intensity>>htemp", "", "goff");
TH1F *htemp = (TH1F*)gDirectory->Get("htemp");
Double_t mean = htemp->GetMean();

// call the function plot_2Dhist defined at bottom of script
plot_2Dhist(c500, tree, mean, 20, 0);
c500->Print(fnames[I]); 

plot_2Dhist(c500, tree, mean, 40, 0);
c500->Print(fnames[I+1]);

plot_2Dhist(c500, tree, mean, 60,0);
c500->Print(fnames[I+2]);

   fprintf(outfil, "<div style=\"display:flex; gap:10px;\">\n");
   fprintf(outfil, "<img src=\"%s\" style=\"width:32%%\">\n", fnames[I]);
   fprintf(outfil, "<img src=\"%s\" style=\"width:32%%\">\n", fnames[I+1]);
   fprintf(outfil, "<img src=\"%s\" style=\"width:32%%\">\n", fnames[I+2]);
   fprintf(outfil, "</div>\n");
I += 3;

   fprintf(outfil,"<br><i> Figure 1: Brain slices at different z-values, t=0.</i> \n");
   fprintf(outfil,"<br><br>\n");

   fprintf(outfil,"Figure 1 shows brain cross sections at z = 20, 40 and 60 for time t = 0. The colorbar indicates the absolute relative deviation from the mean activity level, calculated as:  \n");
   fprintf(outfil,"<br><br>\n");
   
   fprintf(outfil," $$ \\bar{I} = |\\frac{ I - \\text{Global mean}} {\\text{Global mean}} | \\cdot 100 $$\n");

   fprintf(outfil," where $I$ is the voxel intensity and the global mean is taken over all voxels and all time points. Yellow zones indicate voxels whose intensity deviates most strongly from the global mean, regardless of direction. Blue zones are close to the global mean intensity. \n");
   fprintf(outfil,"<br><br>\n");

   fprintf(outfil,"To compensate for reduced spatial resolution due to sampling and to produce smoother plots, intensities were averaged over nearby slices and ROOT's built-in smoothing function was applied. \n");
   fprintf(outfil,"<br><br>\n");

   fprintf(outfil,"<br><b>Scrolling through all brain slices</b><br>\n");
   fprintf(outfil,"<br><br>\n");

   fprintf(outfil,"The animation in Figure 2 shows the z coordinate increasing with each new frame. This creates the effect of scrolling through the brain volume, similar to the slice-by-slice visualization used in CT imaging. \n");
   fprintf(outfil,"<br><br>\n");

// --- scroll through slices, save frames, make GIF ---
int frameCount = 0;
for (int slice = 0; slice < 78; slice += 2)
{
    plot_2Dhist(c500, tree, mean, slice, 0);
    c500->Print(Form("frame_%02d.png", frameCount));
    frameCount++;
}

system("convert -delay 20 -loop 0 frame_*.png scroll_animation.gif");
system("rm frame_*.png");  // clean up frames after GIF is made

   fprintf(outfil, "<br><br>\n");
   fprintf(outfil, "<img src=\"scroll_animation.gif\" style=\"width:50%%\"><br>\n");
   fprintf(outfil,"<br><i>Figure 2: Scrolling animation of brain slices at t=0.</i><br>\n");
   fprintf(outfil, "<br><br>\n");

   fprintf(outfil,"<br><b>Histograms with time evolution </b> \n");
   fprintf(outfil,"<br><br>\n");

   fprintf(outfil,"The following animations incorporate the time dimension to show how activity changes over time at fixed spatial locations. The z-values 20, 40, and 60 were chosen to match those shown in Figure 1. \n");
   fprintf(outfil,"<br><br>\n");

// --- time evolution of slice, save frames, make GIF ---
system("rm frameA_*.png frameB_*.png frameC_*.png combined_*.png"); //cleanup from previous runs (just in case)

for (int t = 0; t < 42; t++)
{
    plot_2Dhist(c500, tree, mean, 20, t);
    c500->Print(Form("frameA_%02d.png", t));

    plot_2Dhist(c500, tree, mean, 40, t);
    c500->Print(Form("frameB_%02d.png", t));

    plot_2Dhist(c500, tree, mean, 60, t);
    c500->Print(Form("frameC_%02d.png", t));

    // stitch the three side by side into one combined frame
    // resizing because of memory error for animation
    system(Form("convert frameA_%02d.png frameB_%02d.png frameC_%02d.png +append -resize 1200x combined_%02d.png", t, t, t, t));
}

system("convert -delay 72 -loop 0 $(ls combined_*.png | sort) timeev_animation.gif");
system("rm frameA_*.png frameB_*.png frameC_*.png combined_*.png");

   fprintf(outfil, "<img src=\"timeev_animation.gif\" style=\"width:98%%\"><br>\n");
   fprintf(outfil, "<br><i>Figure 3: Time evolution of brain slices z=20, 40, 60:</i><br>\n");
   fprintf(outfil, "<br><br>\n");

   fprintf(outfil,"In Figure 3, some regions show notably higher deviation from the mean than surrounding tissue.  For future projects, it would be interesting to investigate whether these regions correspond to areas know to be active during DMN.\n");
   fprintf(outfil,"<br><br>\n");

   fprintf(outfil, "If there was more time for this project, a better normalization strategy would be beneficial. The method used here divides by the global mean intensity across all voxels and time points. While this highlights voxels that deviate strongly from the overall average, it does not capture the temporal dynamics within individual voxels. A more suitable approach for detecting BOLD activation would be to normalize each voxel's time series by its own temporal mean, giving the relative signal change over time for that voxel. This would make it possible to observe how individual brain regions fluctuate around their own baseline, which is the gold standard in fMRI activation analysis.\n");
   fprintf(outfil,"<br><br>\n");

   fprintf(outfil, "<br><b>References</b><br><br>\n");
   fprintf(outfil, "[1] Kamel, R. J. (Ed.). <i>Fundamentals of Medical Physics: Principles and Applications.</i> 1st ed. AkiNik Publications, 2024. DOI: <a href=\"https://doi.org/10.22271/ed.book.2841\">https://doi.org/10.22271/ed.book.2841</a><br><br>\n");
   fprintf(outfil, "[2] Menon, V. (2023). 20 years of the default mode network: A review and synthesis. <i>Neuron</i>, 111(16), 2469-2487. <a href=\"https://doi.org/10.1016/j.neuron.2023.04.023\">https://doi.org/10.1016/j.neuron.2023.04.023</a><br><br>\n");

   fprintf(outfil,"</td></tr></table><br>\n");
 

  //  fprintf(outfil,"</body>\n");     // should be there
  //  fprintf(outfil,"</html>\n");      // but browsers are forgiving


   fclose(outfil);
   
   system("echo \"<br><br><b>The root macro root_to_webN.C producing this HTML report and plots </b>\" >> index.html");
   system("txtbox_white root_to_webN.C");
   system("cat root_to_webN.C.html >> index.html");
   system("txtbox_white about_html_2.txt");
   system("firefox  index.html  &");
   system("python3 -m http.server 8000 &");
   sleep(1);
   system("firefox  http://127.0.0.1:8000/  &");
}

void plot_2Dhist(TCanvas* c, TTree* tree, Double_t mean, int slice = 40, int t = 0)
{
gStyle->SetPadLeftMargin(0.15);
c-> SetRightMargin(0.18);

// create histogram
tree->Draw(
    Form("y:x >> h_%d_%d(32,-10,100,32,-5,120)", slice, t),
    Form("abs((intensity-%f)/%f) *(abs(z-%d)<2 && t==%d)", mean, mean, slice, t),
    "colz"
);
TH2F *h = (TH2F*)gDirectory->Get(Form("h_%d_%d", slice, t));


h->SetTitle(Form("Brain Slice z=%d   t=%d   (%.2f sec)", slice, t, t*0.72));
h->SetMinimum(0);
h->SetMaximum(1);

h->GetXaxis()->SetTitle("x");
h->GetYaxis()->SetTitle("y");
h->GetZaxis()->SetTitle("Intensity - Absolute Relative Deviation");
h->GetZaxis()->SetTitleOffset(1.6);

h->Smooth();
h->SetStats(0);
h->Draw("colz");
gDirectory->Delete(Form("h_%d_%d;1", slice, t));

}

