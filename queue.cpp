#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* next;
    Node(int x){
        data=x;
        next=NULL;
    }
};
class Queue{
    Node *front,*rear;
public:
    Queue(){
        front=rear=NULL;
    }

    void push(int x){
        Node* n=new Node(x);
        if(!rear){
            front=rear=n;
            return;
        }
        rear->next=n;
        rear=n;
    }

    void pop(){
        if(!front) return;
        Node* temp=front;
        front=front->next;
        if(!front) rear=NULL;
        delete temp;
    }

    int top(){
        if(!front) return -1;
        return front->data;
    }

    bool empty(){
        return front==NULL;
    }

    void display(){
        Node* cur=front;
        while(cur){
            cout<<cur->data<<" ";
            cur=cur->next;
        }
        cout<<"\n";
    }
};
int main(){
    Queue q;
    q.push(10);
    q.push(20);
    q.push(30);
    q.display();
    q.pop();
    q.display();
    cout<<q.top()<<"\n";
    return 0;
}
