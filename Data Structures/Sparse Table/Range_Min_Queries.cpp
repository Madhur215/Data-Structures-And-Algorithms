#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout<<fixed;cout.precision(10);
#define endl "\n"
#define tc ll T; cin >> T; while(T--)
#define pb push_back
#define mod 1000000007
#define S second
#define F first
using namespace std;
typedef long long ll;
const ll N = 4e5+5;
 
int32_t main() {
 
    fastio;
    int n; cin >> n;
    vector<int> arr(n);
    for(auto &i : arr) cin >> i;
    const int logN = 22;
 
    vector<vector<int>> st(n+1, vector<int>(logN, INT_MAX));
    for(int i = 0; i < n; i++)
        st[i][0] = arr[i];
    
    // RANGE MIN/MAX QUERIES
    for(int j = 1; j < logN; j++){
        for(int i = 0; i + (1 << j) <= n; i++)
            st[i][j] = min(st[i][j-1], st[i + (1 << (j-1))][j-1]);
    }
 
    int q; cin >> q;
    int l, r;
    while(q--){
        cin >> l >> r;
        int j = log2(r - l + 1);
        cout << min(st[l][j], st[r - (1 << j) + 1][j]) << endl;
    }

 
    return 0ll;
 
} 