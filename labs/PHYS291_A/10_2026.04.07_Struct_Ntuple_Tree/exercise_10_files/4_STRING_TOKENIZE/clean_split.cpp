#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cstring>

using namespace std;

string clean(string spacy) {
   //  clean - takes away initial and trailing spaces, removes multiple spaces
   char Las=' '; int pos=0; int i;
   unsigned long slen=spacy.size();    //  works with 2 char[ ] arrays 
   char *Spac=new char[slen+1];   // slen+1
   char *Tigh=new char[slen+1];   // for (char)0
   strcpy(Spac, spacy.c_str() );       //  copies std::string to char Spac[ ]
   // First remove trailing spaces, to avoid one of them at the end
   for (i=slen-1;i>0;i--) {if (Spac[i]!=' ') break; Spac[i]=(char)0; }
   // Now copy if not space and if not multiple space
   for(i=0;i<slen;i++) { 
      if (Spac[i]!=' ' )  { Tigh[pos]=Spac[i]; pos++; Las=Spac[i]; continue;}
      if (  Las  !=' ' )  { Tigh[pos]=Spac[i]; pos++; Las=Spac[i];} // copies one space
      }
   Tigh[i]=(char) 0;
   string cl(Tigh);   delete[](Spac); delete[](Tigh); // avoid memoryleak
   return(cl);
}

vector<string> split(const string& Qstr, char delimiter) {
  vector<string> tokens;  
  size_t start = 0; size_t it;
  while (start < Qstr.size()) {
    it = Qstr.find(delimiter, start); cout << "it " << it << endl;
    if (it > Qstr.size())  { tokens.push_back(Qstr.substr(start)); break; }
    if (it < Qstr.size())  { tokens.push_back(Qstr.substr(start, it-start)); }
    start = it+1; }
  return tokens;
}

int main() {
   vector <string> parts;
   string INs="   one    two   three four five      ";
   cout << INs << "...__checking trailing" << endl;
   string Q= clean(INs);
   cout << Q << "...__checking trailing"  << endl;
   parts=split( Q, ' ');
   for (int i=0; i< parts.size(); i++) cout << parts[i] << "  length "<< parts[i].size() << endl;

   cout << "   Now repeats the same for a string without unnecessary spaces (checking) \n";

   vector <string> parts2;
   INs="six seven eight nine ten";
   cout << INs << "...__checking trailing" << endl;
   Q= clean(INs);
   cout << Q << "...__checking trailing"  << endl;
   parts2=split( Q, ' ');
   for (int i=0; i< parts2.size(); i++) cout << parts2[i] << "  length "<< parts2[i].size() << endl; 

   return(0);
}
