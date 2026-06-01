//
//  test4.C
{
ofstream m_out;
m_out.open("test4.txt");
int nlines=7;
int k;
for (k=1; k< nlines+1; k++) {
   m_out << k <<" " << k << " " << k << " " << k  << endl;
   cout << k <<" " << k << " " << k << " " << k  << endl;
}
m_out.close();
}

