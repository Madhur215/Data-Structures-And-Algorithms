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

int kadane(int *a, int n){
    int curr_sum = 0;
    int max_sum = INT_MIN;

    ff1(0, n, 1){
        curr_sum += a[i];
        if(max_sum < curr_sum)
            max_sum = curr_sum;

        if(curr_sum < 0)
            curr_sum = 0;
    }
    return max_sum;

}


int main(){
    int n;
    cin >> n;
    int a[n];

    ff1(0, n, 1){
        cin >> a[i];
    }
    cout << kadane(a, n) << endl;
}
