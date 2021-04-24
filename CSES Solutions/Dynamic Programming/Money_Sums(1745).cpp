// Link - https://cses.fi/problemset/task/1745

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
const int MAX_SUM = 1e5 + 5;

int32_t main(){

    fastio;
    int n; cin >> n;
    ll sum = 0;
    vector<int> arr(n);
    for(auto &i : arr) cin >> i, sum += i;

    vector<vector<int>> dp(n+1, vector<int>(sum+1));
    // dp[i][j] = 1 if we can make sum j using first j coins
    // 0 otherwise

    for(int i = 0; i <= n; i++) dp[i][0] = 1;
    
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= sum; j++){
            dp[i][j] = dp[i-1][j];
            if(arr[i-1] <= j)
                dp[i][j] = dp[i][j] or dp[i-1][j - arr[i-1]];
        }
    }

    vector<int> ans;
    for(int i = 1; i <= sum; i++){
        if(dp[n][i]) ans.pb(i);
    }

    cout << ans.size() << endl;
    for(auto i : ans) cout << i << " ";



    return 0;
 
}