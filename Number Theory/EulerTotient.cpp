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

void euler(int *phi){
    for(int i = 2; i <= 1000; i++){
        if(phi[i] == i){
            phi[i] = i-1;
            for(int j = 2*i; j <= 1000; j += i){
                phi[j] = (phi[j] * (i-1)) / i;;
            }
        }
    }

}


int main(){
    int phi[1001];
    ff1(0, 1001, 1){
        phi[i] = i;
    }
    euler(phi);
    ff1(0, 100, 1){
        cout << phi[i] << " ";
    }

}




