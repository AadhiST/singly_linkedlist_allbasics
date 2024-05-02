#include <stdio.h>
#include<stdlib.h>
struct node{
  int data;
  struct node*next;
}*newnode=NULL,*second=NULL,*third=NULL;

void create(int A[],int n)
{
  struct node*head;
  newnode=(struct node*)malloc(sizeof(struct node));
  newnode->data=A[0];
  newnode->next=NULL;
  head=newnode;

  for(int i=1;i<n;i++)
  {
    struct node*temp=(struct node*)malloc(sizeof(struct node));
    temp->data=A[i];
    temp->next=NULL;
    head->next=temp;
    head=temp;
  }
}

void create2(int B[],int n)
{
  struct node*head;
  second=(struct node*)malloc(sizeof(struct node));
  second->data=B[0];
  second->next=NULL;
  head=second;

  for(int i=1;i<n;i++)
  {
    struct node*temp=(struct node*)malloc(sizeof(struct node));
    temp->data=B[i];
    temp->next=NULL;
    head->next=temp;
    head=temp;
  }
}

void display(struct node*head)
  {
  
  while(head!=NULL)
    {
      printf("%d ",head->data);
      head=head->next;
    }
  }

void rdisplay(struct node*p)
{
    if(p!=NULL)
    {
        rdisplay(p->next);
        printf("%d ",p->data);
    }
}

int count(struct node*head)
{
  int count=0;
  while(head)
  {
    count++;
    head=head->next;
  }
  return count;
}

int rcount(struct node*head)
{
  if(head!=NULL)
  return rcount(head->next)+1;
  else
  return 0;
}

int sum(struct node*head)
{
  int s=0;
  while(head!=NULL)
  {
    s=s+head->data;
    head=head->next;
  }
  return s;
}

int rsum(struct node*head)
{
  if(head!=NULL)
  return rsum(head->next)+head->data;
  else
  return 0;
}

int max(struct node*head)
{
  int max=-32768;
  while(head)
  {
    if(head->data>max)
    max=head->data;
    head=head->next;
  }
  return max;
}

int rmax(struct node*head)
{
  int a=0;
  if(head==NULL)
  return -32768;
  a=rmax(head->next);
  if(a>head->data)
  return a;
  else
  return head->data;
}

struct node*lsearch(struct node*head,int key)
{
  struct node*last;
  while(head!=NULL)
  {
    if(key==head->data)
    {
      last->next=head->next;
      head->next=newnode;
      newnode=head;
      return head;
    }
    last=head;
    head=head->next;
  }
  return NULL;
}

struct node*rsearch(struct node*head,int key)
{
  if(head==0)
  return 0;
  if(key==head->data)
  return head;
  return rsearch(head->next,key);
}

void insert(struct node*head,int pos,int n)
{
    struct node*p;
    int len=count(head);
    if(pos<0||pos>len)
    {
        return;
    }    
    p=(struct node*)malloc(sizeof(struct node));
    p->data=n;
    if(pos==0)
    {
        p->next=newnode;
        newnode=p;
    }
    else
    {
        for(int i=1;i<pos-1;i++)
        head=head->next;
        p->next=head->next;
        head->next=p;
    }
}

void sortedlist(struct node*head,int n)
{
  struct node*p,*q=NULL;
  p=(struct node*)malloc(sizeof(struct node));
  p->data=n;
  p->next=NULL;
  if(newnode==0)
  newnode=p;
  else{
    while(head&&head->data<n)
    {
      q=head;
      head=head->next;
      if(head==newnode)
      {
        p->next=newnode;
      }
      else{
        p->next=q->next;
        q->next=p;
      }
    }
  }
}

int delete(struct node*head,int pos)
{
  struct node*q=NULL;
  int x=-1;
  if(pos<1||pos>count(head))
  return x;
  if(pos==1)
  {
    q=newnode;
    x=newnode->data;
    newnode=newnode->next;
    free(q);
    return x;
  }
  else{
    for(int i=0;i<pos-1;i++)
    {
      q=head;
      head=head->next;
    }
    q->next=head->next;
    x=head->data;
    free(head);
    return x;
  }
}

int issorted(struct node*head)
{
  int x=-65536;
  while(head!=NULL)
  {
    if(head->data<x)
    return 0;
    x=head->data;
    head=head->next;
  }
  return 1;
}

void removeduplicate(struct node*head)
{
  struct node*q=head->next;
  while(q!=0)
  {
    if(head->data!=q->data)
    {
      head=q;
      q=q->next;
    }
    else{
      head->next=q->next;
      free(q);
      q=head->next;
    }
  }
}

void reverse(struct node*head)
{
  int*A,i=0;
  struct node*q=head;
  A=(int*)malloc(sizeof(int)*count(head));
  while(q!=NULL)
  {
    A[i]=q->data;
    q=q->next;
    i++;
  }
  q=head;
  i--;
  while(q!=NULL)
  {
    q->data=A[i];
    q=q->next;
    i--;
  }
}

void reverse2(struct node*head)
{
  struct node*q=NULL,*r=NULL;
  while(head!=NULL)
  {
    r=q;
    q=head;
    head=head->next;
    q->next=r;
  }
  newnode=q;
}

void reverse3(struct node*q,struct node*head)
{
  if(head)
  {
    reverse3(head,head->next);
    head->next=q;
  }
  else
  newnode=q;
}

void concat(struct node*head,struct node*q)
{
  third=head;
  while(head->next!=NULL)
  head=head->next;
  head->next=q;
}

void merge(struct node*head,struct node*q)
{
  struct node*last;
  if(head->data<q->data)
  {
    third=last=head;
    head=head->next;
    third->next=NULL;
  }
  else{
    third=last=q;
    q=q->next;
    third->next=NULL;
  }
  while(head && q)
  {
    if(head->data < q->data)
    {
    last->next=head;
    last=head;
    head=head->next;
    last->next=NULL;
    }
    else
    {
    last->next=q;
    last=q;
    q=q->next;
    last->next=NULL;
    }
  }
  if(head)
  {
    last->next=head;
  }
  if(q)
  {
    last->next=q;
  }
}

int main(void) 
{
  struct node*atemp;
  int A[]={1,2,3,4,5};
  int B[]={3,6,9,12,15};
  create(A,5);
  display(newnode);
  printf("\n");
  create2(B,5);
  display(second);
  printf("\n");
  rdisplay(newnode);
  printf("\n");
  printf("Length of the node :%d",count(newnode));
  printf("\n");
  printf("Recursive length of node:%d",rcount(newnode));
  printf("\n");
  printf("Sum of the node:%d",sum(newnode));
  printf("\n");
  printf("Recursive sum of the node:%d",rsum(newnode));
  printf("\n");
  printf("Max in the node:%d\n",max(newnode));
  printf("Recursive sum of the node:%d\n",rmax(newnode));
  atemp=lsearch(newnode,7);
  atemp=lsearch(newnode,8);
  if(atemp)
  printf("key is found in the node:%d\n",atemp->data);
  else
  printf("key not found\n");
  display(newnode);
  printf("\n");
  atemp=rsearch(newnode,4);
  if(atemp)
  printf("key is found in the node:%d\n",atemp->data);
  else
  printf("key not found\n");
  printf("\n");
  insert(newnode,2,10);
  display(newnode);
  sortedlist(newnode,9);
  printf("\n");
  display(newnode);
  delete(newnode,5);
  display(newnode);
  printf("\n");
  if(issorted(newnode))
  {
    printf("\nsorted\n");
  }
  else{
    printf("\nnot sorted\n");
  }
  removeduplicate(newnode);
  display(newnode);
  printf("\n");
  reverse3(NULL,newnode);
  display(newnode);
  printf("\n");
  concat(second,newnode);
  display(third);
  printf("\n");
  
  return 0;
}