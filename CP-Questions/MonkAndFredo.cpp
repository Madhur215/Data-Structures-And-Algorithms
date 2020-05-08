/*
Fredo and you are talking about a movie that you have recently watched while Monk is busy teaching Number Theory.
Sadly, Monk caught Fredo talking to you and asked him to answer his question in order to save himself from punishment.
The question says:
Given two weights of a and b units, in how many different ways you can achieve a weight of d units using only the
given weights? Any of the given weights can be used any number of times (including 0 number of times).
Since Fredo is not able to answer the question, he asked you to help him otherwise he will get punished.

Note: Two ways are considered different if either the number of times a is used or number of times b is used is
different in the two ways.

*/
/*
Below solution uses Extended Euclid algorithm.

*/

#include <bits/stdc++.h>
#define ll long long
#define ff2(j , n , k) for(ll i = j ; i <= n ; i += k)
#define ff1(j , n , k) for(ll i = j ; i < n ; i += k)
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);
#define endl "\n"
#define tc ll t; cin >> t; while(t--)
#define pb push_back
#define mk make_pair
#define mod 1000000007
#define MX 1000001
#define vi vector<int>
#define vs vector<string>
using namespace std;


struct triplet{
    int x;
    int y;
    int gcd;

};

triplet euclid(int a, int b){
    if(b == 0){
        triplet ans;
        ans.x = 1;
        ans.y = 0;
        ans.gcd = a;
        return ans;
    }

    triplet ans;
    triplet smallAns = euclid(b, a%b);
    ans.x = smallAns.y;
    ans.y = smallAns.x - (a/b)*smallAns.y;
    ans.gcd = smallAns.gcd;
    return ans;
}

ll inverse(int a, int m){

    ll b = euclid(a, m).x;
    return ((b%m) + m)%m;

}



int main(){
	// Write your code here

    int t;
    cin >> t;
    while(t--){
        ll a, b, d;
        cin >> a >> b >> d;
        ll n;
        ll g = __gcd(a, b);
        if(d%g){
            cout << 0 << endl;
            continue;
        }

  		if(d == 0){
            cout << 1 << endl;
            continue;
        }

        a /= g;
        b /= g;
        d /= g;
        ll y1 = ((d%a) * inverse(b, a)) % a;
        if(d < y1*b){
            cout << 0 << endl;
            continue;
        }

        n = ((d/b) - y1) / a;
        cout << n + 1 << "\n";


    }
	return 0;
}
