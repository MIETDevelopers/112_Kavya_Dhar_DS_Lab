//Author:Kavya Dhar                                                    © Mr.dhar 6-July-2021
// Purpose :  1)Implement a Circular Linked List  
		//2) perform insertion, 
		//3) perform deletion and 
		//4) perform linear search operations.
           //EXIt @#$%^&
//Date:06-08-2021
//Circular Linked List
#include<stdio.h>//Header file for standard input and output(printf, scanf)
#include<stdlib.h>//Header file for standard library used to allocate memory(malloc function)
void insert();//Insert function prototype
void delete();//Delete function prototype
void view();//view function prototype
void search();//search function prototype
int count=0;//Variable declaration


//In the 8th line we have used typedef so that instead of writing struct node again 
//we can simply write variable of the structure to declare the name of the node 
typedef struct linkedlist//Node structure 
{
	int data;//Node structure member which contains the data
	struct linkedlist *prev;//Node structure member which contains the address of the previous node
	struct linkedlist *next;//Node structure member which contains the address of the next node
}node;//Structure variable

node *head=NULL;//Head node will be the top most node in the list and 
//is initialised with null because the list is empty in the beginning
node *last=NULL;//Last node will be the ;ast node in the list and is 
//initialised with null because the list is empty in the beginning

int main()
{
	int choice;//Variable declaration
	printf("(: Welcome :)\n");
	do{
		printf("Main Menu\n");
		printf("Press 1 to Insert\n");
		printf("Press 2 to Delete\n");//Menu of the program to insert, delete, view, search and exit the program
		printf("Press 3 to search\n");
		printf("Press 4 to view\n");
		printf("Press 5 to Exit\n");
		scanf("%d",&choice);

		switch(choice)
		{
			case 1:
				insert();
				break;

			case 2:
				delete();
				break;	

			case 3:
				search();
				break;	

			case 4:
				view();
				break;	

			case 5:
				printf("Thanks Visit Again\n");	
				break;

			default:
				printf("Invalid input\n");	
		}
	}while(choice!=5);
}

void insert()
{
	int pos, i=2;//Variable declaration

	node *ptr, *temp=head;//Node declaration
	ptr=(node*) malloc(sizeof(node));//Memory Allocation of the node

	if (ptr==NULL)//if the memory is not allocated in the ram then pointer ptr will return null
	{
		printf("Oops! can't insert...Memory not available\n");
	}
	printf("Enter the element\n");
	scanf("%d",&ptr->data);//Entering data in the node
	ptr->next=NULL;//Initialising next of ptr to null
	ptr->prev=NULL;//Initialising prev of ptr to null
	printf("Enter the position\n");
	scanf("%d",&pos);//Taking position as input from the user

	if (head==NULL)//If the list is empty
	{
		if (pos==1)//And if the user have opted for position 1 then only he can insert
		{
			head=ptr;//Head will be equal to the new node i.e. ptr
			last=ptr;//last will be equal to the new node i.e. ptr
			head->next=last;//As it is a circular linked list and its the first element so next of head will point to last 
			head->prev=last;//As it is a circular linked list so prev of head will point to last 
			printf("Node Inserted\n");
			count++;//Increasing the count by 1 as node is inserted
		}
		else//Else the program will print invalid position
		{
			printf("Invalid position\n");
			return;
		}
	}
	else if (pos==count+1)//Entering the node at the end
	{
		while(temp->next!=head)//Treversing the list till last
		{
			temp=temp->next;
		}
		temp->next=ptr;//Assigning the next of temp to ptr i.e. the newnode
		ptr->prev=temp;//Assigning the prev of ptr to temp
		ptr->next=head;//As the its a circular linked list and its the last element so next of ptr will contain head
		last=ptr;
		head->prev=last;//Updating previous of head to last as new node is inserted in last
		printf("Node Inserted\n");
		count++;
	}
	else if (pos==1)//Entering node at position 1
	{
		head=ptr;
		ptr->next=temp;
		temp->prev=ptr;
		head->prev=last;
		last->next=head;
		printf("Node Inserted\n");
		count++;
	}
	else
	{
		while(i<pos)
		{
			temp=temp->next;
			i++;
		}
		temp->next->prev=ptr;
		ptr->next=temp->next;
		temp->next=ptr;
		ptr->prev=temp;
		printf("Node Inserted\n");
		count++;
	}
	printf("Top element=%d\n",head->data);
	printf("Last element=%d\n",last->data);
	printf("Total elements=%d\n",count);
}

void delete()
{
	int pos, i=1;
	node *temp=head, *ptr;

	if (head==NULL)
	{
		printf("List is empty\n");
	}
	printf("Enter the position\n");
	scanf("%d",&pos);

	if (pos==1)
	{
		head=head->next;
		head->prev=last;
		last->next=head;
		printf("%d is deleted\n",temp->data);
		free(temp);
		count--;
	}
	else if (pos==count)
	{
		while(temp->next!=head)
		{
			temp=temp->next;
		}
		last=last->prev;
		last->next=head;
		head->prev=last;
		printf("%d is deleted\n",temp->data);
		free(temp);
		count--;
	}
	else if (pos>count)
	{
		printf("Invalid position\n");
	}
	else
	{
		while(i<pos)
		{
			ptr=temp;
			temp=temp->next;
			i++;
		}
		ptr->next=temp->next;
		temp->next->prev=ptr;
		printf("%d is deleted\n",temp->data);
		free(temp);
		count--;
	}
	printf("Top element=%d\n",head->data);
	printf("Last element=%d\n",last->data);
	printf("Total elements=%d\n",count);
}

void search()
{
	int num, index=1,n;
	node *temp;

	printf("Enter the element to be searched\n");
	scanf("%d",&num);
	if (head==NULL)
	{
		printf("List is empty\n");
	}
	else
	{
		temp=head;
		do
		{
			if (temp->data==num)
			{
				printf("%d is at %d position\n",num, index);
				n=0;
			}
			else
			{
				n=1;
			}
			temp=temp->next;
			index++;
		}while(temp!=last->next);
		if (n==1)
		{
			printf("Element not found\n");
		}
	}
}

void view()
{
	node *temp=head;
	if (head==NULL)
	{
		printf("List is empty\n");
	}
	else
	{
		do
		{
			printf("%d\n",temp->data);
			temp=temp->next;
		}while(temp!=last->next);
		printf("Total elements=%d\n",count);
	}
}
