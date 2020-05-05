#include <bits/stdc++.h>

using namespace std;
int top = -1 , n;
int s[20];
void push(){
    int data;
    cin >> data;
    if(top >= n){
        
        cout << "Overflow!" << endl;
    }
    else{
        top++;
        s[top] = data;
    }
}


void pop(){

    if(top <= -1){
        cout << "Underflow!" << endl;

    }
    else{
        top--;
        cout << "Element pop from stack!" << endl;
    }
}

void display(){

    if(top <= -1){
        cout << "Stack is empty!" << endl;
    }
    else{

        int top1 = top;
        while(top1 >= 0){
            cout << s[top1] << " ";
            top1--;
        }
        cout << endl;


    }
}


int main()
{
    cin >> n;
    while(1){
        cout << "1. Push" << endl;
        cout << "2. Pop" << endl;
        cout << "3. Display" << endl;
        cout << "4. Exit" << endl;
        int x;
        cin >> x;

        switch(x){
    case 1:
        push();
        break;
    case 2:
        pop();
        break;
    case 3:
        display();
        break;
    case 4:
        exit(0);

        }
    }
    return 0;
}
