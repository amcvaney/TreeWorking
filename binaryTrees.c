//Abigayle McVaney
//Data Structures


#include <math.h>
#include <stdio.h>
#include <stdlib.h>



struct Node {
    int data;
    struct Node *left;
    struct Node *right;
};



//adding integers into a binary tree
int inputt(int input, struct Node *root, struct Node *prev)
{
    if (root->data == NULL){
        root->data = input;
        return 1;
    }
    if (root == NULL){
        struct Node *newNode=(struct Node *)malloc(sizeof(struct Node));
        newNode->data = NULL;
        newNode->left = NULL;
        newNode->right = NULL;
        if(prev->data >= input)
        {
            prev->data = root->data;
        }
        else
        {
            prev->data = root->data;
        }
        return 0;
    }
    
    if (root->data >= input){
        return inputt(input, root->left,root);
    }
    if (root->data <= input){
        return inputt(input,root->right,root);
    }
    return root->data;
}

struct Node *insertElement(struct Node *root, int input) {
    struct Node* nodeptr;
    struct Node *parentptr;
    struct Node *ptr = (struct Node*)malloc(sizeof(struct Node));
    ptr->data = input;
    ptr->left = NULL;
    ptr->right = NULL;
        if(root==NULL)
        {
            root=ptr;
            root->left=NULL;
            root->right=NULL;
        }
        else
        {
            parentptr=NULL;
            nodeptr=root;
            while(nodeptr!=NULL)
            {   parentptr=nodeptr;
                if(input < nodeptr->data)
                    nodeptr= nodeptr->left;
                else
                    nodeptr = nodeptr->right;
                
            }
            if(input<parentptr->data)
                parentptr->left = ptr;
            else
                parentptr->right = ptr;
        }
        return root;
    }



//removing a node from the tree
int remo(int input, struct Node *root,struct Node *prev, int first)
{
    
        if(root == NULL)
       {
           return 0;
       }
       if (input > root->data)
       {
           return remo(input, root->right, root,0);
       }
       if(input < root->data)
       {
           return remo(input, root->left, root,0);
       }
    
        //We found our number, remove it
       if(input == root->data)
       {
           printf("Number exists \n");
           
           //Removing root
           if(first == 1){
               
               struct Node *temp = root->right->left;
               struct Node *tempRight = root->right ->right;
               //struct Node **rootPoint = &root;
               root = root->right;
               root->right = temp;
               if(temp != NULL){
                   temp->right = tempRight;
               }
               //free(*rootPoint);
               return 1;
           }
           //Our number exists in a leaf, has no children
           else if (root-> left == NULL && root->right == NULL)
           {
               printf("No children \n");
               //Root is left of prev
               if(prev->left == root){
                   prev->left = NULL;
               }
               //root is right of prev
               else{
                   prev->right = NULL;
               }
               free(root);
               return 1;
           }
            else if(root->left == NULL)//we know it only has one leaf, right
            {
                printf("Right child \n");
                //Root is left of prev
                if(prev->left == root){
                    prev->left = root->right;
                }
                //root is right of prev
                else{
                    prev->right = root->right;
                }
                free(root);
                return 1;
            }
            else if(root->right ==NULL)//we know it only has one leaf, left
            {
                printf("Left child \n");
                //Root is left of prev
                if(prev->left == root){
                    prev->left = root->left;
                }
                //root is right of prev
                else{
                    prev->right = root->left;
                }
                free(root);
                return 1;
            }
            else //it has two children
            {
                printf("Two children\n");
                if(prev->right == root)//if node is right to prev
                {
                    prev->right= root->right;
                    struct Node *temp= root->left;
                    while(temp->right != NULL)
                    {
                        temp= temp->right;
                    }
                    temp->right = root->right->left;
                    prev->right->left = root->left;
                }
                else
                {//if node is left to prev
                    prev->left= root->right;
                    struct Node *temp= root->left;
                    while(temp->right!= NULL)
                    {
                        temp= temp->right;
                    }
                    temp->right = root->left->left;
                    prev->right->left = root->left;
                }
                free(root);
                return 1;
       }
       }
    
    return 0;
}

//searching for a value in the tree
int search(int input, struct Node *root)
{
    if(root == NULL)
    {
        return 0;
    }
    if (input > root->data)
    {
        return search(input, root->right);
    }
    if(input < root->data)
    {
        return search(input, root->left);
    }
    if(input == root->data)
    {
        return 1;
    }
    return 0;
}

//another printing option
int inorderTraversal(struct Node *root)
{
    if(root != NULL)
     {
    inorderTraversal(root->left);
    printf("%d\t", root->data);
    inorderTraversal(root->right);
     }
    return 0;
}

int printLevel(struct Node *root, int level)
{
    if (root == NULL)
        return 0;

    if (level == 1)
    {
        int t = root->data;
        printf("%d ", t);
        return 1;
    }

    int left = printLevel(root->left, level - 1);
    int right = printLevel(root->right, level - 1);

    if (left==1 || right==1)
        return 1;
    else
        return 0;
}
void printTree(struct Node *root)
{
    int level = 1;
    while (printLevel(root, level)){
        level++;
        printf("\n");
    }
}




int main(){

    int input;
    int selection;
    struct Node *root=(struct Node *)malloc(sizeof(struct Node));
    root->data = NULL;
    root->left = NULL;
    root->right = NULL;
    
    
    while(1)
    {
    printf("1. Create an integer binary tree\n");
    printf("2. Remove a specific node in the tree\n");
    printf("3. Search an item in the tree\n");
    printf("4. Display the tree in in the console\n");
    scanf("%d", &selection);
        
        switch(selection){
            case 1:
                for(int i= 0; i <10; i++){
                    int input = rand();
                    //inputt(input, root, NULL);
                    insertElement(root, input);
                }
                break;
                
            case 2:
                printf("what number do you want to remove? ");
                scanf("%d", &input);
                remo(input, root, NULL,1);
                break;
                
            case 3: printf("What value do you want to search: ");
                scanf("%d", &input);
                if(search(input, root) == 1)
                {
                    printf("Found");
                }
                else
                {
                    printf("Not found");
                }
                break;
                
            case 4: printTree(root);
                break;
                
        }
    }
    return 0;
}


