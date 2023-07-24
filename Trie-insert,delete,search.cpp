//*Bismillahir Rahmanir Raheem
//! symonkarim
#include <bits/stdc++.h>
#define FASTER ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
using namespace std;
//!------

#define ll long long
class TrieNode {
public:
    char data;
    TrieNode* children[26];
    bool isTerminal;
    TrieNode(char ch) {
        data = ch;
        for (int i = 0; i < 26; i++) {
            children[i] = NULL;
        }
        isTerminal = false;
    }
};
class Trie {
public:
    TrieNode* root;
    Trie() {
        root = new TrieNode('\0');
    }
    bool isEmpty(TrieNode* root)
    {
        for (int i = 0; i < 26; i++)
            if (root->children[i])
                return false;
        return true;
    }
    TrieNode* deleteUtil(TrieNode *root, string word, int depth = 0 ) {
        if (!root)
            return NULL;

        // If last character of key is being processed
        if (depth == word.size()) {

            if (root->isTerminal)
                root->isTerminal = false;

            // If given is not prefix of any other word
            if (isEmpty(root)) {
                delete (root);
                root = NULL;
            }

            return root;
        }

        // If not last character, recur for the child
        // obtained using ASCII value
        int index = word[depth] - 'A';
        root->children[index] =
            deleteUtil(root->children[index], word, depth + 1);

        // If root does not have any child (its only child got
        // deleted), and it is not end of another word.
        if (isEmpty(root) && root->isTerminal == false) {
            delete (root);
            root = NULL;
        }

        return root;
    }
    void deleteWord(string word) {
        deleteUtil(root, word);
    }
    void insertUtil(TrieNode *root, string word) {
        if (word.size() == 0) {
            root->isTerminal = true;
            return;
        }
        int index = word[0] - 'A';
        // word will be in caps
        TrieNode* child;
        //present
        if (root->children[index] != NULL) {
            child = root->children[index];
        } else { //absent case
            child = new TrieNode(word[0]);
            root->children[index] = child;
        }
        insertUtil(child, word.substr(1));

    }
    void insertWord(string word) {
        insertUtil(root, word);
    }
    bool searchUtil(TrieNode* root, string word) {
        if (word.size() == 0) {
            return root->isTerminal;
        }
        int index = word[0] - 'A';
        TrieNode* child;
        if (root->children[index] != NULL) {
            child = root->children[index];
        } else {
            return false;
        }
        return searchUtil(child, word.substr(1));
    }
    bool searchWord(string word) {
        return searchUtil(root,  word);
    }
};

int main() {
    FASTER;
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    Trie *t = new Trie();
    t->insertWord("SYMON");
    t->insertWord("KARIM");
    t->insertWord("ARHAM");
    cout << "SYMON is :";
    t->searchWord("SYMON")  ? cout << " present" : cout << " Not present";
    t->deleteWord("SYMON");
    cout << endl << "SYMON is:";
    t->searchWord("SYMON")  ? cout << " present" : cout << " Not present";
    t->insertWord("SYMON");
    cout << endl << "ARHAM is:";
    t->searchWord("ARHAM")  ? cout << " present" : cout << " Not present";

    return 0;
}
/*
input:

output:
SYMON is : present
SYMON is: Not present
ARHAM is: present
*/
