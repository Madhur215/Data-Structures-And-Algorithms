// Question Link : https://cses.fi/problemset/task/1671/

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
const int N = 1e5+10;
 
ll n, m;
vector<pair<ll, ll>> adj[N];
vector<ll> vis(N);
 
int main() {
 
    fastio;
    cin >> n >> m;
    ll a, b, c;
    for(int i = 0; i < m; i++){
        cin >> a >> b >> c;
        adj[a].pb({b, c});
        // adj[b].pb({a, c});
    }
 
    // first = distance of vertex.....second = vertex
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> q;
    vector<ll> dis(n+1, LLONG_MAX);
    q.push({0, 1});
    dis[1] = 0;
 
    while(!q.empty()){
        // Extract min distance edge
        auto p = q.top();
        q.pop();
        if(vis[p.S]) continue;
        vis[p.S] = 1;
 
        // Relax all adjacent vertices
        for(auto i : adj[p.S]){
            if(dis[i.F] > dis[p.S] + i.S){
                dis[i.F] = dis[p.S] + i.S;
                q.push({dis[i.F], i.F});
            }
        }
    }
    
    for(int i = 1; i <= n; i++)
        cout << dis[i] << " ";
 
 
    return 0;
 
}