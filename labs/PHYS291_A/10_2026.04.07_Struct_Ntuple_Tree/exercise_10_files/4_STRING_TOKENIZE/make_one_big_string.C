{
    cout << "many lines to a mammut single string\n";
    string line1="many numbers";
    string Spa=" ";
    string line2="one two three";
    string line3="four five six";
    string line4="seven eight nine";
    string TheText=line1 + Spa + line2 + Spa+ line3 + Spa + line4 + Spa;
    string Input;
    cout << "enter a line with a sentence, several words or numbers\n";
    getline(cin,Input);
    TheText = TheText + Input + Spa;
    cout << "enter a line with a sentence, several words or numbers\n";
    getline(cin,Input);
    TheText = TheText + Input + Spa;
    cout << "\n\nHere comes the accumulated long string:\n";
    cout << TheText << endl;
}
