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
const int N = 1e5;

vector<ll> primes;

void sieve(){

    int arr[N+1]{};
    arr[0] = arr[1] = 1;
    for(ll i = 2 ; i <= sqrt(N) ; i++){
        if(arr[i] == 0){
            for(ll j = i*i ; j <= N ; j += i){
                arr[j] = 1;
            }
        }
    }

    for(ll i = 2; i <= N; i++)
        if(arr[i] == 0) primes.pb(i);
    
}

int main() {

    fastio;
    
    sieve();

    ll n, m; cin >> m >> n;

    int segment[n-m+1]{};

    for(ll x : primes){
        if(x * x > n) break;

        ll start = (m / x) * x;
        if(start < m) start += x;

        for(ll i = start; i <= n; i += x)
            segment[i-m] = 1;
        if(start == x and start <= n) segment[start-m] = 0;

    }

    for(ll i = 0; i < n-m+1; i++){
        if(segment[i] == 0 and i+m != 1)
            cout << i + m << endl;
    }
    cout << endl;


    return 0;

}
