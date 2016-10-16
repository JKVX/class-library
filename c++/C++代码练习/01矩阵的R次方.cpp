#include<iostream>
using namespace std;
void fun(int a[][5],int b[][5]) {
	int c[5][5];
	for(int i=0; i<5; i++) {
		for(int j=0; j<5; j++) {
			c[i][j]=0;
		}
	}
	for(int i=0; i<5; i++) {
		for(int j=0; j<5; j++) {
			for(int k=0; k<5; k++) {
				if(a[i][k]*b[k][j]==1) {
					c[i][j]=1;
					break;
				}
			}
		}
	}
	for(int i=0; i<5; i++) {
		for(int j=0; j<5; j++) {
			b[i][j]=c[i][j];
		}
	}
}
int main() {
	int arr[5][5];
	cout<<"R = "<<endl;
	 
	for(int i=0; i<5; i++) {
		for(int j=0; j<5; j++)
			cin>>arr[i][j];
	}
	int num;
	cout<<"输入想算的R的n次方:";
	cin>>num;
	while(num>0) {
		int b[5][5];
		for(int i=0; i<5; i++) {
			for(int j=0; j<5; j++)
				b[i][j]=arr[i][j];
		}
		for(int j=1; j<num; j++) {
			fun(arr,b);
		}
		for(int i=0; i<5; i++) {
			if(i==2)cout<<"R^"<<num<<" = ";
			else cout<<"      ";
			for(int j=0; j<5; j++)
				cout<<b[i][j]<<' ';
			cout<<endl;
		}
		cout<<"输入想算的R的n次方:";
		cin>>num;
	}
	return 0;
}

