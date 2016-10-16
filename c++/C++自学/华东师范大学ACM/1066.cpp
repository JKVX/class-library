#include<iostream>
#include<algorithm>
using namespace std;
void configuration(char c[],int,char ch[],int);
bool unguarded(int,char ch[],int);
int main() {
	int n;
	cin>>n;
	for(int i=0; i<n; i++) {
		string s;
		cin>>s;
		char c[8];
		int size;
		size=s.size();
		for(int j=0; j<size; j++) {
			c[j]=s[j];
		}
		sort(c,c+size);
		char ch[8];
		configuration(c,size,ch,0);
		cout<<endl;
	}
	return 0;
}
void configuration(char c[],int size,char ch[],int row) {
	if(row==size) {
		for(int i=0; i<size; i++)cout<<ch[i];
		cout<<endl;
	} else {
		for(int i=0; i<size; i++) {
			if(unguarded(c[i],ch,row)) {
				ch[row]=c[i];
				configuration(c,size,ch,row+1);
				ch[row]=0;
			}
		}
	}
}
bool unguarded(int a,char ch[],int row) {
	for(int j=0; j<row; j++)
		if(ch[j]==a)return false;
	return true;
}
