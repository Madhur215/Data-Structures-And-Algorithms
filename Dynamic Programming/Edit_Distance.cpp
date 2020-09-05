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


string s1, s2;
int solve(int n, int m){


    /* Recursive solution */
    // if(n == 0)
    //     return m;
    // if(m == 0)
    //     return n;

    // if(s1[n-1] == s2[m-1])
    //     return solve(n-1, m-1);
    
    // return 1 + min({
    //     solve(n-1, m-1),
    //     solve(n-1, m),
    //     solve(n, m-1)
    // });

    /* DP solution */
    int dp[n+1][m+1];
    rep(i, 0, n+1){
        dp[i][0] = i;
    }
    rep(i, 0, m+1){
        dp[0][i] = i;
    }

    rep(i, 1, n+1){
        rep(j, 1, m+1){
            if(s1[i-1] == s2[j-1]){
                dp[i][j] = dp[i-1][j-1];
            }
            else{
                dp[i][j] = 1 + min({dp[i-1][j], dp[i][j-1], dp[i-1][j-1]});
            }
        }
    }

    return dp[n][m];

}

int main(){
 
    fastio;
    // tc{
        int n, m;
        cin >> s1 >> s2;
        n = (int)s1.length();
        m = (int)s2.length();

        cout << solve(n, m) << endl;


    // }
 
 
    return 0;
}
 