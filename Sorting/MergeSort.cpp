#include <iostream>

using namespace std;
void merge(int a[] , int left , int mid , int right){
int temp[right - left + 1];
int i = left , j = mid , k = 0 ;
while(i < mid && j <= right){
    if(a[i] < a[j])
        temp[k++] = a[i++];
    else
        temp[k++] = a[j++];
}
while(i < mid ){
    temp[k++] = a[i++];

}
while(j <= right){
    temp[k++] = a[j++];
}
for(i = left , k = 0 ; i <= right ; i++ , k++)
    a[i] = temp[k];
}
void mergeSort(int a[] , int l, int r){
    if(l<r){
        int m = (l+r)/2;
        mergeSort(a,l, m);
        mergeSort(a, m+1, r);
        merge(a,l,m+1,r);
    }
}

int main()
{
    int n;
    cin >> n;
    int a[n];
    for(int i = 0; i < n ; i++)
        cin >> a[i];
    mergeSort(a, 0, n);
    for(int i = 0 ;i < n ; i++)
        cout << a[i]<<endl;
    return 0;
}
