// Unordered_Map STL
#include<iostream>
#include<unordered_map>
#include<string>
using namespace std;

int main()
{
    // creation
    unordered_map<string,int> mp;

    // insertion
    // first way to insert
    pair<string,int> p = make_pair("Baleno",10);
    mp.insert(p);

    // second way to insert
    mp["Alto"] = 5;

    // third way to insert
    pair<string,int> p1("Fortuner",9);
    mp.insert(p1);

    // Access
    cout << mp.at("Baleno") << endl;
    cout << mp["Fortuner"] << endl;

    cout << "Size of Map is: " << mp.size() << endl;

    if(mp.empty())
    {
        cout << "Map is empty..!" << endl;
    }
    else
    {
        cout << "Map is not empty..!" << endl;
    }

    // searching or finding
    cout << mp.count("Baleno") << endl; // search that Baleno is present or not ->its return 1 or 0(T or F)
    // finding
    if(mp.find("Fortuner") != mp.end()) // if fortuner end tk janese pehle mil gai then it is found
    {
        cout << "Fortuner is found" << endl;
    }
    else // otherwise map ke end tk pohoch gaye to fortuner nahi mili
    {
        cout << "Fortuner is not found" << endl;
    }

    cout << mp["Innova"] << endl; 
    // searching for the element which is not present then it return 0 but map-enter its entry and the size is increase
    cout << "Size: " << mp.size() << endl;

    cout << "Printing the Map: " << endl;
    for(auto i:mp) // i.first is string (key) and i.second is int (value)
    {
        cout << i.first << "-> " << i.second << endl;
    }

    // In unordered Map the entries are in random order 

    return 0;  
}