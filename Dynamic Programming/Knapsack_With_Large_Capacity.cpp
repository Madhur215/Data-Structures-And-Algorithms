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

const int N = 1e2;
const int MAX_SUM = 1e5;
const ll WM = 1000000005;
vector<pll> arr;
int n, w;
ll dp[MAX_SUM+1][N];

// returns the min weight required
// to get "value" 
ll solve(int value, int x){

    if(value <= 0) return 0;

    if(x == n) return WM;

    if(dp[value][x] != -1){
        return dp[value][x];
    }
    dp[value][x] = min(solve(value, x+1), 
                        solve(value - arr[x].S, x+1) + arr[x].F);

    return dp[value][x];
}

int main(){

    fastio;
    cin >> n >> w;

    rep(i, 0, n){
        int a, b; cin >> a >> b;
        arr.pb({a, b});
    }
    memset(dp, -1, sizeof(dp));

    for(int i = MAX_SUM; i >= 0; i--){
        if(solve(i, 0) <= w){
            cout << i;
            return 0;
        }
    }

    cout << 0;

    return 0;
}
