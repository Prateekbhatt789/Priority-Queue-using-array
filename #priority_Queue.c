#include<stdio.h>
#define max 10
int queue[max][2],front=-1,rear=-1;
int high,l;
int high_index()                  //function to get value of high //don't want to use this function
{
    int highest,high=front;
    highest=queue[front][0];
   for(int i=front;i<=rear;i++)
    {
     if(highest>queue[i][0])
        high=i;
    }
    return high;
}
void gethighest()
{
 int highest,high=front;
 highest=queue[front][0];
 for(int i=front;i<=rear;i++)
    {
     if(highest>queue[i][0])
       {
        highest=queue[i][0];
        high=i;                                 //do not returning the value of high at dequeue()
       }
    }
  printf("Highest priority of queue:%d\n"
         "Value stored at corresponding priority:%d\n",highest,queue[high][1]);
}
void getlowest()
{
 int lowest,l=front;
 lowest=queue[front][0];
 for(int i=front;i<=rear;i++)
    {
     if(lowest<queue[i][0])
       {
        lowest=queue[i][0];
        l=i;
       }
    }
  printf("Lowest priority of queue:%d\n"
         "Value stored at corresponding priority:%d\n",lowest,queue[l][1]);
}

void enqueue(int priority,int val)
{
 if(rear==max-1)
    printf("Queue Overflow");
 else
 {
     if(front==-1)
       {
        front=0;
        rear=0;
        printf("front:%d\t Rear:%d\n",front,rear);
        queue[rear][0]=priority;
        queue[rear][1]=val;
       }
     else
       {
        rear=rear+1;
        printf("front:%d\t Rear:%d\n",front,rear);
        queue[rear][0]=priority;
        queue[rear][1]=val;
       }
 }
}
void dequeue()
{
  if(rear==-1||front==rear+1)
      printf("Queue Underflow");
  else
      {
        for(int i=high_index();i<rear;i++)       //don't want to use high_index()
                                                  //high value from gethighest() is 0
        {
          queue[i][0]=queue[i+1][0];
          queue[i][1]=queue[i+1][1];
        }
        rear=rear-1;
      }
}
void display()
{
 printf("Elements of Queue:\n priority\tData element\n");
 for(int i=front;i<=rear;i++)
 {
   printf("%d \t %d\n",queue[i][0],queue[i][1]);
 }
}
int main()
{
  int choice,val,priority;
  char ch;
  do{
  printf("--------Priority Queue-------\n"
         "1.Insert element in queue\n"
         "2.Delete element from queue\n"
         "3.Display Element with highest and lowest priority\n"
         "4.Display all the elements of queue"
         "\nEnter choice:");
  scanf("%d",&choice);
  switch(choice)
  {
     case 1:
              printf("Enter the priority:");
              scanf("%d",&priority);
              printf("Enter the value corresponding to this priority:");
              scanf("%d",&val);
              enqueue(priority,val);
              break;
     case 2:
              dequeue();
              break;
     case 3:
              gethighest();
              getlowest();
              break;
     case 4:
              display();
              break;
     default:
              printf("Wrong choice ");
              break;
  }
  printf("do you want to continue:");
  scanf(" %c",&ch);
  printf("\n");
  }while(ch=='y'||ch=='Y');
}



