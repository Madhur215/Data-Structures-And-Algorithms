#include <bits/stdc++.h>
#define ll long long
#define ff2(j , n , k) for(ll i = j ; i <= n ; i += k)
#define ff1(j , n , k) for(ll i = j ; i < n ; i += k)
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);
#define endl "\n"
#define pb push_back
#define mk make_pair
#define mod 1000000007
#define MX 1000001
using namespace std;
vector<int> v;

void primeFactorization(int n){

	while(n % 2 == 0){
		v.pb(2);
		n = n / 2;
	}

	for(int i = 3; i <= sqrt(n); i += 2){
		while(n%i == 0){
			v.pb(i);
			n /= i;
		}
	}

	if(n > 2)
		v.pb(n);
}

int main() {
	int n;
	cin >> n;
	primeFactorization(n);
	for(auto i:v)
		cout << i << " ";



	return 0;
}
