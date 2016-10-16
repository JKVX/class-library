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
	Board game,next_game;//�½�Board����game
	game.print_Board();// ��ӡ����
	game.initialize();//��ʼ�����̣���������յ��ϰ���λ��
	start=clock();	//��ʾ��ʼ�����յ��ʱ��
	solve_from(game);//��ʼ�Զ������յ�
	if(game.least_steps!=0) {
		game_count++;		
		game.clear();
		solve_from(game);//��ʼ�Զ������յ�
	}
	now=clock();//��ʾ���������յ��ʱ��
	game.result();//��ӡ�����������
	system("pause");//��ֹ���н��������˳�
	return 0;
}
void solve_from(Board&game) {
	if(!game.is_solved()) {//����Ѿ��ҵ��յ�ֹͣ�ݹ�
		int best_way=game.better_step();//�ṩ��λ�õ���ѷ���
		int way=0;
		for(int move=best_way; move<4+best_way; move++) {
			move>4?way=move%4:way=move;
			if(game.unguarded(way)) {//����÷��򲻿����򷵻�
				game.go_forward(way);//ǰ��
				solve_from(game);//�ݹ飬����һ��
				//if(game_count==0)if(game.is_solved())return;//����ҵ��յ���ֹͣ�ݹ鷵��
				game.go_back(way);//�õ���·���Ҳ����յ㷵����һ��
			}
		}
	}
}
