// Link - https://cses.fi/problemset/task/1633

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
const int N = 2e5+5;

int32_t main(){

    fastio;
    int n; cin >> n;
    int dp[n+1]{};
    dp[0] = 1;
    // dp[i] = Number of ways to make value i.

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= 6 and i - j >= 0; j++){
            dp[i] = (dp[i] + dp[i - j]) % mod;
        }
    }

    cout << dp[n];



    return 0;
 
}