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

int buildTree(int* tree, int ss, int se, int si, int *arr){

    if(ss == se){
        tree[si] = arr[ss];
        return arr[ss];
    }

    int mid = (ss + se) / 2;
    tree[si] = buildTree(tree, ss, mid, 2*si+1, arr) + buildTree(tree, mid+1, se, 2*si+2, arr);
    return tree[si];

}


int main(){

    int n = 5;
    int tree[4 * n];
    memset(tree, -1, sizeof(tree));

    int arr[] = {2, 4, 1, 6, 8};
    buildTree(tree, 0, n-1, 0, arr);
    for(int i = 0; i < 20; i++)
        cout << tree[i] << " ";
    cout << endl;

}
