/*
Tabulation based solution of ALPHACODE problem.
Problem Link: https://www.spoj.com/problems/ACODE/
*/
#include <bits/stdc++.h>
#define ll long long
#define repe(i, j, n) for(ll i = j ; i <= n ; i++)
#define rep(i, j , n) for(ll i = j ; i < n ; i++)
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout<<fixed;cout.precision(10);
#define endl "\n"
#define tc ll T; cin >> T; while(T--)
#define pb push_back
#define mk make_pair
#define mod 1000000007
#define MX 1000001
#define vi vector<int>
#define vs vector<string>
#define pii pair<int, int>
#define S second
#define F first
using namespace std;
 
ll ways(string s, int n){
 
    ll dp[n+1] = {0};
    dp[0] = 1, dp[1] = 1;
 
    rep(i, 2, n+1){
        if(s[i-1] > '0')
            dp[i]= dp[i-1];
 
        if(s[i-2] == '1' or (s[i-2] == '2' and s[i-1] < '7'))
            dp[i] += dp[i-2];
    }
 
    return dp[n];
 
}
 
 
int main(){
 
    fastio;
    while(true){
 
        string s;
        cin >> s;
        if(s == "0")
            break;
        cout << ways(s, (int)s.length()) << endl;
 
    }
    return 0;
}