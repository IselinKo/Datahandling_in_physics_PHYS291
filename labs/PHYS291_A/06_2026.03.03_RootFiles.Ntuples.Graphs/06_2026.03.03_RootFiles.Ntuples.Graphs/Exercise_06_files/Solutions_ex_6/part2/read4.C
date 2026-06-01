
//  read4.C
{
   ifstream m_in;
   m_in.open("test4.txt");

   int nlines=0;
   double x,y;
   while (1) {
      m_in >> x >> y;
      if (! m_in.good()) break; 
      cout << x << " " << y << endl;    
      nlines++;
   }
   printf("==========\nThe file has %d lines\n", nlines);
   m_in.close();
}


