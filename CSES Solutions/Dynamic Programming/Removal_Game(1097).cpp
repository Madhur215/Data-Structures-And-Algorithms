// Link - https://cses.fi/problemset/task/1097

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
    int n; cin >> n;
    vector<int> arr(n);
    for(auto &i : arr) cin >> i;

    vector<vector<ll>> dp(n, vector<ll>(n));
    // Maximum score reachable using 
    // elements from i to j
    for(int i = 0; i < n-1; i++){
        dp[i][i+1] = max(arr[i], arr[i+1]);
        dp[i][i] = arr[i];
    }
    dp[n-1][n-1] = arr[n-1];

    for(int gap = 2; gap < n; gap++){
        for(int i = 0; i + gap < n; i++){
            int j = i + gap;
            dp[i][j] = max(arr[i] + min(dp[i+2][j], dp[i+1][j-1]), 
                        arr[j] + min(dp[i+1][j-1], dp[i][j-2]));
        }
    }

    cout << dp[0][n-1];


    return 0;
 
}