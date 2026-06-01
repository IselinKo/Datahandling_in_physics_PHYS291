// C++ program to print words in a sentence
// Using getline() function

#include <iostream>
#include <sstream>
#include <string>

using namespace std;

int main()
{
    string sentence = "Hello World have a nice day";
    string word;
 
    istringstream iss(sentence);
    while (getline(iss, word, ' ')) {
        cout << word << endl;
    }
 
    return 0;
}
 
