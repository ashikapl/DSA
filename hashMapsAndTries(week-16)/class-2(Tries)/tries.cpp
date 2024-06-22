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
    public:
    void insert(TreeNode* root, string word, int i)
    {
        if(word.length() == 0)
        {
            isTerminal = true;
            return;
        }

        char ch = word[0];
        int index = ch - 'A';
        TrieNode* child;
        
        if(root->children ! NULL)
        {
            child = root->children[index];
        }
        else
        {
            child = new TrieNode(ch);
            root->children[index] = child;
        }

        insert(child,word.substr(1));
    }

    bool search(TrieNode* root, string word)
    {
        if(word.length() == 0)
        {
            return root->isTerminal;
        }
    
        char ch = word[0];
        int index = ch - 'A';
        TrieNode* child;

        if(root->children != NULL)
        {
            child = root->children[index];
        }
        else
        {
            return false;
        }

        return search(child,word.substr(1));
    }
};