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

// Helper function to fill lps array
vector<int> kmp(string &s){

    int n = s.length();
    vector<int> lps(n);
    for(int i = 1; i < n; i++){

        int j = lps[i-1];
        while(j > 0 and s[i] != s[j])
            j = lps[j-1];
        if(s[i] == s[j])
            j++;
        lps[i] = j;
    }
    return lps;
}

int main() {

    fastio;
    int n; 
    while(cin >> n){
        string pat, txt;
        cin >> pat >> txt;
        
        string str = pat + "$" + txt;
        vector<int> lps = kmp(str);

        for(int i = n+1; i < str.length(); i++){
            if(lps[i] == n){
                cout << i - 2*n << endl;
            }
        }
        cout << endl;

    }


    return 0;

}