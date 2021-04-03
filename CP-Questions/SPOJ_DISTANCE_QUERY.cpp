// Question: https://www.spoj.com/problems/DISQUERY/
// Approach - LCA and DP

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
const int maxN = 18;
vector<pair<int, int>> adj[N];
// store the depth of every node
int depth[N]; 
// LCA[i][j] = (2 ^ j)th parent of node i
int LCA[N][maxN];
int dp[N][maxN][2];

int ans_mn = INT_MAX, ans_mx = INT_MIN;
 
void dfs(int node, int par, int cost){
 
    // For every node store its 2^0 th (first) parent
    depth[node] = (par == -1 ? 0 : depth[par]) + 1;
    LCA[node][0] = par;
    if(par != -1)
    dp[node][0][0] = dp[node][0][1] = cost;
    for(auto child : adj[node]){
        if(child.F != par)
            dfs(child.F, node, child.S);
    }
}

void init(){

    // calculate first parent for every node
    dfs(1, -1, INT_MAX);

    // calculate other parents for every node using previously 
    // calculated parents
    for(int j = 1; j < maxN; j++){
        for(int i = 1; i <= n; i++){
            if(LCA[i][j-1] != -1){
                int par = LCA[i][j-1];
                // because 2 ^ i == 2 * (2 ^ (i-1))
                LCA[i][j] = LCA[par][j-1];
                dp[i][j][0] = min(dp[i][j-1][0], dp[par][j-1][0]);
                dp[i][j][1] = max(dp[i][j-1][1], dp[par][j-1][1]);
            }
        }
    }
}

void findLCA(int a, int b){
 
    if(depth[a] > depth[b]) swap(a, b);
    int diff = depth[b] - depth[a];
    int mn1= INT_MAX, mn2 = INT_MAX, mx1 = INT_MIN, mx2 = INT_MIN;
    while(diff){
        int h = log2(diff); // highest power of 2 less than or equal to diff
        mn1 = min(mn1, dp[b][h][0]);
        mx1 = max(mx1, dp[b][h][1]);
        b = LCA[b][h];
        diff -= (1 << h); 
    } 
    
    if(a == b){
        ans_mn = mn1; ans_mx = mx1;
        return;
    }

    for(int i = maxN-1; i >= 0; i--){
        if(LCA[a][i] != -1 and (LCA[a][i] != LCA[b][i])){
            mn1 = min(mn1, dp[a][i][0]);
            mx1 = max(mx1, dp[a][i][1]);
            mn2 = min(mn2, dp[b][i][0]);
            mx2 = max(mx2, dp[b][i][1]);
            a = LCA[a][i], b = LCA[b][i];
        }
    }
    ans_mn = min({mn1, mn2, dp[a][0][0], dp[b][0][0]});
    ans_mx = max({mx1, mx2, dp[a][0][1], dp[b][0][1]});
    // return ans + 2;
}

int main() {
 
    fastio;
    int q; cin >> n;
    int a, b, c;
    for(int i = 0; i < n-1; i++){
        cin >> a >> b >> c;
        adj[a].pb({b, c});
        adj[b].pb({a, c});
    }
    for(int i = 0; i < N; i++){
        for(int j = 0; j < maxN; j++){
            dp[i][j][0] = INT_MAX;
            dp[i][j][1] = INT_MIN;
        }
    }
    init();
    cin >> q;
    while(q--){
        cin >> a >> b;
        findLCA(a, b);
        cout << ans_mn << " " << ans_mx << endl;
    }
 
    return 0;
 
}