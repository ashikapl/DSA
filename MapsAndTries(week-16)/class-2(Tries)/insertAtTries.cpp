// Tries -> Data structure -> multi-Way tree Structure -> Help in pattern searching (string)
#include<iostream>
#include<string>
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

void insertionAtTrie(TrieNode* root, string word)
{
    // cout << "Insertion: " << word << endl;
    // base case
    if(word.length() == 0)
    {
        root->isTerminal = true;
        return;
    }

    char ch = word[0];
    int index = ch - 'A';
    TrieNode* child;

    // present
    if(root->children[index] != NULL)
    {
        child = root->children[index];
    }
    else // not present
    {
        child = new TrieNode(ch);
        root->children[index] = child;
    }

    // recursive call
    insertionAtTrie(child,word.substr(1));
}

// searching in Tries
bool searchWord(TrieNode* root, string word)
{
    // base case
    if(word.length() == 0)
    {
        return root->isTerminal;
    }

    char ch = word[0];
    int index = ch - 'A';
    TrieNode* child;

    if(root->children[index] != NULL)
    {
        child = root->children[index];
    }
    else
    {
        return false;
    }

    // recursive call
    return searchWord(child,word.substr(1));
}

// deletion
void deleteWord(TrieNode* root, string word) {
    // base case
    if (word.length() == 0) {
        return;
    }

    TrieNode* current = root;
    for (char ch : word) {
        int index = ch - 'A';
        if (current->children[index] == nullptr) {
            // Word not found in the Trie
            return;
        }
        current = current->children[index];
    }

    // Mark the last character's node as not terminal
    if (current->isTerminal) {
        current->isTerminal = false;
    }
}

int main()
{
    TrieNode* root = new TrieNode('-');

    insertionAtTrie(root,"CODING");
    insertionAtTrie(root,"CODE");
    insertionAtTrie(root,"CODER");
    insertionAtTrie(root,"CODEHELP");
    insertionAtTrie(root,"CALLING");
    insertionAtTrie(root,"LAXMI");

    if(searchWord(root,"CODE"))
    {
        cout << "Present" << endl;
    }
    else
    {
        cout << "Absent" << endl;
    }

    deleteWord(root,"CODE");

    if (searchWord(root, "CODE")) 
    {
        cout << "CODE is still present" << endl;
    } 
    else 
    {
        cout << "CODE is deleted" << endl;
    }

    return 0;
}