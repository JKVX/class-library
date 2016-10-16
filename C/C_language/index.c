#include <string.h>
#include <stdio.h>


//********** Specification of FactorialZeros **********
char*  CharsReplace(char *p)
/* PreCondition:
     p points to a string, with length no more than 50
   PostCondition:
     every character is replaced with its next character (¡Z¡¯ with ¡A¡¯),
     and return p
*/
{ //TODO: your function definitionint ;
char *a[51];
int i=0;
while(*p)
{if(*p=='Z')
    *p='A';
    else
        *p=*p+'B'-'A';
        *(a+i)=*p;
         p++;
         i++;}
  return a;

}

/***************************************************************/

void solve()
{  char s[51];  scanf("%s",s);
//********** CharsReplace is called here **********
   CharsReplace(s);
   printf("%s\n",s);
//*************************************************
}

int main()
{  int i,t; scanf("%d",&t);
   for (i=0;i<t;i++) {
                printf("case #%d:\n",i);
   solve(); }
   return 0;
}
