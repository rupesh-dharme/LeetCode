// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Node {
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
    void insert(string &word) {
        Node *node = root;
        for (int i = 0; i < word.size(); i++) {
            if(!node->contains(word[i])) {
                node->put(word[i], new Node());
            }
            node = node->get(word[i]);
        }
        node->setEnd();
    }
    void addSent(vector<string> &res, string &s, string sent, int i, Node *node) {
        for (; i < s.size(); i++) {
            if (!node->contains(s[i])) return;
            sent += s[i];
            node = node->get(s[i]);
            if (node->isEnd()) {
                addSent(res, s, sent + ' ', i+1, root);
            }
        }
        if (sent.back() == ' ') sent.pop_back();
        if (node->isEnd()) (res.push_back(sent));
    }
};

class Solution{
public:
    vector<string> wordBreak(int n, vector<string>& dict, string s)
    {
        // code here
        Trie t;
        for (auto word : dict) t.insert(word);
        vector<string> res;
        t.addSent(res, s, "", 0, t.root);
        return res;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        vector<string> dict;
        string s;
        cin>>n;
        for(int i = 0;i < n;i++){
            cin>>s;
            dict.push_back(s);
        }
        cin>>s;
        
        Solution ob;
        vector<string> ans = ob.wordBreak(n, dict, s);
        if(ans.size() == 0)
            cout<<"Empty\n";
        else{
            sort(ans.begin(), ans.end());
            for(int i = 0;i < ans.size();i++)
                cout<<"("<<ans[i]<<")";
            cout<<endl;
        }
    }
    return 0;
}  // } Driver Code Ends