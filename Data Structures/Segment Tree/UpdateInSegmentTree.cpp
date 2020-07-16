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

int getSum(int *tree, int ss, int se, int qs, int qe, int si){

    if(ss > qe or se < qs)
        return 0;
    if(qs <= ss and qe >= se)
        return tree[si];

    int mid = (se + ss) / 2;
    return getSum(tree, ss, mid, qs, qe, 2*si+1) + getSum(tree, mid+1, se, qs, qe, 2*si+2);

}

void update(int* tree, int ss, int se, int si, int i, int diff){

    if(i < ss or i > se)
        return;
    tree[si] += diff;

    if(se > ss){
        int mid = (se + ss) / 2;
        update(tree, ss, mid, 2*si+1, i, diff);
        update(tree, mid+1, se, 2*si+2, i, diff);
    }


}


int main(){

    int n = 5;
    int tree[4 * n];
    memset(tree, -1, sizeof(tree));

    int arr[] = {2, 4, 1, 6, 8};
    buildTree(tree, 0, n-1, 0, arr);
    cout << getSum(tree, 0, n-1, 2, 4, 0) << endl;
    arr[3] = 4;
    update(tree, 0, n-1, 0, 3, 2);
    cout << getSum(tree, 0, n-1, 2, 4, 0);


}
