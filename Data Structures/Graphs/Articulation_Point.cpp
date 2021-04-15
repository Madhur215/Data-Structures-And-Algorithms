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
const int N = 1e4+5;

int n, m, inTm, ans;
vector<int> adj[N], vis(N);
vector<int> low(N), par(N), inTime(N), ap(N);

void articulationP(int s){

    int cnt = 0;
    vis[s] = 1;
    inTime[s] = low[s] = ++inTm;

    for(auto i : adj[s]){

        if(!vis[i]){
            cnt++;
            par[i] = s;
            articulationP(i);
            low[s] = min(low[s], low[i]);

            if(par[s] == -1 and cnt > 1) ap[s] = 1;
            if(par[s] != -1 and low[i] >= inTime[s]) ap[s] = 1;
        }
        else if(i != par[s]) low[s] = min(low[s], inTime[i]);
    }

}

int main(){
 
    fastio;
    while(1){
        cin >> n >> m;
        if(n == 0 and m == 0) break;
        int a, b; 
        ans = inTm = 0;
        vis.clear(); vis.resize(N);
        low.clear(); low.resize(N);
        par.clear(); par.resize(N, -1);
        ap.clear(); ap.resize(N);
        inTime.clear(); inTime.resize(N);
        for(int i = 0; i < N; i++) adj[i].clear();

        for(int i = 0; i < m; i++){
            cin >> a >> b;
            adj[a].pb(b);
            adj[b].pb(a);
        }
        for(int i = 1; i <= n; i++){
            if(!vis[i]){
                articulationP(i);
            }
        }
        
        for(int i = 1; i <= n; i++)
            ans += ap[i];
        cout << ans << endl;


    }

    return 0;
 
}