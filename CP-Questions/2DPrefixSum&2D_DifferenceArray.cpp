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
const int N = 1e3;

int n, m;
ll mat[N+1][N+1];
// pre[i][j] stores the sum of all elements 
// on top of (i,j) and on left of (i,j)
ll pre[N+1][N+1];

void Prefix2D(ll temp[N+1][N+1]){

    pre[0][0] = temp[0][0];
    for(int i = 1; i < m; i++)
        pre[0][i] = pre[0][i-1] + temp[0][i];

    for(int i = 1; i < n; i++)
        pre[i][0] = pre[i-1][0] + temp[i][0];
    
    for(int i = 1; i < n; i++){
        for(int j = 1; j < m; j++)
            pre[i][j] = temp[i][j] + pre[i-1][j] + pre[i][j-1] - pre[i-1][j-1];
    }

}

// 2D Difference array
ll diff[N+1][N+1];

void Difference2D(){

    diff[0][0] = mat[0][0];
    for(int i = 1; i < m; i++)
        diff[0][i] = mat[0][i] - mat[0][i-1];
    for(int i = 1; i < n; i++)
        diff[i][0] = mat[i][0] - mat[i-1][0];
    
    for(int i = 1; i < n; i++){
        for(int j = 1; j < m; j++)
            diff[i][j] = mat[i][j] - mat[i-1][j] - mat[i][j-1] + mat[i-1][j-1];
    }

}

int main() {

    fastio;
    

    return 0;

}
