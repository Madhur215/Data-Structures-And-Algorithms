// Link - https://www.spoj.com/problems/MATSUM/

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
const ll N = 1400;

int n;
vector<vector<ll>> arr;
vector<vector<ll>> bt;

void update(int x, int y, ll val){

    for(int i = x; i <= n; i += (i & (-i)))
        for(int j = y; j <= n; j += (j & (-j)))
            bt[i][j] += val;
}

ll query(int x, int y){
    ll sum = 0ll;
    for(int i = x; i > 0; i -= (i & (-i)))
        for(int j = y; j > 0; j -= (j & (-j)))
            sum += bt[i][j];
    return sum;
}

void build(){
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            update(i+1, j+1, arr[i][j]);

}

int32_t main() {

    fastio;
    tc{
        cin >> n;
        arr = vector<vector<ll>>(n, vector<ll>(n));
        bt = vector<vector<ll>>(n+1, vector<ll>(n+1));
        build();
        string s;
        while(1){
            cin >> s;
            if(s == "END") break;
            if(s == "SET"){
                int x, y, v;
                cin >> x >> y >> v;
                update(x+1, y+1, -arr[x][y]);
                update(x+1, y+1, v);
                arr[x][y] = v;
            }
            else{
                int x1, x2, y1, y2;
                cin >> x1 >> y1 >> x2 >> y2;
                x1++, y1++, x2++, y2++;
                cout << query(x2, y2) - query(x1-1, y2) - query(x2, y1-1) 
                    + query(x1-1, y1-1) << endl;
            }
        }

    }


    return 0ll;
 
}