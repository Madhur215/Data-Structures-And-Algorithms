#include <iostream>

using namespace std;

void indexSearch(int a[] , int n , int s){

    int ind = 0 , e[20] , c[20];
    for(int i = 0 ; i < n ; i+=3){

        e[ind] = a[i];
        c[ind] = i;
        ind++;
    }

    if(s < a[0]){
        cout << "Not found" << endl;
        return;
    }
    int start , nd;
    for(int i = 1 ; i <= ind ; i++){
        if(s < e[i]){
            start = c[i-1];
            nd = c[i];
            break;
        }
    }

    for(int i = start ; i <= nd ; i++){
        if(s == a[i]){
            cout << "Found at " << i+1 << endl;
            return;
        }
    }

    cout << "Not Found!" << endl;

}

int main()
{
    int n;
    cin >> n;
    int a[n];
    for(int i = 0 ; i < n ; i++)
        cin >> a[i];
    int s;
    cin >> s;
    indexSearch(a , n , s);
    return 0;
}
