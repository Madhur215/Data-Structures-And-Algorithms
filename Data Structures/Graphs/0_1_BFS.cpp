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
const int N = 1e5+5;

int n, m;
vector<pair<ll, ll>> adj[N];

int main(){
 
    fastio;
    cin >> n >> m;
    ll a, b;
    for(int i = 0; i < m; i++){
        cin >> a >> b;
        adj[a].pb({b, 0});
        adj[b].pb({a, 1});
    }

    vector<ll> dis(N, INT_MAX);
    deque<int> q;
    q.pb(1);
    dis[1] = 0;

    while(!q.empty()){

        auto p = q.front();
        q.pop_front();

        for(auto i : adj[p]){
            if(dis[i.F] > dis[p] + i.S){
                dis[i.F] = dis[p] + i.S;
                if(i.S == 1) q.push_back(i.F);
                else q.push_front(i.F);
            }
        }
    }

    cout << (dis[n] == INT_MAX ? -1 : dis[n]);



    return 0;
 
}