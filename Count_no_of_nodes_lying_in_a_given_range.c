//Count BST nodes that lie in a given range
#include <stdio.h>
#include <stdlib.h>
//structure of Binary Search Tree node
struct Node
{
  int data;
  struct Node *left,*right; 
};

//Adding a new node in binary search tree
void add( struct Node **root, int data)
{
  //Create a dynamic node of binary search tree 
  struct Node *new_node = (struct Node *)malloc(sizeof(struct Node ));

  if(new_node!=NULL)
  {
    //Set data and pointer values
    new_node->data = data;
    new_node->left = NULL; //Initially node left-pointer is NULL
    new_node->right = NULL;//Initially node right-pointer is NULL

    if(*root == NULL)
    {
      //When adds a first node in binary tree
      *root = new_node;
    }
    else
    {
      struct Node *find = *root;
      //iterate binary tree and add new node to proper position
      while(find != NULL)
      {
        if(find -> data > data)
        { 
          if(find->left==NULL)
          {
            find->left = new_node;
            break;
          }
          else
          { //visit left sub-tree
            find = find->left;
          }
        }
        else
        {
          if(find->right == NULL)
          {
            find->right = new_node;
            break;
          }
          else
          {
            //visit right sub-tree
            find = find->right;
          }
        }
      }
    }
  }else
  {
    printf("Memory Overflow\n");
    exit(0); //Terminate program execution
  }

}
void count_element(struct Node*root,
  int *counter,int first,int second)
{
  
  if(root!=NULL)
  {
    if(root->data >= first && root->data <=second)
    {
      (*counter)++;
    }
    count_element(root->left,counter,first,second);

    count_element(root->right,counter,first,second);


  }
 
 
}
void counter_nodes(struct Node*root,int first,int second)
{
  if(root != NULL)
  {
    
   int counter=0;
   if(first < second)
   {
     count_element(root,&counter,first,second);
   }
   else
   {
     count_element(root,&counter,second,first);
   }
  
    printf("[%d,%d] => %d\n",first,second,counter );
   
  }
  else
  {
    printf("Empty BST\n");
  }
}

int main(){
    
  struct Node*root = NULL;

  //Add nodes in binary search tree
  /*
              6
            /    \
           /      \
          3        9
         /  \      / \
        1    5    7   11
       / \   /         \
     -3  2  4           12


  */                


    add(&root,6); 
    add(&root,3); 
    add(&root,9); 
    add(&root,1); 
    add(&root,5); 
    add(&root,7); 
    add(&root,11); 
    add(&root,-3); 
    add(&root,2); 
    
    add(&root,12);
    add(&root,4);  
  
    counter_nodes(root,1,10);

    
  return 0;
}
/*
Output
[1,10] => 8
*/
