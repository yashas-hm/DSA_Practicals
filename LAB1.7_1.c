#include<stdio.h>
#include<malloc.h>

void insert_beg();
void insert_end();
void insert_pos();
void display();
void delete_beg();
void delete_end();
void delete_pos();

struct node{
    int data;
    struct node *next;
}*start=NULL,*n2,*n1;



int main(){
    int ch;

    while(1){
        printf("\n1.Insert\n2.Display\n3.Delete\n4.Exit\n\n");
        printf("Enter your choice(1-4):");
        scanf("%d",&ch);

        switch(ch){
            case 1: printf("\n1.Insert at beginning\n2.Insert at end\n3.Insert at specified position\n4.Exit");
                    printf("\n\nEnter your choice(1-4):");
                    scanf("%d",&ch);

                    switch(ch){
                        case 1: insert_beg();
                                break;
                        case 2: insert_end();
                                break;
                        case 3: insert_pos();
                                break;
                        case 4: return 0;
                        default: printf("Wrong Choice!!");
                    }
                    break;

            case 2: display();
                    break;

            case 3: printf("\n1.Delete from beginning\n2.Delete from end\n3.Delete from specified position\n4.Exit");
                    printf("\n\nEnter your choice(1-4):");
                    scanf("%d",&ch);

                    switch(ch){
                        case 1: delete_beg();
                                break;
                        case 2: delete_end();
                                break;
                        case 3: delete_pos();
                                break;
                        case 4: return 0;
                        default: printf("Wrong Choice!!");
                    }
                    break;
            case 4: return 0;

            default: printf("Wrong Choice!!");
        }
    }
    return 0;
}

void insert_beg(){
    int num;
    n1=(struct node*)malloc(sizeof(struct node));
    printf("Enter data:");
    scanf("%d",&num);
    n1->data=num;

    if(start==NULL){
        n1->next=NULL;
        start=n1;
    }
    else{
        n1->next=start;
        start=n1;
    }
}

void insert_end(){
    int num;
    n1=(struct node*)malloc(sizeof(struct node));
    printf("Enter data:");
    scanf("%d",&num);
    n1->data=num;
    n1->next=NULL;

    if(start==NULL){
        start=n1;
    }
    else{
        n2=start;
        while(n2->next!=NULL)
        n2=n2->next;
        n2->next=n1;
    }
}

void insert_pos(){
    int pos,i,num;
    if(start==NULL){
        printf("List is empty!!");
    }

    n1=(struct node*)malloc(sizeof(struct node));
    printf("Enter data:");
    scanf("%d",&num);
    printf("Enter position to insert:");
    scanf("%d",&pos);
    n1->data=num;

    n2=start;
    for(i=1;i<pos-1;i++){
        if(n2->next==NULL){
            printf("There are less elements!!");
        }
        n2=n2->next;
    }

    n1->next=n2->next;
    n2->next=n1;
}

void display(){
    if(start==NULL){
        printf("List is empty!!");
    }
    else{
        n2=start;
        printf("The linked list is:\n");
        while(n2!=NULL){
            printf("%d->",n2->data);
            n2=n2->next;
        }
    }
}

void delete_beg(){
    if(start==NULL){
        printf("The list is empty!!");
    }
    else{
        n2=start;
        start=start->next;
        printf("Deleted element is %d",n2->data);
        free(n2);
    }
}

void delete_end(){
    if(start==NULL){
        printf("The list is empty!!");
    }
    else{
        n2=start;
        while(n2->next->next!=NULL)
        n2=n2->next;

        n1=n2->next;
        n2->next=NULL;
        printf("Deleted element is %d",n1->data);
        free(n1);
    }
}

void delete_pos(){
    int pos,i;

    if(start==NULL){
        printf("List is empty!!");
    }

    printf("Enter position to delete:");
    scanf("%d",&pos);

    n2=start;
    for(i=1;i<pos-1;i++){
        if(n2->next==NULL){
            printf("There are less elements!!");
        }
        n2=n2->next;
    }

    n1=n2->next;
    n2->next=n1->next;
    printf("Deleted element is %d",n1->data);
    free(n1);
}
