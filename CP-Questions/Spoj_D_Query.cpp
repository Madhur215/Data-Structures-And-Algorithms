// Link - https://www.spoj.com/problems/DQUERY/ 
// Mo's Algorithm


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

int block, cnt = 0;
vector<int> val(N);

struct Query{
    int a, b, ind;
    bool operator<(Query q){
        if(a/block != q.a/block)
            return a/block < q.a/block;
        return b < q.b;
    }
};

void remove(int x){
    val[x]--;
    if(val[x] == 0) cnt--;
}

void add(int x){
    val[x]++;
    if(val[x] == 1) cnt++;
}

int n;
vector<int> arr;

int32_t main() {

    fastio;
    cin >> n;
    arr.resize(n);
    for(auto &i : arr) cin >> i;
    block = sqrt(n);
    int q; cin >> q;
    vector<Query> qr;
    int a, b;
    for(int i = 0; i < q; i++){
        cin >> a >> b;
        qr.pb(Query{a-1, b-1, i});
    }

    sort(qr.begin(), qr.end());
    vector<int> ans(q);
    int currL = 0, currR = -1;

    for(int i = 0; i < q; i++){
        int l = qr[i].a, r = qr[i].b;

        while(currL < l){
            remove(arr[currL]);
            currL++;
        }
        while(currL > l){
            currL--;
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
        ans[qr[i].ind] = cnt;
    }

    for(auto i : ans)
        cout << i << endl;

    return 0ll;
 
}