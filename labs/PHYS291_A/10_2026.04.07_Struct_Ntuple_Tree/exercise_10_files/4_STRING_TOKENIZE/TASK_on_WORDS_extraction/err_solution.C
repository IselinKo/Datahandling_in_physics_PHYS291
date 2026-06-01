{  //  Combining read_lineGOOD.C and  strtokMore.C examples
   //  
   //  Split lines in article.txt into single words, one word per line
   //
   //  C++ style file reading stop auto
   //  in-file-stream called  m_in here
   //  using    getline (m_in,line);  cf  getline (cin,line); 
   //  stops on false  m_in.good()  
   int nl=0; n_tok=0;
   string line;        // for reading
   char LINE[256];
   TString tokens[300];      // Number of words  10000 enough here
   char *str; str=LINE;      // array is pointer; str from strtok points to LINE
   char * pch;   

   ifstream m_in;
   m_in.open("article.txt");

   nl=0;
   while (1){   
         //   GETLINE ( STREAM, aSTRING ) 
         //   access by aSTRING.c_str()   
       getline (m_in,line);
         //   
       if ( !m_in.good()) break; 
       if (line.length() > 1 ) {
           nl=nl+1;
           strcpy(LINE, line.c_str() );    
 
           printf ("Splitting string \n\"%s\" \n into tokens:\n",str);
           pch = strtok (str," ,.-");
           while (pch != NULL)
              {
               printf ("%s    %d\n",pch, n_tok);   
               tokens[n_tok]=pch; n_tok=n_tok+1;
               pch = strtok (NULL, " ,.-");
              }
          }
   }
   m_in.close();  
   ofstream fout("words.txt");
   for (int k=0;k<n_tok;k=k+1){
       cout << tokens[k] << endl;
       fout << tokens[k] << endl;
    }
   
   cout << nl << " lines from article.txt gave n_tok words\n" ;
   fout.close()
   //  cout << "program finished with " <<  n_tok << " words\n" ;
}

