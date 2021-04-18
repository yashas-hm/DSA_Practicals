#include <stdio.h>
#include <stdlib.h>

// A linked list node
struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

// ads to start of list
void push(struct Node** head, int new_data){

    struct Node* new_node
        = (struct Node*)malloc(sizeof(struct Node));

    new_node->data = new_data;
    new_node->next = (*head);
    new_node->prev = NULL;
    if ((*head) != NULL)
        (*head)->prev = new_node;

    (*head) = new_node;
}

// adds to the end of list
void append(struct Node** head, int new_data){
    struct Node* new_node
        = (struct Node*)malloc(sizeof(struct Node));

    struct Node* last_node = *head;
    new_node->data = new_data;
    new_node->next = NULL;

    if (*head == NULL) {
        new_node->prev = NULL;
        *head = new_node;
        return;
    }

    while (last_node->next != NULL)
        last_node = last_node->next;

    last_node->next = new_node;

    new_node->prev = last_node;
}

void printList(struct Node* node){
    struct Node* last_node;
    printf("Doubly Linked List is: ");
    while (node != NULL) {
        printf(" %d ", node->data);
        last_node = node;
        node = node->next;
    }
    printf("\n");
}

int main(){
    struct Node* head = NULL;

    append(&head, 6);
    push(&head, 7);
    push(&head, 1);


    printList(head);

    append(&head, 4);

    printList(head);

    return 0;
}
