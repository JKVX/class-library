#include<iostream>
#include<string>
using namespace std;
int main()
{
	int l;
	string s;
	cin>>l;
	while(cin>>l>>s) 
	{	 
    	int i=0,j=1,k=0,t;
    	while (i<l&&j<l&&k<l)
    	{
        	t=s[(i+k)%l]-s[(j+k)%l];
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
     cout<<min(i,j)<<endl;
 	}
	return 0;
} 
