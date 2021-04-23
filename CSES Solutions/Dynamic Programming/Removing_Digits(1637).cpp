// Link - https://cses.fi/problemset/task/1637/

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
const int N = 1000005;
 
// Recursive solution
int solve(int n){
 
    if(n < 0) return INT_MAX;
    if(n == 0) return 0;
 
    int temp = n, res = INT_MAX;
    while(temp){
        int dig = temp % 10;
        if(dig)
            res = min(res, solve(n - dig) + 1);
        temp /= 10;
    }
    return res;
}
 
vector<int> dp(N, INT_MAX);
//dp[i] = Minimum number of operations to convert
// i to 0.
int solveDP(int n){
 
    if(n < 0) return INT_MAX;
    if(dp[n] != INT_MAX) return dp[n];
    int temp = n;
    while(temp){
        int dig = temp % 10;
        if(dig)
            dp[n] = min(dp[n], solveDP(n - dig) + 1);
        temp /= 10;
    }
    return dp[n];
}
 
int32_t main(){
 
    fastio;
    int n; cin >> n;
    dp[0] = 0;
    cout << solveDP(n);
 
    return 0;
 
}