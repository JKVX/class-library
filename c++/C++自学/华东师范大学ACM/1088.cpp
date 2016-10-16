#include<iostream>
#include<cmath>
using namespace std;
int main() {
	int n;
	while(cin>>n) {
		int m;
		m=pow(10,n*log10(n)-int(n*log10(n)));
		cout<<m<<endl;
	}
	return 0;
}
