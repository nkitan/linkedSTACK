#include<iostream>
#include<stdlib.h>
#include<conio.h>


struct Node 
{
	 int info;
	 Node *next;
} *top,*ptr;

Node * CreateNode(int);
void Push(Node *);
void Display(Node *);
void Pop();

int main()
{

 int choice,value;
 char exiit;
 Node *mainpointer;

 start:
 std::cout<<"1.PUSH\n";
 std::cout<<"2.POP\n";
 std::cout<<"3.DISPLAY\n";
 std::cout<<"4.EXIT\n";
 std::cout<<"ENTER CHOICE:\n";

 std::cin>>choice;
 
 if(choice==1)
 {
  system("cls");
  std::cout<<"ENTER INFORMATION:";
  std::cin>>value;
  mainpointer=CreateNode(value);
  if(mainpointer==NULL)
  {
  	 std::cout<<"CANNOT CREATE NODE!";
  	 std::cout<"\nAborting!";
  }
  Push(mainpointer);
 }
 
 else if(choice==2)
 {   
 	char temp;
 	 std::cout<<"ARE YOU SURE?";
 	 std::cin>>temp;
 	 if(temp=='y' || temp=='Y')
 	 	Pop();
 	 system("cls");
 }
 
 else if(choice==3)
 {
  system("cls");
  std::cout<<"\nTHE STACK IS:";
  Display(top);
  getch();
 }
 
 else if(choice==4)
 {   
   std::cout<<"EXIT? (Y/N)";
   std::cin>>exiit;
   if(exiit=='y' || exiit=='Y')
    {
     system("cls");
 	   std::cout<<"\nEXITING , Press any key";
     getch();
     goto end;
    } 
   goto start;
 }
 system("cls");
 goto start;
 end:
 return 0;
}



Node * CreateNode(int val)
{
ptr= new Node;
ptr ->info = val;
ptr ->next = NULL;
return ptr;
}

void Push(Node *fresh)
{
	Node *save;
	if(top==NULL)
	 top = fresh;

	else
	{
	 save=top;
     fresh->next=save;
     top=fresh;  
    } 
}

void Pop()
{
	if(top==NULL)
	 {
	  system("cls");
      std::cout<<"UNDERFLOW!\n";
	 }

    else
    {
     ptr=top;
     top=top->next;
     delete ptr;
    }
}

void Display(Node *dispnode)
{
	 while(dispnode!=NULL)
	 { 
      std::cout<<dispnode->info<<" ->";
      dispnode=dispnode->next;
	 }
	 std::cout<<"\nEND OF STACK \n";
}


