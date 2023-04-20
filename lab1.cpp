#include <iostream>
#include <fstream>

using namespace std;

void write_caesar(string str)
{
    ofstream file("caesar_encoded.txt");
    if (file.is_open())
    {
        file << str;
    }
}

void write_vigenere(string str)
{
    ofstream file("vigenere_encoded.txt");
    if (file.is_open())
    {
        file << str;
    }
}

// 97-122
void Caesar(string str, int key)
{
    cout << "String to encode: " << str << endl;
    key %= 26;

    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] + key > 'z') 
            str[i] -= 26;
        str[i] += key;     
    }

    cout << "Encoded string: " << str << endl;
    write_caesar(str);

    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] - key < 'a')
            str[i] += 26;
        str[i] -= key;
    }

    cout << "Decoded string: " << str << endl << endl;
}

void Vigenère(string str, string key)
{
    cout << "String to encode: " << str << endl;

    while (key.length() > str.length())
        key.pop_back();

    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] + (key[i % key.length()] - 'a') > 'z') 
            str[i] -= 26;
        str[i] += (key[i % key.length()] - 'a');
    }

    cout << "Encoded string: " << str << endl;
    write_vigenere(str);

    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] - (key[i % key.length()] - 'a') < 'a')
            str[i] += 26;
        str[i] -= (key[i % key.length()] - 'a');
    }

    cout << "Decoded string: " << str << endl;
}

void read_caesar()
{
    string str = "";
    string key = "";
    
    ifstream file("caesar.txt");
    if (file.is_open())
    {
        getline(file, str);
        getline(file, key);
    }

    int k = stoi(key);
    Caesar(str, k);
}

void read_vigenere()
{
    string str = "";
    string key = "";

    ifstream file("vigenere.txt");
    if (file.is_open())
    {
        getline(file, str);
        getline(file, key);
    }

    Vigenère(str, key);

}

int main()
{
    read_caesar();
    read_vigenere();
    //Caesar();
    //Vigenère();
    return 0;
}