#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		int m;
		cin>>m;
		int *p;
		p=new int[m];
		for(int j=0;j<m;j++)
		{
			cin>>p[j];
		}
		sort(p,p+m);
		int count=1;
		while(p[0]==p[count])
		{
			count++;
			if(count==m)
			break;
		} 
		if(count==m)cout<<"NO"<<endl;
		else cout<<p[count]<<endl; 
	}
	return 0;
} 
