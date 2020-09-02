/*
Problem Link: https://www.spoj.com/problems/AIBOHP/
Memoization based solution
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

ll dp[6105][6105];
string s;

ll solve(int i, int j){

    /* Recursive solution */ 
    
    /* Params: i = start index, j = end index */
    // if(i == j)
    //     return 0;
    // if(i > j or j < 0 or i >= (int)s.length())
    //     return INT_MAX;
    // if(s[i] == s[j]){
    //     if(j != i+1)
    //         return solve(s, i+1, j-1);
    //     return 0;
    // }
    // return min(solve(s, i+1, j), solve(s, i, j-1)) + 1;

    /* Dp solution */
    if(i > j)
        return INT_MAX;

    if(dp[i][j] != -1)
        return dp[i][j];
    if(s[i] == s[j]){
        if(j != i+1)
            return dp[i][j] = solve(i+1, j-1);
        return dp[i][j] = 0;
    }
    return dp[i][j] = (min(solve(i+1, j), solve(i, j-1)) + 1);

}


int main(){

    fastio;
    tc{
        
        cin >> s;
        int n = (int)s.length();
        memset(dp, -1,sizeof(dp));
        rep(i, 0, n+1){
            rep(j, 0, n+1){
                if(i == j)
                    dp[i][j] = 0;
            }
        }
        cout << solve(0, n-1) << endl;

    }


    return 0;
}
