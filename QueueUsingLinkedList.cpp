#include <bits/stdc++.h>

using namespace std;

struct node{
    int data;
    struct node* ptr;
}*Qfront , *rear , *Qfront1 , *temp;

void enqueue(){
    int x;
    cin >> x;
    if(rear == NULL){
        rear = (struct node*)malloc(sizeof(struct node));
        rear->data = x;
        rear->ptr = NULL;

        Qfront = rear;
    }
    else{
        temp = (struct node*)malloc(sizeof(struct node));
        temp->data = x;
        temp->ptr = NULL;

        rear->ptr = temp;
        rear = temp;
    }
}


void dequeue(){

    if(Qfront == NULL){
        cout << "Queue empty!"<< endl;

    }

    else{

        if(Qfront->ptr == NULL){
            free(Qfront);
            Qfront = rear = NULL;
        }
        else{
            Qfront1 = Qfront;

            Qfront1 = Qfront1->ptr;
            free(Qfront);
            Qfront = Qfront1;
        }

    }
    cout << endl;
}

void display(){

    Qfront1 = Qfront;
    if((Qfront == NULL) && (rear == NULL))
        cout << "Queue empty!" << endl;
    else{
        while(Qfront1 != rear){
            cout << Qfront1->data << " ";
            Qfront1 = Qfront1->ptr;
        }
        if(Qfront1 == rear){
            cout << Qfront1->data << endl;
        }
    }
}



int main()
{
    Qfront = rear = NULL;
    while(1){
    cout << "1. Enqueue" << endl;
    cout << "2. Dequeue" << endl;
    cout << "3. Display" << endl;
    cout << "4. Exit" << endl;
    int x;
    cin >> x;

    switch(x){
    case 1:
        enqueue();
        break;
    case 2:
        dequeue();
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
