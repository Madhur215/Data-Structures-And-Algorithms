#include<bits/stdc++.h>
#define ll long long
#define ff1(j, n, k) for(ll i = j; i < n; i++)
#define ff2(j, n, k) for(ll i = j; i <= n; i++)
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);
#define pb push_back
#define mk make_pair
#define endl "\n"
#define tc ll t; cin >> t; while(t--)
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


int main(){
    int a = 17;
    int b = 17;
    triplet ans = euclid(a, b);
    cout << ans.x << " " << ans.y << " " << ans.gcd;

}










