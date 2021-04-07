// Question Link : https://cses.fi/problemset/task/1132

#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout<<fixed;cout.precision(10);
#define endl "\n"
#define tc ll T; cin >> T; while(T--)
#define pb push_back
#define mod 1000000007
#define S second
#define F first
using namespace std;
typedef long long ll;
const int N = 2e5+10;

int n; 
vector<int> adj[N], vis(N);
vector<int> ans(N);

int bfs(int s){

    vis.clear(); vis.resize(N);
    int dis = 0;
    queue<pair<int, int>> q;
    q.push({s, 0});
    pair<int, int> node;

    while(!q.empty()){
        node = q.front();
        vis[node.F] = 1;
        q.pop();

        for(auto i : adj[node.F]){
            if(!vis[i]){
                q.push({i, node.S+1});
                ans[i] = max(ans[i], node.S+1);
            }
        }
    }

    return node.F;

}


int main() {

    fastio;
    cin >> n;
    int a, b;
    for(int i = 0; i < n-1; i++){
        cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
    }

    int node1 = bfs(1);
    int node2 = bfs(node1);
    bfs(node2);
    
    for(int i = 1; i <= n; i++)
        cout << ans[i] << " ";





    return 0;

}