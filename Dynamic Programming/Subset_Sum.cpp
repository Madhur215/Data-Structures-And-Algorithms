#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout<<fixed;cout.precision(10);
#define endl "\n"
#define tc int T; cin >> T; while(T--)
#define pb push_back
#define S second
#define F first
#define int long long
using namespace std;
const int N = 2e5+5;

bool dp[102][N];

bool possible(vector<int> &arr, int n, int sum){

    if(n == 1) return false;
    for(int i = 0; i <= n; i++) dp[i][0] = true;
    for(int j = 1; j <= sum; j++) dp[0][j] = false;
    
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= sum; j++){
            dp[i][j] = dp[i-1][j];
            if(arr[i-1] <= j)
                dp[i][j] = dp[i][j] or dp[i-1][j - arr[i-1]];
        }
    }

    return dp[n][sum];

}

int32_t main(){

    fastio;
    int n; cin >> n;
    vector<int> arr(n);
    int sum = 0, oc = 0, ind = -1;
    for(int i = 0; i < n; i++){
        cin >> arr[i], sum += arr[i];
        if(arr[i] & 1) ind = i;
    }

    if((sum & 1) or !possible(arr, n, sum/2)){
        cout << 0;
        return 0;
    }
    if(ind != -1){
        cout << "1\n" << ind + 1;
        return 0;
    }

    vector<int> temp;
    for(int i = 0; i < n; i++){
        temp = arr;
        temp.erase(temp.begin() + i);
        if(!possible(temp, n-1, (sum - arr[i])/2)){
            cout << "1\n" << i+1;
            return 0;
        }
    }




    

    return 0;
 
}