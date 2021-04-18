#include <stdio.h>
#include <stdlib.h>

struct node{
    int info;
    struct node *ptr;
}*top,*top1,*temp;

void push(int data);
void pop();
void display();

int count = 0;

void main(){
    int element,ch;
    top=NULL;
    while (1){
        printf("\n 1 - Push\n 2 - Pop\n 3 - Dipslay\n 4 - Exit");
        printf("\n Enter choice : ");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1: printf("Enter data : ");
                scanf("%d", &element);
                push(no);
                break;

        case 2: pop();
                break;

        case 3: display();
                break;

        case 4: exit(0);

        default:    printf(" Wrong choice, Please enter correct choice  ");
                    break;
        }
    }
}

void push(int data){
    if (top == NULL){
        top =(struct node *)malloc(1*sizeof(struct node));
        top->ptr = NULL;
        top->info = data;
    }
    else{
        temp =(struct node *)malloc(1*sizeof(struct node));
        temp->ptr = top;
        temp->info = data;
        top = temp;
    }
    count++;
}

void display(){
    top1 = top;

    if (top1 == NULL){
        printf("Empty Stack");
        return;
    }

    while (top1 != NULL){
        printf("%d ", top1->info);
        top1 = top1->ptr;
    }
 }

void pop(){
    top1 = top;

    if (top1 == NULL){
        printf("\n Stack Underflow");
        return;
    }
    else
        top1 = top1->ptr;
    printf("\n Popped value : %d", top->info);
    free(top);
    top = top1;
    count--;
}
