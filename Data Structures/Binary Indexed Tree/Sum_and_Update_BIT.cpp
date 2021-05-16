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
const ll N = 1e6+5;

int bt[N];

void build(int n, int arr[]){

    memset(bt, 0, sizeof(bt));
    for(int i = 1; i <= n; i++){
        int curr = arr[i-1], k = i;
        while(k <= n){
            bt[k] += curr;
            k += (k & (-k));
        }
    }

}

int prefixSum(int R, int n){

    ll ans = 0;
    int i = R + 1;
    while(i > 0){
        ans += bt[i];
        i -= (i & (-i));
    }
    return ans;
}

void update(int ind, int val, int n){

    int i = ind+1;
    while(i <= n){
        bt[i] += val;
        i += (i & (-i));
    }
}

int32_t main() {

    fastio;
    int n; cin >> n;
    int arr[n];
    for(int &i : arr) cin >> i;
    build(n, arr);

    cout << prefixSum(3, n);
    update(2, 10, n);
    cout << prefixSum(3, n);



    return 0ll;
 
}