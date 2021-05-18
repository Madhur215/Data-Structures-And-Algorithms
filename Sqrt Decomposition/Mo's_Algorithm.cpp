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

const int block = 555;

ll sum = 0;
vector<ll> mp(N);

struct Query{
    int a, b, ind;
    bool operator<(Query q){
        if(a/block != q.a/block)
            return a/block < q.a/block;
        return b < q.b;
    }
};

void remove(ll x){
    
    sum -= (mp[x] * mp[x] * x);
    mp[x]--;    
    sum += (mp[x] * mp[x] * x);
}

void add(ll x){
    
    sum -= (mp[x] * mp[x] * x);
    mp[x]++;
    sum += (mp[x] * mp[x] * x);
}

int n;
vector<ll> arr;

int32_t main() {

    fastio;
    int q;
    cin >> n >> q;
    arr.resize(n);
    for(auto &i : arr) cin >> i;

    vector<Query> qr;
    int a, b;
    for(int i = 0; i < q; i++){
        cin >> a >> b;
        qr.pb(Query{a-1, b-1, i});
    }
    // Sort the queries
    sort(qr.begin(), qr.end());
    vector<ll> ans(q);
    int currL = 0, currR = -1;

    for(int i = 0; i < q; i++){
        int l = qr[i].a, r = qr[i].b;

        while(currL < l){
	    // Desired "remove" function
            remove(arr[currL]);
            currL++;
        }
        while(currL > l){
            currL--;
	    // Desired "add" function
            add(arr[currL]);
        }
        while(currR < r){
            currR++;
            add(arr[currR]);
        }
        while(currR > r){
            remove(arr[currR]);
            currR--;
        }
        ans[qr[i].ind] = sum;
    }

    for(auto i : ans)
        cout << i << endl;

    return 0ll;
 
}