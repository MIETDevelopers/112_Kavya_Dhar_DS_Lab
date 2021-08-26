//Author:Kavya Dhar                                                    © Mr.dhar 3_Aug-2021
// Purpose :  
           //1)Implement a Stack using Linked List  
		   //2 perform push 
		   //3 pop operations.
		   //4 Display stack
		   //5 Stack Count Total Nodes
#include <stdio.h>  
#include <stdlib.h>  
void push();  
void pop();  
void display();
void stack_count();  
struct node   
{  
int val;  
struct node *next;  
};  
struct node *head;  
 int count=0; 
void main ()  
{  
    int choice=0;     
   	printf("\t\t\t\t // Our Heartiest welcome goes to you //    ");  
    while(1)  
    {  
        printf("\nMain--Menu");  
        printf("\n1.Push");
		printf("\n2.Pop");
		printf("\n3.View");
		printf("\n4.Total Stack");
		printf("\n5.Exit");  
        printf("\n Enter your Desired choice(1-5): >   \n");        
        scanf("%d",&choice);  
        switch(choice)  
        {  
            case 1:  
            {   
                push();  
                break;  
            }  
            case 2:  
            {  
                pop();  
                break;  
            }  
            case 3:  
            {  
                display();  
                break;  
            }  
            case 4:
            	{
            	stack_count();  
				break;	
				}
            case 5:   
            {  
                printf("Exiting....");  
                break;   
            }  
            default:  
            {  
                printf("// ERROR:404 ::: Please Enter valid choice ");  
            }   
    };  
}  
}  
void push ()  
{  
    int val;  
    struct node *ptr = (struct node*)malloc(sizeof(struct node));   
    if(ptr == NULL)  
    {  
        printf("not able to push the element");   
    }  
    else   
    {  
        printf("Enter the value: > ");  
        scanf("%d",&val);  
          ptr->val = val;  
            ptr -> next = NULL;  
            head=ptr;  
        printf("\n Item Pushed Succesfully");
        printf(" \n %d Is  pushed in Stack\n",val);  
        count++;  
    }  
}  
  
void pop()  
{  
    int item;  
    struct node *ptr;  
    if (head == NULL)  
    {  
        printf("Underflow");  
    }  
    else  
    {  
        item = head->val;  
        ptr = head;  
        head = head->next;  
        free(ptr); 
		printf("Item Poped From Stack\n"); 
        printf("\n %d popped From Stack\n",item);  
       count--;   
    }  
    
}  
void display()  
{  
    int i;  
    struct node *ptr;  
    ptr=head;  
    if(ptr == NULL)  
    {  
        printf("Stack is empty\n");  
    }  
    else  
    {  
        printf("\t\nPrinting Stack elements \n");  
        while(ptr!=NULL)  
        {  
            printf("%d\n",ptr->val);  
            ptr = ptr->next;  
        }  
    }  
}
/* Count stack elements */
void stack_count()
{
    printf("\n No. of elements in stack : %d", count);
}
