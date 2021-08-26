//Author:K.D (Vilen)                                                                                              © Mr.Dhar 16-08-2021

// Purpose ;  // 
          /*<Implement a data structure in C to represent the shops in Raghunath Bazaar. <*/
		  /*.Perform operations on the data structure for finding out the shop with cheapest rate of walnut. <*/
          
          
#include<stdio.h> //Precessive To include to standard input and output funtions

#include<stdlib.h> //Including libraray files for the predefined functions used in this program.

struct info // Declaraing struct info as  user defined funtion
{
int Product; // Product with inta data type 
char name[40]; // name with char data type that stores 40 character size in memory
int price; // price as int data type
struct info *next; // next as pointer variable 
};
struct info *temp,*disp,*head; //Creating a user defined data type using structure to satisfy the memory storage of this program.

int TypeSearch; // for different catogries 

void pushrecord(); // funtion prototype 
void View();
void Viewmin();
void Viewmax();
void poprecord();
void displaySpecMin();
void displaySpecMax();
                                      //Declaring user defined functions for this program.

int main()
{
  int ch, ch1;
  
  while (1) //Using loop so that our function doesn't get close after a specific function, untill we enter the assigned input for exiting.
    {
      printf("\n~Dry Fruit tracker~\n");
      printf("\n 1. To add records.");
      printf("\n 2. To delete records.");
      printf("\n 3. To view the records.");
      printf("\n 4. To exit.");
      printf("\n Enter your choice: ");
      //Print functions used for creating a user inteface.
      
      scanf("%d",&ch);
      //Scan function is used to get the user input.       
      
      fflush(stdin);
      switch(ch)
            {
              case 1:
                  pushrecord();
                      break;

              case 2:
                  poprecord();
                    break;
              
              case 3:
                  printf("\n 1. DISPLAY ALL THE RECORDS: ");
                  printf("\n 2. Display minimum priced Product.");
                  printf("\n 3. Display maximum priced Product.");
                  printf("\n 4. Display minimum price of Walnuts.");
                  printf("\n 5. Display maximum price of Walnuts.");
                  printf("\n 6. Display minimum price of Almonds.");
                  printf("\n 7. Display maximum price of Almonds.");
                  printf("\n 8. Display minimum price of Cashew.");
                  printf("\n 9. Display maximum price of Cashew.");
                  printf("\n10. Display minimum price of Peanut.");
                  printf("\n11. Display maximum price of Peanut.");
                  printf("\n Enter desired display option: ");
                  scanf("%d", &ch1);
                  switch(ch1)
                  {
                    case 1:
                      View();
                        break;

                    case 2:
                      Viewmin();
                        break;

                    case 3:
                      Viewmax();
                        break;

                    case 4: 
                      TypeSearch = 1;
                      displaySpecMin(TypeSearch);
                      break;

                    case 5:
                      TypeSearch = 1;
                      displaySpecMax(TypeSearch);
                      break;

                    case 6: 
                      TypeSearch = 2;
                      displaySpecMin(TypeSearch);
                      break;

                    case 7:
                      TypeSearch = 2;
                      displaySpecMax(TypeSearch);
                      break;

                    case 8: 
                      TypeSearch = 3;
                      displaySpecMin(TypeSearch);
                      break;

                    case 9:
                      TypeSearch = 3;
                      displaySpecMax(TypeSearch);
                      break;

                    case 10: 
                      TypeSearch = 4;
                      displaySpecMin(TypeSearch);
                      break;

                    case 11:
                      TypeSearch = 4;
                      displaySpecMax(TypeSearch);
                      break;

                    default:
                      printf("\n Invalid choice! :/");
                        break;
                  }
                      break;

              case 4:
                  exit(0);
                      break;

              default:
                  printf("Invalid choice! :/");
                    break;
            }
//Switch case is used to determine the function to be performed as per user input.

    }
return 0;
}

//Here onwards: The body of our declared functions.
void pushrecord()
{
  struct info *add;
  //Using our user defined data structure a pointer variable is created.
  
  add=(struct info*)malloc(sizeof(struct info));
  //Memory is allocated to our variable using malloc.

  printf("\n Enter the name of dealer: ");
  gets(add->name);
  //As a name is generally considered as string so, gets is used to read that string & assign to the variable.
  printf("\n Enter the price of item: ");
  scanf("%d",&add->price);
  //As a price is generally considered as number so, scanf is used to read that number & assign to the variable.

  printf("\nWhich item's record you want to store?\n Available categories:");
  printf("\n1. Walnut\n2. Almond\n3. Cashew\n4. Peanut\n Enter your choice: ");
  scanf("%d", &add->Product);
  //This will assign an integer respective to the type of dry fruit.
  
  fflush(stdin);

    if(head==NULL|| head->price>=add->price)
      {
        add->next=head;
        head=add;
      }
    else
      {
        temp=head;
          
          while(temp->next!=NULL && temp->next->price < add->price)
            {
              temp=temp->next;
            }
//A loop is used so that it can iterate through whole list and place the data entered in ascending order with respect to price.
        add->next=temp->next;
        temp->next=add;
      }

//if-else statements are used to insert/add the user input into the list.
  return;
 }

void View()
{
  int count=0, category;
//A integer value is declared for printing serial number.
  if(head==NULL)
    {
      printf("\n No records to view\n");
      return;
    }
//If it is observed that the list is empty than the program will display the print statement & return back to main function.

  for(disp=head;disp!=NULL;disp=disp->next)
    {
      printf("\n -- \nSerial number: %d", count);
      printf("\nName of dealer: %s",disp->name);
      category=disp->Product;
      switch(category)
      {
        case 1: printf("\nCategory of Product: Walnut"); 
                break;

        case 2: printf("\nCategory of Product: Almond");
                break;

        case 3: printf("\nCategory of Product: Cashew");
                break;

        case 4: printf("\nCategory of Product: Peanut");
                break; 
      } //This switch case will determine the item type and print the respective name of item.
      printf("\nPrice of item: %d \n",disp->price);
      count++;
      //This will keep on increasing the value of interger by 1 each time the loop iterates.
    }
//The loop will iterate through whole list & keep on printing untill it reaches to the end of list.
  count=0;
//The variable declared would get initialed by zero.
return;
}

void poprecord()
{
    View();
//The purpose of display function used here is to display user all the records then he can have precise information of record to be deleted.
    int i,pos;
    struct info *temp,*ptr;
    if(head==NULL)
    {
        printf("\nThe List is Empty! :/");
        return;
    }
//If it is observed that the list is empty than the program will display the print statement & return back to main function.
    else
    {
        printf("\nEnter the serial number of record to be deleted: ");
        scanf("%d",&pos);
            if(pos==0)
            {
                ptr=head;
                head=head->next;
                printf("\nRecord deleted!");
                    free(ptr);
            }
            else
            {
                ptr=head;
                for(i=0;i<pos;i++) 
                { 
                    temp=ptr; 
                    ptr=ptr->next;
                    if(ptr==NULL)
                    {
                        printf("\nNode not found :/");
                        return;
                    }
                }
                temp->next=ptr->next;
                printf("\nRecord deleted!");
                    free(ptr);
            }
    }
//if-else statements are used to delete the record from the list based on user input.
}

void Viewmin()
{
  int category;
  if(head==NULL)
    {
      printf("\n No records to view!\n");
      return;
    }
//If it is observed that the list is empty than the program will display the print statement & return back to main function.

  for(disp=head;disp!=NULL;disp=disp->next)
    {
      if(disp=head)
      {
        printf("\nName of dealer: %s",disp->name);
        category=disp->Product;
        switch(category)
        {
          case 1: printf("\nCategory of Product: Walnut"); 
                  break;

          case 2: printf("\nCategory of Product: Almond");
                  break;

          case 3: printf("\nCategory of Product: Cashew");
                  break;

          case 4: printf("\nCategory of Product: Peanut");
                  break;
        }
        printf("\nPrice of item: %d \n",disp->price); 
        return; 
      }
    }
//The loop will iterate through whole list & will print the first element from loop as it will has minimum numeric value(price) in whole list.
return;  
}

void Viewmax()
{
  int count1=0, count2=0,category;
  //Two variables are declared to used as counter
  for(disp=head;disp!=NULL;disp=disp->next)
  {
    count1++;
  }
//A counter variable count1 is iterated in loop to get its value as the number of elements in list.

  for(disp=head;disp!=NULL;disp=disp->next)
  {
    count2++;
    //A counter variable count2 is iterated in loop to get its value increased by 1 each time it iterates.
    if(count1==count2)
    {
    printf("\nName of dealer: %s",disp->name);
    category=disp->Product;
    switch(category)
    {
      case 1: printf("\nCategory of Product: Walnut"); 
              break;

      case 2: printf("\nCategory of Product: Almond");
              break;

      case 3: printf("\nCategory of Product: Cashew");
              break;

      case 4: printf("\nCategory of Product: Peanut");
              break;
    }
    printf("\nPrice of item: %d \n",disp->price);
    return;
    }
    //If statement is used to check whether if both the counter variables are equal, if it does then it is determined that the loop has reached the end and it will print the record.
  }
    count1=0;
    count2=0;
}

void displaySpecMin()
{
  int count3=0;
  for(disp=head;disp!=NULL;disp=disp->next)
  {
    if(TypeSearch==disp->Product) //This if statement will statisfy the need as per user input for query & will print specific output.
    {
      count3++;
      printf("\nName of dealer: %s",disp->name);
      printf("\nPrice of item: %d \n",disp->price);
      return; //This return statement is supposed to allow the loop to return to main function after t came into being.
    }
  }
    if(count3==0) //This if statement will work only if value of count3 is equal to 0, which can be possible if there no specific item present in list.
    {
      printf("\n No records to view!\n");
      return;
    }
}

void displaySpecMax()
{
  int count1=0, count2=0,category;
  //Two variables are declared to used as counter
  for(disp=head;disp!=NULL;disp=disp->next)
  {
    if(disp->Product==TypeSearch)
    {
      count1++;
    }
    //A counter variable count1 is iterated in loop within if-else to get its value increased by 1 each time it iterates with satisfied.
  }
//A counter variable count1 is iterated in loop to get its value as the number of elements in list.

  for(disp=head;disp!=NULL;disp=disp->next)
  {
    if(disp->Product==TypeSearch)
    {
      count2++;
    }
    //A counter variable count2 is iterated in loop within if-else to get its value increased by 1 each time it iterates with satisfied.
    if(count1==count2)
    {
    printf("\nName of dealer: %s",disp->name);
    printf("\nPrice of item: %d \n",disp->price);
    return;
    }
    //If statement is used to check whether if both the counter variables are equal, if it does then it is determined that the loop has reached the end and it will print the record.
  }
      if(count1==0)
      {
        printf("\n No records to view!\n");
        return;
      }
    count1=0;
    count2=0; 
    //Initializing both values at 0 again.
}
