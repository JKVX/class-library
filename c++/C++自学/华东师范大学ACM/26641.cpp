#include<iostream>
#include<stdio.h>
using namespace std;
int main()
{
	int n;
	while(cin>>n)
	{
		int *p;
		bool b=1;
		int count=0;
		p=new int[n];
		for(int i=0;i<n;i++)
		{
			scanf("%d",&p[i]);
		}
    	int i=0,j=1,k=0,t;
    	while (i<n&&j<n&&k<n)
    	{
        	t=p[(i+k)%n]-p[(j+k)%n];
         	if (t == 0)
            	 k++;
         	else
         	{
            	if (t > 0)
                	i += k + 1;
             	else
              	    j += k + 1;
             	if(i==j)
                j++;
            	k = 0;
         	}
     	}
     	t=min(i,j);
     	for(int x=0;x<n-1;x++)
     	{
     		if(p[(x+t)%n]>p[(x+t+1)%n])
     		{
     			b=0;
     			break;
			 }
		}
		delete p;
		t=(n-t)%n;
		if(b==1)
		{ 
     		cout<<t<<endl;
     	}
     	else 
		{
		 	cout<<-1<<endl;
		}
 	}
	return 0;
} 

