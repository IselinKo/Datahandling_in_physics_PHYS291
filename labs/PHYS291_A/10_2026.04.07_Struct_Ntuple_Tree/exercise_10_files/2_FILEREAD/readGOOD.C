{
   //  C++ style file reading stop auto
   //  in-file-stream called  m_in here
   //  using     m_in >> variables .....
   //  stops on false  m_in.good()  
   ifstream m_in;
   m_in.open("datain.txt");
   double x,y;
   int n=0;
   while (1){
       m_in >> x >> y ;
       if ( !m_in.good()) break; 
       n=n+1;
       printf(" %lf   %lf \n", x,y);
   }
   printf(" %d lines from datain.txt\n", n);
   m_in.close();
  m_in.open("datain.txt");
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
           sscanf(LINE, " %lf %lf", &x, &y);
           printf(" %lf   %lf \n", x,y);
       }
   }
    cout << n << " lines from datain.txt\n" ;
    m_in.close();  
}

