#include <cstring>
#include <iostream>

using namespace std;

int main()
{
    char str[] = "parrot,owl,sparrow,pigeon,crow";
    char delim[] = ",";
    cout << "The tokens are:" << endl;
    char *token = strtok(str,delim);
    while (token)
    {
        cout << token << endl;
        token = strtok(NULL,delim);
    }
    return 0;
}

