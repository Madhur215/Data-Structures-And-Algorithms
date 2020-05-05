#include <iostream>

using namespace std;

void bubbleSort(int a[] , int n){

    for(int i = 0 ; i < n - 1 ; i++){

        for(int j = 0 ; j < n - i - 1 ; j++){

            if(a[j] > a[j+1]){
                int temp = a[j+1];
                a[j+1] = a[j];
                a[j] = temp;
            }
        }

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
    bubbleSort(a , n);
    cout << endl;
    cout << endl;
    for(int i = 0 ; i < n ; i++){
        cout << a[i] << endl;
    }
    return 0;
}
