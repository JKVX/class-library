#include<iostream>
#include<Windows.h>
#include<cmath>
#include<stack>
#include<time.h>
enum Board_Condition {avaliable,starting_point,destination,obstacle,restrict,avaliable2,restrict2};
using namespace std;
const int board_size=9;
const int sleep_time=100;
HANDLE hOut=GetStdHandle(STD_OUTPUT_HANDLE);
CONSOLE_CURSOR_INFO curInfo;
COORD pos;
extern double now,start; 
class Board {
	public:
		Board();//构造函数 。
		void print_Board();//初始打印棋盘 。
		void initialize();//根据输入执行相应操作 。
		bool unguarded(int i);//判断棋子能不能往四个方向前进。
		int better_step();//优化算法。
		void go_forward(int);//棋子前进。
		void go_back(int);//棋子撤销。
		bool is_solved();//判断棋子有没有找到终点。
		void result();//输出结果。
	private:
		Board_Condition square[(board_size-1)/2][(board_size-1)/2];//棋盘的状态。
		int move_count_square[(board_size-1)/2][(board_size-1)/2];
		int cursor_row,cursor_col;//光标的地址。
		int destination_row,destination_col;//终点的地址。
		int move_row,move_col;//棋子的地址。
		int start_row,start_col;//起点地址。
		int count;//记录按了space的次数。
		int move_count;//棋子走的步数。
		int least_steps;//棋子走的最小步数。
		stack<int>solution;//棋子走的路径。
		stack<int>best_solution;//棋子走的最佳路径。
};
//********************************
Board::Board() {
	cursor_row=0;
	cursor_col=0;//光标初始
	least_steps=(board_size-1)/2*((board_size-1)/2+1)+board_size;//最小步数初始 
	destination_row=-1;
	destination_col=-1;//终点初始
	move_row=0;
	move_col=0;//棋子初始
	count=0;//space初始
	move_count=0;//棋子步数初始
	for(int i=0; i<(board_size-1)/2; i++)
		for(int j=0; j<(board_size-1)/2; j++) {
			square[i][j]=avaliable;//棋盘初始
			move_count_square[i][j]=100;
		}
}
//*******************************
void Board::print_Board() {//打印棋盘并使光标在（0，0）位置

	for(int i=0; i<board_size; i++) {
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
void Board::initialize() {
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
						pos.X=cursor_col*4,pos.Y=(cursor_row)*2;
						SetConsoleCursorPosition(hOut,pos);
						if(cursor_col==0)cout<<"┣━╋";
						else if(cursor_col==(board_size-1)/2-1)cout<<"╋━┫";
						else cout<<"╋━╋" ;
						pos.Y=(cursor_row)*2+1;
						SetConsoleCursorPosition(hOut,pos);
						cout<<"┃";
						pos.X=cursor_col*4+4;
						SetConsoleCursorPosition(hOut,pos);
						cout<<"┃";
						pos.X=cursor_col*4,pos.Y=(cursor_row)*2+2;
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
						pos.X=cursor_col*4,pos.Y=(cursor_row-1)*2;
						SetConsoleCursorPosition(hOut,pos);
						cout<<"╔┉╗";
						pos.Y=(cursor_row-1)*2+1;
						SetConsoleCursorPosition(hOut,pos);
						cout<<"┋";
						pos.X=cursor_col*4+4;
						SetConsoleCursorPosition(hOut,pos);
						cout<<"┋";
						pos.X=cursor_col*4,pos.Y=(cursor_row-1)*2+2;
						SetConsoleCursorPosition(hOut,pos);
						cout<<"╚┉╝";
						cursor_row--;
					}
					break;
				case 80:
					if(cursor_row==(board_size-1)/2-1)break;
					else {
						pos.X=cursor_col*4,pos.Y=(cursor_row)*2;
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
						pos.Y=(cursor_row)*2+1;
						SetConsoleCursorPosition(hOut,pos);
						cout<<"┃";
						pos.X=cursor_col*4+4;
						SetConsoleCursorPosition(hOut,pos);
						cout<<"┃";
						pos.X=cursor_col*4,pos.Y=(cursor_row)*2+2;
						SetConsoleCursorPosition(hOut,pos);
						if(cursor_col==0)cout<<"┗━┻";
						else if(cursor_col==(board_size-1)/2-1)cout<<"┻━┛";
						else cout<<"┻━┻" ;
						pos.X=cursor_col*4,pos.Y=(cursor_row+1)*2;
						SetConsoleCursorPosition(hOut,pos);
						cout<<"╔┉╗";
						pos.Y=(cursor_row+1)*2+1;
						SetConsoleCursorPosition(hOut,pos);
						cout<<"┋";
						pos.X=cursor_col*4+4;
						SetConsoleCursorPosition(hOut,pos);
						cout<<"┋";
						pos.X=cursor_col*4,pos.Y=(cursor_row+1)*2+2;
						SetConsoleCursorPosition(hOut,pos);
						cout<<"╚┉╝";
						cursor_row++;
					}
					break;
				case 75:
					if(cursor_col==0)break;
					else {
						pos.X=cursor_col*4,pos.Y=(cursor_row)*2;
						SetConsoleCursorPosition(hOut,pos);
						if(cursor_col==(board_size-1)/2-1) {
							if(cursor_row==0)cout<<"┳━┓";
							else if(cursor_row==(board_size-1)/2-1)cout<<"╋━┫";
							else cout<<"╋━┫" ;
						} else {
							if(cursor_row==0)cout<<"┳━┓";

							else cout<<"╋━╋";
						}
						pos.Y=(cursor_row)*2+1;
						SetConsoleCursorPosition(hOut,pos);
						cout<<"┃";
						pos.X=cursor_col*4+4;
						SetConsoleCursorPosition(hOut,pos);
						cout<<"┃";
						pos.X=cursor_col*4,pos.Y=(cursor_row)*2+2;
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
						pos.X=(cursor_col-1)*4,pos.Y=cursor_row*2;
						SetConsoleCursorPosition(hOut,pos);
						cout<<"╔┉╗";
						pos.Y=cursor_row*2+1;
						SetConsoleCursorPosition(hOut,pos);
						cout<<"┋";
						pos.X=(cursor_col-1)*4;
						SetConsoleCursorPosition(hOut,pos);
						cout<<"┋";
						pos.X=(cursor_col-1)*4,pos.Y=cursor_row*2+2;
						SetConsoleCursorPosition(hOut,pos);
						cout<<"╚┉╝";
						cursor_col--;
					}
					break;
				case 77:
					if(cursor_col==(board_size-1)/2-1)break;
					else {
						pos.X=cursor_col*4,pos.Y=(cursor_row)*2;
						SetConsoleCursorPosition(hOut,pos);
						if(cursor_col==0) {
							if(cursor_row==0)cout<<"┏━┳";
							else cout<<"┣━╋" ;
						} else {
							if(cursor_row==0)cout<<"┳━┳";
							else cout<<"╋━╋";
						}
						pos.Y=(cursor_row)*2+1;
						SetConsoleCursorPosition(hOut,pos);
						cout<<"┃";
						pos.X=cursor_col*4+4;
						SetConsoleCursorPosition(hOut,pos);
						cout<<"┃";
						pos.X=cursor_col*4,pos.Y=(cursor_row)*2+2;
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
						pos.X=(cursor_col+1)*4,pos.Y=cursor_row*2;
						SetConsoleCursorPosition(hOut,pos);
						cout<<"╔┉╗";
						pos.Y=cursor_row*2+1;
						SetConsoleCursorPosition(hOut,pos);
						cout<<"┋";
						pos.X=(cursor_col+2)*4;
						SetConsoleCursorPosition(hOut,pos);
						cout<<"┋";
						pos.X=(cursor_col+1)*4,pos.Y=cursor_row*2+2;
						SetConsoleCursorPosition(hOut,pos);
						cout<<"╚┉╝";
						cursor_col++;
					}
					break;
			}
		} else {
			if(command==' ') {//改变该位置的状态。
				pos.X=cursor_col*4+2,pos.Y=cursor_row*2+1;
				SetConsoleCursorPosition(hOut,pos);
				if(square[cursor_row][cursor_col]==avaliable) {
					if(count==0) {
						cout<<"●";
						square[cursor_row][cursor_col]=starting_point;

						//square2[cursor_row][cursor_col]=starting_point;
						move_row=cursor_row;
						move_col=cursor_col;
						start_row=cursor_row;
						start_col=cursor_col;
					} else if(count==1) {
						cout<<"★";
						square[cursor_row][cursor_col]=destination;
						//square2[cursor_row][cursor_col]=destination;
						destination_row=cursor_row;
						destination_col=cursor_col;
					} else {
						cout<<"■" ;
						square[cursor_row][cursor_col]=obstacle;
						//square2[cursor_row][cursor_col]=obstacle;
					}
					count++;
				} else if(square[cursor_row][cursor_col]==obstacle) {
					cout<<"  ";
					square[cursor_row][cursor_col]=avaliable;
					//square2[cursor_row][cursor_col]=avaliable;
				}
			} else if(command==13) {
				if(count==0||count==1)command='1';
				else {
					curInfo.dwSize=1;
					curInfo.bVisible=false;
					pos.X=0,pos.Y=board_size;
					SetConsoleCursorPosition(hOut,pos);
					cout<<"我在找哦。。。";
				}
			}
		}
	}
}
//*********************************
bool Board::unguarded(int i) {
	switch(i) {
		case 1:
			if(move_row==0)return false;
			else if(square[move_row-1][move_col]==restrict||
			        square[move_row-1][move_col]==obstacle)return false;
			else if(move_count_square[move_row-1][move_col]<move_count)return false;
			else return true;
			break;
		case 2:
			if(move_row==(board_size-1)/2-1)return false;
			else if(square[move_row+1][move_col]==restrict
			        ||square[move_row+1][move_col]==obstacle)return false;
			else if(move_count_square[move_row+1][move_col]<move_count)return false;
			else return true;
			break;
		case 3:
			if(move_col==0)return false;
			else if(square[move_row][move_col-1]==restrict
			        ||square[move_row][move_col-1]==obstacle)return false;
			else if(move_count_square[move_row][move_col-1]<move_count)return false;
			else return true;
			break;
		case 4:
			if(move_col==(board_size-1)/2-1)return false;
			else if(square[move_row][move_col+1]==restrict
			        ||square[move_row][move_col+1]==obstacle)return false;
			else if(move_count_square[move_row][move_col+1]<move_count)return false;
			else return true;
			break;
	}
}
//********************************
int Board::better_step() {
	int best_way;
	if(move_row<destination_row)best_way=2;
	else if(move_row>destination_row)best_way=1;
	else if(move_col<destination_col)best_way=4;
	else best_way=3;
	if(!unguarded(best_way)) {
		switch(best_way) {
			case 1:
			case 2:
				if(move_col<destination_col)best_way=4;
				else best_way=3;
				break;
			case 3:
			case 4:
				if(move_col<destination_col)best_way=2;
				else best_way=1;
				break;
		}
	}
	return best_way;
}
//*********************************
void Board::go_forward(int i) {
	square[move_row][move_col]=restrict;
	switch(i) {
		case 1:
			move_row--;
			break;
		case 2:
			move_row++;
			break;
		case 3:
			move_col--;
			break;
		case 4:
			move_col++;
			break;
	}
	solution.push(i);
	move_count++;
	if(move_count_square[move_row][move_col]>move_count)
	move_count_square[move_row][move_col]=move_count;
}
//***********************************
void Board::go_back(int i) {
	switch(i) {
		case 1:
			move_row++;
			break;
		case 2:
			move_row--;
			break;
		case 3:
			move_col++;
			break;
		case 4:
			move_col--;
			break;
	}
	square[move_row][move_col]=avaliable;
	solution.pop();
	move_count--;
}
//*********************************
bool Board::is_solved() {
	if(move_count>=least_steps)
		return true;//如果步数达到最优走法却没有找到终点直接放弃该路线。
	if(square[move_row][move_col]==destination) {
		if(move_count<least_steps) {
			least_steps=move_count;
			best_solution=solution;
		}
		return true;//找到终点！与最优走法对比。比最优走法好替换最优走法。 
	}
	return false;
}
//********************************
void Board::result() {
	stack <int>copy_stack; 
	int copy;
	while(!best_solution.empty()) {
		copy=best_solution.top();
		copy_stack.push(copy);
		best_solution.pop();
	}//best_solution中的操作反转。 
	best_solution=copy_stack;
	while(!best_solution.empty()) {
		Sleep(sleep_time);
		pos.X=start_col*4+2,pos.Y=start_row*2+1;
		SetConsoleCursorPosition(hOut,pos);
		copy=best_solution.top();
		switch(copy) {
			case 1:
				start_row--;
				cout<<"↑";
				break;
			case 2:
				start_row++;
				cout<<"↓";
				break;
			case 3:
				start_col--;
				cout<<"←";
				break;
			case 4:
				start_col++;
				cout<<"→";
				break;
		}
		pos.X=start_col*4+2,pos.Y=start_row*2+1;
		SetConsoleCursorPosition(hOut,pos);
		cout<<"●";
		best_solution.pop();
	}//根据stack中的操作输出路径。 
	pos.X=0,pos.Y=board_size;
	SetConsoleCursorPosition(hOut,pos);
	if(least_steps==((board_size-1)/2*((board_size-1)/2+1)+board_size))
	cout<<"笨蛋找不到终点了::>_<::"<<endl;
	else cout<<"笨蛋花了"<<(now-start)/CLOCKS_PER_SEC+0.0001 
	<<" s ，走了 "<<least_steps<<" 步,终于找到终点了@_@"<<endl;
}

