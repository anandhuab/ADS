#include<stdio.h>
#include<conio.h>

struct node
{
int data;
struct node *prev,*next;
}*head, *last;

void createlist(int n);
void displayfirst();
void displayinsbeg(int data);
void inslast(int data);
void insertany(int data, int pos);
void delbeg();
void delend();
void deleteany(int pos);
void search(int data);
void main()
{
int n,data,choice,pos;
clrscr();


while(1)
  {
  printf("\nchoose the bellow options:\n");
  printf("1.create list \n 2.display \n 3.exit \n 4.insert at beginning \n5.insert at end \n 6. insert at any pos..\n 7. delete from begining \n8. delete end\n 9.delete any \n 10. searching");
  printf("\nEnter your choice:");
  scanf("%d",&choice);
    switch(choice)
    {
      case 1:
      {

      printf("enter the total no. of nodes:");
      scanf("%d",&n);
      createlist(n);

      break;
      }

       case 2:
      {
      displayfirst();
      break;

      }


      case 3:
      {
      exit(0);
      break;
      }
       case 4:
      {
      printf("enter the data of first node:");
      scanf("%d",&data);
      displayinsbeg(data);
      break;
      }
       case 5:
      {
      printf("enter the data of last node:");
      scanf("%d",&data);
      inslast(data);
      break;
      }
       case 6:
      {
      printf("enter the possition to insert:");
      scanf("%d",&pos);
      printf("enter the data of first node:");
      scanf("%d",&data);
      insertany(data,pos);
      break;
      }

	 case 7:
      {
      delbeg();
      break;

      }

      case 8:
      {
      delend();
      break;

      }
      case 9:
      {
      printf("enter the node possition to delete:");
      scanf("%d",&n);
      deleteany(n);
      break;

      }

      case 10:
      {
      printf("enter the data want to search:");
      scanf("%d",&data);
      search(data);
      break;

      }
      default:
      {
      printf("enter valid option!!!!!!");
      }
    };
  }
}


void createlist(int n)
{
int i,data;
struct node *newnode;
if(n>=1)
{
head=(struct node *)malloc(sizeof(struct node));
printf("enter the data of node 1:");
scanf("%d",&data);
head->data=data;
head->prev=NULL;
head->next=NULL;
last=head ;
for(i=2;i<=n;i++)
{
newnode=(struct node *)malloc(sizeof(struct node));
printf("enter data of node %d",i);
scanf("%d",&data);
newnode->data=data;
newnode->prev=last;
newnode->next=NULL;
last->next=newnode;
last=newnode;
}

printf("\n doubly linked list created::");
}
}

void displayfirst()
{
struct node *temp;
int n=1;
if(head==NULL)
{
printf("list is empty::");
}
else
{
temp=head;
printf("\n datas in the list:\n");
while(temp!=NULL)
{
printf("Data of node %d=%d\n",n,temp->data);
n++;
temp=temp->next;
}
}
}

void displayinsbeg(int data)
{
struct node *newnode;
if(head==NULL)
{
printf("list empty");
}
else
{
newnode=(struct node *)malloc(sizeof(struct node));
newnode->data=data;
newnode->next=head;
newnode->prev=NULL;
head->prev=newnode;
head=newnode;
printf("node inserted");
}
}

void inslast(int data)
{
struct node *newnode;
if(head==NULL)
{
printf("list empty");
}
else
{
newnode=(struct node *)malloc(sizeof(struct node));
newnode->data=data;
newnode->next=NULL;
newnode->prev=last;
last->next=newnode;
last=newnode;
printf("node inserted::");
}
}
void insertany(int data,int pos)
{
struct node *newnode,*temp;
int i;
if(head==NULL)
{
printf("enpty list:::");
}
else
{
temp=head;
i=1;
while(i!=pos-1 && temp!=NULL)
{
temp=temp->next;
i++;
}
if(pos==1)
{
displayinsbeg(data);
}
else if(temp==last)
{
inslast(data);
}
else if(temp!=NULL)
{
newnode=(struct node *)malloc(sizeof(struct node));
newnode->data=data;
newnode->next=temp->next;
newnode->prev=temp;
if(temp->next!=NULL)
{
temp->next->prev=newnode;
}
temp->next=newnode;
printf("node inserted:::::");
}
else
{
printf("error invalid\n");
}
}
}

void delbeg()
{
struct node *todelete;
if(head==NULL)
{
printf("unable to delete:empty list:::");
}
else
{
todelete=head;
head=head->next;
if(head!=NULL)
{
head->prev=NULL;
}
free(todelete);
printf("successfully deleted");
}
}

void delend()
{
struct node *todelete;
if(last==NULL)
{
printf("empty");
}
else
{
todelete=last;
last=last->prev;
if(last!=NULL)
{
last->next=NULL;
}
free(todelete);
printf("successully deleted");
}
}

void deleteany(int pos)
{
struct node *current;
int i;
current=head;
for(i=1;i<pos && current!=NULL;i++)
{
current=current->next;
}
if(pos==1)
{
delbeg();
}
else if(current==last)
{
delend();
}
else if(current!=NULL)
{
current->prev->next=current->next;
current->next->prev=current->prev;
free(current);
printf("successfull");
}
else
{
printf("invalid");
}
}

void search(int data)
{
struct node *current;
int pos=0;
if(head==NULL)
{
printf("list empty");
}
current=head;
while(current!=NULL)
{
pos++;
if(current->data==data)
{
printf("%d found at %d th possition",data,pos);
break;
}
if(current->next!=NULL)
{
current=current->next;
}
else
{
printf("not exist");
break;
}
}
}