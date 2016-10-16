#include<iostream>
#include<Windows.h>
#include<conio.h>
#include"Board.h"
#include"time.h"
using namespace std;
double start=clock();
double now=clock();
void solve_from(Board&game);
int main() {
	Board game;
	char command='1',extend_command;
	game.print_Board();
	game.initialize();
	start=clock();	
	solve_from(game);
	now=clock();
	game.result();
	system("pause");
	return 0;
}
void solve_from(Board&game) {
	if(!game.is_solved()) {
		int best_way=game.better_step();
		int way=0;
		for(int move=best_way; move<4+best_way; move++) {
			if(move>4) way=move%4;
			else way=move;
			if(game.unguarded(way)) {
				game.go_forward(way);
				solve_from(game);
				game.go_back(way);
			}
		}
	}
}
