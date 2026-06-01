
int black=0; int red=1;   int green=2; int yellow=3; 
int blue=4;  int magenta=5; int cyan=6;  int white=7; 
void ForGr(int COL) {printf("\033[1;%dm",30+COL);}
void BckGr(int COL) {printf("\033[%dm",40+COL);}
void ClearScr() {printf("\033[2J");}
void RESET() {printf("\033[0m");}
void GoToPos(int Line, int Colum) {printf("\033[%d;%dH", Line, Colum);}


void life2(){
//    matlab code      e.g.  m=20;
//    n = [m 1:m-1];  y north  bottom m  to top ....    periodic boundary
//    e = [2:m 1];    y east   left  1   to the right - east    
//    s = [2:m 1];    y south
//    w = [m 1:m-1];  x west
// initialize
//    X=rand(m,m);
// count neighbors for each
//    N = X(n,:) + X(s,:) + X(:,e) + X(:,w) +  X(n,e) + X(n,w) + X(s,e) + X(s,w);
// repeat update
//    X = (X & (N == 2)) | (N == 3);

    int I=0; int J=320; int K;

    int n[]={19,0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18}; // x north
    int w[]={19,0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18}; // y west
    int e[]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,0}; // y east
    int s[]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,0}; // x south

    char C[20][20];
    int X[20][20];   //  Integers 0 or 1
    int N[20][20];   //  number of live neighbors
    int np=20; int i; int j;

 // gRandom->SetSeed();
  for(i=0;i<np;i++) { for(j=0;j<np;j++){ 
 //    X[i][j] = (int)(gRandom->Rndm()<0.33); }}
       X[i][j] = 0; }}  
//  glider =    [0 1 0; 
//               1 1 0; 
//               1 0 1];
                  X[9][10]=1;  
    X[10][9]=1; X[10][10]=1;
    X[11][9]=1;             X[11][11]=1;
    int fgcol, bgcol;    // screen colors - can be changing
    fgcol=white;  bgcol=blue;
    ForGr(white); BckGr(blue); ClearScr(); 

for(I=0;I<12000;I++){    // very many steps   
     ClearScr(); 
     GoToPos(1,1);  


  for(i=0;i<np;i++) { for(j=0;j<np;j++){
      N[i][j]  = X[n[i]][j]    + X[s[i]][j]    + X[i][w[j]]    + X[i][e[j]] + 
             + X[n[i]][e[j]] + X[n[i]][w[j]] + X[s[i]][e[j]] + X[s[i]][w[j]] ; }}
    
  for(i=0;i<np;i++) { for(j=0;j<np;j++){  
        X[i][j] = (int)((X[i][j] && (N[i][j]==2))||(N[i][j]==3));}}


    for(i=0;i<np;i++) { for(j=0;j<np;j++){ 
        C[i][j] = (char)(32+56*X[i][j]); }}
   printf("\033[2J");
   for(i=0;i<np;i++) { for(j=0;j<np;j++){ 
        printf("%c ",C[i][j]); } printf("|\n");}
    printf("-----------------------------------------\n");
   
     usleep(100000);
     ClearScr();     
     printf("\n"); 
}
RESET();
system("ls -lrt");
gROOT->ProcessLine(".qq");
}
