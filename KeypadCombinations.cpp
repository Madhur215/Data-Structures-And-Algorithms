#include <iostream>

using namespace std;

string getChars(int x){
    if(x == 1 || 0)
        return "";
    else if(x == 2)
        return "abc";
    else if(x == 3)
        return "def";
    else if(x == 4)
        return "ghi";
    else if(x == 5)
        return "jkl";
    else if(x == 6)
        return "mno";
    else if(x == 7)
        return "pqrs";
    else if(x == 8)
        return "tuv";
    else
        return "wxyz";
}


int keypad(int n, string output[]){

    if(n == 0){
        output[0] = "";
        return 1;
    }
    int rem = n % 10;
    int smallOutputSize = keypad(n / 10, output);
    string str = getChars(rem);

    for(int i = 0; i < str.size() * smallOutputSize; i++){
        output[i + smallOutputSize] = output[i];

    }

    for(int i = 0; i < str.size() * smallOutputSize; i++){
        int curr_char = i / smallOutputSize;
        output[i] = output[i] + str[curr_char];
    }
    return smallOutputSize * str.size();
}


int main()
{
    int n;
    cin >> n;
    string op[1000];
    int cn = keypad(n , op);
    for(int i = 0 ; i < cn ; i++){
        cout << op[i] << endl;
    }

    return 0;
}
