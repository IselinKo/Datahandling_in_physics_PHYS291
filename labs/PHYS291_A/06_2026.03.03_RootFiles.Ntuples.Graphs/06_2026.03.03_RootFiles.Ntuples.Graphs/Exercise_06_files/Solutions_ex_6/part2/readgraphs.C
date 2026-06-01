

//  read4.C  changed to  goes to readgraphs.C
{
   ifstream m_in;
   m_in.open("graphsdata.txt");

   int nlines=0;
   double x,y,z,w;
   double X[1000], Y[1000], Z[1000], W[1000]; 

   while (1) {
      m_in >> x >> y >> z >> w;
      X[nlines]=x;  Y[nlines]=y;  
      Z[nlines]=z;  W[nlines]=w;  
      if (! m_in.good()) break;  
      cout <<x<<" "<<y<<" "<<z<<" "<<w<<endl;  
      nlines++;
   }
   printf("==========\nThe file has %d lines\n", nlines);
   m_in.close();
   
   TGraph * gr1 = new TGraph( nlines, X, Y);
   TGraph * gr2 = new TGraph( nlines, X, Z);
   TGraph * gr3 = new TGraph( nlines, X, W);

   TMultiGraph *ThreeGr = new TMultiGraph();

//  and add the three graphs
//  using    ThreeGr->Add( grname );  
 
   ThreeGr->Add( gr1 );
   ThreeGr->Add( gr2 );
   ThreeGr->Add( gr3 );

//  The three graphs will be shown by
   ThreeGr->Draw("ACP");

}

