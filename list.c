#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Node { 
    char data; 
    struct Node* next; 
}; 


void append(struct Node** head_ref, int new_data) 
{ 
    /* 1. allocate node */
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node)); 
  
    struct Node* last = *head_ref;  /* used in step 5*/
  
    /* 2. put in the data  */
    new_node->data  = new_data; 
  
    /* 3. This new node is going to be the last node, so make next of 
          it as NULL*/
    new_node->next = NULL; 
  
    /* 4. If the Linked List is empty, then make the new node as head */
    if (*head_ref == NULL) 
    { 
       *head_ref = new_node; 
       return; 
    } 
  
    /* 5. Else traverse till the last node */
    while (last->next != NULL) 
        last = last->next; 
  
    /* 6. Change the next of last node */
    last->next = new_node; 
    return; 
} 


void printReverse(struct Node* head) 
{ 
    // Base case   
    if (head == NULL) 
       return; 
  
    // print the list after head node 
    printReverse(head->next); 
  
    // After everything else is printed, print head 
    printf("%c", head->data); 
} 

int main(int argc,char *argv[])
{
    char *str;
    str=argv[1];
    
    struct Node* head = NULL; 
    
    for (int i=0;i<strlen(str);i++) {
        append(&head, str[i]);
    }
    printReverse(head); 
    printf("\n");
    return 0;
}

	
