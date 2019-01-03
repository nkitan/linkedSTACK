#include <iostream>
#include <conio.h>

 struct node                            //DEFINITION / STRUCTURE OF NODE
  {
 	 int data;
	 node *next;
  };

struct stack                            //STACK STRUCTURE <CONTAINS FUNCTIONS FOR STACK OPERATIONS
  {
	 struct node *head,tail;
	 stack()
	 {
	 	 //head=NULL;                   //DOESN'T SEEM TO WORK FOR SOME REASON,WOULD LOOK FORWARD TO FIXING IT IN NEXT UPDATE
	 	 //tail=NULL;
	 }
     ~stack()                           //STACK DESTRUCTOR DELETES ALL CREATED NODES
     {
     	do
     	{
     	 struct node *delnode=head;
     	 head=head->next;
     	 delete delnode;
     	}
     	while(head!=NULL);
     } 

     inline void pushNode(int value)    //FUNCTION TO PUSH A NODE INTO STACK
	  	{

     	 struct node *NewNode= new node;
         
         if(head==NULL)
         {
         	NewNode->data=value;
         	*head=tail;
         	NewNode->next=head;
            head=NewNode;
         }

         else if(head!=NULL)
         {
          NewNode->data=value; 
          NewNode->next=head;
          head=NewNode;
         }
	    }

     inline void popNode()             //FUNCTION TO POP A NODE FROM STACK
		 {
		  if(head!=NULL)
		  {	
     	  struct node *temp=head;
      	  head=head->next;
      	  std::cout<<"DELETING "<<temp->data;
       	  delete temp;  	
          }
          else
          {
          	std::cout<<"NO ELEMENTS TO POP";
          	getch();
          }
         } 

     inline void display()             //FUNCTION TO DISPLAY THE STACK
	   {
	    struct node *nodewa = head;
	     next:
         do
         {      
          std::cout<<nodewa->data;
      	  nodewa=nodewa->next;
      	  std::cout<<"\n";
      	  goto next;
     	 }
     	 while(nodewa!=NULL);
     	                               //THERE ARE SOME BUGS HERE, FOR SOME REASON THE PROGRAM STOPS RESPONDING ON GOING TO DISPLAY
     	 if(nodewa==NULL)
         {  
         	std::cout<<"END OF STACK";
         }
        
        nodewa=NULL;
        delete nodewa;
	   }
  };

int main()                             //MAIN FUNCTION
{    
     stack STACK;
	 int data;
	 int choice;
	 char quit='y';
	 start:                            //START JUMP POINT
	 system("cls");
	 std::cout<<"STACK MENU\n";        //MENU FOR STACK
	 std::cout<<"1.PUSH\n";             
	 std::cout<<"2.POP\n";       
	 std::cout<<"3.DISPLAY\n";
	 std::cout<<"4.EXIT\n"; 
//         char cred[7];
//	 cred={"N","K","I","T","A","N"};
	std::cout<<"ENTER YOUR CHOICE:\n";
     std::cin>>choice;

	  if(choice==1)
	   {

	   std::cout<<"ENTER DATA:";
	   std::cin>>data;
       STACK.pushNode(data);
       goto start;
       }
      
      else if(choice==2)
       {
        std::cout<<"POPPING NODE";	
        STACK.popNode();
        goto start;
       }

      else if(choice==3)
      { 
        std::cout<<"DATA:";
      	STACK.display();
      	getch();
      	goto start;
      } 

      else if(choice==4)
      {
      	std::cout<<"\nExit Program? [y/n]:";
        std::cin>>quit;
        if(quit=='y' || quit =='Y')
         {
          getch();
      	  goto end;
         }

      	else
      	goto start;
      }

      else if(choice>4)
      {
       	std::cout<<"ENTER VALID CHOICE!";
        getch();
        goto start;
      } 	

      end:
     return 0; 
}
