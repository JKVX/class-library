#include <iostream> 
#include <stdlib.h> 
#include <time.h> 
using namespace std; 
int main() 
{ 
		const int NUMBER=10;//����10������� 
		const int MAX=100;//����1����100�������
        srand((unsigned)time(NULL));
        int square[NUMBER];
        for(int i=0;i<10;i++)
		{ 
			int tmp=rand()%MAX+1;
			bool is_exit=false;
			square[i]=tmp;
			for(int j=0;j<i;j++)
			{
				if(square[j]==square[i])
				{
					is_exit=true;
					i--;
				}
			}
			if(is_exit==false)
			{
        		cout <<tmp<<endl; 
        	}
    	}
        return 0; 
}
