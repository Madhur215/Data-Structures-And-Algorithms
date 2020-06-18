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

//Given heads of two sorted linked list. Merge the linked list so that the resultant list is also in sorted order.


struct node{
    int key;
    node *next;
    node(int x){
        key = x;
        next = NULL;
    }
};

void mergeLL(Node* head1, Node* head2){
    if(head1 == NULL)
        return head2;
    if(head2 == NULL)
        return head1;

    Node* c1 = head1;
    Node* c2 = head2;
    Node* tail = NULL;
    Node* head = NULL;

    if(c1->data < c2->data){
        head = c1;
        tail = c1;
        c1 = c1->next;
    }
    else{
        head = c2;
        tail = c2;
        c2 = c2->next;
    }

    while(c1 != NULL and c2 != NULL){
        if(c1->data < c2->data){
            tail->next = c1;
            tail = c1;
            c1 = c1->next;
        }
        else{
            tail->next = c2;
            tail = c2;
            c2 = c2->next;
        }

    }

    if(c1 == NULL and c2 != NULL){
        tail->next = c2;
    }
    else if(c1 != NULL and c2 == NULL){
        tail->next = c1;
    }

    return head;

}


int main(){

    return 0;

}
