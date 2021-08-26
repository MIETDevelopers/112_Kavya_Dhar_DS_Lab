//Author:Kavya Dhar                                                    © Mr.dhar 26-June-2021
// Purpose :  
           // 1) Enqueue/Push an Element in Queue
           // 2) Dequeue/Pop an Element in Queue
           // 3) Display the Element in the Queue
           // 4) $$ Exit  $$
           
  // Question :Implement a Queue using Array and develop functions to perform enqueue and dequeue operations.
           
#include<stdio.h> //  Pre-Processive to include standard input and output funtion header files

#include<stdlib.h>  // Pre-Processive to include standard Libraray funtion header files (only Used for Exit function)

int *a; //  Pointer variable declaratation with data type 'int'

int n, KD, choice, rear = -1,front = -1, i; // Global Variable

int push(); // Funtion prototype 
int pop();
void view();
int main()
{
    printf("Enter the size of queue: ");
    scanf("%d",&n);
    a = (int*)malloc(n * sizeof(int)); // Malloc Syntax
    printf("\n\n\t  <> MENU FOR Queue <>\n\n");
    while(1)
	{
    	
        printf("\nEnter 1 to enqueue/Push element in stack.");
        printf("\nEnter 2 to dequeue/Pop element in stack.");
        printf("\nEnter 3 to view / Display element in stack.");
        printf("\nEnter 4 to EKDit.");
        printf("\n\nEnter the choice: ");
        scanf("%d",&choice);
        switch(choice){
            case 1:push();
                        break;
            case 2:pop();
                        break;
            case 3:view();
                        break;
            case 4:exit(0);
            default:printf("\n\n\t**See menu Program carefully*\n\n ");
        }
    }
    return 0;
}

int push()
{
    if (rear == n -1)
        printf("\nQueue is in  overflow\n");
    else
    {
        if(front == - 1)
            front = 0;
        printf("\nEnter the Desired element ");
        scanf("%d",&KD);
        rear = rear + 1;
        a[rear] = KD;
    }
    return 0;
}

int pop()
{
    if(front == -1 || front > rear)
        printf("\nQueue is in underflow \n");
    else
    {
        printf("\nElement %d has been popped out from queue\n",a[front]);
        front = front + 1;
    }
    return 0;
}

void view()
{
    if (front == -1){
        printf("\nEmpty bOe !!!!!");
    }
    else{
        printf("\nElements of the queue:\n");
        for(i = front; i <= rear; ++i){
            printf("%d\n",a[i]);
        }
    }
}
