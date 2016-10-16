#include<iostream>
#include<Windows.h>
#include<conio.h>
#include"Board.h"
#include"time.h"
using namespace std;
double start=clock();
double now=clock();
void solve_from(Board&game);
int game_count=0;
int main() {
	Board game,next_game;//新建Board对象game
	game.print_Board();// 打印棋盘
	game.initialize();//初始化棋盘，设置起点终点障碍物位置
	start=clock();	//表示开始搜索终点的时间
	solve_from(game);//开始自动搜索终点
	if(game.least_steps!=0) {
		game_count++;		
		game.clear();
		solve_from(game);//开始自动搜索终点
	}
	now=clock();//表示结束搜索终点的时间
	game.result();//打印棋盘搜索结果
	system("pause");//防止运行结束立刻退出
	return 0;
}
void solve_from(Board&game) {
	if(!game.is_solved()) {//如果已经找到终点停止递归
		int best_way=game.better_step();//提供该位置的最佳方向
		int way=0;
		for(int move=best_way; move<4+best_way; move++) {
			move>4?way=move%4:way=move;
			if(game.unguarded(way)) {//如果该方向不可走则返回
				game.go_forward(way);//前进
				solve_from(game);//递归，走下一步
				//if(game_count==0)if(game.is_solved())return;//如果找到终点则停止递归返回
				game.go_back(way);//该点后的路线找不到终点返回上一步
			}
		}
	}
}
