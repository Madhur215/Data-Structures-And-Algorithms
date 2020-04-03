#include <iostream>

using namespace std;

void insertionSort(int a[] , int n){
    int j , temp;
    for(int i = 1 ; i < n ; i++){
        temp = a[i];
        j = i - 1;
        while(j >= 0 && a[j] > temp){
            a[j+1] = a[j];
            j--;

        }
        a[j+1] = temp;
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
    insertionSort(a , n);
    cout << endl;
    cout << endl;
    for(int i = 0 ; i < n ; i++){
        cout << a[i] << endl;
    }
    return 0;
}
