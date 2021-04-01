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
vector<int> adj[N];
// store the depth of every node
int depth[N]; 
// LCA[i][j] = (2 ^ j)th parent of node i
int LCA[N][maxN];

void dfs(int node, int par){

    // For every node store its 2^0 th (first) parent
    depth[node] = (par == -1 ? 0 : depth[par]) + 1;
    LCA[node][0] = par;
    for(auto child : adj[node]){
        if(child != par) 
            dfs(child, node);
    } 

}

void init(){

    // calculate first parent for every node
    dfs(1, -1);

    // calculate other parents for every node using previously 
    // calculated parents
    for(int j = 1; j < maxN; j++){
        for(int i = 1; i <= n; i++){
            if(LCA[i][j-1] != -1){
                LCA[i][j] = LCA[LCA[i][j-1]][j-1];
                // because 2 ^ i == 2 * (2 ^ (i-1))
            }
        }
    }

}

int findLCA(int a, int b){

    if(depth[a] > depth[b]) swap(a, b);

    int diff = depth[b] - depth[a];
    while(diff){
        int h = log2(diff); // highest power of 2 less than or equal to diff
        b = LCA[b][h];
        diff -= (1 << h); 
    } 

    if(a == b) return a;
    // Simple approach - O(n) in worst case
    // while(LCA[a][0] != LCA[b][0]){
    //     a = LCA[a][0];
    //     b = LCA[b][0];
    // }
    // return LCA[a][0];

    // Optimized - O(LogN)

    for(int i = maxN-1; i >= 0; i--){
        if(LCA[a][i] != -1 and (LCA[a][i] != LCA[b][i]))
            a = LCA[a][i], b = LCA[b][i];
    }    

    return LCA[a][0];
}


int main() {

    fastio;
    int q; cin >> n >> q;
    int a, b;
    for(int i = 0; i < n-1; i++){
        cin >> a;
        adj[a].pb(i+2);
        adj[i+2].pb(a);
    }
    init();
    while(q--){
        cin >> a >> b;
        cout << findLCA(a, b) << endl;
    }







    return 0;

}