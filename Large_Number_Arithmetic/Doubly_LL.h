
#ifndef DOUBLY_LL_H_INCLUDED
#define DOUBLY_LL_H_INCLUDED

struct Node
{
   struct Node *prev;
   int data;
   struct Node *next;
}*first=NULL;

struct Node * create(int A[],int n)
{
   struct Node *t,*last,*first1;
   int i;
   first1=(struct Node *)malloc(sizeof(struct Node));
   first1->data=A[0];
   first1->prev=first1->next=NULL;
   last=first1;
  for(i=2;i<n;i++)
  {
     t=(struct Node *)malloc(sizeof(struct Node));
     t->data=A[i];
     t->next=last->next;
     t->prev=last;
     last->next=t;
     last=t;
 }
return first1;
}

struct Node * createEmpty(int n)
{
   struct Node *t,*last,*first1;
   int i;
   first1=(struct Node *)malloc(sizeof(struct Node));
   first1->data=0;
   first1->prev=first1->next=NULL;
   last=first1;
  for(i=1;i<n;i++)
  {
     t=(struct Node *)malloc(sizeof(struct Node));
     t->data=0;
     t->next=last->next;
     t->prev=last;
     last->next=t;
     last=t;
  }
return first1;
}

void Display(struct Node *p)
{
     while (p!=NULL)
     {
         printf("%d",p->data);
         p=p->next;
     }
}

int Length(struct Node *p)
 {
     int len = 0;
     while (p!=NULL)
     {
         len = len+1;
         p=p->next;
     }
     p=NULL;
     return len;
 }

void Insert (struct Node *p,int pos,int x)
 {
   struct Node *t;
   int i;
   if (pos<0 || pos > Length(p))
     return;

   if(pos == 0)
   {
       t = (struct Node *)malloc(sizeof(struct Node));
       t->data = x;
       t->prev = NULL;
       t->next = first;
       first->prev = t;
       first = t;
   }
   else
   {
       t = (struct Node *)malloc(sizeof(struct Node));
       t->data = x;
       for(i=0;i<pos-1;i++)
          p=p->next;

       t->next = p->next;
       t->prev = p;
       if(p->next)
         p->next->prev = t;

       p->next=t;

   }

 }

struct Node* Inserthead(struct Node *p,int x)
{
    struct Node *t;
    if(p==NULL)
    {
        p=(struct Node *)malloc(sizeof(struct Node));
        p->data=x;
        p->prev=p->next=NULL;
    }
    else
    {
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = x;
        t->prev = NULL;
        t->next = p;
        p->prev = t;
        p = t;

    }
    return p;
}

struct Node* Delete(struct Node *p,int pos)
 {
     int i;
     struct Node *q=NULL;
     if (pos<0||pos>Length(p))
       return NULL;

     if (pos == 1)
      {
         q=p;
         p=p->next;
         free(q);
         p->prev=NULL;
     }
     else
     {
        for(i=0;i<pos-1;i++)
          p=p->next;

        p->prev->next=p->next;
        if(p->next)
        p->next->prev=p->prev;

     }
     return p;
 }

void Reverse(struct Node *p)
 {
   struct Node *temp;
   while(p!=NULL)
  {
     temp=p->next;
     p->next=p->prev;
     p->prev=temp;
     p=p->prev;
     if(p!=NULL && p->next==NULL)
     first=p;

  }
}

void clear(struct Node *p)
{
   struct Node *q=NULL;
   while(p!=NULL)
   {
      q=p;
      p=p->next;
      free(q);
   }
}


#endif // DOUBLY_LL_H_INCLUDED


