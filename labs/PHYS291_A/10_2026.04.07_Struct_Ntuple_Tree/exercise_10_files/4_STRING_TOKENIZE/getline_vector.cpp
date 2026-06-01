#include <iostream>
#include <sstream>
#include <vector>
#include <string>
using namespace std;

int main() {
   // inputs
   string TheStr("alfa,beta,gamma");
   char split_char = ',';

   // work
   istringstream Tosplit(TheStr);
   vector<string> tokens;
   for (string each; getline(Tosplit, each, split_char); tokens.push_back(each));

   // now use `tokens`

   for(int i=0;i<tokens.size();i++) {cout << tokens[i] <<endl;}
}

