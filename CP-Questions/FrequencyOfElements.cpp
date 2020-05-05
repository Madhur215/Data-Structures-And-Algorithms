// Given an unsorted array of integers of size N, having elements between range 1 to N. You need to
// find the frequency of each element in the array.
// This solution takes O(n) time and O(1) extra space, i.e, without using any extra map or array.
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

void printfrequency(int arr[], int n)
{

    // Reduce each term of the array by one, to make them in the range 0 to n-1
	for(int i = 0 ; i < n ; i++)
	    arr[i] -= 1;

    // Add N to every element at index arr[i] % n
	for(int i =0; i<n; i++){
	    arr[arr[i]%n] += n;
	}

	// Count the number of times N was added to a particular index
	for(int i = 0 ; i < n ; i++){
	    cout << arr[i] / n << " ";
	}

}


int main(){
    int n;
    cin >> n;
    int a[n];
    ff1(0, n, 1)
        cin >> a[i];
    printfrequency(a, n);
}
