#include <iostream>

using namespace std;

long merge1(int a[] , int left , int mid , int right){
int i = left , j = mid , k = 0;
int temp[right - left + 1];
long count = 0;
while(i < mid && j <= right){
    if(a[i] <= a[j]){
        temp[k++] = a[i++];
    }
    else{
        temp[k++] = a[j++];
        count += mid - i;
    }


}
while(i<mid){
    temp[k++] = a[i++];
}
while(j<=right){
    temp[k++] = a[j++];
}
for(int i = left , k = 0; i<=right ; i++ , k++){
    a[i] = temp[k];
}
return count;
}

long merge_sort(int a[] , int left , int right){
  long count = 0;
  if(right > left){
     int mid = (left + right)/2 ;
     count += merge_sort(a , left , mid );
     count += merge_sort(a, mid + 1 , right);
     count += merge1(a , left , mid + 1 , right);
     return count;
  }
  return  0;

}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for(int i = 0 ; i < n ;i++){
        cin >> arr[i];
    }
    int ans = merge_sort(arr , 0 , n - 1);
    cout << ans;
    return 0;
}
