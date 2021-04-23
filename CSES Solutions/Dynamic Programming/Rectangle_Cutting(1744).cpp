// Link - https://cses.fi/problemset/task/1744

#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout<<fixed;cout.precision(10);
#define endl "\n"
#define tc int T; cin >> T; while(T--)
#define pb push_back
#define mod 1000000007
#define S second
#define F first
#define ll long long
using namespace std;
const int N = 2050;

int32_t main(){

    fastio;
    int n, m; cin >> n >> m;
    vector<vector<int>> dp(n+1, vector<int>(m+1, 1e9));

    // dp[i][j] = Number of moves to cut a rectangle
    // of length i and width j into squares.
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(i == j){
                dp[i][j] = 0; continue;
            }
            for(int k = 1; k < i; k++)  
                dp[i][j] = min(dp[i][j], 1 + dp[k][j] + dp[i-k][j]);
            for(int k = 1; k < j; k++)
                dp[i][j] = min(dp[i][j], 1 + dp[i][k] + dp[i][j-k]);
        }
    }
    
    cout << dp[n][m];




    return 0;
 
}