// Link - https://cses.fi/problemset/task/1638

#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout<<fixed;cout.precision(10);
#define endl "\n"
#define tc int T; cin >> T; while(T--)
#define pb push_back
#define mod 1000000007
#define S second
#define F first
#define int long long
using namespace std;
const int N = 1002;

int n;
vector<string> mat;
vector<vector<int>> dp(N, vector<int>(N, -1));
// dp[i][j] = total number of paths to reach from
// (i, j) to (n-1, n-1).
pair<int, int> adj[] = {{0, 1}, {1, 0}};

bool check(int x, int y){

    return x >= 0 and y >= 0 and x < n and y < n;

}

int paths(int x, int y){

    if(mat[x][y] == '*') return 0;
    if(dp[x][y] != -1) return dp[x][y];
    if(x == n-1 and y == n-1) return 1;
    dp[x][y] = 0;
    for(auto i : adj){
        int nx = x + i.F, ny = y + i.S;
        if(check(nx, ny))
            (dp[x][y] += paths(nx, ny)) %= mod;
    }

    return dp[x][y];

}

int32_t main(){

    fastio;
    cin >> n;
    mat.resize(n);
    for(auto &i : mat) cin >> i;
    cout << paths(0, 0);

    return 0;
 
}