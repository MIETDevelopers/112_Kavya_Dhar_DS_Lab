//Author:Kavya Dhar                                                    © Mr.dhar 28-June-2021
// Purpose :  
           // 1) Taking Postfix Expression
           // 2) Converting Postfix to Infix
           // 3) Display The Required Expression
           // 4) $$ Exit  $$
#include <stdio.h>
#include <stdlib.h>
int top = 10;
struct node
{
	char ch;
	struct node *next;
	struct node *prev;
}  *stack[11];
typedef struct node node;
 
void push(node *str)
{
	if (top <= 0)
	printf("Stack is Full ");
	else
	{
		stack[top] = str;
		top--;
	}
}
 
node *pop()
{
	node *exp;
	if (top >= 10)
		printf("Stack is Empty ");
	else
		exp = stack[++top];
	return exp;
}
void convert(char exp[])
{
	node *op1,  *op2;
	node *temp;
	int i;
	for (i=0;exp[i]!='\0';i++)
	if (exp[i] >= 'a'&& exp[i] <= 'z'|| exp[i] >= 'A' && exp[i] <= 'Z')
	{
		temp = (node*)malloc(sizeof(node));
		temp->ch = exp[i];
		temp->next = NULL;
		temp->prev = NULL;
		push(temp);
	}
	else if (exp[i] == '+' || exp[i] == '-' || exp[i] == '*' || exp[i] == '/' ||
exp[i] == '^')
	{
		op1 = pop();
		op2 = pop();
		temp = (node*)malloc(sizeof(node));
		temp->ch = exp[i];
		temp->next = op1;
		temp->prev = op2;
		push(temp);
	}
}
 
void display(node *temp)
{
	if (temp != NULL)
	{
		display(temp->prev);
		printf("%c", temp->ch);
		display(temp->next);
	}
}
 
void main()
{
	char exp[50];
	printf("Enter the postfix expression :");
	scanf("%s", exp);
	convert(exp);
	printf("\nThe Equivalant Infix expression is:");
	display(pop());
	printf("\n\n");
	getch();
}
