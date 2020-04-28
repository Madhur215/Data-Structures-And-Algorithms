#include<bits/stdc++.h>
using namespace std;

void tower(int n, char A, char B, char C){

    if(n == 1){
        cout << "Move 1 from " << A << " to " << C << endl;
        return;
    }
    tower(n-1, A, C, B);
    cout << "Move " << n << " from " << A << " to " << C << endl;
    tower(n-1, B, A, C);


}


int main(){

    //No. of discs
    int n;
    cin >> n;
    tower(n, 'A', 'B', 'C');
}

