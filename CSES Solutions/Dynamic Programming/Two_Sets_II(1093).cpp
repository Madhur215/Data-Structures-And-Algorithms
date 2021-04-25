// Link - https://cses.fi/problemset/task/1093
// Subset Sum problem


#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout<<fixed;cout.precision(10);
#define endl "\n"
#define tc int T; cin >> T; while(T--)
#define pb push_back
#define mod 1000000007
#define S second
#define F first
using namespace std;
const int N = 1002;
 
int n, x;
vector<int> price, pages;
 
int solve(){
 
    int dp[n+1][x+1];
    for(int i = 0; i <= n; i++) dp[i][0] = 0;
    for(int i = 1; i <= x; i++) dp[0][i] = 0;
 
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= x; j++){
            if(price[i-1] <= j)
                dp[i][j] = max(dp[i-1][j], (int)pages[i-1] + dp[i-1][j - price[i-1]]);
            else dp[i][j] = dp[i-1][j];
        }
    }
 
    return dp[n][x];
 
}
 
int32_t main(){
 
    fastio;
    cin >> n >> x;
    price.resize(n); pages.resize(n);
    for(auto &i : price) cin >> i;
    for(auto &i : pages) cin >> i;
    cout << solve();
 
    return 0;
 
}