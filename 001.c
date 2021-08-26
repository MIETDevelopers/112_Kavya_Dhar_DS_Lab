//Author:Kavya Dhar
// Creation Date : 25-05-21
// Purpose ;  // 
           // 1) Inserting an Element in an Array
           // 2) Deleting an Element in an Array
           // 3) Searching an Element in an Array
           
#include<stdio.h> //  Pre-Processive to include standard input and output funtion header files
void insert();  // Funtion Prototype
void del();  // Funtion Prototype
void search ();  // Funtion Prototype
int main()  // Main funtion 
{
	int i;
	char ch;  // Variable Declratation
	do

	{
		printf("      // Our Heartiest welcome goes to you //    ");
		printf("\nMain menu");
		printf(" \n1. Insert");
		printf("\n2.  Delete");
		printf("\n3. Search");
		printf("\n enter your choice >> ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1: insert();
					break;
			case 2: del();
					break;
			case 3: search();
					break;
		default:
              printf("Wrong choice, Please try again later");
    }
    printf ("\n Do you want to continue: y/n  ");
    scanf (" %c", &ch);
    } while(ch == 'y');
 }
// CASe for Inserting an element at specified position
 void insert()
{
	int  a[20],n,l,x,i;
	printf("Enter Size of array >> ");
	scanf("%d",&n);
	printf("Enter elements >> ");
	for(i=0;i<n;i++)
	{
	    scanf("%d",&a[i]);
	    
	}
	printf("\nElements Before Inserting elements respective array is: ");
    for(i=0;i<n;i++)
 
    {
        printf("%d  ", a[i]);
    }
	printf("\n enter location where elements is to be inserted >> ");
	scanf("%d",&l);
	printf("\n enter element to be inserted >> ");
	scanf("%d",&x);
	n=n+1;
	for(i=n-1;i>=l;i--)
    {
        a[i]=a[i-1];
    }

	a[i]=x;
	printf("\nArray After insertion is >> ");
	for(i=0;i<n;i++)
	{
		printf("\t%d",a[i]);
	}
	}
	 // CAse for deleting element from respective array 
void del()
{
	int a[20],n,l,i;
	printf("Enter Size of Array >> ");
	scanf("%d",&n);
	printf("enter elements >> ");
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	printf("\nElements Before Delelting elements respective array is: ");
    for(i=0;i<n;i++)
 
    {
        printf("%d  ", a[i]);
    }
	printf("\n Enter location where element is to be deleted >> ");
	scanf("%d",&l);
	for(i=l-1;i<n-1;i++)
	{
		a[i]=a[i+1];
	}
	n=n-1;
	printf("\n Array after deletion>> ");
	for(i=0;i<n;i++)
	{
		printf("\t %d",a[i]);
	}
}
	// CASE For Searching An Element
void search()
{
	int a[20],n,x,i;
	printf("\n Enter Size of array >> ");
	scanf("%d",&n);
	printf("\n enter elements >> ");
	for(i=0;i<n;i++)
	{
	scanf("%d",&a[i]);
}
printf("\nElements Before Searching elements respective array is: ");
    for(i=0;i<n;i++)
 
    {
        printf("%d  ", a[i]);
    }
printf(" \n Enter elements to be searched >> ");
scanf("%d",&x);
for(i=0;i<n;i++)
{
	/* 
         * If element is found in array then raise found 
         * and terminate from loop.
         */ 
	if(a[i]==x)
	{
		printf("\n Element is at  %d Index",i);
		printf("\n Element is at %d Position",i+1);
		break;
	}
}
if(i==n)
/*
     * If element is not found in array
     */
printf("\n element is not present");
}
