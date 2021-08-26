//Author:Kavya Dhar                                                    © Mr.dhar 4-July-2021
// Purpose :  1)Implement a Doubly Linked List  
		//2) perform insertion, 
		//3) perform deletion and 
		//4) perform linear search operations.
           //EXIt @#$%^&
#include<stdio.h>
#include<stdlib.h>
void insert();
void delete();
void search();
void view();
int count=0, i=2;
typedef struct linkedlist
{
	int data;
	struct linkedlist *prev;
	struct linkedlist *next;
}node;
node *head=NULL, *last=NULL;
int main()
{
	int choice;
	printf("(: Welcome :)\n");
	do{
		printf("Main Menu\n");
		printf("Press 1 to Insert\n");
		printf("Press 2 to Delete\n");
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
	int pos;
	node *ptr, *temp;
	ptr=(node*) malloc(sizeof(node));
	if (ptr==NULL)
	{
		printf("Oops! can't enter element.....Memory not available\n");
	}
	printf("Enter the element\n");
	scanf("%d",&ptr->data);
	ptr->prev=NULL;
	ptr->next=NULL;
	printf("Enter the position\n");
	scanf("%d",&pos);

	if (head==NULL)
	{
		if (pos==1)
		{
			head=ptr;
			last=ptr;
			count++;
			printf("Node inserted\n");
		}
		else
		{
			printf("Invalid position\n");
		}
	}
	else if (pos==1)
	{
		ptr->next=head;
		head->prev=ptr;
		head=ptr;
		count++;
		printf("Node inserted\n");
	}
	else if (pos==count+1)
	{
		temp=head;
		while(temp->next!=NULL)
		{
			temp=temp->next;
		}
		ptr->prev=temp;
		temp->next=ptr;
		last=ptr;
		count++;
		printf("Node inserted\n");
	}
	else
	{
		temp=head;
		while(i<pos)
		{
			temp=temp->next;
			i++;
		}
		temp->next->prev=ptr;
		ptr->next=temp->next;
		temp->next=ptr;
		ptr->prev=temp;
		count++;
		printf("Node Inserted\n");

	}
	printf("Total elements=%d\n",count);
}

void delete()
{
	int num, choice, pos, x=1;
	node *ptr, *temp;
	if (head==NULL)
	{
		printf("Oops! List is empty\n");
		return;
	}

		printf("Press 1 to delete from a position\n");
		printf("Press 2 to delete a specific element\n");
		scanf("%d",&choice);

		switch(choice)
		{
			case 1:
				printf("Enter the position\n");
				scanf("%d",&pos);

				if (head==NULL)
				{
					printf("List is empty\n");
				}
				else if (head->next==NULL)
				{
					printf("%d is deleted\n",head->data);
					head=NULL;
					last=NULL;
					free(head);
					count--;
				}
				else if (pos>count)
				{
					printf("Invalid Position\n");
				}
				else if (pos==1)
				{
					temp=head;
					printf("%d is deleted\n",temp->data);
					head=head->next;
					free(temp);
					count--;
				}
				else
				{
					temp=head;
					while(x<pos)
					{
						ptr=temp;
						temp=temp->next;
						x++;
					}
					ptr->next=temp->next;
					printf("%d is deleted\n",temp->data);
					free(temp);
					count--;
				}
				break;

			case 2:
				printf("Enter the element to be deleted\n");
				scanf("%d",&num);
				temp=head;
				
				if(head->next==NULL)
				{
					while(temp!=NULL && temp->data==num)
					{
						head=NULL;
						printf("%d is deleted\n",temp->data);
						free(temp);
						count--;
					}
				}
				else if (head->data==num)
				{
					head=head->next;
					head->prev=NULL;
					printf("%d is deleted\n",temp->data);
					free(temp);
					count--;
				}
				else if (last->data==num)
				{
					temp=last;
					last=last->prev;
					last->next=NULL;
					printf("%d is deleted\n",temp->data);
					free(temp);
					count--;
				}
				else
				{
					while(temp!=NULL && temp->data!=num)
					{
						ptr=temp;
						temp=temp->next;
					}
						ptr->next=temp->next;
						temp->next->prev=ptr;
						count--;
						printf("%d is deleted\n",temp->data);
						free(temp);
				}
				break;
		}
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
		while(temp!=NULL)
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
		}
		if (n==1)
		{
			printf("Element not found\n");
		}
	}
}

void view()
{
	int choice;
	node *temp;
	if (head==NULL)
	{
			printf("Oops! List is empty\n");
	}
	else
	{
	printf("Press 1 to view the list from beginning\n");
	printf("Press 2 to view the list from end\n");
	scanf("%d",&choice);
	switch(choice)
		{
			case 1:
					temp=head;
					while(temp!=NULL)
					{
						printf("%d\n",temp->data);
						temp=temp->next;
					}
				break;

			case 2:
				temp=last;
				while(temp!=NULL)
				{
					printf("%d\n",temp->data);
					temp=temp->prev;
				}
		}	
		printf("Total elements=%d\n",count);
	}		
}
