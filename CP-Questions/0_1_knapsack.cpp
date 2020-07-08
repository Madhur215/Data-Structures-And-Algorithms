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

/*  Given n items with their values and weights and a knapsack of capacity W.
    Find the maximum value that can be made by putting the items in the knapsack
    with total weight no more than W */

// Recursive solution

int RecursiveKnapsack(int v[], int wt[], int W, int n){
    if(n == 0 or W == 0)
        return 0;

    if(wt[n-1] > W)
        return RecursiveKnapsack(v, wt, W, n-1);
    return max(RecursiveKnapsack(v, wt, W, n-1), v[n-1] + RecursiveKnapsack(v, wt, W - wt[n-1], n-1));

}

// Dynamic Programming Solution
int DPKnapsack(int v[], int wt[], int W, int n){
    int dp[n+1][W+1];
    // Initialize first row with 0
    for(int i = 0; i <= W; i++)
        dp[0][i] = 0;
    // Initialize first column with 0
    for(int i = 0; i <= n; i++)
        dp[i][0] = 0;

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= W; j++){

            if(wt[i-1] > j)
                dp[i][j] = dp[i-1][j];
            else
                dp[i][j] = max(dp[i-1][j], v[i-1] + dp[i-1][j - wt[i-1]]);
        }
    }
    return dp[n][W];
}



int main(){
    int v[] = {10, 40, 30, 50};
    int wt[] = {5, 4, 6, 3};
    int W = 10;

    cout << RecursiveKnapsack(v, wt, W, 4) << endl;
    cout << DPKnapsack(v, wt, W, 4);


}
