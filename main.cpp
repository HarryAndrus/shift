#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <cctype>


using namespace std;


string encrypt(string text, const vector<int>& shifts) {
    int i = 0;
    for (char &c: text) {
        c = isalpha(c) ? static_cast<char>(c - (isupper(c) ? 'A' : 'a') + shifts.at(i % shifts.size())) % 26 + (isupper(c) ? 'A' : 'a') : c; // NOLINT(*-narrowing-conversions)
        i++;
    }
    return text;

}

string decrypt(string encrypted, const vector<int>& shifts) {
    int i = 0;
    for (char &c : encrypted) {
        c = isalpha(c) ? static_cast<char>(c - (isupper(c) ? 'A' : 'a') - shifts.at(i % shifts.size()) + 26) % 26 + (isupper(c) ? 'A' : 'a') : c; // NOLINT(*-narrowing-conversions)
        i++;
    }
    return encrypted;


}

int main() {
    vector<int> key = {1,2,3,4,5};
    string test = "Hello there how are you doing?";

    string encrypted = encrypt(test, key);
    string decrypted = decrypt(encrypted, key);

    cout << "Encrypted Message: " << encrypted << endl;
    cout << "Decrypted Message: " << decrypted << endl;


}