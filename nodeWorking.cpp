//Abigayle McVaney
//Data Structures
//Lab 5 C++


#include <iostream>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

//global variables
struct node* head;
struct node* tail;
int rev = 0;

struct node //creating the node type and bounds
{
    int data;
    struct node *next;
    struct node *prev;
};


void create() //creating the doubly linked list
{
    struct node *new_node, *ptr;
    int num;
    
    cout <<"\nEnter –1 to end the list";
    cout <<"\nEnter the data : ";
    cin >> num;
    while(num != -1)
    {
        if(head == NULL)
        {
            new_node = (struct node*)malloc(sizeof(struct node));
            new_node -> prev = NULL;
            new_node -> data = num;
            new_node -> next = NULL;
            head = new_node;
            cout << "\n(start)" << head->data;
        }
        
        else
        {
            ptr=head;
            new_node = (struct node*)malloc(sizeof(struct node));
            new_node->data=num;
            while(ptr->next!=NULL)
                ptr = ptr->next;
            
            ptr->next = new_node;
            new_node->prev = ptr;
            new_node->next = NULL;
            tail = new_node;
        }
    cout << "\nEnter the data: ";
    cin >> num;
}
}


void print() //printing the doubly linked list in specified orders
{
    if (rev == 0){
        struct node *ptr;
        ptr = head;
        
        while(ptr!=NULL)
    {
        cout<<ptr->data<< "\n";
        ptr = ptr->next;
    }
    }
    
    else{
    struct node *ptr;
    ptr = tail;
    while(ptr!=NULL)
        {
            cout<<ptr->data<< "\n";
            ptr = ptr->prev;
            
        }
    }
}


void insert_beg() //inserting new node in beginning of list
{
    struct node *new_node;
    int num;
    cout<< "\nEnter the data: ";
    cin >> num;
    new_node = (struct node *)malloc(sizeof(struct node));
    new_node -> data = num;
    head -> prev = new_node;
    new_node -> next = head;
    new_node -> prev = NULL;
    head = new_node;
}


void insert_end() //inserting new node at end of list
{
    struct node *ptr, *new_node;
    int num;
    cout << "\n Enter the data : ";
    cin >> num;
    
    new_node = (struct node *)malloc(sizeof(struct node));
    new_node -> data = num;
    ptr=head;
    
    while(ptr -> next != NULL)
    ptr = ptr -> next;
    
    ptr -> next = new_node;
    new_node -> prev = ptr;
    new_node -> next = NULL;
}



void reverse() //reversing the list
{
    if (rev == 1)
        rev = 0;
    else
        rev = 1;
}


void delete_beg() //deleting node at begining of list
{
    struct node *ptr;
    ptr = head;
    head = head -> next;
  head -> prev = NULL;
    free(ptr);
}

void delete_end()//delteing node at end of list
{
    struct node *ptr; ptr = head;
    while(ptr -> next != NULL)
    ptr = ptr -> next;
    ptr -> prev -> next = NULL;
    free(ptr);
}





//main function
int main(){
    int option; //selection of user to input from menu
    
    
while(1) //infinite loop generating menu till pressed otherwise
{
    cout << "1. Create doubly linked list\n";
    cout << "2. Insert node\n";
    cout << "3. Delete a node\n";
    cout << "4. Print the list\n";
    cout << "5. Reverse the list\n";
    cout << "6. End program\n";
    cin >> option;
    
    switch(option)//goes to specified functions
    {
        case 1:
            create();
            break;
        
        case 2: cout << "Choose direction: \n";
            cout << "1. At beginning of list\n";
            cout << "2. At end of list\n";
            cout << "*To end program, click any other key*\n";
            int k;
            cin >> k;
            
            if(k == 1)
            {
            insert_beg();
                cout << "\nSuccessfully added\n";
                break;
            }
            else if(k == 2)
            {
                insert_end();
                cout << "Successfully added\n";
                break;
            }
            else
                return 0;
    
        case 3: cout << "Choose direction: \n";
            cout << "1. At beginning of list\n";
            cout << "2. At end of list\n";
            cout << "*To end program, click any other key*\n";
            int j;
            cin >> j;
            
            if(j == 1)
            {
            delete_beg();
            cout << "Successfully deleted\n";
            break;
            }
            
            else if(j == 2)
            {
            delete_end();
            cout << "Successfully deleted\n";
            break;
            }
            else
                return 0;
                break;
        
        case 4:
            cout << "Printing list\n";
            print();
            break;
        
        case 5: reverse();
            break;
    
        case 6: return 0;
    
    }
}
    return 0;
}
