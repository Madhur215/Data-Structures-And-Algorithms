#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout<<fixed;cout.precision(10);
#define endl "\n"
#define tc ll T; cin >> T; while(T--)
#define pb push_back
#define mod 1000000007
#define S second
#define F first
using namespace std;
typedef long long ll;
const ll N = 1e5+5;

int seg[N], lazy[N];
int arr[N];

void build(int ind, int low, int high){

    if(low == high){
        seg[ind] = arr[low]; return; 
    }

    int mid = (low + high) / 2;
    build(2 * ind + 1, low, mid);
    build(2 * ind + 2, mid + 1, high);
    seg[ind] = seg[2 * ind + 1] + seg[2 * ind + 2];
    
}

int rangeSum(int ind, int low, int high, int left, int right){

    // completely overlaps
    if(low >= left and high <= right)
        return seg[ind];

    // Do not lies
    if(low > right or high < left) return 0;
    int mid = (low + high) / 2;
    int la = rangeSum(2 * ind + 1, low, mid, left, right);
    int ra = rangeSum(2 * ind + 2, mid + 1, high, left, right);
    return la + ra;
}

// Add a value x to the element at index pos
void pointUpdate(int ind, int low, int high, int x, int pos){

    if(low == high){
        seg[ind] += x;
        return;
    }

    int mid = (low + high) / 2;
    if(pos >= low and pos <= mid) pointUpdate(2 * ind + 1, low, mid, x, pos);
    else pointUpdate(2 * ind + 2, mid+1, high, x, pos);
    seg[ind] = seg[2 * ind + 1] + seg[2 * ind + 2];

}

// Add a value x to all elements in the range [left.....right]
void rangeUpdate(int ind, int low, int high, int left, int right, int x){

    // Check if there is already some value in lazy[ind]
    if(lazy[ind] != 0){
        seg[ind] += (high - low + 1) * lazy[ind];
        if(low != high){
            lazy[2 * ind + 1] += lazy[ind];
            lazy[2 * ind + 2] += lazy[ind];
        }
        lazy[ind] = 0;
    }

    if(low > right or high < left) return;
    if(low >= left and high <= right){
        seg[ind] += (high - low + 1) * x;
        if(low != high){
            lazy[2*ind+1] += x;
            lazy[2*ind+2] += x;
        }
        return;
    }

    int mid = (low + high) / 2;
    rangeUpdate(2*ind+1, low, mid, left, right, x);
    rangeUpdate(2*ind+2, mid+1, high, left, right, x);
    seg[ind] = seg[2*ind+1] + seg[2*ind+2];

}

int querySumLazy(int ind, int low, int high, int left, int right){

    int l = 2 * ind + 1, r = 2 * ind + 2;
    if(lazy[ind] != 0){
        seg[ind] += lazy[ind] * (high - low + 1);
        if(low != high){
            lazy[l] += lazy[ind];
            lazy[r] += lazy[ind];
        }
        lazy[ind] = 0;
        return;
    }

    if(low > right or high < left) return;
    if(low >= left and high <= right) return seg[ind];

    int mid = (low + high) / 2;
    return querySumLazy(l, low, mid, left, right) + 
        querySumLazy(r, mid + 1, high, left, right);

}

int main() {

    fastio;
    int n; cin >> n;
    

    return 0;
 
}