//================    small.C      small data file test 
{  
   ifstream m_in;
   m_in.open("small.dat.txt");
   double x,y,z;
   int nlines = 0;
   int counter=0;
   while (1) {
      m_in >> x >> y >> z;
      if (!m_in.good()) break;      
      if (counter==2) printf("%dth line: x=%8f, y=%8f, z=%8f\n",nlines,x,y,z);
      nlines++; counter++;
      if (counter==3) counter=0; // prints every 3. line
   }
   printf("==========\nThe file has %d lines\n", nlines);
}
//===================   end of small.C
