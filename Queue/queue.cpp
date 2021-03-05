#include <iostream>
using namespace std;

struct node{
    int data;
    struct node* next;
};

struct node* head=NULL;
struct node* tail=NULL;

//function to create new node
struct node* get_new_node(int value){
    struct node* new_node=new node;
    new_node->data=value;
    new_node->next=NULL;
    return new_node;
}

//function to add node in queue (Enqueue)
void enqueue(int value){
    struct node* new_node=get_new_node(value);
    if(head==NULL&&tail==NULL){
        head=tail=new_node;
    }else{
        tail->next=new_node;
        tail=new_node;
    }
}

//function to remove node from the queue (Dequeue)
void dequeue(){
    if(head==NULL){
        head=tail=NULL;
        cout<<"Queue is Empty"<<endl;
    }else{
        struct node* temp=head;
        head=head->next;
        delete temp;
    }
}

//function to display queue
void display(){
    struct node* current=head;
    while (current!=NULL)
    {
        cout<<current->data<<"-";
        current=current->next;
    }
    cout<<endl;
    
}


int main(){
enqueue(6);
enqueue(9);
enqueue(1);
enqueue(4);
display();
dequeue();
dequeue();
enqueue(5);
display();
    return 0;
}