#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int arr[n+1] = {0};
    arr[0] = arr[1] = 1;
    for(int i = 2 ; i <= sqrt(n) ; i++){
        if(arr[i] == 0){

            for(int j = i*i ; j <= n ; j += i){
                arr[j] = 1;
            }
        }
    }

    for(int i = 0; i < n ; i++){
        if(arr[i] == 0)
            cout << i << " ";
    }

    return 0;
}
