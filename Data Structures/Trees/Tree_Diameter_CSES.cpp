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


pair<int, int> bfs(int s){

    queue<pair<int, int>> q;
    q.push({s, 0});
    int dis = 0;
    vis.clear(); vis.resize(N);
    pair<int, int> res;

    while(!q.empty()){
        res = q.front();
        q.pop();
        vis[res.F] = 1;
        for(auto i : adj[res.F]){
            if(!vis[i]) q.push({i, res.S+1});
        }
    }

    return res;

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

    pair<int, int> node1 = bfs(1);
    pair<int, int> node2 = bfs(node1.F);
    cout << node2.S;




    return 0;

}