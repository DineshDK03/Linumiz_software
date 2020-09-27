#include <stdio.h>
#include <stdlib.h>
#include"Doubly_LL.h"
#include<string.h>
#include"DLLmath.h"
struct Node *f1=NULL,*f2=NULL,*f3=NULL,*f4=NULL,*f5=NULL,*f6=NULL;



int main(int argc, char *argv[])
{


    int len1 = strlen(argv[1]);
    len1 = len1-1;
    for(int i=len1;i>=0;i--)
    {
        int val = argv[1][i]-48;
        f1=Inserthead(f1,val);
    }



    int len2 = strlen(argv[2])-1;
    for(int i=len2;i>=0;i--)
    {
        int val = argv[2][i]-48;
        f2=Inserthead(f2,val);
    }


    f3=add(f1,f2,f3);
    printf("\n ADDITION       : ");
    Display(f3);

    f4=sub(f1,f2,f4);
    if(signbit == 1)
    {
       printf("\n SUBTRACTION     : -");
       Display(f4);
    }
    else
    {
       printf("\n SUBTRACTION    : ");
       Display(f4);
    }

    f5=multiply(f1,f2,f5);
    printf("\n MULTIPLICATION : ");
    Display(f5);


    f6 = quo(f1,f2,f6);
    printf("\n QUO            : ");
    Display(f6);
    printf("\n REM            : ");
    Display(rem);
	
    clear(f1);
    clear(f2);
    clear(f3);
    clear(f4);
    clear(f5);
    clear(f6);
    printf("\n");
    return 0;
 }
