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

Node* getSuccessor(Node* curr){

    curr = curr->right;
    while(curr != NULL and curr->left != NULL)
        curr = curr->left;

    return curr;
}


Node *deleteNode(Node *root,  int X){

    if(root == NULL)
        return root;

    if(root->data < X){
        root->right = deleteNode(root->right, X);
    }
    else if(root->data > X){
        root->left = deleteNode(root->left, X);
    }
    else{
        if(root->left == NULL){
            Node* temp = root->right;
            delete(root);
            return temp;
        }
        else if(root->right == NULL){
            Node* temp = root->left;
            delete(root);
            return temp;
        }
        else{
            Node* temp = getSuccessor(root);
            root->data = temp->data;
            root->right = deleteNode(root->right, temp->data);
        }

    }

    return root;

}







int main(){

	Node* root = new Node(50);
	root->left = new Node(20);
	Node* temp = root->left;
	root->right = new Node(70);
	Node* temp2 = root->right;
	temp->left = new Node(10);
	temp->right = new Node(30);
	temp2->left = new Node(60);
	temp2->right = new Node(80);

	deleteNode(root, 30);

	delete(temp->left);
	delete(temp->right);
	delete(temp2->left);
	delete(temp2->right);
	delete(temp);
	delete(temp2);
	delete(root);

	return 0;
}

