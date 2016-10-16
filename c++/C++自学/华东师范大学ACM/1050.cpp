#include<iostream>
#include<string>
using namespace std;
void Exchange(string &s1,string &s2)
{
	int l1,l2;
	int i=0,j=0;
	l1=s1.length();
	l2=s2.length(); 
	while(s1[i]=='0')
	{
		i++;
		if(i==l1)
		break; 
	}
	if(i==l1)
	s1="0";
	else s1=s1.substr(i,l1-i);
	while(s2[j]=='0')
	{
		j++;
		if(j==l2)
		break;
	}
	if(j==l2)s2="0";
	else s2=s2.substr(j,l2-j);
	l1=s1.length();
	l2=s2.length(); 
	if(l1>l2)
	{
		string temp;
		temp=s2;
		s2=s1;
		s1=temp;
	}
	else if(l1==l2)
	{
		for(int i=0;i<l1;i++)
		{
			if(s1[i]<s2[i])break;
			else if(s1[i]>s2[i])
			{
				string temp;
				temp=s2;
				s2=s1;
				s1=temp;
				break;	
			}
		}
	}
	
}
int main()
{
	string s;
	while(cin>>s)
	{
		int i,l,j,count=0;//151
		string str[500];
		l=s.length();//l=3
		for(i=0;i<l;i++)
			if(s[i]!='5')
			{
				s=s.substr(i,l-i);
				l=s.length();
				break;
			}
		for(j=0;j<l;j++)
		{
			if(s[j]=='5')
			{
				str[count]=s.substr(0,j);
				count++;
				while(s[j]=='5')
				{
					j++;
				}
				s=s.substr(j,l-j);
				j=0;
				l=s.length();
			}
		}
		if(l!=0)
		{
			str[count]=s;
			count++;
		}
		if(count==0)
		{
			int k=0;
			while(s[k]=='0')
			{
				k++;
				if(k==l)
				break;
			}
			if(k==l)s="0";
			else s=s.substr(k,l);
			cout<<s<<endl;
		}
		else if(count==1)
		{
			int z=0,l;
			l=str[0].length();
			while(str[0][z]=='0')
			{
				z++;
				if(z==l)break;
			}
			if(z==l)str[0]="0";
			else str[0]=str[0].substr(z,l-z);
			cout<<str[0]<<endl;
		}
		else 
		{
			for(int i=0;i<count;i++)
				for(int j=0;j<count-i-1;j++)
				{
					Exchange(str[j],str[j+1]);
				}
			cout<<str[0];
			for(int k=1;k<count;k++)
				cout<<' '<<str[k];
			cout<<endl;
		}
		
	}
	return 0;
} 
