


#ifndef DLLMATH_H_INCLUDED
#define DLLMATH_H_INCLUDED
#include <stdio.h>

struct Node* add(struct Node *p1,struct Node *p2,struct Node *p3);
void complement9s(struct Node *p);
void  accumulate (struct Node *p ,int v, int c);
void  final ( struct Node *p);
struct Node* copy(struct Node *p1, struct Node *p2);
int compare(struct Node *p1, struct Node *p2);
struct Node* removeLeadingZeros(struct Node* a) ;
struct Node *rem = NULL;


int carry=0;
int signbit=0;

struct Node*  multiply( struct Node *p1, struct Node *p2, struct Node *p3)
{


    struct Node *q1 = NULL;
    struct Node *q2 = NULL;
    q1 = copy(q1,p1);
    q2 = copy(q2,p2);
    int l1 = Length(q1);
    int l2 = Length(q2);
    p3 = createEmpty(l1+l2-1);
    struct Node *t1 = NULL;
    t1 = q1;

    int res =0;
    int i, j =0;
    while (q2 != NULL)
    {
          i=0;
          q1=t1;
          while(q1 != NULL)
          {
              res = q2->data * q1->data;
              accumulate(p3,res,i+j);
              q1=q1->next;
              i=i+1;

          }
          j=j+1;
          q2 = q2->next;
    }

    final(p3);
    struct Node *t=NULL;
    while(p3->next!=NULL)
    {
       p3=p3->next;
    }
    while(p3!=NULL)
    {
       int temp=0;
       if(p3->data>9)
       {
          temp=p3->data;
          t=Inserthead(t,temp%10);
          t=Inserthead(t,temp/10);
       }
       else
       {
          temp=p3->data;
          t=Inserthead(t,temp);
       }
       p3=p3->prev;
    }
    clear(q1);
    clear(q2);
    clear(p3);
    return t;
}


void  accumulate (struct Node *p ,int v, int c)
{
    for( int i=0; i<c; i++)
    {
          p=p->next;
    }

    p->data = p->data + v;

}


void  final ( struct Node *p)
{
     while(p->next!= NULL)
     {
         p=p->next;
     }
     while(p->prev != NULL)
     {
        int  temp = 0;
        temp = p->data/10;
        p->data = p->data % 10;
        p=p->prev;
        p->data = p->data +temp;
     }


}


struct Node* add(struct Node *p1,struct Node *p2,struct Node *p3)
{
     struct Node *q1 = NULL;
     struct Node *q2 = NULL;
     q1 = copy(q1,p1);
     q2 = copy(q2,p2);
     int sum = 0;
     carry=0;
     int len1 = Length(q1);
     int len2 = Length(q2);

     if(len1>len2)
     {
        int n = len1-len2;
        for(int i=0; i<n; i++)
        {
            q2=Inserthead(q2,0);
        }
      }
      else if(len2>len1)
      {
        int n = len2-len1;
        for(int i=0; i<n; i++)
        {
            q1=Inserthead(q1,0);
        }
      }



     while(q1->next!=NULL)
     {
        q1=q1->next;
     }
     while(q2->next!=NULL)
     {
        q2=q2->next;
     }

     while (q1!=NULL && q2!=NULL)
     {
         sum = q1->data + q2->data + carry;
         carry = sum / 10;
         sum=sum%10;
         p3=Inserthead(p3,sum);
         q1=q1->prev;
         q2=q2->prev;
     }
     if(carry>0)
     {
         p3=Inserthead(p3,carry);
     }
     clear(q1);
     clear(q2);
     return p3;
}


struct Node* sub(struct Node *p1,struct Node *p2,struct Node *p3)
{
    struct Node *temp=NULL,*rf=NULL;
    struct Node *q1=NULL;
    struct Node *q2=NULL;
    q1 = copy(q1,p1);
    q2 = copy(q2,p2);

    int len1 = Length(q1);
    int len2 = Length(q2);



      if(len1>len2)
     {
        int n = len1-len2;
        for(int i=0; i<n; i++)
        {
            q2=Inserthead(q2,0);
        }
      }
      else if(len2>len1)
      {
        int n = len2-len1;
        for(int i=0; i<n; i++)
        {
            q1=Inserthead(q1,0);
        }
      }


    complement9s(q2);
    p3=add(q1,q2,p3);
    if(carry==1)
    {
       p3=Delete(p3,1);
       int length = Length(p3);
       temp=Inserthead(temp,carry);
       p3=add(p3,temp,rf);
    }
    else
    {
        signbit =1;
        complement9s(p3);
    }
    int i = 1;
    p3 = removeLeadingZeros(p3);
    clear(q1);
    clear(q2);
    return p3;
}


struct Node* quo(struct Node *p1,struct Node *p2,struct Node *p3)
{

    struct Node *nu=NULL;
    struct Node *de=NULL;
    struct Node *mul=NULL;
    struct Node *mul_res=NULL;
    struct Node *nu_min =NULL;
    struct Node *quo = NULL;
    struct Node *t1 = NULL;
    struct Node *t2 = NULL;
    struct Node *empty = NULL;


    quo = createEmpty(0);


    nu = copy(nu,p1);
    de = copy(de,p2);


    while(1)
    {
    int len1 = Length(nu);
    int len2 = Length(de);
    int diff = len1-len2;

    int s = compare(nu,p2);

    if(diff>=0)
    {
    mul = createEmpty(diff);

    }

    if(s==-1)
    {

       rem = copy(rem,nu);
       return quo;
    }

    if(s==0)
    {


       return quo;
    }

    int j=1;
    while(1)
    {

       mul->data = j;


       mul_res = multiply(de,mul,empty);
       clear(empty);
       empty = NULL;



       int c = compare(nu,mul_res);

       if(c == -1)
       {
          break;
       }
       else if(c == 0)
       {
          t1 = NULL;
          t2 = NULL;
          t1 = copy(t1,mul);
          t2 = copy(t2,mul_res);
          break;
       }
       t1 = NULL;
       t2 = NULL;
       t1 = copy(t1,mul);
       t2 = copy(t2,mul_res);
       clear(mul_res);
       mul_res=NULL;
       j++;
     }



    quo = add(t1,quo,empty);
     clear(empty);
     empty = NULL;

     nu = sub(nu,t2,empty);
     clear(empty);
     empty = NULL;

     clear(t1);
     clear(t2);

}


   return quo;

}

void complement9s(struct Node *p)
{
  while(p!= NULL)
  {
    p->data = 9 - p->data;
    p=p->next;
  }
}


struct Node* copy(struct Node *p1, struct Node *p2)
{
   int temp = 0;

   while(p2->next != NULL)
   {
      p2=p2->next;
   }

   while(p2->prev != NULL)
   {
     temp = p2->data;
     p1 =  Inserthead(p1,temp);
     p2=p2->prev;
   }

   temp = p2->data;
   p1 =  Inserthead(p1,temp);
   p2=NULL;
   return p1;
}

struct Node* removeLeadingZeros(struct Node* a)
{
    if (a != NULL && a->data == 0)
        return removeLeadingZeros(a->next);
    else
        return a;
}

int compare(struct Node *q1, struct Node *q2)
{
    q1=removeLeadingZeros(q1);
    q2=removeLeadingZeros(q2);
    if(q2 == NULL)
    {
       return -1;
    }


    int len1 = Length(q1);
    int len2 = Length(q2);

     if(len1>len2)
     {
       return 1;
     }
     else if(len2>len1)
     {
       return -1;
     }
     else if(len2 == len1)
     {
       while(q1->next!= NULL)
       {
           if(q1->data > q2->data)
           {
             while(q1->prev != NULL)
             {
                 q1=q1->prev;
                 q2=q2->prev;
             }
             return 1;

           }
           else if(q2->data > q1->data)
           {
             while(q1->prev != NULL)
             {
                 q1=q1->prev;
                 q2=q2->prev;
             }
             return -1;
           }
           q1=q1->next;
           q2=q2->next;
        }
      if(q1->data>q2->data)
      {
         return 1;
      }
      else if(q1->data<q2->data)
      {
         return -1;
      }
      while(q1->prev != NULL)
             {
                 q1=q1->prev;
                 q2=q2->prev;
             }

      return 0;


  }
}




#endif // DLLMATH_H_INCLUDED


