#include "conio.h"

struct Node 
{ int info;
  Node *next;
} *top,*ptr;

struct Stack {
Node * CreateNode(int val){
 ptr= new Node;
 ptr ->info = val;
 ptr ->next = NULL;
 return ptr;
}

void Push(Node *fresh){
 Node *save;

 if(top==NULL){
  top = fresh;
 }
 
 else {
  save=top;
  fresh->next=save;
  top=fresh;  
 } 
}

int Pop(){
 if(top==NULL){
  clrs();
  std::cout<<"[ERROR] CANNOT DELETE EMPTY LIST\n";
  return 0;
  }
  
  else{ 
   ptr=top;
   int save = ptr->info;
   top=top->next;
   delete ptr;
   return save;
 }
}

void Display(Node *node){
 while(node!=NULL){ 
   std::cout<<node->info<<" > ";
   node=node->next;
  }
}

void collectGarbage(){
    while(top!=NULL){ 
      Node *pt;
      pt=top;
      top=top->next;
      delete pt;
      }
 }
  
};


int main()
{	
 int choice,value;
 char temp;
 bool exit = false;

 Node *node;

while(!exit){
 std::cout<<"\n1.PUSH\n";
 std::cout<<"2.POP\n";
 std::cout<<"3.DISPLAY\n";
 std::cout<<"4.EXIT\n";
 std::cout<<"ENTER CHOICE:\n";

 Stack stack;
 std::cin>>choice;
 
 switch (choice)
 {
 case 1:  
    clrs();
    std::cout<<"[-] ENTER INFORMATION:\n";
    std::cin>>value;
    
    node=stack.CreateNode(value);
    
     if(node==NULL){
  	  std::cout<<"[ERROR] CANNOT CREATE NODE!\n";
  	  std::cout<<"[+] Aborting!\n";
     }

     else{ 
     stack.Push(node);
     }
    break;

 case 2:
  clrs();
  std::cout<<"POPPED- "<<stack.Pop();   
  break;

 case 3:
  clrs();
  std::cout<<"\nSTACK: ";
  stack.Display(top);
  break;
 
 case 4:
    std::cout<<"[-] EXIT? (Y/N)";
    std::cin>>temp;
    if(temp=='y' || temp=='Y')
      exit = true;
    break;
 
 default:
     std::cout<<"[ERROR - 2] INVALID CHOICE";
     gtch();
     clrs();
     break;
  }
}
 clrs();
 return 0;
}
