/**
 * @author ${hisham_maged10}
 *https://github.com/hisham-maged10
 * ${DesktopApps}
 */
#include <stdio.h>
#include <stdlib.h>
#define type int
typedef struct
{
    type data;
    node*next;
}node;
typedef struct
{
    node*front,*rear;
}queue;
node* newnode(type value)
{
    node*n=(node*)malloc(sizeof(node));
    n->data=value;
    n->next=NULL;
}
void initializequeue(queue*q)
{
    q->front=NULL;
    q->rear=NULL;
}
void enqueue(queue*q,type value)
{
    node*n=newnode(value);
    if(isempty(q))
    {
        q->rear=q->front=n;
    }
    else
    {
    q->rear->next=n;
    q->rear=n;
    }

}
type dequeue(queue*q)
{
    if(isempty(q))
    {
        printf("Queue is empty!\n");
        return -1;
    }
    else if(q->front==q->rear)
    {
        q->front=q->rear=NULL;
    }
    else
    {
        node*n=q->front;
        q->front=n->next;
        type value=n->data;
        free(n);
        return value;
    }
}
int size(queue*q)
{
    node*n=q->front;
    int counter=0;
    while(n)
    {
       counter++;
       n=n->next;
    }
    return counter;
}
int isempty(queue*q)
{
    if(q->front==NULL && q->rear==NULL)
    {
        return 1;
    }
    else
        return 0;
}
void display(queue*q)
{
    queue copy;
    initializequeue(&queue);
    printf("[");
    while(!isempty(q))
    {
     type x=dequeue(q);
        printf("%d",x);
    enqueue(&copy,x);
    }
    while(!isempty(&copy))
    {
        enqueue(q,dequeue(&copy));
    }
}
int main()
{
    printf("Hello world!\n");
    return 0;
}
