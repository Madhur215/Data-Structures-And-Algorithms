// Question Link : https://cses.fi/problemset/task/1133

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
vector<int> adj[N];
vector<ll> ans(N), cnt(N), sub(N);

// cnt[i] = number of nodes including i in the subtree rooted
// at i

// sub[i] = sum of all distances from i to all
// the nodes in the subtree rooted at i

void calc(int s, int p){
    
    for(auto i : adj[s]){
        if(i != p){
            calc(i, s);
            cnt[s] += cnt[i];
            sub[s] += sub[i] + cnt[i];
        }
    }
    cnt[s]++;
}

void solve(int s, int p, ll p_ans){

    ans[s] = sub[s] + (p_ans + (n - cnt[s]));
    for(auto i : adj[s]){
        if(i != p)
            solve(i, s, ans[s] - (sub[i] + cnt[i]));
    }

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

    calc(1, 0);
    solve(1, 0, 0);

    for(int i = 1; i <= n; i++)
        cout << ans[i] << " ";



    return 0;

}