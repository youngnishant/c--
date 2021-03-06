 #include <iostream>
 using namespace std;
 //BST--Binary Search Tree
struct node{
    int data;
    struct node* right;
    struct node* left;
};

struct node* root=NULL;

//function to create node
struct node* create_node(int value){
    struct node* new_node=new node;
    new_node->data=value;
    new_node->left=NULL;
    new_node->right=NULL;
    return new_node;
}

//function to insert node
void insert(int value){
    struct node* new_node=create_node(value);
    if(root==NULL){
        root=new_node;
    }else{
        struct node* current=root;
        struct node* temp;
        while(current!=NULL){
            temp=current;
            if(current->data<value){
                current=current->right;
            }else {
                current=current->left;
            }
        }
        if(temp->data<value){
            temp->right=new_node;
        }else{
            temp->left=new_node;
        }
    }
}

//function to display Min_value of the tree
void min_value(){
    struct node* current=root;
    while(current->left!=NULL){
        current=current->left;
    }
    cout<<"Min vaue in tree: "<<current->data<<endl;
}


//function to display Max_value of the tree
void max_value(){
    struct node* current=root;
    while(current->right!=NULL){
        current=current->right;
    }
    cout<<"Max vaue in tree: "<<current->data<<endl;
}
 int main(){
     insert(3);
     insert(4);
     insert(8);
     insert(9);
     insert(1);
     insert(2);
     min_value();
     max_value();
     return 0;
 }