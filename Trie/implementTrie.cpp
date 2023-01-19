#include <bits/stdc++.h>
using namespace std;

class TrieNode
{
public:
    // root ke pas char hoga , ek vector of size 26 hoga and isTerminated

    char data;
    TrieNode *children[26];
    bool isTerminal;

    TrieNode(char ch)
    {
        data = ch;
        for (int i = 0; i < 26; i++)
        {
            children[i] = NULL;
        }
        isTerminal = false;
    }
};

class Trie
{
    TrieNode *root;

public:
    Trie()
    {
        root = new TrieNode('\0');
    }

    void insertUtils(TrieNode *root, string word)
    {

        if (word.length() == 0)
        {
            root->isTerminal = true;
            return;
        }

        int index = word[0] - 'a';
        TrieNode *child;
        // present
        if (root->children[index] != NULL)
        {
            child = root->children[index];
        }
        else
        {
            // absent
            child = new TrieNode(word[0]);
            root->children[index] = child;
        }

        insertUtils(child, word.substr(1));
    }

    void insert(string word)
    {
        insertUtils(root, word);
    }

    bool searchUtils(TrieNode *root, string word)
    {

        // base case
        if (word.length() == 0)
        {
            return root->isTerminal;
        }

        int index = word[0] - 'a';
        TrieNode *child;

        // present
        if (root->children[index] != NULL)
        {
            child = root->children[index];
        }
        else
        {
            return false;
        }

        return searchUtils(child, word.substr(1));
    }

    bool search(string word)
    {
        return searchUtils(root, word);
    }

    bool startsWithUtils(TrieNode *root, string prefix)
    {

        // base case
        if (prefix.length() == 0)
        {
            return true;
        }

        int index = prefix[0] - 'a';
        TrieNode *child;

        // present
        if (root->children[index] != NULL)
        {
            child = root->children[index];
        }
        else
        {
            return false;
        }

        return startsWithUtils(child, prefix.substr(1));
    }

    bool startsWith(string prefix)
    {
        return startsWithUtils(root, prefix);
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
int32_t main()
{

    

    return 0;
}