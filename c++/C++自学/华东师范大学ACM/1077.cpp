#include<iostream>
using namespace std;
int a[210000];  
void fun()  
{  
    int i,j;  
    int num;  
    num=1;  
    for(int i=3; i<=1000001; i++)  
    {  
        if(num==100000)  
        {  
            a[num]=i;  
            return ;  
        }  
        if(i%3==0||i%5==0)  
        {  
            a[num]=i;  
            num++;  
        }  
    }  
    return ;  
}  
int main()  
{  
    int n;  
    fun();  
    while(scanf("%d",&n)!=EOF)  
    {  
        printf("%d\n",a[n]);  
  
    }  
    return 0;  
}  
