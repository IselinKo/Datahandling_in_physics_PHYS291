{
// program to make a table of sin(x) and sin(2*x) - on (0,2*Pi)
using namespace std;
using namespace TMath;
cout << TMath::Pi() << endl; // check the TMath namespace
cout << Pi() << endl;    // check  using namespace  TMath  
double pi=Pi(); 
// Table N lines long; 

int N=20; int it=0; 
double delta=2*pi/(double)N; 
double x[100], sin_x[100], sin_2x[100];


//int z;
for (double z=0; z<2*pi+delta/2.0; z=z+delta){
    x[it] = z;
    sin_x[ it]=sin(z);
    sin_2x[it]=sin(2*z);   it++;
  }
     printf("  %7s  %10s  %10s \n","   x  ","  sin(x)","  sin(2 x) ");

for (int i=0; i<it; i++) {
	   printf("  %7.4f  %10.4f %10.4f \n", x[i], sin_x[it], sin_2x[i]);
  }
     printf("  %7s  %10s  %10s \n","   x  ","  sin(x)","  sin(2 x) ");

//  check by plot that you really get period and double period

  TGraph *SIN =  new TGraph(it,x,sin_x);
  TGraph *SIN2 = new TGraph(it,x,sin_2x);
  SIN->Draw("AC");
  SIN2->Draw("SAME");
}

