 #include <iostream>
 #include <queue>
 #include <stack>
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

///---Functions to traverse BST---///

//1. BFS traversal or level-order traversal
void bfs(){
    queue<struct node*> qu;
    qu.push(root);
    cout<<"BFS Traversal: ";
    while(!qu.empty()){  
    struct node* front= qu.front();
    cout<<front->data<<"-";
    qu.pop(); 
    if(front->left)qu.push(front->left);
    if(front->right)qu.push(front->right);
    
    }
    cout<<endl;
} 

//2. DFS traversal

// a. Pre-order traversal
void pre_order(){
    stack<struct node*> st;
    st.push(root);
    cout<<"Pre-Order Traversal: ";
    while(!st.empty()){
        struct node* current=st.top();
        cout<<current->data<<"-";
        st.pop();
        if(current->right)st.push(current->right);
        if(current->left)st.push(current->left);
    }
    cout<<endl;
}

//b. Post-order traversal
void post_order(){
    stack<struct node*> S1;
    stack<struct node*> S2;
    struct node* current=root;
    S1.push(current);
    while(!S1.empty()){
        current=S1.top();
        S2.push(S1.top());
        S1.pop();
        if(current->left)S1.push(current->left);
        if(current->right)S1.push(current->right);
    }
    cout<<"Post-Order Traversal: ";
    while(!S2.empty()){
       cout<<S2.top()->data<<"-";
       S2.pop();
   }
}

// c. In-order traversal
void in_order(){
    stack<struct node*> st;
    struct node* current= root;
    cout<<"In-Order Traversal: ";
    
    while(!st.empty()||current!=NULL){
    
        while(current!=NULL){
        st.push(current);
        current=current->left;
    }
        current=st.top();
         st.pop();
        cout<<current->data<<"-";
        current=current->right;    
   }
    cout<<endl;
}



//function to display Min_value of the tree
void min_value(){
    struct node* current=root;
    while(current->left!=NULL){
        current=current->left;
    }
    cout<<"Min value in tree: "<<current->data<<endl;
}


//function to display Max_value of the tree
void max_value(){
    struct node* current=root;
    while(current->right!=NULL){
        current=current->right;
    }
    cout<<"Max value in tree: "<<current->data<<endl;
}
 int main(){
     insert(5);
     insert(2);
     insert(3);
     insert(1);
     insert(10);
     insert(8);
     insert(11);
     
     min_value();
     max_value();
     bfs();
     pre_order();
     in_order();
     post_order();

     return 0;
 }