#include<stdio.h>   
#include<stdlib.h>

struct Node{
    int data;
    struct Node *next;
};

struct Node *front;
struct Node *rear;

void insert();
void delete();
void display();

void main ()  {
    int choice;
    while(choice != 4){
        printf("\n1.insert an element\n2.Delete an element\n3.Display the queue\n4.Exit\n");
        printf("\nEnter your choice ?");
        scanf("%d",& choice);
        switch(choice){
            case 1: insert();
                    break;
            case 2: delete();
                    break;
            case 3: display();
                    break;
            case 4: exit(0);

            default: printf("\nEnter valid choice??\n");
                     break;
        }
    }
}

void insert(){
    struct Node *node;
    int item;

    node = (struct Node *) malloc (sizeof(struct Node));
    if(node == NULL){
        printf("\nQueue Overflow\n");
        return;
    }
    else{
        printf("\nEnter value?\n");
        scanf("%d",&item);
        node -> data = item;
        if(front == NULL){
            front = node;
            rear = node;
            front -> next = NULL;
            rear -> next = NULL;
        }
        else{
            rear -> next = node;
            rear = node;
            rear->next = NULL;
        }
    }
}

void delete (){
    struct Node *node;
    if(front == NULL){
        printf("\nQueue Underflow\n");
        return;
    }
    else
    {
        node = front;
        front = front -> next;
        free(node);
    }
}

void display(){
    struct Node *node;
    node = front;
    if(front == NULL){
        printf("\nEmpty queue\n");
    }
    else{
        printf("\nQueue:\n");
        while(node != NULL){
            printf("%d ",node -> data);
            node = node -> next;
        }
    }
}
