#include<iostream>
#include<cmath>
using namespace std;
int main() {
	int a,b;
	while(cin>>a>>b) {
		int c=b-a;
		int d;
		if(c==0)cout<<0<<endl;
		else {
			d=sqrt(c);
			if(c-d*d==0)cout<<2*d-1<<endl;
			else if((c-d*d)>d)cout<<2*d+1<<endl;
			else cout<<2*d<<endl;
		}
	}
}
