// Linked list

#include<stdlib.h>
#include <stdio.h >


// Data type to represent a particular node in a linked list
struct node {

    // Variable to store the data of the node
    int data ;

    // struct node type pointer to store the address of the next node
    struct node * next ;

}
// This pointer is same a struct node type pointer that will store the address
// of the first node

// It is a global pointer that means it can be used directly in the every function

*first = NULL;


// Function to create an linked using an array
void create (int arr[], int size_of_array){

    // A temporary pointer  to create a new node each time a number is entered
    // and a pointer that will point on the last node every time so that we can add
    // a new node every time at the last
    struct node * new_node , * last ;

    // Now we will create a new node in the heap using malloc function

    // Pointer first will point on that node type of the structure
    first = (struct node * ) malloc (sizeof(struct node ));



    first -> data = arr[0];
    first -> next = NULL;

    // So there's only one element in the linked list, therefore the first is equal to last
    last = first ;

    // Now we will make for loop that will assign the values of the array to linked list

    // We are starting  from one because we have already assigned first value
    for (int i = 1 ; i < size_of_array ; i ++ ){

        new_node = (struct node *) malloc (sizeof(struct node ));
        new_node -> data = arr[i];
        new_node->next = NULL;
        last -> next = new_node ;
        last = new_node ;


    }





}

void display (struct node * p){
    // Here the input will be the pointer pointing on the first node
    // As first pointer is a global variable it can be directly accessed but we are using another pointer for simplification
    printf("The numbers of the linked list are \n");
    while (p!= NULL) {

        printf("%d", p->data);
        printf(" ");
        p = p->next;
    }

}

// Function to count number of elements in a linked list
int count_elements (struct node * p ){

    // Variable to store the count of number of elements
    int count = 0  ;
    while (p!=NULL){
        count ++;
        p=p->next ;

    }

    printf("The number of elements in the linked list are %d " , count );
    return 0 ;

}

// Function to give the sum of the elements of the linked list
int sum_linked_list (struct node * p ){

    // Variable to store the sum of the linked list
    int sum =0 ;
    while (p!= NULL){
        sum = sum + p ->data ;
        p= p->next ;
    }
    printf("The sum of the linked list is %d " , sum );
    return 0 ;
}

int max_in_linked_list(struct node * p ){

    // Variable to store the max element of the linked list
    int max = p -> data;
    while (p!=NULL){
        if (p->data > max ){
            max =p ->data;

        }
        p=p->next ;

    }
    printf("The max element in the linked list is %d" , max );
    return 0 ;

}

// Function to search element in a linked list
// In a linked list we do not use binary search because we cannot directly access the middle element of the linked list
int searching (struct node * p , int key ){
    // Key is the number to be searched
    int i=0;
    while (p!=NULL){
        if (p-> data == key ){
            printf("The element to be searched is at position number %d", i );
            printf(" ");

        }
        i++;
        p=p->next ;


    }
    printf("The key was not in the list of elements ");
    return 0 ;


}

// Function to insert in a sorted linked list
void sorted_insertion (struct node *p, int key ){
    // Key is the element to be entered

    // It is sure that we have to enter an element therefore we will create a node with that element
    struct node  * new_node , * q = NULL;
    // q is a pointer that will follow the pointer p and it is known as the following pointer
    new_node = (struct node *)malloc (sizeof(struct node ));
    new_node->data = key ;
    new_node->next = NULL;




    // # Special Case Number 1
    // Checking whether there's a linked list or not
    if (p == NULL){

        // Just making the new node as the first node
        p = new_node ;

    }


    else {


        // For all other cases we will run a loop
        while (p->data < key ){
            p = p->next ;
            q=p;
        }
        // # Special Case Number 2
        // If the entered element is the smallest in the linked list it will enter in starting
        if (p == first ){
            new_node ->next = first ;
            first = new_node;
        }

        // Now is at position after which we have to enter the node
        // # For general insertion in the linked list
        else {

            new_node->next = q->next   ;
            q->next = new_node;
        }



    }



}

// Deletion in a linked list
void deletion_linked_list  (struct node * p , int key ){
    // Here key is the element to be deleted

    // For deletion we need a following pointer
    struct node * q = NULL ;

    // If linked list is empty
    if (first == NULL){
        printf("The linked list is empty ");

    }


    else {
        while (p->data < key ){
            q=p;
            p=p->next ;
        }

        if (first == p ){
            first = p->next ;
            delete p ;
        }
        else {
            q->next = p->next ;
            delete p ;

        }
    }
}

void Sorted_linked_list(struct node *p ){
    while (p!=NULL){
        if (p->data < p->next->data ){
            p=p->next ;
            printf("hello");
        }
        else {
            break ;
        }

    }
    if (p == NULL){
        printf("The linked list is sorted ");
    }
    else {
        printf("The linked list is not sorted ");
    }
}


int main (){

    // An array that will be converted to an linked list
    int arr[] = {1,2,6 ,7,8};
    create(arr, 5 );
    display (first );
    printf("\n");
    Sorted_linked_list(first);
    //display(first);
    return 0 ;


}
