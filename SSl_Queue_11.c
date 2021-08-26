//Author:Kavya Dhar                                                    © Mr.dhar 4-August-2021
// Purpose :  
           //1) Implement a Queue using Linked List 
		   //2 perform enqueue 
		   //3 dequeue operations
		   //4 Display 
#include<stdio.h>   
#include<stdlib.h>  
struct node   
{  
    int data;   
    struct node *next;  
};  
struct node *front;  
struct node *rear;   
void Enqueue();  
void Dequeue();  
void display(); 
void queuesize(); 
int count=0;
void main ()  
{  
    int choice; 
	printf("\t\t\t\t // Our Heartiest welcome goes to you //    ");  
    while(1)   
    {     
        printf("\nMain--Menu");  
        printf("\n1.Enqueu");
		printf("\n2.Dequeue");
		printf("\n3.Show");
		printf("\n4.Total Queue");
		printf("\n5.Exit"); 
        printf("\nEnter Your Desried Choice(1-5): > ");  
        scanf("%d",& choice);  
        switch(choice)  
        {  
            case 1:  
            Enqueue();  
            break;  
            case 2:  
            Dequeue();  
            break;  
            case 3:  
            display();  
            break;
			case 4:
			queuesize();
			break;  
            case 5:  
            exit(0);  
            break;  
            default:   
            printf("\nEnter valid choice??\n");  
        }  
    }  
}  
void Enqueue()  
{  
    struct node *ptr;  
    int item;   
      
    ptr = (struct node *) malloc (sizeof(struct node));  
    if(ptr == NULL)  
    {  
        printf("\nOVERFLOW\n");  
        return;  
    }  
    else  
    {   
        printf("\nEnter Desired Value\n");  
        scanf("%d",&item);  
        ptr -> data = item;  
        if(front == NULL)  
        {  
            front =rear= ptr;  
            front -> next = NULL;  
            rear -> next = NULL;  
        }  
        else   
        {  
            rear -> next = ptr;  
            rear = ptr;  
            rear->next = NULL;  
            printf("Enqueing Succesfully");
        }  
        count++;
    }  
}     
void Dequeue ()  
{  
    struct node *ptr;  
    if(front == NULL)  
    {  
        printf("\nUNDERFLOW\n");  
        return;  
    }  
    else   
    {  
        ptr = front;  
        front = front -> next;  
        printf("Dequeing Succesfully");
        free(ptr); 
	 
    }  
    count--;
}  
void display()  
{  
    struct node *ptr;  
    ptr = front;      
    if(front == NULL)  
    {  
        printf("\nEmpty queue\n");  
    }  
    else  
    {   printf("\n\tPrinting values .....\n");  
        while(ptr != NULL)   
        {  
            printf("\n%d\n",ptr -> data);  
            ptr = ptr -> next;  
        }  
    }  
} 
void queuesize()
{
    printf("\n Element Containg in Queue is  : %d", count);
} 

