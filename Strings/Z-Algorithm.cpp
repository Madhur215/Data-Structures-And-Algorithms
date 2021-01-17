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
const int N = 2e5;

int main() {

    fastio;
    tc{
        string s, t;
        cin >> s >> t;
        string str = t + "$" + s;

        int n = s.length(), m = t.length();
        vector<int> z(str.length());

	// Fill the Z-array
        for(int i = 1, l = 0, r = 0; i < str.length(); i++){
            if(i <= r)
                z[i] = min(z[i-l], r-i+1);
            while(i + z[i] < str.length() and str[z[i]] == str[i+z[i]])
                ++z[i];
            if(i + z[i] - 1 > r){
                l = i;
                r = i + z[i] - 1;
            }
        }

        vector<int> ans;
        for(int i = m+1; i < str.length(); i++){
            if(z[i] == m){
                ans.pb(i-m);
            }
        }
        if(!ans.size()){
            cout << "Not Found\n";
        }
        else{
            cout << ans.size() << endl;
            for(auto i : ans)
                cout << i << " ";
            cout << endl;
        }

        cout << endl;
    }


    return 0;

}