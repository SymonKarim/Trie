//problem Link: https://leetcode.com/problems/longest-common-prefix/
class TrieNode{
  public:
    char ch;
    TrieNode* children[26];
    bool isTerminal;
    int childCount;
    TrieNode(char ch){
        this->ch = ch;
        for(int i=0;i<26;i++){
            children[i] = NULL;
        }
        isTerminal = false;
        childCount = 0;
    }  
};
class Trie{
    public: 
        TrieNode* root;
        Trie(){
            root = new TrieNode('\0');
        }
     void insertUtil(TrieNode *root, string word) {
        if (word.size() == 0) {
            root->isTerminal = true;
            return;
        }
        int index = word[0] - 'a';
        // word will be in caps
        TrieNode* child;
        //present
        if (root->children[index] != NULL) {
            child = root->children[index];
        } else { //absent case
            child = new TrieNode(word[0]);
            root->childCount++;
            root->children[index] = child;
        }
        insertUtil(child, word.substr(1));

    }
    void insertWord(string word) {
        insertUtil(root, word);
    }
    void lcs(string &word, string &ans){
            for(int i=0;i<word.size();i++){
            if(root->isTerminal) return;  
                char ch = word[i]-'a';
                if(root->childCount==1) {
                    ans+=word[i];
                    root= root->children[ch];
                }else return;

                 
            }
    }
};
class Solution {
public:
	string longestCommonPrefix(vector<string>& strs) {
        Trie* temp = new Trie();
        string word = strs[0], ans="";
        for(string i:strs){
            temp->insertWord(i);
        }
        temp->lcs(word, ans);
        return ans;
    }
};
