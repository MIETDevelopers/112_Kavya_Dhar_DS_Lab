//Author:Kavya Dhar
// Creation Date : 26-05-21
// Purpose ;  // 
           //Implement a Stack using Array and develop functions to perform push and pop operations.
#include<stdio.h>
#include <stdio.h>   
int stack[100],i,j,choice=0,n,top=-1, val;  
void push();  
void pop();  
void show();  
int main ()  
{  
      
    printf("Enter the number of elements in the stack ");   
    scanf("%d",&n);  
    printf("****Stack operations using array****");  
  
printf("\n----------------------------------------------\n");  
    while(choice != 4)  
    {  
        printf("Chose one from the below options...\n");  
        printf("\n1.Push\n2.Pop\n3.Show\n4.Exit");  
        printf("\n Enter your choice \n");        
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
                show();  
                break;  
            }  
            case 4:   
            {  
                printf("\nExiting....");  
                break;   
            }  
            default:  
            {  
                printf("\nPlease Enter valid choice ");  
            }   
        }  
    }  
}   
  
void push ()  
{  
    int val;      
    if (top == n )   
    printf("\n Overflow");   
    else
    {
        printf("\nEnter the value?");  
        scanf("%d",&val);   
        if(val % 2 == 1)
        {         
            top = top +1;   
            stack[top] = val;   
        }
        printf("%d element is successfully pushed \n",val);
    }   
}   
  
void pop ()   
{   
    if(top == -1)   
        printf("\nUnderflow");  
    else
    {
        if(stack[top]<9 ){
            printf("\nEnter A Number  greater than 9");
        }
        else{
            printf("%d is successfully poped from stack \n",stack[top] );
            top = top -1;
        }
}

           
}   
void show()  
{  
    printf("\nElement in the Stack are\n");
    for (i=top;i>=0;i--)  
    {  
        printf("%d\n",stack[i]);  
    }  
    if(top == -1)   
    {  
        printf("\nStack is empty");  
    }  
}
