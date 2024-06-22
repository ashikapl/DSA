// Given a strings of vector ans and a input string i have to print the suggestions string as the input string 
// given word by word

#include<iostream>
#include<vector>
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
    int index = ch - 'a';
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
    int index = ch - 'a';
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

void storeSuggestions(TrieNode* curr, vector<string> &temp, string &prefix)
{
    if(curr->isTerminal)
    {
        temp.push_back(prefix);
    }

    // giving a to z choices to a particular word
    for(char ch = 'a'; ch <= 'z'; ch++)
    {
        int index = ch - 'a';

        TrieNode* next = curr->children[index];

        if(next != NULL)
        {
            // if exists
            prefix.push_back(ch);
            storeSuggestions(next,temp,prefix);
            prefix.pop_back();
        }
    }
}

vector<vector<string>> getSuggestions(TrieNode* root, string input)
{
    TrieNode* prev = root;
    vector<vector<string>> output;
    string prefix = "";

    for(int i = 0; i < input.length(); i++)
    {
        char lastCh = input[i];
        int index = lastCh - 'a';
        TrieNode* curr = prev->children[index];

        if(curr == NULL)
        {
            break;
        }
        else
        {
            vector<string> temp;
            prefix.push_back(lastCh);
            storeSuggestions(curr,temp,prefix);
            output.push_back(temp);
            prev = curr;
        }
    }

    return output;
}

int main()
{
    vector<string> v;
    v.push_back("code");
    v.push_back("coder");
    v.push_back("coding");
    v.push_back("codehelp");
    v.push_back("codechef");
    v.push_back("codeforces");
    v.push_back("codecompiler");

    string input = "codech";

    TrieNode* root = new TrieNode('-');

    for(int i = 0; i < v.size(); i++)
    {
        insertionAtTrie(root,v[i]);
    }

    vector<vector<string>> ans = getSuggestions(root,input);

    cout << "Printing the suggestions:- " << endl;

    for(int i = 0; i < ans.size(); i++)
    {
        for(int j = 0; j < ans[i].size(); j++)
        {
            cout << ans[i][j] << ", ";
        }
        cout << endl;
    }

    return 0;
}
