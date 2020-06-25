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

// Breadth First Search in Graphs

void addEdge(vector<int> ad[], int u, int v){

    ad[u].push_back(v);
    ad[v].push_back(u);

}

BFS(vector<int> ad[], int n, int start, bool vis[]){

    queue<int> q;
    q.push(start);
    cout << start << " ";
    vis[start] = true;

    while(!q.empty()){
        int temp = q.front();
        q.pop();

        for(auto i : ad[temp]){
            if(vis[i] == false){
                q.push(i);
                vis[i] = true;
                cout << i << " ";
            }
        }
    }
}

void BFSHelper(vector<int> ad[], int n){
    bool vis[n+1];
    for(int i = 0 ; i < n; i++)
        vis[i] = false;

    for(int i = 0; i < n; i++){
        if(vis[i] == false)
            BFS(ad, n, i, vis);
    }

}



int main(){
    vector<int> ad[10];
    addEdge(ad, 0, 1);
    addEdge(ad, 0, 2);
    addEdge(ad, 0, 3);
    addEdge(ad, 1, 2);
    addEdge(ad, 1, 5);
    addEdge(ad, 2, 4);
    addEdge(ad, 2, 5);
    addEdge(ad, 3, 4);
    addEdge(ad, 4, 5);

    BFSHelper(ad, 6);


}


