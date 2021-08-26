	//Author:Kavya Dhar                                                              //  © Mr.dhar 25-June-2021
// Purpose ;  // Prefix expressions
           // 1) Enter prefix Expression along with operation
           // 3) Result
           // 4) $$ Exit $$
	#include<stdio.h>  //   Pre-Processive to include standard input and output funtion header files
	
	#include<conio.h>  //    Pre-Processive to include console input and output funtion header files
	
	#include<string.h>   //    Pre-Processive to include string funtions header files
	
	int James[20]; // Maximum size of Stack i.e 20
	
	int top=-1; // stack is empty

	int A,B,i; // Global Declratation
	void push(int value)  
	
	{
	
				top=top+1;
				James[top]=value;
	
	}
	
	int pop()
	
	{
	
		return(James[top--]);
	
	}
	
	int ope(char c)
	
	{
	
			if(c=='+'||c=='-'||c=='*'||c=='/')
	
				return 1;
		
	else
	
	return 0;
	
	}
	
	void main()
	
	{
	int exp1;
	int exp2;
	int res;
		char prefix[10];
	
	printf("Enter the prefix Expression: ");
	
	scanf("%s",prefix);
	
	A=strlen(prefix);
	
	for(i=A-1;i>=0;i--)
	
	{
	
		switch(ope(prefix[i]))
	
	{
	
	case 0:
		
			B=prefix[i];
			
				push(B);
		
						break;
	
	
	
	case 1: 	exp1=pop();
	
					 exp2=pop();
		
		switch(prefix[i])
	
	{
	
			case '+': res=exp1+ exp2;
	
						break;
	
		case '-': res=exp1- exp2;
	
						break;
	
	case '*': res=exp1* exp2;
	
					break;
	
	case '/': res=exp1/ exp2;
	
					break;
	
	}
	
	push(res);
	
	}
	
	}
	
	printf("Result is %d",James[top]);
	
		
	}
