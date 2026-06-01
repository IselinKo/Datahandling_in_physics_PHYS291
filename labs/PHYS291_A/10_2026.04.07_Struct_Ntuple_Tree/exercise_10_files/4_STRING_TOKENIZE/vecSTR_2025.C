 
 { 
   // explicit  use istringstream getline - instead of - while(getline())

   string TheStr("alfa beta gamma delta eta zeta sigma rho");
   char split_char = ' ';

   istringstream Tosplit(TheStr);
   vector<string> tokens; int tr=1; string word="";
   
   while(tr){ word=""; 
              getline(Tosplit, word, split_char); tr=word.length();
              if(tr) tokens.push_back(word); }
    
   for(int i=0;i < tokens.size();i++) {cout << tokens[i] <<endl;}
}
 
