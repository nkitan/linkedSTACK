#include"conio.h"


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
 clrs();
 std::cout<<"1.PUSH\n";
 std::cout<<"2.POP\n";
 std::cout<<"3.DISPLAY\n";
 std::cout<<"4.EXIT\n";
 std::cout<<"ENTER CHOICE:\n";

 std::cin>>choice;
 
 if(choice==1)
 {
  clrs();
  std::cout<<"[-] ENTER INFORMATION:";
  std::cin>>value;
  mainpointer=CreateNode(value);

  if(mainpointer==NULL)
  {
  	 std::cout<<"[ERROR] CANNOT CREATE NODE!";
  	 std::cout<<"\n[+] Aborting!";
  }
  Push(mainpointer);
 }
 
 else if(choice==2)
 {   
 	char temp;
 	 std::cout<<"[-] ARE YOU SURE?";
 	 std::cin>>temp;
 	 if(temp=='y' || temp=='Y')
 	 	Pop();
 	 clrs();
 }
 
 else if(choice==3)
 {
  clrs();
  std::cout<<"\nSTACK: ";
  Display(top);
  gtch();
 }
 
 else if(choice==4)
 {   
   std::cout<<"[-] EXIT? (Y/N)";
   std::cin>>exiit;
   if(exiit=='y' || exiit=='Y')
    {
     while(top!=NULL)
      { 
       Node *pt;
       pt=top;
       top=top->next;
       delete pt;
      }
     clrs();
 	   std::cout<<"\n[+] EXITING , ENTER AN ALPHABET THEN PRESS ENTER";
     gtch();
     goto end;
    } 
   goto start;
 }
 else
  { 
   std::cout<<"[ERROR - 2] INVALID CHOICE";
   gtch();
   clrs();
   goto start;
  }
 clrs();
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
	  clrs();
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


