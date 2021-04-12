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
vector<vector<ll>> g, dis;
 
int main() {
 
    fastio;
    int q;
    cin >> n >> m >> q;
    g.resize(n, vector<ll>(n, 1e18));
    ll a, b, c;
    for(int i = 0; i < m; i++){
        cin >> a >> b >> c;
        --a, --b;
        g[a][b] = g[b][a] = min(g[a][b], c);
    }
    dis = g;
    for(int i = 0; i < n; i++)
        dis[i][i] = 0ll;
    
 
    for(int vertex = 0; vertex < n; vertex++){
        // Consider vertex as intermediate vertex for all 
        // pair of nodes u - v
        for(int u = 0; u < n; u++){
            for(int v = 0; v < n; v++){
                if(dis[u][v] > dis[u][vertex] + dis[vertex][v]){
                    dis[u][v] = dis[u][vertex] + dis[vertex][v];
                }
            }
        }
    }
 
    while(q--){
        cin >> a >> b;
        if(dis[--a][--b] == 1e18) cout << "-1\n";
        else cout << dis[a][b] << endl;
    }
 
 
 
    
 
    return 0;
 
}