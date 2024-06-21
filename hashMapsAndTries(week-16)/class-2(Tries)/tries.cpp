// Trie
#include<iostream>
#include<unordered_map>
using namespace std;

class TrieNode
{
    public:
    char data;
    TrieNode* children[26];
    bool isTerminal;

    TrieNode(char d)
    {
        data = d;
        for(int i = 0; i < 26; i++)
        {
            children[i] = NULL;
        }
        isTerminal = false;
    }
};

class Trie
{
    
};