#include <iostream>
#include <map>
#include <sstream>
using namespace std;
int main()
{
    string sentence;
    cout << "Enter a sentence: ";
    getline(cin, sentence);
    map<string, int> freq;
    stringstream ss(sentence);
    string word;
    while(ss >> word)
        freq[word]++;
    cout << "\nWord Frequency\n";
    for(auto x : freq)
        cout << x.first << " : " << x.second << endl;
    return 0;
}
