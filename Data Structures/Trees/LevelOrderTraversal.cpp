#include <bits/stdc++.h>
#define ll long long
#define repe(j, n) for(ll i = j ; i <= n ; i++)
#define rep(j , n) for(ll i = j ; i < n ; i++)
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);
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

struct Node{
    int data;
    Node* left;
    Node* right;
    Node(int x){
        data = x;
        left = NULL;
        right = NULL;
    }
};

void LevelOrder(Node* root){

    if(root == NULL)
        return;

    queue<Node*> q;
    q.push(root);

    while(!q.empty()){

        Node* curr = q.front();
        q.pop();
        cout << curr->data << " ";
        if(curr->left != NULL)
            q.push(curr->left);
        if(curr->right != NULL)
            q.push(curr->right);


    }
}


int main(){

    Node* root = new Node(10);
	root->left = new Node(20);
	Node* temp = root->left;
	root->right = new Node(30);
	Node* temp2 = root->right;
	temp->left = new Node(40);
	temp->right = new Node(50);
	temp2->left = new Node(60);
	temp2->right = new Node(70);

	LevelOrder(root);

	delete(temp->left);
	delete(temp->right);
	delete(temp2->left);
	delete(temp2->right);
	delete(temp);
	delete(temp2);
	delete(root);


    return 0;
}
