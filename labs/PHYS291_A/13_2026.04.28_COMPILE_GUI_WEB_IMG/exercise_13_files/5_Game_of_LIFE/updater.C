
int black=0; int red=1;   int green=2; int yellow=3; 
int blue=4;  int magenta=5; int cyan=6;  int white=7; 
void ForGr(int COL) {printf("\033[1;%dm",30+COL);}
void BckGr(int COL) {printf("\033[%dm",40+COL);}
void ClearScr() {printf("\033[2J");}
void RESET() {printf("\033[0m");}
void GoToPos(int Line, int Colum) {printf("\033[%d;%dH", Line, Colum);}
void Inverse() {printf("\033[7m");}
void Inv_end() {printf("\033[27m");}

void updater(){int I=0; int J=15; int K;
int i;  
K=J; int fgcol, bgcol;    // screen colors - can be changing

    fgcol=white;  bgcol=blue;
//  ForGr(fgcol); BckGr(bgcol); ClearScr(); 
    ForGr(white); BckGr(blue); ClearScr(); 

for(i=0;i<1111;i++){
     I++; J--;
     ForGr(fgcol); BckGr(bgcol);  ClearScr();
     GoToPos(2,20);  
     Inverse();  printf("%4d  sec ",I);  Inv_end();
     GoToPos(4,20);  printf("%4d until stop",J);
     GoToPos(22,20); printf("RUNS FOR %d seconds. ", K );     
     Inverse(); printf("  Try resizing terminal  \n");  
     Inv_end();
     sleep(1);
     ForGr(fgcol); BckGr(bgcol);  ClearScr();     
     printf("\n"); 
     if(I==4)   {fgcol=yellow;  bgcol=red;   }   //6
     if(I==8)  {fgcol=white;   bgcol=green; }  // 15
     if(I==12)  {fgcol=blue;   bgcol=white; }   // 22
     if ( !J ) break;  
}
gROOT->ProcessLine(".qq");

}
