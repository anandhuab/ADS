#include<stdio.h>
#include<conio.h>

int stack[100],top=-1,choice=0,i,j,n;
void push();
void pop();
void display();

void main()
{
clrscr();
printf("enter the size of stack:");
scanf("%d",&n);
printf("\n...........................\n");

  while(choice!=4)
  {
  printf("chose the bellow options:\n");
  printf("1.push \n 2.pop \n 3.show \n 4.exit");
  printf("\nEnter your choice:");
  scanf("%d",&choice);
    switch(choice)
    {
      case 1:
      {
      push();
      break;
      }

       case 2:
      {
      pop();
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

void push()
{
int val;
  if(top==n-1)
  {
  printf("stack overflows!!!!");
  }
  else
  {
  printf("enter the value");
  scanf("%d",&val);
  top=top+1;
  stack[top]=val;
  }
}

  void pop()
  {
    if(top==-1)
    {
    printf("stack underflows ");
    }
    else
    {
    top=top-1;
    }
}

  void display()
  {
  for(i=top;i>=0;i--)
  {
  printf("%d\n",stack[i]);
  }
  if(top==-1)
  {
  printf("stack is empty");
  }
  }

