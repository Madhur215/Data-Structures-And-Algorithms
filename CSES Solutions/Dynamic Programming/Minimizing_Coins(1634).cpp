// Link - https://cses.fi/problemset/task/1634

// Variation of Subset Sum
// We just need to store the minimum number of elements required to make
// a given sum.

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

int dp[N][MAX_SUM];

int32_t main(){

    fastio;
    int n, x; cin >> n >> x;
    vector<int> arr(n);
    for(auto &i : arr) cin >> i;

    for(int i = 1; i <= x; i++) dp[0][i] = 1e9;
    for(int i = 0; i <= n; i++) dp[i][0] = 0;

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= x; j++){
            dp[i][j] = dp[i-1][j];
            if(arr[i-1] <= j)
                dp[i][j] = min(dp[i][j], 1 + dp[i][j - arr[i-1]]);
        }
    }

    cout << (dp[n][x] == 1e9 ? -1 : dp[n][x]);


    return 0;
 
}