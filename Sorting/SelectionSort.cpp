
#include <iostream>

using namespace std;

void selectionSort(int a[] , int n){

    for(int i = 0 ; i < n - 1   ; i++){

        int index = i;
        for(int j = i + 1 ; j < n ; j++){

            if(a[j] < a[index]){
                index = j;
            }

        }

        int temp = a[i];
        a[i] = a[index];
        a[index] = temp;

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
    selectionSort(a , n);
    cout << endl;
    cout << endl;
    for(int i = 0 ; i < n ; i++){
        cout << a[i] << endl;
    }
    return 0;
}
