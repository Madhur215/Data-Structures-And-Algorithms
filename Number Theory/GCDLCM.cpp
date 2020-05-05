#include <bits/stdc++.h>

using namespace std;

int getGCD(int a , int b){
    if(a == 0)
        return b;
    return getGCD(b%a , a);
}


int getLCM(int a , int b){
    int l = min(a , b);
    int m = max(a , b);
    for(int i = m ; ; i += m){
        if(i % l == 0)
            return i;
    }
}

int main()
{
    int a , b;
    cin >> a >> b;
    cout << "GCD = " << getGCD(a , b) << endl;
    cout << "LCM = " << getLCM(a , b) << endl;
    return 0;
}
