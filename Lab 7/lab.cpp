
#include "PriorityQueue.h"
#include <iostream>
#include <string>

using namespace std;

void printMenu();

int main(){
    Queue<string,20> example;
    int x;  //menu input
    string input; //input for queue
    int priority; //priority of input
    while(true){
        printMenu();
        cin>>x;
        switch(x){
            case 0:
                return 0;
                break;
            case 1:
                {
                    cout<<"Input: ";
                    cin>>input;
                    cout<<"Priority: ";
                    cin>>priority;
                    example.enqueue(input, priority);
                    break;
                }
            case 2:
                cout<<"Dequeued: "<<example.dequeue()<<endl;
                break;
            case 3:
                cout<<"Peek: "<<example.peek()<<endl;
                break;
            case 4:
                cout<<"Empty? Yes(1) or No(0): "<<example.isEmpty()<<endl;
                break;
            case 5:
                cout<<"Count: "<<example.count()<<endl;
                break;
            default:
                cout<<"Try again."<<endl;
                break;
        }
        cout<<endl;
    }

}

void printMenu(){
    cout<<"Menu: "<<endl;
    cout<<"1: Enqueue, 2: Dequeue, 3: Peek"<<endl;
    cout<<"4: isEmpty, 5: count, 0: Quit"<<endl;
}

