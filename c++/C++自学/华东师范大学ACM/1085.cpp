#include<iostream>
using namespace std;
int a[10];
bool fun(int n,int depth);
int main() {
	int n;
	a[0]=1;
	for(int i=1; i<10; i++) {
		a[i]=a[i-1]*(i+1);
	}
	cin>>n;
	while(n>=0) {
		if(n==0)cout<<"NO"<<endl;
		else {
			int i;
			for(i=9; i>=0; i--) {
				if(a[i]<=n)break;
			}
			if(fun(n,i))cout<<"YES"<<endl;
			else cout<<"NO"<<endl;
		}
		cin>>n;
	}
}
bool fun(int n,int depth) {
	if(depth==0)return true;
	else if(a[depth]==n)return true;
	else {
		n=n-a[depth];
		if(n>a[depth])return false;
		else {
			int i;
			for(i=depth-1; i>=0; i--) {
				if(a[i]<=n)break;
			}
			fun(n,i);
		}
	}
}
