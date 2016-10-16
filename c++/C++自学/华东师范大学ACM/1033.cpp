#include<iostream>
using namespace std;
int main()
{
	int a[4];
	int b[4];
	int c[4];
	char t;
	cin>>a[0]>>t>>a[1]>>t>>a[2]>>t>>a[3];
	cin>>b[0]>>t>>b[1]>>t>>b[2]>>t>>b[3];
	int m,n;
	cin>>m;
	for(n=0;n<m;n++)
	{
		cin>>c[0]>>t>>c[1]>>t>>c[2]>>t>>c[3];
		if(b[3]!=255)
		{
			if(b[2]!=255)
			{
				if(b[1]!=255)
				{
					if(b[0]!=255)
					{
						cout<<"INNER"<<endl;
					}
					else if(a[0]!=c[0])
						cout<<"OUTER"<<endl;
					else cout<<"INNER"<<endl;
				}
				else if(a[1]!=c[1])
					cout<<"OUTER"<<endl;
				else if(a[0]!=c[0])
					cout<<"OUTER"<<endl;
				else cout<<"INNER"<<endl;
			}
			else if(a[2]!=c[2])
				cout<<"OUTER"<<endl;
			else if(a[1]!=c[1])
				cout<<"OUTER"<<endl;
			else if(a[0]!=c[0])
				cout<<"OUTER"<<endl;
			else cout<<"INNER"<<endl;
		}
		else if(a[3]!=c[3])
			cout<<"OUTER"<<endl;
		else if(a[2]!=c[2])
			cout<<"OUTER"<<endl;
		else if(a[1]!=c[1])
			cout<<"OUTER"<<endl;
		else if(a[0]!=c[0])
			cout<<"OUTER"<<endl;
		else cout<<"INNER"<<endl;
	}
	return 0;
}
