// Link - https://cses.fi/problemset/task/1635

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
const int N = 105;
const int MAX_SUM = 1000005;

int32_t main(){

    fastio;
    int n, x; cin >> n >> x;
    vector<int> arr(n);
    for(auto &i : arr) cin >> i;

    int dp[x+1]{};
    dp[0] = 1;

    for(int i = 1; i <= x; i++){
        for(int j = 0; j < n; j++){
            if(arr[j] <= i)
                dp[i] = (dp[i] + dp[i - arr[j]]) % mod;
        }
    }

    cout << dp[x];

    return 0;
 
}