
int black=0; int red=1;   int green=2; int yellow=3; 
int blue=4;  int magenta=5; int cyan=6;  int white=7; 
void ForGr(int COL) {printf("\033[1;%dm",30+COL);}
void BckGr(int COL) {printf("\033[%dm",40+COL);}
void ClearScr() {printf("\033[2J");}
void RESET() {printf("\033[0m");}
void GoToPos(int Line, int Colum) {printf("\033[%d;%dH", Line, Colum);}

string lin;  int cod;
void learn(){
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

//  Adjust terminal

BckGr(blue);   ClearScr(); ForGr(white);
cout << "Line 1  Adjust terminal to see all the 28 lines ============ \n";
for (int I=2;I<28;I++) {cout << "Line "<<I << endl;if (I>10) usleep(200000);}
cout << "Line 28  Adjust terminal - see at least all 28 lines ============ \n";
cout << "Press ENTER when ready. ENTER for each step; q ENTER to exit ";  getline(cin,lin);


    int I=0; int J=20; int K;

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

for(I=0;I<11120;I++){


  for(i=0;i<np;i++) { for(j=0;j<np;j++){
    N[i][j]  = X[n[i]][j]    + X[s[i]][j]    + X[i][w[j]]    + X[i][e[j]] + 
             + X[n[i]][e[j]] + X[n[i]][w[j]] + X[s[i]][e[j]] + X[s[i]][w[j]] ; }}
    
  for(i=0;i<np;i++) { for(j=0;j<np;j++){  
        X[i][j] = (int)((X[i][j] && (N[i][j]==2))||(N[i][j]==3));}}


  for(i=0;i<np;i++) { for(j=0;j<np;j++){
        C[i][j] = (char)(32+56*X[i][j]); }}
 
  for(i=0;i<np;i++) { for(j=0;j<np;j++){
  N[i][j]  = X[n[i]][j]    + X[s[i]][j]    + X[i][w[j]]    + X[i][e[j]] + 
           + X[n[i]][e[j]] + X[n[i]][w[j]] + X[s[i]][e[j]] + X[s[i]][w[j]] ; }}

   BckGr(blue);
   ClearScr(); 
   GoToPos(1,1);  
   //printf("\033[2J");
   BckGr(blue);

   for(i=0;i<np;i++) { for(j=0;j<np;j++){ 
        printf("%c ",C[i][j]); } printf("|\n");}
    printf("-----------------------------------------\n");
    printf("Living cells are marked by  X   \n");
    printf("Count neighbours   \n");
    printf("Living, but only 1 neighbor (too lonely) WILL DIE \n");
    printf("Living, with     2 neighbors, good life continues \n");
    printf("Living, with     3 neighbors, good life continues \n");    
    printf("Living, with     4, 5 neighbors,(too crowded) DIE  \n");
    printf("Empty cell with  3  neighbors - New cell is BORN   \n");

   getline(cin,lin); if(lin[0]=='q') break;

    for(i=0;i<np;i++) { for(j=0;j<np;j++){ 
        //  C[i][j] = (char)(32+(16+N[i][j])*X[i][j]); }}
        cod = 32;
        cod = cod + (int)(N[i][j]>0)*(16+N[i][j]);
        C[i][j] = (char)cod;   }}

     BckGr(red);
     ClearScr();
     GoToPos(1,1);
      BckGr(red);

   for(i=0;i<np;i++) { for(j=0;j<np;j++){
        printf("%c ",C[i][j]); } printf("|\n");}
    printf("-----------------------------------------\n");
    printf("Counted all neighbours for all cells  \n");
    printf("Only cells with at least one neighbour shown   \n");
    printf("Living, but only 1 neighbor (too lonely) WILL DIE \n");
    printf("Living, with     2 neighbors, good life continues \n");
    printf("Living, with     3 neighbors, good life continues \n");    
    printf("Living, with     4, 5 neighbors,(too crowded) DIE  \n");
    printf("Empty cell with  3  neighbors - New cell is BORN   \n");
   

   getline(cin,lin);  if(lin[0]=='q') break;

    for(i=0;i<np;i++) { for(j=0;j<np;j++){ 
        //  C[i][j] = (char)(32+(16+N[i][j])*X[i][j]); }}
        cod = 32;
        cod = cod + (int)(N[i][j]>0)*(16+N[i][j]);
        if (N[i][j]==2 && X[i][j]==0 ) cod= (int)'-';
        if (N[i][j]==1 || N[i][j]>3 ) cod= (int)'.';
 
        C[i][j] = (char)cod;   }}

     BckGr(red);
     ClearScr();
     GoToPos(1,1);
        BckGr(red);
   for(i=0;i<np;i++) { for(j=0;j<np;j++){
        printf("%c ",C[i][j]); } printf("|\n");}
    printf("-----------------------------------------\n");
    printf("Empty cells with 2 neighbours marked  -  \n");
    printf("All  cells with only 1 neighbour marked . \n");
    printf("Living, but only 1 neighbor (too lonely) WILL DIE \n");
    printf("Living, with     2 neighbors, good life continues \n");
    printf("Living, with     3 neighbors, good life continues \n");    
    printf("Living, with     4, 5 neighbors,(too crowded) DIE  \n");
    printf("Empty cell with  3  neighbors - New cell is BORN   \n");
  


   //  usleep(400000);
     getline(cin,lin);    if(lin[0]=='q') break;
      BckGr(blue);
     ClearScr();     
    // printf("\n"); 
}
RESET();
system("ls -lrt");
gROOT->ProcessLine(".qq");
}
