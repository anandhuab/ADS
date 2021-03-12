#include<stdio.h>
#include<conio.h>
#define MAXSIZE 5

int queue[MAXSIZE],rear=-1,front=-1,choice=0,i,j,n,val;
void insert();
void del();
void display();

void main()
{
clrscr();
printf("enter the size of queue:");
scanf("%d",&n);
printf("\n...........................\n");

  while(choice!=4)
  {
  printf("chose the bellow options:\n");
  printf("1.insert \n 2.delete \n 3.show \n 4.exit");
  printf("\nEnter your choice:");
  scanf("%d",&choice);
    switch(choice)
    {
      case 1:
      {
      insert();
      break;
      }

       case 2:
      {
      del();
      break;
      }

	case 3:
      {
      display();
      break;
      }

       case 4:
      {
      printf("exiting:");
      break;
      }
      default:
      {
      printf("enter valid option!!!!!!");
      }
    };
  }
}

void insert()
{
printf("enter the element:");
scanf("%d",&val);
  if(front==(rear+1)%MAXSIZE)
  {
  printf("queue is full");
  }
  else
  {
  if(front==-1)
  {
  front=rear=0;
  }
  else
  {
  rear=(rear+1)%MAXSIZE;
  }
  queue[rear]=val;
  printf("\nvalue inserted");
  }
}


  void del()
  {
  if((front==-1)&&(rear==-1))

  {
  printf("queue is empty");
  }
  else
  {
  val=queue[front];
  if(rear==front)
  {
  front=rear=-1;
  }
  else
  {
  front=(front+1)%MAXSIZE;
  }
  printf("deleted item %d",val);
}
}


  void display()
  {
  if((front==-1)&&(rear==-1))
  {
  printf("\nEmpty QUEUE");
  }
  else
  {
  if(front<=rear)
  {
  for(i=front;i<=rear;i++)
  {
   printf("%d\t",queue[i]);
   }
  }
  else
  {
  for(i=front;i<MAXSIZE;i++)
  {
  printf("%d\t",queue[i]);
  }
  for(i=0;i<=rear;i++)
  {
  printf("%d\t",queue[i]);
  }
  }
  }
}





