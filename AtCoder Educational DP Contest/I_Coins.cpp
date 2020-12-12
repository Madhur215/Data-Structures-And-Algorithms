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
#define setbits(x) __builtin_popcountll(x)
#define zerobits(x) __builtin_ctzll(x)
#define S second
#define F first
#define pi acos(-1)
using namespace std;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<string> vs;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int N = 1e5;

double ans = 0;
int n;
double arr[3000];

double dp[3001][3001];
// dp[i][j] = p-bility of 
// having i heads among j coins

void solve(){

    memset(dp, 0, sizeof(dp));
    dp[0][0] = 1;

    rep(i, 0, n){

        dp[0][i+1] = (1-arr[i]) * dp[0][i];

        for(int j = 1; j <= i+1; j++){
            // p-ability of getting j heads
            // among i+1 coins.
            // If we take head in this move then, 
            // we have to take j-1 heads among all pevious moves
            // If we take tails in this move then,
            // take j heads in all previous moves with i coins.
            dp[j][i+1] = arr[i] * dp[j-1][i] + 
                        (1 - arr[i]) * dp[j][i];
        }
    }

    // sum all p-abilities where 
    // num of heads is more than
    // n/2
    repe(i, n/2+1, n){
        ans += dp[i][n];
    }

}



int main(){

    fastio;
    cin >> n;
    rep(i, 0, n) cin >> arr[i];

    solve();
    cout << ans;
    
    return 0;
}
