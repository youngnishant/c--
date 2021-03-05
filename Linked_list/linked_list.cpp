#include <iostream>
using namespace std;


//declaration of structure

struct node{
    int data;
    struct node *next;
};
    struct node *head =NULL;
    

//function to create node

struct node* create_node(int data){
    struct node *newNode=new node;
    newNode->data=data;
    newNode->next=NULL;
    return newNode;
}

//function to add node in beginning

void add_in_beg(int data){
    
    struct node *newNode=create_node(data);
    if(head==NULL){
        head=newNode;
    }else{
       newNode->next=head;
        head=newNode;
    }
}

//funtion to add node in the last

void add_in_end(int data){
    struct node* newNode=create_node(data);
    struct node *current=head;
    while(current->next!=NULL){
        current=current->next;
    }
    current->next=newNode;
}

//function to add node on given position
 
void add_on_pos(int pos,int data){
    struct node* newNode=create_node(data);
    struct node* current=head;
    for(int i=0;i<pos-2;i++){
        current=current->next;
    }
    newNode->next=current->next;
    current->next=newNode;
}




//function to delete at position

void delete_node(int pos){
   struct node* current =head;
   if(pos==1){
       head=NULL;

   }
   else if(head!=NULL){
        for (int i=0;i<pos-2;i++){
            if(current==NULL){
                break;
            }
            current=current->next;
    }
    if(current!=NULL&&pos>0){
            struct node* delete_node=current->next;
            current->next=current->next->next;
            delete delete_node;
    }else{
        cout<<"postion doesn't exist !";
    }

   }else{
       cout<<"List is empty !";
   }
   }



//function to reverse the linked list

void reverse(){
    struct node* current =head;
    struct node* prev =NULL;
    struct node* next;
    while(current!=NULL){
        next=current->next;
        current->next=prev;
        prev=current;
        current=next;
    }
    head=prev;
}


//display all nodes data

void display(){
    if(head==NULL){
        cout<<"List is Empty!";
    }else{
        struct node *current=head;
        
        while(current!=NULL){
            cout<<current->data<<"-";
            current=current->next;
            
        }
    }
}


int main()
{
    
    add_in_beg(5);
    add_in_beg(4);
    add_in_beg(3);
    add_in_beg(2);
    add_in_beg(1);
    display();
    cout<<endl;
    reverse();
    display();

    return 0;
}
