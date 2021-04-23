// Link - https://cses.fi/problemset/task/1746

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
const int N = 1002;

int n, m;
int dp[100005][102];
// dp[i][j] = Number of arrays that can be formed
// by putting value j on index i...

// DP Solution
int numWays(vector<int> &arr){

    int cnt = 0;
    if(arr[0] == 0)
        for(int i = 0; i <= m; i++) dp[0][i] = 1;
    else
        dp[0][arr[0]] = 1;

    for(int i = 1; i < n; i++){
        if(arr[i] == 0){
            for(int j = 1; j <= m; j++){
                (dp[i][j] += dp[i-1][j]) %= mod;
                if(j > 1) (dp[i][j] += dp[i-1][j-1]) %= mod;
                if(j < m) (dp[i][j] += dp[i-1][j+1]) %= mod;
            }
        }
        else{
            (dp[i][arr[i]] += dp[i-1][arr[i]]) %= mod;
            if(arr[i] > 1) (dp[i][arr[i]] += dp[i-1][arr[i]-1]) %= mod;
            if(arr[i] < m) (dp[i][arr[i]] += dp[i-1][arr[i]+1]) %= mod;
        }
    }

    for(int i = 1; i <= m; i++){
        (cnt += dp[n-1][i]) %= mod;
    }
    return cnt;

}


int32_t main(){

    fastio;
    cin >> n >> m;
    vector<int> arr(n);
    for(auto &i : arr) cin >> i;
    memset(dp, 0, sizeof(dp));
    cout << numWays(arr) << endl;

    return 0;
 
}