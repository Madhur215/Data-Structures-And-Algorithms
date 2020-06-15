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

queue<int> rev(queue<int> q){
    stack<int> s;
    while(!q.empty()){
        s.push(q.front());
        q.pop();
    }

    while(!s.empty()){
        q.push(s.top());
        s.pop();

    }

    return q;
}

void reverseQ(queue<int> &q){

    if(q.empty())
        return;

    int x = q.front();
    q.pop();
    reverseQ(q);
    q.push(x);

 /*   while(!q.empty()){
        cout << q.front() << " ";
        q.pop();
    }
*/
}

int main(){
    queue<int> q1;
    q1.push(1);
    q1.push(2);
    q1.push(3);
    q1.push(4);
    q1.push(5);
    reverseQ(q1);
//    queue<int> q = rev(q1);
    while(!q1.empty()){
        cout << q1.front() << " ";
        q1.pop();

    }

    return 0;

}

