// Link - https://cses.fi/problemset/task/1636

#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout<<fixed;cout.precision(10);
#define endl "\n"
#define tc int T; cin >> T; while(T--)
#define pb push_back
#define mod 1000000007
#define S second
#define F first
using namespace std;
const int N = 105;
const int MAX_SUM = 1000005;

int32_t main(){

    fastio;
    int n, x; cin >> n >> x;
    vector<int> arr(n);
    for(auto &i : arr) cin >> i;

    // dp[i][j] = Number of ways to make sum i using first j coins
    
    vector<vector<int>> dp(n+1, vector<int>(x+1));
    for(int i = 1; i <= x; i++) dp[0][i] = 0;
    for(int i = 0; i <= n; i++) dp[i][0] = 1;

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= x; j++){
            dp[i][j] = dp[i-1][j];
            if(arr[i-1] <= j)
                dp[i][j] = ((long long)dp[i][j] + (long long)dp[i][j - arr[i-1]]) % mod;
        }
    }
    cout << dp[n][x];

    return 0;
 
}