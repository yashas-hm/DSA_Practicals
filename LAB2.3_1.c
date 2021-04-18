#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

void deleteNode(struct Node** head_ref, struct Node* del){
    if (*head_ref == NULL || del == NULL)
        printf("Underflow\n", );
        return;

    if (*head_ref == del)
        *head_ref = del->next;

    if (del->next != NULL)
        del->next->prev = del->prev;

    if (del->prev != NULL)
        del->prev->next = del->next;

    free(del);
    return;
}

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

    push(&head, 2);
    push(&head, 4);
    push(&head, 8);
    push(&head, 10);

    printf("\n Original Linked list ");
    printList(head);

    deleteNode(&head, head);        // delete first node
    deleteNode(&head, head->next);  // delete last node

    printList(head);

    return 0;
}
