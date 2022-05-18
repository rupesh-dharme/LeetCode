// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Node{
    private:
    Node *links[26];
    bool flag;
    public:
    bool contains(char ch) {
        return links[ch - 'a'] != NULL;
    }
    void put(char ch, Node *node) {
        links[ch - 'a'] = node;
    }
    Node *get(char ch) {
        return links[ch - 'a'];
    }
    void setEnd() {
        flag = true;
    }
    bool isEnd() {
        return flag;
    }
};

class Trie {
    public:
    Node *root;
    Trie() {
        root = new Node();
    }
    void insert(string word) {
        Node *node = root;
        for (int i = 0; i < word.size(); i++) {
            if (!node->contains(word[i])) node->put(word[i], new Node());
            node = node->get(word[i]);
        }
        node->setEnd();
    }
};

class Solution{
    public:
    // A : given string to search
    // B : vector of available strings
    
    int wordBreak(string A, vector<string> &B) {
        Trie trie;
        for (auto &word : B) trie.insert(word);
        return recurse(A, trie.root);
    }
    
    int recurse(string A, Node *root) {
        Node *node = root;
        for (int i = 0; i < A.size(); i++) {
            if (node->isEnd() && recurse(A.substr(i), root) == 1) return 1;
            if (!node->contains(A[i])) return 0;
            node = node->get(A[i]);
        }
        return node->isEnd();
    }
};

// { Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<string> dict;
        for(int i=0;i<n;i++){
            string S;
            cin>>S;
            dict.push_back(S);
        }
        string line;
        cin>>line;
        Solution ob;
        cout<<ob.wordBreak(line, dict)<<"\n";
    }
}
  // } Driver Code Ends