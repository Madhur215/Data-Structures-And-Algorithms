#include <bits/stdc++.h>
#define ll long long
#define ff2(j , n , k) for(ll i = j ; i <= n ; i += k)
#define ff1(j , n , k) for(ll i = j ; i < n ; i += k)
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout << fixed;cout.precision(10);
#define endl "\n"
#define tc ll T; cin >> T; while(T--)
#define pb push_back
#define mk make_pair
#define mod 1000000007
#define MX 1000001
#define vi vector<int>
#define vs vector<string>
#define pii pair<int, int>

using namespace std;

struct TrieNode{
    TrieNode* child[26];
    bool isEnd;
    TrieNode(){
        isEnd = false;
        for(int i = 0 ; i < 26; i++)
            child[i] = NULL;
    }
};

void insertWord(TrieNode *root, string key){
    TrieNode* curr = root;
    for(int i = 0; i < key.length(); i++){
        int ind = key[i] - 'a';
        if(curr->child[ind] == NULL)
            curr->child[ind] = new TrieNode();
        curr = curr->child[ind];
    }
    curr->isEnd = true;

}

bool isEmpty(TrieNode* root){
    for(int i = 0; i < 26; i++){
        if(root->child[i] != NULL)
            return false;
    }
    return true;
}

TrieNode deleteWord(TrieNode* root, string key, int i){

    if(root == NULL)
        return NULL;
    if(key.length() == i){
        root->isEnd = false;
        if(isEmpty(root)){
            delete(root), root = NULL;
        }
        return root;
    }

    int ind = key[i] - 'a';
    root->child[ind] = deleteWord(root->child[ind], key, i+1);
    if(isEmpty(root) and root->isEnd == false)
        delete(root), root = NULL;

    return root;
}



int main(){
    TrieNode* root = new TrieNode;
    insertWord(root, "apple");
    insertWord(root, "boy");
    insertWord(root, "cat");
    cout << deleteWord(root, "boy");
}




