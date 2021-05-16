// Link - https://www.spoj.com/problems/INVCNT/

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
const ll N = 2e5+5;

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

ll prefixSum(int R){

    ll ans = 0;
    int i = R;
    while(i > 0){
        ans += bt[i];
        i -= (i & (-i));
    }
    return ans;
}

void update(int ind, int val, int n){

    int i = ind;
    while(i <= n){
        bt[i] += val;
        i += (i & (-i));
    }
}

int32_t main() {

    fastio;
    tc{
        int n; cin >> n;
        int arr[n];
        for(int &i : arr) cin >> i;
        memset(bt, 0, sizeof(bt));
        int temp[n];
        for(int i = 0; i < n; i++) temp[i] = arr[i];
        sort(temp, temp + n);

        for(int i = 0; i < n; i++)
            arr[i] = lower_bound(temp, temp+n, arr[i]) - temp + 1;
        ll ans = 0ll;
        for(int i = n-1; i >= 0; i--){
            ans += prefixSum(arr[i]-1);
            update(arr[i], 1, n);
        }
        cout << ans << endl;

    }


    return 0ll;
 
}