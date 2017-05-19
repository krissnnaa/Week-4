#include<stdio.h> 
#include<stdlib.h>      
 struct node
 {  
   int value;  
   struct node* left;  
   struct node* right;  
   int height;  
 };

 struct node* get_node(int val){  
   struct node* new_node = (struct node*)malloc(sizeof(struct node));  
   new_node->left = NULL;  
   new_node->right = NULL;  
   new_node->value = val;  
   new_node->height = 1;  
   return new_node;  
 }  
 
 //Insertion in a AVL tree
 struct node* insert(struct node* root, int val){   
   if(!root){  
     struct node* new_node = get_node(val);  
     return new_node;  
   }  
   if(root->value > val)  
     root->left = insert(root->left, val);  
   else  
     root->right = insert(root->right, val);  
   //To update height of root  
   root->height = get_max(get_height(root->left), get_height(root->right)) + 1;  
   //To check for balancing  
   int balance = get_balance(root);  
   //Case of left-left and let-right 
   if(balance > 1){
	   if(root->left->value > val){  
		root = right_rotate(root);  
		}
		
		else{
		 root->left = left_rotate(root->left);  
		 root = right_rotate(root);
		}
   }
   //Case of right-right and right-left  
   if(balance < -1){
		if(root->right->value < val){  
		 root = left_rotate(root);  
		}
		
		else{  
		 root->right = right_rotate(root->right);  
		 root = left_rotate(root);  
		}  
   }  
   
   return root;  
 }  
 
 //To get height of node
 int get_height(struct node* root){  
   if(!root)  
	 return 0;  
   else
	 return root->height;  
 }  
 
 //To get maximum height
 int get_max(int x, int y){  
	if(x>y) 
	 return x;
	else   
	 return y;
 } 
 
 //To get balance of left and right values of node in AVL
 int get_balance(struct node* root){  
   if(!root) 
	 return 0;  
   else 		
	 return (get_height(root->left) - get_height(root->right));  
 }  
 
 //To Perform left rotation
 struct node* left_rotate(struct node* root){  
   struct node* right = root->right;  
   struct node* left = right->left;  
   right->left = root;  
   root->right = left;  
   root->height = get_max(get_height(root->left), get_height(root->right)) + 1;  
   right->height = get_max(get_height(right->left), get_height(right->right)) + 1;  
   return right;  
 } 
 
 //To Perform right rotation
 struct node* right_rotate(struct node* root){  
   struct node* left = root->left;  
   struct node* right = left->right;  
   left->right = root;  
   root->left = right;  
   root->height = get_max(get_height(root->left), get_height(root->right)) + 1;  
   left->height = get_max(get_height(left->left), get_height(left->right)) + 1;  
   return left;  
 }  
 
 //To Print the pre-order of tree  
 void preorder(struct node* root){  
   if(!root)
	   return;  
   printf("%d\t",root->value);  
   preorder(root->left);  
   preorder(root->right);  
 }  

 void main(){  
   struct node* root = NULL;  
   int i,n;
   for(i=0;i<10;i++){
	   printf("Enter number to insert in a tree=");
	   scanf("%d",&n);
	   root = insert(root, n);  
   }
   
   printf("Preorder of a tree after insertion\n");  
   preorder(root);  
    
 }  