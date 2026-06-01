{
const int nrows=5; const int ncols=10; 


int img[nrows*ncols];
int * PP[nrows];
for (int i=0;i<nrows;i++) PP[i]=(img+i*ncols);
  // whole matrix 0s
  // via linear array img
  for (int i=0;i<nrows;i++) img[i]=0;
  // short diagonal set to 1s
  //   via matrix PP[i][j]
  for (int i=0;i<nrows;i++)  PP[i][i]=1;

  // Print the matrix P[i][j]
  //

  for (int i=0;i<nrows;i++) {
     for (int j=0;j<ncols;j++) {
          cout << PP[i][j] << "  "; }
     cout << endl;
  }
/*     The printout is 
 *
Processing doub_array.C...
1  0  0  0  0  0  0  0  0  0  
0  1  0  0  0  0  0  0  0  0  
0  0  1  0  0  0  0  0  0  0  
0  0  0  1  0  0  0  0  0  0  
0  0  0  0  1  0  0  0  0  0  
 *
 *
*/
}

