#include<iostream>
#include<Windows.h>
#include<stack>
#include<time.h>
#include<cmath>
enum Board_Condition {avaliable,starting_point,destination,obstacle,restrict};
//avaliable可改变的或可走的；starting_point起点；destination终点
// obstacle障碍物；restrict被限制区域
using namespace std;
const int board_size=21;//棋盘变长*2+1，需要小于等于37
const int sleep_time=100;//打印的时间间隔
HANDLE hOut=GetStdHandle(STD_OUTPUT_HANDLE);
CONSOLE_CURSOR_INFO curInfo;
COORD pos;
extern double now,start; //引用main.cpp中的nowstart变量
extern int game_count;
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
		int least_steps;//棋子走的最小步数。
		int move_count;//棋子走的步数。
		void clear();
	private:
		Board_Condition square[(board_size-1)/2][(board_size-1)/2];//棋盘的状态。
		int move_count_square[(board_size-1)/2][(board_size-1)/2];
		//记录棋盘某个位置棋子经过的次数
		int cursor_row,cursor_col;//光标的地址。
		int destination_row,destination_col;//终点的地址。
		int move_row,move_col;//棋子的地址。
		int start_row,start_col;//起点地址。
		int count;//记录按了space的次数。
		stack<int>solution;//棋子走的路径。
		stack<int>best_solution;//棋子走的最佳路径。
};
void Board::clear() {
	move_row=start_row;
	move_col=start_col;//棋子的位置初始
	move_count=0;
	square[destination_row][destination_col]=destination;
	for(int i=0; i<(board_size-1)/2; i++)
		for(int j=0; j<(board_size-1)/2; j++) {
			move_count_square[i][j]=(board_size-1)/2*(board_size-1)/2;
			if(square[i][j]!=obstacle&&square[i][j]!=starting_point
			        &&square[i][j]!=destination) square[i][j]==avaliable;
		}
	while(!solution.empty()) {
		solution.pop();
	}
}
//********************************
Board::Board() { //构造函数
	cursor_row=0;
	cursor_col=0;//光标初始
	//least_steps=(board_size-1)/2*((board_size-1)/2+1)+board_size;//最小步数初始
	destination_row=-1;
	destination_col=-1;//终点初始
	move_row=0;
	move_col=0;//棋子的位置初始
	count=0;//space初始
	move_count=0;//棋子步数初始
	for(int i=0; i<(board_size-1)/2; i++)
		for(int j=0; j<(board_size-1)/2; j++) {
			square[i][j]=avaliable;//棋盘初始
			move_count_square[i][j]=0;//棋盘某位置棋子经过次数初始
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
				else if(i==2&&j==2)cout<<"╝";//打印光标位置
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
					else cout<<"━";//打印网格
				}
			} else {
				if(i==1&&j==0)cout<<"┋";
				else if(i==1&&j==2)cout<<"┋";//打印光标位置
				else if(j==0)cout<<"┃";
				else if(j==board_size-1)cout<<"┃";
				else if(j%2==0)cout<<"┃";
				else cout<<"  ";//打印网格
			}
		}
		cout<<endl;
	}
}
//********************************
void Board::initialize() {
	char command='1';//初始化命令
	while(command!=13) {//命令为13表示输入的为Enter键
		command=getch();//输入命令不为Enter时继续输入
		if(command==-32) {//命令为-32对应ascII表示输入的为↑↓←→
			command=getch();//再次获取得到确切的方向
			switch(command) {
				case 72://方向向上
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
				case 80://方向向下
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
				case 75://方向向左
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
				case 77://方向向右
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
			if(command==' ') {//space键改变该位置的状态。
				pos.X=cursor_col*4+2,pos.Y=cursor_row*2+1;
				SetConsoleCursorPosition(hOut,pos);
				if(square[cursor_row][cursor_col]==avaliable) {//该位置为可改变状态
					if(count==0) {//第一次输入，输入起点
						cout<<"●";
						square[cursor_row][cursor_col]=starting_point;
						//该位置标记为起点
						move_row=cursor_row;
						move_col=cursor_col;//记录棋子位置
						start_row=cursor_row;
						start_col=cursor_col;//记录起点位置
					} else if(count==1) {//第二次输入，输入终点
						cout<<"★";
						square[cursor_row][cursor_col]=destination;
						//该位置标记为终点
						destination_row=cursor_row;
						destination_col=cursor_col;//记录终点位置
					} else {
						cout<<"■" ;
						square[cursor_row][cursor_col]=obstacle;
						//该位置标记为障碍物
					}
					count++;
				} else if(square[cursor_row][cursor_col]==obstacle) {
					cout<<"  ";
					square[cursor_row][cursor_col]=avaliable;
					//如果该位置为障碍物，再次space取消障碍物，重新变为可改变状态
				}
			} else if(command==13) {//如果输入的为Enter键，自动寻路开始
				if(count==0||count==1)command='1';//如果起点终点未确定，Enter键无效
				else {
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
			if(move_row==0)return false;//棋子位于第一行，向上走无效
			else if(square[move_row-1][move_col]==restrict||
			        square[move_row-1][move_col]==obstacle)return false;
			//向上走为障碍物或者被限制区域 ，向上走无效
			else if(game_count==0) {
				if(move_count_square[move_row-1][move_col]!=0)return false;
				//向上走的区域为已经过的区域，向上走无效
			} else if(move_count_square[move_row-1][move_col]<move_count)return false;
			return true;
		case 2:
			if(move_row==(board_size-1)/2-1)return false;//棋子位于最后一行，向下走无效
			else if(square[move_row+1][move_col]==restrict
			        ||square[move_row+1][move_col]==obstacle)return false;
			//向下走为障碍物或者被限制区域 ，向下走无效
			else if(game_count==0) {
				if(move_count_square[move_row+1][move_col]!=0)return false;
				//向下走的区域为已经过的区域，向下走无效
			} else if(move_count_square[move_row+1][move_col]<move_count)return false;
			return true;
		case 3:
			if(move_col==0)return false;//棋子位于第一列，向左走无效
			else if(square[move_row][move_col-1]==restrict
			        ||square[move_row][move_col-1]==obstacle)return false;
			//向左走为障碍物或者被限制区域 ，向左走无效
			else if(game_count==0) {
				if(move_count_square[move_row][move_col-1]!=0)return false;
				//向左走的区域为已经过的区域，向左走无效
			} else if(move_count_square[move_row][move_col-1]<move_count)return false;
			return true;
		case 4:
			if(move_col==(board_size-1)/2-1)return false;//棋子位于最后一列，向右走无效
			else if(square[move_row][move_col+1]==restrict
			        ||square[move_row][move_col+1]==obstacle)return false;
			//向右走为障碍物或者被限制区域 ，向右走无效
			else if(game_count==0) {
				if(move_count_square[move_row][move_col+1]!=0)return false;
				//向右走的区域为已经过的区域，向右走无效
			} else if(move_count_square[move_row][move_col+1]<move_count)return false;
			return true;
	}
}
//********************************
int Board::better_step() {
	int best_way;
	if(move_row<destination_row)best_way=2;//如果终点在棋子下放，向下走
	else if(move_row>destination_row)best_way=1;//不然如果终点在棋子上放，向上走
	else if(move_col<destination_col)best_way=4;//不然如果棋子在终点左方，向右走
	else best_way=3;//不然向左走
	if(!unguarded(best_way)) {
		switch(best_way) {
			case 1:
			case 2:
				//如果向上向下走为无效走法，根据棋子在终点左方或右方，来决定向右或向左走
				if(move_col<destination_col)best_way=4;
				else best_way=3;
				break;
			case 3:
			case 4:
				//如果向左向右走为无效走法，根据棋子在终点上方或下方，来决定向下或向上走
				if(move_col<destination_col)best_way=2;
				else best_way=1;
				break;
		}
	}
	return best_way;
}
//*********************************
void Board::go_forward(int i) {
	square[move_row][move_col]=restrict;//前进之前的位置设为限制区域防止棋子回走
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
	if(game_count==0) {
		move_count++;//步数加一
		move_count_square[move_row][move_col]++;//该位置棋子经过的次数加一
		solution.push(i);
	}
	if(game_count==1) {
		solution.push(i);
		move_count++;
		if(move_count_square[move_row][move_col]>move_count)
			move_count_square[move_row][move_col]=move_count;
	}
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
	square[move_row][move_col]=avaliable;//返回后的位置重新变为可行走区域
	move_count--;//步数减一
	solution.pop();
}
//*********************************
bool Board::is_solved() {
	if(game_count==1) {
		if(move_count>=least_steps) {
			return true;//如果步数达到最优走法却没有找到终点直接放弃该路线。
		}
	}
	if(square[move_row][move_col]==destination) {
		if(game_count==1) {
			if(move_count<least_steps) {
				least_steps=move_count;
				best_solution=solution;
			}
		} 
		else {
			least_steps=move_count;
			best_solution=solution;
		}
		return true;
		//找到终点！与最少步数对比。比最优走法好替换最优走法。
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
	if(game_count==1) {
		if(least_steps==((board_size-1)/2*((board_size-1)/2+1)+board_size))
			cout<<"笨蛋找不到终点了::>_<::"<<endl;
		else cout<<"笨蛋花了"<<(now-start)/CLOCKS_PER_SEC+0.0001
			         <<" s ，走了 "<<least_steps<<" 步,终于找到终点了@_@"<<endl;
	} else cout<<"笨蛋找不到终点了::>_<::"<<endl;
}

