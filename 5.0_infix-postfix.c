//Author:Kavya Dhar                                                    © Mr.dhar 26-June-2021
// Purpose :  
           // 1) Taking Infix Expression
           // 2) Converting Infix to Postfix/...
        
           // 3) Display the EXpression
           // 4) $$ Exit  $$
#include<stdio.h>
#include<stdlib.h>
#define size 100
char stack[size];
int top=-1;
void push (char item)
{
	if(top>=size-1)
	printf("\n Stack overflow push not possible");
	else
	{
		top++;
		stack[top]=item;
	}
}
char pop()
{
	char item;
	item=stack[top];
	top--;
	return(item);
}
int is_operator(char symbol)
{
	if(symbol=='^'|| symbol=='*'||symbol=='/'||symbol=='+'||symbol=='-')
	return 1;
	else
	return 0;
}
int precedence(char symbol)
{
	if(symbol=='^')
	return 3;
	else if (symbol=='*'||symbol=='/')
	return 2;
	else if (symbol=='+'||symbol=='-')
	return 1;
	else
	return 0;
}
int main()
{
	char infix[size],postfix[size],item,temp;
	int i=0,j=0;
	printf("Enter the arithematic expression in Infix notattions");
	gets(infix);
	while(infix[i]='\0')
	{
		item=infix[i];
		if(item=='(')
		{
			push(item);
		}
		else if (item>='A'&&item<='Z'|| item>='a'&&item<='z')
		{
			postfix[j]=item;
			j++;
		}
		else if (is_operator(item)==1)
		{
			temp=pop();
			while(is_operator(temp)==1 && presedence(temp)>=precedence(item))
			{
				postfix[j]=temp;
				j++;
				temp=pop();
			}
			push(temp);
			push(item);
		}
		else if (item==')')
		{
			temp=pop();
			while(temp!='(')
			{
				postfix[j]=temp;
				j++;
				temp=pop();
			}
		}
		else {
			pritntf("Invalid Arithematic expression");
			return 0;
			exit(0);
		}
		i++;
	}
	while(top>-1)
	{
		postfix[j]=pop();
		j++;
	}
	postfix[j]='\0';
	printf("Arithematic expression in postfix notation is");
	scanf("%d",postfix);
	return 0;
	}
