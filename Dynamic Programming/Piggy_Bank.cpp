/*
Using 2D array and memoization approach!
Problem Link: https://www.spoj.com/problems/PIGBANK/
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
const int MAX = 10005;

int val[MAX], wt[MAX];
ll dp[505][MAX];

ll solve(ll req, ll n, int ind) {
	
    // if(ind >= n)
    //     return INT_MAX;
    // if(req == 0)
    //     return 0;
    // if(req < 0)
    //     return INT_MAX;
    
    // return min(solve(req, n, ind+1), solve(req - wt[ind], n, ind) + val[ind]);

    if(ind > n or req < 0 or ind < 0)
        return INT_MAX;
    if(dp[ind][req] != -1)
        return dp[ind][req];
    
    return dp[ind][req] = min(solve(req, n, ind-1), solve(req-wt[ind-1], n, ind) + val[ind-1]);
   
}

int main(){

    fastio;
    tc{
        int a, b;
        cin >> a >> b;
        int req = b - a;
        int n;
        cin >> n;
        rep(i, 0, n+1){
            rep(j, 0, req+1)
                dp[i][j] = -1;
        }

        rep(i, 0, n+1){
            dp[i][0] = 0;
        }
        rep(i, 1, req+1){
            dp[0][i] = INT_MAX;
        }

        rep(i, 0, n){
            cin >> val[i] >> wt[i];
        }

        int ans = solve(req, n, n);
        if(ans == INT_MAX)
            cout << "This is impossible.\n";
        else
            cout << "The minimum amount of money in the piggy-bank is " << ans << "." << endl;
    }

    return 0;
}
