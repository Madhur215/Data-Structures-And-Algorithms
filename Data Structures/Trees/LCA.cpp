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

//Lowest Common Ancestor Problem

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

bool findPath(Node* root, int key, vector<Node*> &v){

    if(root == NULL)
        return false;

    v.push_back(root);

    if(root->data == key)
        return true;

    if((root->left != NULL and findPath(root->left, key, v)) or
        (root->right != NULL and findPath(root->right, key, v)))
        return true;

    if(!v.empty())
        v.pop_back();
    return false;


}

Node* lca(Node* root ,int n1 ,int n2 )
{
    vector<Node*> v;
    vector<Node*> v1;
    if(!findPath(root, n1, v) or !findPath(root, n2, v1)){
        return NULL;
    }

    int i;
    for(i = 0; i < v.size() and i <v1.size(); i++){
        if(v[i] != v1[i])
            break;
    }

    return v[i-1];

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

	Node* ans = lca(root, 60, 70);
    cout << ans->data;
	delete(temp->left);
	delete(temp->right);
	delete(temp2->left);
	delete(temp2->right);
	delete(temp);
	delete(temp2);
	delete(root);

	return 0;
}
