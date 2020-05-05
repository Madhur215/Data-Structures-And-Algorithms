#include<bits/stdc++.h>
#include<vector>
#include<algorithm>
using namespace std;
vector<int> longestSubsequence(int *arr, int n){
	// Write your code here
    sort(arr , arr+n);
    vector<int> result;

    int max_size = 0 , j;
    int start_index = 0 , end_index = 0;
    for(int i = 0 ; i < n ; i++){
        int count = 1;
        for(j = i+1 ; j < n ; j++){
            if(arr[j] == arr[j-1] + 1){
                count++;

            }
            else
                break;
         }
            start_index = i;
            end_index = j ;
        int k ;
           if(count > max_size){
                max_size = count;
                result.clear();
                for(k = start_index; k < end_index ; k++ ){
                     //for(int l = 0 ; l = end_index - start_index ; l++)
                    result.push_back(arr[k]); }

           }

        }
    return result;
    }
    int main(){
    int arr[] = {2 ,12 ,9 ,16 ,10 ,5 ,3 ,20 ,25 ,11 ,1 ,8 ,6 };
    int n =13;
    vector<int> v(longestSubsequence(arr , n));
    vector<int>::iterator it;
    for(it = v.begin() ; it!= v.end() ; it++)
        cout << *it << endl;
    return 0;
    }
