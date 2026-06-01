
{
  char str[] ="- This, and that,  sample string.";
  char * pch;
  TString tokens[100];    // added    why?
  int Count=0;            // added
  printf ("Splitting string \n\"%s\" \n into tokens:\n",str);
  pch = strtok (str," ,.-");
  while (pch != NULL)  {
    printf ("%s\n",pch);   
    tokens[Count]=pch; Count=Count+1;
    pch = strtok (NULL, " ,.-");
  }
  cout << "=================================\nreversed order\n";
  for (int k=Count;k>0;k=k-1){
    cout << tokens[k-1] << " ";
  }
  cout << endl;

}
