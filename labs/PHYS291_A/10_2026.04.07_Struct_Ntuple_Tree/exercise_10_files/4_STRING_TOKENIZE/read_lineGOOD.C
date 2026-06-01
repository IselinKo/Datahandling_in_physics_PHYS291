{
   //  C++ style file reading stop auto   (shortened version of readGOOD.C)
   //  in-file-stream called  m_in here
   //   using    getline (m_in,line);  cf  getline (cin,line); 
   //  stops on false  m_in.good() (i.e. when reading is NOT succesful) 
   ifstream m_in;
   m_in.open("article.txt");
   string line;    
   char LINE[256];
   n=0;
   while (1){   
         //   GETLINE ( STREAM, STRING ) 
         //   access by name.c_str()   
        getline (m_in,line);
         //   
       if ( !m_in.good()) break; 
         //  extra if, also needed by fgets()
       if (line.length() > 1 ) {
           n=n+1;
           strcpy(LINE, line.c_str() );
           cout << LINE << endl;
       }
   }
    cout << n << " lines from article.txt\n" ;
    m_in.close();  
}

