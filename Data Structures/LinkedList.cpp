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

struct node{
    int key;
    node *next;
    node(int x){
        key = x;
        next = NULL;
    }
};

node* insertBegin(node *head, int key){
    node *newNode = new node(key);
    newNode->next = head;
    return newNode;

}

void traverseLL(node *head){
    if(head == NULL)
        return;
    while(head != NULL){
        cout << head->key << " ";
        head = head->next;
    }

}

node* insertEND(node *head, int key){

    node *curr = head;
    while(curr->next != NULL)
        curr = curr->next;
    curr->next = new node(key);
    return head;
}

int main(){
    node *head = NULL;
    head = insertBegin(head, 10);
    head = insertBegin(head, 15);
    head = insertBegin(head, 20);
    head = insertEND(head, 55);
    head = insertEND(head, 100);
    head = insertEND(head, 250);
    traverseLL(head);


}
