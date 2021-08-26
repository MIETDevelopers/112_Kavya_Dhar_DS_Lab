// Author: Kavya Dhar                                                     
// Purpose :  
           // 1) Enqueue/Push an Element in Queue (Without Memory Wstage)
           // 2) Dequeue/Pop an Element in Queue (Without Memory Wstage)
           // 3) Display the Element in the Queue (Without Memory Wstage) 
           // 4) $$ Exit  $$
           
  // Question :Implement a Queue using Array and develop functions to perform enqueue and dequeue operations (Without Memory Wstage).         
#include<stdio.h> //  Pre-Processive to include standard input and output funtion header files

#include<stdlib.h>  // Pre-Processive to include standard Libraray funtion header files (only Used for Exit function)

int *a; //  Pointer variable declaratation with data type 'int'

int n, KD,i; // Global Variable
int front=-1,rear=-1;// Initial postion is a Empty (Underflow)

int Enqueu(); // Funtion prototype to push
int Dequeu();  // Funtion prototype to pop
void view();  // Funtion prototype to display
int main()

{
	int choice; // Local Variable
    printf("Enter the size of queue: "); 
    scanf("%d",&n); // queue ka Size 
    a = (int*)malloc(n * sizeof(int)); // Malloc Syntax  // 
    printf("\n\n\t  <> MENU FOR Queue <>\n\n");
    while(1)
	{
    	
        printf("\nEnter 1 to enqueue/Push element in stack.");
        printf("\nEnter 2 to dequeue/Pop element in stack.");
        printf("\nEnter 3 to view / Display element in stack.");
        printf("\nEnter 4 to Exit.");
        printf("\n\nEnter the choice: ");
        scanf("%d",&choice);
        switch(choice){
            case 1:Enqueu();
                        break;
            case 2:Dequeu();
                        break;
            case 3:view();
                        break;
            case 4:exit(0);
            default:printf("\n\n\t**See menu Program carefully*\n\n ");
        }
    }
    return 0;
}

int Enqueu() 
{
    if (rear == n -1) // goes MAx Size upto  // (n-1):Index Value  
        printf("\nQueue is in  overflow\n"); // 
    else
    {
        if(front == - 1) // Front is Emppty 
            front = 0; // Front =0 the rear incremennt
        printf("\nEnter the Desired element ");
        scanf("%d",&KD);
        rear = rear + 1; // Rear=-1, 1st elemnt at 0th index 
        a[rear] = KD; // Value store KD 0th iNdex =KD 
    }
    return 0;
}

int Dequeu() // 
{
    if(front == -1 || front > rear) // front=-1 rear<front, que underflow (elemnt not inset
        printf("\nQueue is in underflow \n"); // 
    else
    {
        printf("\nElement %d has been popped out from queue\n",a[front]);
        rear = rear - 1;
    }
    return 0;
}

void view()
{
    if (front == -1 ||front>rear) {
        printf("\nEmpty bOe !!!!!");
    }
    else{
        printf("\nElements of the queue:\n");
        for(i = front; i <= rear; ++i){
            printf("%d\n",a[i]);
        }
    }
}
