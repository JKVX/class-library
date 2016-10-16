#include<iostream>
#include<Windows.h>
#include<cmath>
#include<stack>
#include<time.h>
#include<conio.h>
using namespace std;
HANDLE hOut=GetStdHandle(STD_OUTPUT_HANDLE);
CONSOLE_CURSOR_INFO curInfo;
COORD pos;
template<int max_size>
class Board 
/*打印一个棋盘，根据构造函数可以控制棋盘大小，上下左右控制光标移动，space控制棋盘状态。*/{
	public:
		Board(int);//构造函数 。
		void print();//初始打印棋盘 。
		void initialize();//根据输入执行相应操作 。
		void get_board(bool geted_board[(max_size-1)/2][(max_size-1)/2]);
		void introduction();
	private:
		int board_size;
		bool square[(max_size-1)/2][(max_size-1)/2];//棋盘的状态。
		int cursor_row,cursor_col;//光标的地址。
		
};
//********************************
template<int max_size>
void Board<max_size>::get_board(bool geted_board[(max_size-1)/2][(max_size-1)/2]){
	for(int i=0;i<(board_size-1)/2;i++)
		for(int j=0;j<(board_size-1)/2;j++)
		geted_board[i][j]=square[i][j];
} 
template<int max_size>
Board<max_size>::Board(int size) {
	board_size=size*2+1;
	cursor_row=0;
	cursor_col=0;//光标初始
	for(int i=0; i<(board_size-1)/2; i++)
		for(int j=0; j<(board_size-1)/2; j++) {
			square[i][j]=0;//棋盘初始
		}
}
//*******************************
template<int max_size>
void Board<max_size>::print() {//打印棋盘并使光标在（0，0）位置
	system("CLS");
	cout<<' ';
	for(int i=0;i<board_size/2;i++)
	cout<<"  "<<i+1<<" ";
	cout<<endl; 
	for(int i=0; i<board_size; i++) {
		if(i%2==1)
		{
			if((i/2+1)<10)
			cout<<i/2+1<<' ';
			else cout<<i/2+1;
		}
		else cout<<"  ";
		for(int j=0; j<board_size; j++) {
			if(i%2==0) {
				if(i==0&&j==0)cout<<"╔";
				else if(i==0&&j==1)cout<<"┉";
				else if(i==0&&j==2)cout<<"╗";
				else if(i==2&&j==0)cout<<"╚";
				else if(i==2&&j==1)cout<<"┉";
				else if(i==2&&j==2)cout<<"╝";
				else if(i==0) {
					if(j==0)	cout<<"┏";
					else if(j==board_size-1)cout<<"┓";
					else if(j%2==0) cout<<"┳";
					else cout<<"━";
				} else if(i==board_size-1) {
					if(j==0)	cout<<"┗";
					else if(j==board_size-1)cout<<"┛";
					else if(j%2==0)cout<<"┻";
					else cout<<"━";
				} else {
					if(j==0)cout<<"┣";
					else if(j==board_size-1)cout<<"┫";
					else if(j%2==0)cout<<"╋";
					else cout<<"━";
				}
			} else {
				if(i==1&&j==0)cout<<"┋";
				else if(i==1&&j==2)cout<<"┋";
				else if(j==0)cout<<"┃";
				else if(j==board_size-1)cout<<"┃";
				else if(j%2==0)cout<<"┃";
				else cout<<"  ";
			}
		}
		cout<<endl;
	}
}
//********************************
template<int max_size>
void Board<max_size>::initialize() {
	char command='1';
	while(command!=13) {
		command=getch();
		if(command==-32) {
			command=getch();
			curInfo.dwSize=1;
			curInfo.bVisible=false;
			switch(command) {//移动光标。
				case 72:
					if(cursor_row==0)break;
					else {
						pos.X=cursor_col*4+2,pos.Y=(cursor_row)*2+1;
						SetConsoleCursorPosition(hOut,pos);
						if(cursor_col==0)cout<<"┣━╋";
						else if(cursor_col==(board_size-1)/2-1)cout<<"╋━┫";
						else cout<<"╋━╋" ;
						pos.Y=(cursor_row)*2+2;
						SetConsoleCursorPosition(hOut,pos);
						cout<<"┃";
						pos.X=cursor_col*4+6;
						SetConsoleCursorPosition(hOut,pos);
						cout<<"┃";
						pos.X=cursor_col*4+2,pos.Y=(cursor_row)*2+3;
						SetConsoleCursorPosition(hOut,pos);
						if(cursor_row==(board_size-1)/2-1) {
							if(cursor_col==0)cout<<"┗━┻";
							else if(cursor_col==(board_size-1)/2-1)cout<<"┻━┛";
							else cout<<"┻━┻" ;

						} else {
							if(cursor_col==0)cout<<"┣━╋";
							else if(cursor_col==(board_size-1)/2-1)cout<<"╋━┫";
							else cout<<"╋━╋" ;

						}
						pos.X=cursor_col*4+2,pos.Y=(cursor_row-1)*2+1;
						SetConsoleCursorPosition(hOut,pos);
						cout<<"╔┉╗";
						pos.Y=(cursor_row-1)*2+2;
						SetConsoleCursorPosition(hOut,pos);
						cout<<"┋";
						pos.X=cursor_col*4+6;
						SetConsoleCursorPosition(hOut,pos);
						cout<<"┋";
						pos.X=cursor_col*4+2,pos.Y=(cursor_row-1)*2+3;
						SetConsoleCursorPosition(hOut,pos);
						cout<<"╚┉╝";
						cursor_row--;
					}
					break;
				case 80:
					if(cursor_row==(board_size-1)/2-1)break;
					else {
						pos.X=cursor_col*4+2,pos.Y=(cursor_row)*2+1;
						SetConsoleCursorPosition(hOut,pos);
						if(cursor_row==0) {
							if(cursor_col==0)cout<<"┏━┳";
							else if(cursor_col==(board_size-1)/2-1)cout<<"┳━┓";
							else cout<<"┳━┳" ;

						} else {
							if(cursor_col==0)cout<<"┣━╋";
							else if(cursor_col==(board_size-1)/2-1)cout<<"╋━┫";
							else cout<<"╋━╋" ;

						}
						pos.Y=(cursor_row)*2+2;
						SetConsoleCursorPosition(hOut,pos);
						cout<<"┃";
						pos.X=cursor_col*4+6;
						SetConsoleCursorPosition(hOut,pos);
						cout<<"┃";
						pos.X=cursor_col*4+2,pos.Y=(cursor_row)*2+3;
						SetConsoleCursorPosition(hOut,pos);
						if(cursor_col==0)cout<<"┗━┻";
						else if(cursor_col==(board_size-1)/2-1)cout<<"┻━┛";
						else cout<<"┻━┻" ;
						pos.X=cursor_col*4+2,pos.Y=(cursor_row+1)*2+1;
						SetConsoleCursorPosition(hOut,pos);
						cout<<"╔┉╗";
						pos.Y=(cursor_row+1)*2+2;
						SetConsoleCursorPosition(hOut,pos);
						cout<<"┋";
						pos.X=cursor_col*4+6;
						SetConsoleCursorPosition(hOut,pos);
						cout<<"┋";
						pos.X=cursor_col*4+2,pos.Y=(cursor_row+1)*2+3;
						SetConsoleCursorPosition(hOut,pos);
						cout<<"╚┉╝";
						cursor_row++;
					}
					break;
				case 75:
					if(cursor_col==0)break;
					else {
						pos.X=cursor_col*4+2,pos.Y=(cursor_row)*2+1;
						SetConsoleCursorPosition(hOut,pos);
						if(cursor_col==(board_size-1)/2-1) {
							if(cursor_row==0)cout<<"┳━┓";
							else cout<<"╋━┫" ;
						} else {
							if(cursor_row==0)cout<<"┳━┳";
							else cout<<"╋━╋";
						}
						pos.Y=(cursor_row)*2+2;
						SetConsoleCursorPosition(hOut,pos);
						cout<<"┃";
						pos.X=cursor_col*4+6;
						SetConsoleCursorPosition(hOut,pos);
						cout<<"┃";
						pos.X=cursor_col*4+2,pos.Y=(cursor_row)*2+3;
						SetConsoleCursorPosition(hOut,pos);
						if(cursor_col==(board_size-1)/2-1) {
							if(cursor_row==0)cout<<"╋━┫";
							else if(cursor_row==(board_size-1)/2-1)cout<<"┻━┛";
							else cout<<"╋━┫" ;
						} else {
							if(cursor_row==0)cout<<"╋━╋";
							else if(cursor_row==(board_size-1)/2-1)cout<<"┻━┻";
							else cout<<"╋━╋" ;
						}
						pos.X=(cursor_col-1)*4+2,pos.Y=cursor_row*2+1;
						SetConsoleCursorPosition(hOut,pos);
						cout<<"╔┉╗";
						pos.Y=cursor_row*2+2;
						SetConsoleCursorPosition(hOut,pos);
						cout<<"┋";
						pos.X=(cursor_col-1)*4+2;
						SetConsoleCursorPosition(hOut,pos);
						cout<<"┋";
						pos.X=(cursor_col-1)*4+2,pos.Y=cursor_row*2+3;
						SetConsoleCursorPosition(hOut,pos);
						cout<<"╚┉╝";
						cursor_col--;
					}
					break;
				case 77:
					if(cursor_col==(board_size-1)/2-1)break;
					else {
						pos.X=cursor_col*4+2,pos.Y=(cursor_row)*2+1;
						SetConsoleCursorPosition(hOut,pos);
						if(cursor_col==0) {
							if(cursor_row==0)cout<<"┏━┳";
							else cout<<"┣━╋" ;
						} else {
							if(cursor_row==0)cout<<"┳━┳";
							else cout<<"╋━╋";
						}
						pos.Y=(cursor_row)*2+2;
						SetConsoleCursorPosition(hOut,pos);
						cout<<"┃";
						pos.X=cursor_col*4+6;
						SetConsoleCursorPosition(hOut,pos);
						cout<<"┃";
						pos.X=cursor_col*4+2,pos.Y=(cursor_row)*2+3;
						SetConsoleCursorPosition(hOut,pos);
						if(cursor_col==0) {
							if(cursor_row==0)cout<<"┣━╋";
							else if(cursor_row==(board_size-1)/2-1)cout<<"┗━┻";
							else cout<<"┣━╋" ;
						} else {
							if(cursor_row==0)cout<<"╋━╋";
							else if(cursor_row==(board_size-1)/2-1)cout<<"┻━┻";
							else cout<<"╋━╋" ;
						}
						pos.X=(cursor_col+1)*4+2,pos.Y=cursor_row*2+1;
						SetConsoleCursorPosition(hOut,pos);
						cout<<"╔┉╗";
						pos.Y=cursor_row*2+2;
						SetConsoleCursorPosition(hOut,pos);
						cout<<"┋";
						pos.X=(cursor_col+2)*4+2;
						SetConsoleCursorPosition(hOut,pos);
						cout<<"┋";
						pos.X=(cursor_col+1)*4+2,pos.Y=cursor_row*2+3;
						SetConsoleCursorPosition(hOut,pos);
						cout<<"╚┉╝";
						cursor_col++;
					}
					break;
			}
		} else {
			if(command==' ') {//改变该位置的状态。
				pos.X=cursor_col*4+4,pos.Y=cursor_row*2+2;
				SetConsoleCursorPosition(hOut,pos);
				if(square[cursor_row][cursor_col]==0) {
					cout<<"●";
					square[cursor_row][cursor_col]=1;
				} else {
					cout<<"○";
					square[cursor_row][cursor_col]=0;
				}
			}
		}
	}
}

