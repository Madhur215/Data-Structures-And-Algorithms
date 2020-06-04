#include <bits/stdc++.h>
#define ll long long
#define ff2(j , n , k) for(ll i = j ; i <= n ; i += k)
#define ff1(j , n , k) for(ll i = j ; i < n ; i += k)
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout << fixed;cout.precision(10);
#define endl "\n"
#define tc ll T; cin >> T; while(T--)
#define pb push_back
#define mk make_pair
#define mod 1000000007
#define MX 1000001
#define vi vector<int>
#define vs vector<string>
#define pii pair<int, int>

using namespace std;

void rabinKarp(string txt, string pat){
    int n = (int)txt.length();
    int m = (int)pat.length();
    int d = 5;
    // computing (d^(m-1)) % mod
    int h = 1;
    for(int i = 1; i < m; i++)
        h = (h * d) % mod;

    // computing hash value of pattern(p) and first window(t)
    int p = 0, t = 0;
    for(int i = 0; i < m; i++){
        p = (p * d + pat[i]) % mod;
        t = (t * d + txt[i]) % mod;
    }

    for(int i = 0; i <= n - m ; i++){

        // check for spurious hit
        if(p == t){
            int f = 0;
            for(int j = 0; j < m; j++){
                if(txt[j+i] != pat[j]){
                    f = 1;
                    break;
                }
            }
            if(f == 0)
                cout << i << " ";
        }

        // changing the hash value of next window
        if(i < n-m){
            t = (d * (t - txt[i] * h) + txt[i+m]) % mod;
            if(t < 0)
                t += mod;

        }
    }

}


int main(){
    string text, pattern;
    cin >> text >> pattern;
    rabinKarp(text, pattern);

    return 0;
}
