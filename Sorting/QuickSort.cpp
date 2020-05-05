#include <iostream>

using namespace std;

int partitionArray(int a[] , int l , int r){
    int pivot = a[r];
    int i = l - 1;

    for(int j = l ; j < r ; j++){
        if(a[j] < pivot){
            i++;
            int temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
    }

    int temp1 = a[i+1];
    a[i+1] = a[r];
    a[r] = temp1;

    return i+1;
}

void quickSort(int a[] , int l , int r){

    if(l < r){
        int p = partitionArray(a , l , r);

        quickSort(a , l , p - 1);
        quickSort(a , p+1 , r);
    }

}

int main()
{
    int a[20];
    int n;
    cin >> n;
    for(int i = 0 ; i < n ; i++){
        cin >> a[i];
    }
    quickSort(a , 0 , n - 1);
    cout << endl;
    cout << endl;
    for(int i = 0 ; i < n ; i++){
        cout << a[i] << endl;
    }
    return 0;
}
