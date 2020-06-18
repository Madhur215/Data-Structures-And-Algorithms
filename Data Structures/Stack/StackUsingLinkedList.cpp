#include <bits/stdc++.h>

using namespace std;

struct node{
    int data;
    struct node* ptr;

}*top , *top1 , *temp;

void push(){
    int x;
    cin >> x;

    if(top != NULL){
        temp = (struct node*)malloc(sizeof(struct node));
        temp->data = x;
        temp->ptr = top;
        top = temp;
    }
    else{
        top = (struct node*)malloc(sizeof(struct node));
        top->data = x;
        top->ptr = NULL;
    }
}

void pop(){
    if(top == NULL){
        cout << "Stack empty!" << endl;
    }
    else{
        top1 = top;
        top1 = top1->ptr;
        free(top);
        top = top1;
    }
}

void display(){

    if(top == NULL){
        cout << "Stack empty!" << endl;

    }
    else{
        top1 = top;
        while(top1 != NULL){
            cout << top1->data << " ";
            top1 = top1->ptr;
        }
    }
}

int main()
{
    top = NULL;
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
