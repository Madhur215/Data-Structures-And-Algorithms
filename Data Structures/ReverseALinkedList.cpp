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

struct Node{
    int key;
    Node* next;
    Node(int x){
        key = x;
        next = NULL;
    }
};


Node* insertBegin(Node *head, int key){
    Node *newNode = new Node(key);
    newNode->next = head;
    return newNode;

}

void traverseLL(Node *head){
    if(head == NULL)
        return;
    while(head != NULL){
        cout << head->key << " ";
        head = head->next;
    }

}

Node* IterativeReverse(Node* head){
    Node* curr = head;
    Node* prev = NULL;

    while(curr != NULL){
        Node* temp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = temp;
    }

    return prev;
}

Node* recursiveReverse(Node* head){
    if(head == NULL or head->next == NULL)
        return head;

    Node* rest_head = recursiveReverse(head->next);
    Node* rest_tail = head->next;
    rest_tail->next = head;
    head->next = NULL;

    return rest_head;

}

Node* recursiveReverse2(Node* head, Node* prev){

   if(head == NULL)
        return prev;

   Node* temp = head->next;
   head->next = prev;
   return recursiveReverse2(temp, head);

}


int main(){
    Node* head = NULL;
    head = insertBegin(head, 10);
    head = insertBegin(head, 15);
    head = insertBegin(head, 20);
    head = insertBegin(head, 25);

    traverseLL(head);
    cout << endl;

    head = IterativeReverse(head);
    traverseLL(head);
    cout << endl;
    head = recursiveReverse(head);
    traverseLL(head);
    cout << endl;
    head = recursiveReverse2(head, NULL);
    traverseLL(head);
    cout << endl;

}





