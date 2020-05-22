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

int Lomuto(int *a, int l, int h){
    int pivot = a[h];
    int i = l-1;
    for(int j = l ; j <= h-1 ; j++){
        if(a[j] < pivot){
            i++;
            swap(a[i], a[j]);
        }
    }
    swap(a[i+1], a[h]);
    return i+1;

}

int Hoare(int *a, int l ,int h){
    int pivot = a[l];
    int i =l-1, j = h+1;
    while(true){
        do{
            i++;
        }while(a[i] < pivot);
        do{
            j--;
        }while(a[j] > pivot);

        if(i >= j)
            return j;
        swap(a[i], a[j]);
    }

}

int main(){
    int a[] = {1, 2, 5, 10, 15, 9, 7, 6, 4};
    cout << Lomuto(a, 0, 8);
    cout << " " << Hoare(a, 0, 8);

}
