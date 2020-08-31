/*
Find the number of squares present in a N X N grid.
Problem Link: https://www.spoj.com/problems/SAMER08F/
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


ll solve(ll n) {
	
    ll cnt = 0;

    rep(i, 1, n+1){
        rep(j, 1, n+1){
            if((i >= j or j >= i) and i > 1 and j > 1){
                cnt += (min(i, j) - 1);
            }
        }
    }
    cnt += (n * n);
    return cnt;

}

int main(){

    fastio;
    while(true){
        ll n;
        cin >> n;
        if(n == 0)
            break;
        cout << solve(n) << endl;

    }

    return 0;
}
