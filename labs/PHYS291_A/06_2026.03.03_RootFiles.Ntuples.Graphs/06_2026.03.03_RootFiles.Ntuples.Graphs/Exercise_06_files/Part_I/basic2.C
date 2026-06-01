{
//     This will be basic1.C
//
//           Modifying   small.C    to work with  basic.dat.txt
//           The file  basic.dat.txt   must be downloaded
//
//================   basic1.C           reading basic.dat.txt 
//
//  1. trivial modifications - change name and which lines printed
//  change the name of the in-file
   ifstream m_in;
   m_in.open("basic.dat.txt");

   double x,y,z;
   int nlines = 0;
   int counter=0;
   
// This must be added 
//                     The limits -4,4 are just a hint; they work well

   TH1F *h1 = new TH1F("h1","x distribution",100,-4,4);   // histogram
   TNtuple *ntuple = new TNtuple("ntuple","data from ascii file","x:y:z");

//  the loop must be modified later to include TNtuple and histogram
   while (1) {
      m_in >> x >> y >> z;
      if (! m_in.good()) break;      
      if (counter==9) printf("%dth line: x=%8f, y=%8f, z=%8f\n",nlines,x,y,z);
	   h1->Fill(x);             // fill one x into the histogram 
	   ntuple->Fill(x,y,z);     // add a line into the ntuple                      
      nlines++; counter++;
      if (counter==10) counter=0; // prints every 10th line
   }
   printf("==========\nThe file has %d lines\n", nlines);


// after the loop is finished, draw the histogram

   h1->Draw();
}
