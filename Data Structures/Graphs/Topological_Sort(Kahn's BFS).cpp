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

int n, m;
vector<int> adj[N];
vector<int> inDeg(N);

int main(){
 
    fastio;
    cin >> n >> m;
    int a, b;
    for(int i = 0; i < m; i++){
        cin >> a >> b;
        adj[a].pb(b);
        inDeg[b]++;
    }

    queue<int> q;
    for(int i = 1; i <= n; i++){
        if(inDeg[i] == 0) q.push(i);
    }

    vector<int> ans;
    while(!q.empty()){
        int p = q.front(); q.pop();
        ans.pb(p);
        for(auto i : adj[p]){
            inDeg[i]--;
            if(inDeg[i] == 0) q.push(i);
        }
    }

    if(ans.size() != n){
        cout << "IMPOSSIBLE\n";
        return 0;
    }
    for(auto i : ans)
        cout << i << " ";


    return 0;
 
}