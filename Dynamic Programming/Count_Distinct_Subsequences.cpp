/*
Problem Link: https://www.spoj.com/problems/DSUBSEQ/
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
 
void iarr(int *a, int n){
    rep(i, 0, n)
        cin >> a[i];
}

int countDistinct(string s){

    int n = (int)s.length();
    int last[256];
    memset(last, -1, sizeof(last));
    ll dp[n+1] = {0};
    dp[0] = 1;
    rep(i, 1, n+1){
        dp[i] = (2 * dp[i-1]) % mod;
        if(last[s[i-1]] != -1){
            dp[i] = (dp[i] - dp[last[s[i-1]]] + mod) % mod;
        }
        last[s[i-1]] = i - 1;
    }

    return dp[n];
}


int main(){
 
    fastio;
    tc{
        string s;
        cin >> s;
        cout << countDistinct(s) << endl;

    }
 
 
    return 0;
}
 