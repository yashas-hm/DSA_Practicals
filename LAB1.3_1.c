#include<stdio.h>

int stack[6];
int top=-1;
void push(int arr[], int n);
void pop(int arr[], int n);
void peep();
void change();
void display(int arr[]);

int main(){
    int n;
    char choice;
    printf("Enter stack limit : ");
    scanf("%d", &n);
    int stack[n];
    do{
        printf("Enter option number : \n1. Push\n2. Pop\n3.Change\n4. Peep\n5. Display\n6. Exit\n");
        scanf("%c", &choice);
        switch(choice){
            case '1':   push(stack, n);
            			break;

            case '2':   pop(stack, n);
            			break;

            case '3':   change();
            			break;

            case '4':   peep();
            			break;

            case '5':   display(stack);
            			break;

            case '6':   return 0;
            			break;

        }
    }while(1);
    return 0;
}

void push()
{
	int num;
	if(top==5)
	{
		printf("Stack is full\n");
	}
	else
	{
		printf("Enter number: ");
		scanf("%d",num);
		top++;
		stack[top]=num;
		printf("Insertion is successfull\n");
	}
}

void pop()
{
	if(top==-1)
	{
		printf("Stack is empty\n");
	}
	else
	{

		top--;

		printf(stack[top+1]<<" is popped\n");
	}
}

void display()
{
	if(top==-1)
	{
		printf("Stack is empty\n");
	}
	else
	{
		for(int i=top;i>=0;i--)
		printf(stack[i]<<", ");
	}
}

void peep()
{
	int i;
	printf("Enter the element u want to see: ");
	scanf("%d",i);
	if(top+1<i)
	{
		printf("Element does not exist");
	}
	else
	{
		printf("Element at"<<i<<" position is"<<stack[i-1];
	}
}

void change()
{
	int i,n;
	printf("Enter the position of element you want to change");
	scanf("%d",i);
	printf("Enter new value: ");
	scanf("%d",n);
	if(top+1<i)
	{
		printf("Element does not exist at that position");
	}
	else
	{
		stack[i-1]=n;
	}
}
