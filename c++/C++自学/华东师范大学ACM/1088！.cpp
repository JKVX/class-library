#include<iostream>
using namespace std;
int mymin(int a, int b, int c,int d) {
	int temp = (a < b ? a : b);
	int temp2 = (temp < c ? temp : c);
	return (temp2 < d ? temp2 : d);
}
int main() {
	int ugly[5842];
	ugly[0] = 1;
	int index2 = 0;
	int index3 = 0;
	int index5 = 0;
	int index7 = 0;
	int index = 1;
	while (index < 5842) {
		int val = mymin(ugly[index2]*2, ugly[index3]*3, ugly[index5]*5,ugly[index7]*7);
		if (val == ugly[index2]*2)
			++index2;
		if (val == ugly[index3]*3)
			++index3;
		if (val == ugly[index5]*5)
			++index5;
		if (val == ugly[index7]*7)
			++index7;
		ugly[index++] = val;
	}
	int n;
	cin>>n;
	while(n!=0) {
		string s;
		int m,p;
		p=n-n/100*100;
		if(p==11||p==12||p==13)s="th";
		else {
			m=n-n/10*10;
			switch(m) {
				case 1:
					s="st";
					break;
				case 2:
					s="nd";
					break;
				case 3:
					s="rd";
					break;
				default:
					s="th";
					break;
			}
		}
		cout<<"The "<<n<<s<<" humble number is "<<ugly[n-1]<<"."<<endl;
		cin>>n;
	}
	return 0;
}
