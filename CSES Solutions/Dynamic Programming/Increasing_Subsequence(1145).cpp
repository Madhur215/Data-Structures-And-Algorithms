// Link - https://cses.fi/problemset/task/1145

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
 
int index(vector<int> &dp, int e, int x){
 
    int s = 0;
    while(s < e){
        int m = s + (e - s) / 2;
        if(dp[m] >= x)
            e = m;
        else s = m+1;
    }
    return e;
}
 
int32_t main(){
 
    fastio;
    int n; cin >> n;
    vector<int> arr(n);
    for(auto &i : arr) cin >> i;
 
    vector<int> dp(n);
    // dp[i] = Minimum value for LIS of length(i+1);
    dp[0] = arr[0];
    int len = 1;
    for(int i = 1; i < n; i++){
        if(arr[i] > dp[len-1]){
            dp[len] = arr[i]; len++;
            continue;
        }
        int ind = index(dp, len-1, arr[i]);
        dp[ind] = arr[i];
    }
    cout << len;
 
    return 0;
 
}