#include<iostream>
#include<string>
#include<vector>
using namespace std;

class TrieNode
{
    public:
    char data;
    TrieNode* children[26];
    bool isTerminal;
    int childCount;

    TrieNode(char d)
    {
        data = d;
        for(int i = 0; i < 26; i++)
        {
            children[i] = NULL;
        }
        isTerminal = false;
        childCount = 0;
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
            root->childCount++;
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

    void findLCP(string first, string &ans, TrieNode* root)
    {
        if(root->isTerminal)
        {
            return;
        }

        for(int i = 0; i < first.length(); i++)
        {
            char ch = first[i];

            if(root->childCount == 1)
            {
                ans.push_back(ch);
                int index = ch - 'a';
                root = root->children[index];
            }
            else
            {
                break;
            }
            if(root->isTerminal)
            {
                break;
            }
        }
    }
    
    string longestCommonPrefix(vector<string>& strs) 
    {
        TrieNode* root = new TrieNode('-');
        
        for(int i = 0; i < strs.size(); i++)
        {
            insertionAtTrie(root, strs[i]);
        }

        string ans = "";
        string first = strs[0];
        findLCP(first,ans,root);
        return ans;
    };

int main()
{
    vector<string> strs{"geeksforgeeks","geeks","geek","geezer"};

    string ans = longestCommonPrefix(strs);

    cout << "The Longest Common Prefix is:-> " << ans << endl;

    return 0;
}