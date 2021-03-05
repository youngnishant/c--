#include <iostream>
using namespace std;

struct node{
    int data;
    struct node* next;
};

struct node* top = NULL;

// function to create a  new node
struct node* get_new_node(int value){
    struct node* new_node=new node;
    new_node->data=value;
    new_node->next=NULL;
    return new_node;
}

//function to check if stack is empty
bool is_empty(){
    if(top==NULL){
        return true;
    }return false;
}

//function to push value in the stack
void push(int value){
    struct node* new_node=get_new_node(value);
    if(top==NULL){
        top=new_node;
    }else{
        new_node->next=top;
        top=new_node;
    }
}


//function to pop the values from the stack
void pop(){
    
    if(top==NULL){
        cout<<"Stack is empty";
    }else{
        struct node* temp = top;
        top=top->next;
        delete temp;
    }
}

//function is to display all the values in the stack
void display(){
    struct node* current=top;
    while(current!=NULL){
                cout<<current->data<<"-";

        current=current->next;
    }

}
int main(){
push(4);
push(5);
push(1);
push(8);
push(9);
display();
cout<<endl;
pop();
pop();
display();
}