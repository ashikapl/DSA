// strings funtions
#include <iostream>
#include <string>
using namespace std;

int main()
{
    // length funtion
    string str = "ashika";
    cout << "Length is:- " << str.length() << endl;

    // empty funtion
    cout << "Is the string is empty or not:- " << str.empty() << endl;

    // push_back funtion
    str.push_back('A');
    cout << "Push-back:- " << str << endl;

    // pop_back funtion
    str.pop_back(); // here pop-back funtion remove last character from string
    cout << "Pop-back:- " << str << endl;

    // substr funtion
    string str2 = "My name is Ashika Panchal.";

    cout << "Find the element btwn 3 to 5 index:- " << str2.substr(3, 5) << endl;
    // 0 and 4 is index to find the word btwn this index

    // find funtion

    string sentence = "Hello kese hai aap log";
    string word = "Hello";

    cout << "find the value is in 1st string or not:- " << sentence.find(word) << endl;
    // it return index value that where the word is put

    // replace funtion
    string str3 = "jeee";

    cout << "Replace value btwn 0 to 5 index:- " << sentence.replace(0, 5, str3) << endl;
    // 0 is starting index and 5 is ending index and str3 string to change the word

    // erase funtion

    cout << "Erase the 0 to 5 index character:- " << sentence.erase(0, 5) << endl;
    // to erase 0 to 5 character from the sentence

    return 0;
}