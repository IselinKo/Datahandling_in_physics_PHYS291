
{

//  Here we define our 3 nice curves which we shall
//  work with in different ways

//  Basic multiplot we did before

   int nlines = 0;
   ofstream m_out;
   m_out.open("graphsdata.txt");

   double x,y,z,w;
   for(int m=0; m<100; m++){ 
       x=m*0.06;
       y=sin(2*x)*exp(-0.3*x);
       z=cos(2.5*x)*exp(-0.4*x);
       w=0.7*sin(1.5*x)*exp(0.1*x);
       m_out <<x<<" "<<y<<" "<<z<<" "<<w<<endl;
       cout <<x<<" "<<y<<" "<<z<<" "<<w<<endl;
     }
   m_out.close();
}

