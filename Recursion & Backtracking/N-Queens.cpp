#include <bits/stdc++.h>
#define ll long long
#define ff2(j , n , k) for(ll i = j ; i <= n ; i += k)
#define ff1(j , n , k) for(ll i = j ; i < n ; i += k)
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);
#define endl "\n"
#define pb push_back
#define mk make_pair
#define mod 1000000007
#define MX 1000001
#define vi vector<int>
#define vs vector<string>
using namespace std;
int m[11][11];

bool canPlace(int row, int col, int n){
    for(int j = row;j >= 0; j--)
        if(m[j][col] == 1)
            return false;
    for(int i = row-1, j = col-1; i >= 0, j >= 0; i--, j--)
        if(m[i][j] == 1)
            return false;
    for(int i = row-1, j = col+1; i >= 0, j < n; i--, j++)
        if(m[i][j] == 1)
            return false;
    return true;


}
void queens(int n, int row){

    if(n == row){
        ff1(0, n, 1){
            for(int j = 0 ; j < n ; j++)
                cout << m[i][j] << " ";
            cout << endl;
        }
        cout << endl;

    }

    for(int j = 0; j < n ; j++){

        if(canPlace(row, j, n)){
            m[row][j] = 1;
            queens(n, row+1);
            m[row][j] = 0;
        }

    }
    return;

}


int main(){

    fastio;
//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
    int n;
    cin >> n;
    memset(m, 0, sizeof(m));
    if(n == 2 || n == 3){
        cout << "Not Possible\n";
    }
    else{
        queens(n, 0);
    }

    return 0;
}
