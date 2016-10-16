#include<iostream>
#include<Windows.h>
#include<stack>
#include<time.h>
enum Board_Condition {avaliable,starting_point,destination,obstacle,restrict};
//avaliable�ɸı�Ļ���ߵģ�starting_point��㣻destination�յ�
// obstacle�ϰ��restrict���������� 
using namespace std;
const int board_size=81;//���̱䳤*2+1����ҪС�ڵ���37 
const int sleep_time=0;//��ӡ��ʱ���� 
HANDLE hOut=GetStdHandle(STD_OUTPUT_HANDLE);
CONSOLE_CURSOR_INFO curInfo;
COORD pos;
extern double now,start; //����main.cpp�е�nowstart���� 
class Board {
	public:
		Board();//���캯�� ��
		void print_Board();//��ʼ��ӡ���� ��
		void initialize();//��������ִ����Ӧ���� ��
		bool unguarded(int i);//�ж������ܲ������ĸ�����ǰ����
		int better_step();//�Ż��㷨��
		void go_forward(int);//����ǰ����
		void go_back(int);//���ӳ�����
		bool is_solved();//�ж�������û���ҵ��յ㡣
		void result();//��������
	private:
		Board_Condition square[(board_size-1)/2][(board_size-1)/2];//���̵�״̬��
		int move_count_square[(board_size-1)/2][(board_size-1)/2];
		//��¼����ĳ��λ�����Ӿ����Ĵ��� 
		int cursor_row,cursor_col;//���ĵ�ַ��
		int destination_row,destination_col;//�յ�ĵ�ַ��
		int move_row,move_col;//���ӵĵ�ַ��
		int start_row,start_col;//����ַ��
		int count;//��¼����space�Ĵ�����
		int move_count;//�����ߵĲ�����
};
//********************************
Board::Board() { //���캯�� 
	cursor_row=0;
	cursor_col=0;//����ʼ
	destination_row=-1;
	destination_col=-1;//�յ��ʼ
	move_row=0;
	move_col=0;//���ӵ�λ�ó�ʼ
	count=0;//space��ʼ
	move_count=0;//���Ӳ�����ʼ
	for(int i=0; i<(board_size-1)/2; i++)
		for(int j=0; j<(board_size-1)/2; j++) {
			square[i][j]=avaliable;//���̳�ʼ
			move_count_square[i][j]=0;//����ĳλ�����Ӿ���������ʼ 
		}
}
//*******************************
void Board::print_Board() {//��ӡ���̲�ʹ����ڣ�0��0��λ��

	for(int i=0; i<board_size; i++) {
		for(int j=0; j<board_size; j++) {
			if(i%2==0) {
				if(i==0&&j==0)cout<<"�X";
				else if(i==0&&j==1)cout<<"��";
				else if(i==0&&j==2)cout<<"�[";
				else if(i==2&&j==0)cout<<"�^";
				else if(i==2&&j==1)cout<<"��";
				else if(i==2&&j==2)cout<<"�a";//��ӡ���λ�� 
				else if(i==0) {
					if(j==0)	cout<<"��";
					else if(j==board_size-1)cout<<"��";
					else if(j%2==0) cout<<"��";
					else cout<<"��";
				} else if(i==board_size-1) {
					if(j==0)	cout<<"��";
					else if(j==board_size-1)cout<<"��";
					else if(j%2==0)cout<<"��";
					else cout<<"��";
				} else {
					if(j==0)cout<<"��";
					else if(j==board_size-1)cout<<"��";
					else if(j%2==0)cout<<"��";
					else cout<<"��";//��ӡ���� 
				}
			} else {
				if(i==1&&j==0)cout<<"��";
				else if(i==1&&j==2)cout<<"��";//��ӡ���λ��
				else if(j==0)cout<<"��";
				else if(j==board_size-1)cout<<"��";
				else if(j%2==0)cout<<"��";
				else cout<<"  ";//��ӡ����
			}
		}
		cout<<endl;
	}
}
//********************************
void Board::initialize() {
	char command='1';//��ʼ������ 
	while(command!=13) {//����Ϊ13��ʾ�����ΪEnter�� 
		command=getch();//�������ΪEnterʱ�������� 
		if(command==-32) {//����Ϊ-32��ӦascII��ʾ�����Ϊ�������� 
			command=getch();//�ٴλ�ȡ�õ�ȷ�еķ��� 
			switch(command) {
				case 72://�������� 
					if(cursor_row==0)break; 
					else {
						pos.X=cursor_col*4,pos.Y=(cursor_row)*2;
						SetConsoleCursorPosition(hOut,pos);
						if(cursor_col==0)cout<<"�ǩ���";
						else if(cursor_col==(board_size-1)/2-1)cout<<"�贈��";
						else cout<<"�贈��" ;
						pos.Y=(cursor_row)*2+1;
						SetConsoleCursorPosition(hOut,pos);
						cout<<"��";
						pos.X=cursor_col*4+4;
						SetConsoleCursorPosition(hOut,pos);
						cout<<"��";
						pos.X=cursor_col*4,pos.Y=(cursor_row)*2+2;
						SetConsoleCursorPosition(hOut,pos);
						if(cursor_row==(board_size-1)/2-1) {
							if(cursor_col==0)cout<<"������";
							else if(cursor_col==(board_size-1)/2-1)cout<<"�ߩ���";
							else cout<<"�ߩ���" ;

						} else {
							if(cursor_col==0)cout<<"�ǩ���";
							else if(cursor_col==(board_size-1)/2-1)cout<<"�贈��";
							else cout<<"�贈��" ;

						}
						pos.X=cursor_col*4,pos.Y=(cursor_row-1)*2;
						SetConsoleCursorPosition(hOut,pos);
						cout<<"�X���[";
						pos.Y=(cursor_row-1)*2+1;
						SetConsoleCursorPosition(hOut,pos);
						cout<<"��";
						pos.X=cursor_col*4+4;
						SetConsoleCursorPosition(hOut,pos);
						cout<<"��";
						pos.X=cursor_col*4,pos.Y=(cursor_row-1)*2+2;
						SetConsoleCursorPosition(hOut,pos);
						cout<<"�^���a";
						cursor_row--;
					}
					break;
				case 80://��������
					if(cursor_row==(board_size-1)/2-1)break;
					else {
						pos.X=cursor_col*4,pos.Y=(cursor_row)*2;
						SetConsoleCursorPosition(hOut,pos);
						if(cursor_row==0) {
							if(cursor_col==0)cout<<"������";
							else if(cursor_col==(board_size-1)/2-1)cout<<"�ש���";
							else cout<<"�ש���" ;

						} else {
							if(cursor_col==0)cout<<"�ǩ���";
							else if(cursor_col==(board_size-1)/2-1)cout<<"�贈��";
							else cout<<"�贈��" ;

						}
						pos.Y=(cursor_row)*2+1;
						SetConsoleCursorPosition(hOut,pos);
						cout<<"��";
						pos.X=cursor_col*4+4;
						SetConsoleCursorPosition(hOut,pos);
						cout<<"��";
						pos.X=cursor_col*4,pos.Y=(cursor_row)*2+2;
						SetConsoleCursorPosition(hOut,pos);
						if(cursor_col==0)cout<<"������";
						else if(cursor_col==(board_size-1)/2-1)cout<<"�ߩ���";
						else cout<<"�ߩ���" ;
						pos.X=cursor_col*4,pos.Y=(cursor_row+1)*2;
						SetConsoleCursorPosition(hOut,pos);
						cout<<"�X���[";
						pos.Y=(cursor_row+1)*2+1;
						SetConsoleCursorPosition(hOut,pos);
						cout<<"��";
						pos.X=cursor_col*4+4;
						SetConsoleCursorPosition(hOut,pos);
						cout<<"��";
						pos.X=cursor_col*4,pos.Y=(cursor_row+1)*2+2;
						SetConsoleCursorPosition(hOut,pos);
						cout<<"�^���a";
						cursor_row++;
					}
					break;
				case 75://��������
					if(cursor_col==0)break;
					else {
						pos.X=cursor_col*4,pos.Y=(cursor_row)*2;
						SetConsoleCursorPosition(hOut,pos);
						if(cursor_col==(board_size-1)/2-1) {
							if(cursor_row==0)cout<<"�ש���";
							else if(cursor_row==(board_size-1)/2-1)cout<<"�贈��";
							else cout<<"�贈��" ;
						} else {
							if(cursor_row==0)cout<<"�ש���";

							else cout<<"�贈��";
						}
						pos.Y=(cursor_row)*2+1;
						SetConsoleCursorPosition(hOut,pos);
						cout<<"��";
						pos.X=cursor_col*4+4;
						SetConsoleCursorPosition(hOut,pos);
						cout<<"��";
						pos.X=cursor_col*4,pos.Y=(cursor_row)*2+2;
						SetConsoleCursorPosition(hOut,pos);
						if(cursor_col==(board_size-1)/2-1) {
							if(cursor_row==0)cout<<"�贈��";
							else if(cursor_row==(board_size-1)/2-1)cout<<"�ߩ���";
							else cout<<"�贈��" ;
						} else {
							if(cursor_row==0)cout<<"�贈��";
							else if(cursor_row==(board_size-1)/2-1)cout<<"�ߩ���";
							else cout<<"�贈��" ;
						}
						pos.X=(cursor_col-1)*4,pos.Y=cursor_row*2;
						SetConsoleCursorPosition(hOut,pos);
						cout<<"�X���[";
						pos.Y=cursor_row*2+1;
						SetConsoleCursorPosition(hOut,pos);
						cout<<"��";
						pos.X=(cursor_col-1)*4;
						SetConsoleCursorPosition(hOut,pos);
						cout<<"��";
						pos.X=(cursor_col-1)*4,pos.Y=cursor_row*2+2;
						SetConsoleCursorPosition(hOut,pos);
						cout<<"�^���a";
						cursor_col--;
					}
					break;
				case 77://�������� 
					if(cursor_col==(board_size-1)/2-1)break;
					else {
						pos.X=cursor_col*4,pos.Y=(cursor_row)*2;
						SetConsoleCursorPosition(hOut,pos);
						if(cursor_col==0) {
							if(cursor_row==0)cout<<"������";
							else cout<<"�ǩ���" ;
						} else {
							if(cursor_row==0)cout<<"�ש���";
							else cout<<"�贈��";
						}
						pos.Y=(cursor_row)*2+1;
						SetConsoleCursorPosition(hOut,pos);
						cout<<"��";
						pos.X=cursor_col*4+4;
						SetConsoleCursorPosition(hOut,pos);
						cout<<"��";
						pos.X=cursor_col*4,pos.Y=(cursor_row)*2+2;
						SetConsoleCursorPosition(hOut,pos);
						if(cursor_col==0) {
							if(cursor_row==0)cout<<"�ǩ���";
							else if(cursor_row==(board_size-1)/2-1)cout<<"������";
							else cout<<"�ǩ���" ;
						} else {
							if(cursor_row==0)cout<<"�贈��";
							else if(cursor_row==(board_size-1)/2-1)cout<<"�ߩ���";
							else cout<<"�贈��" ;
						}
						pos.X=(cursor_col+1)*4,pos.Y=cursor_row*2;
						SetConsoleCursorPosition(hOut,pos);
						cout<<"�X���[";
						pos.Y=cursor_row*2+1;
						SetConsoleCursorPosition(hOut,pos);
						cout<<"��";
						pos.X=(cursor_col+2)*4;
						SetConsoleCursorPosition(hOut,pos);
						cout<<"��";
						pos.X=(cursor_col+1)*4,pos.Y=cursor_row*2+2;
						SetConsoleCursorPosition(hOut,pos);
						cout<<"�^���a";
						cursor_col++;
					}
					break;
			}
		} else {
			if(command==' ') {//space���ı��λ�õ�״̬��
				pos.X=cursor_col*4+2,pos.Y=cursor_row*2+1;
				SetConsoleCursorPosition(hOut,pos);
				if(square[cursor_row][cursor_col]==avaliable) {//��λ��Ϊ�ɸı�״̬ 
					if(count==0) {//��һ�����룬������� 
						cout<<"��";
						square[cursor_row][cursor_col]=starting_point;
						//��λ�ñ��Ϊ��� 
						move_row=cursor_row;
						move_col=cursor_col;//��¼����λ�� 
						start_row=cursor_row;
						start_col=cursor_col;//��¼���λ�� 
					} else if(count==1) {//�ڶ������룬�����յ� 
						cout<<"��";
						square[cursor_row][cursor_col]=destination;
						//��λ�ñ��Ϊ�յ� 
						destination_row=cursor_row;
						destination_col=cursor_col;//��¼�յ�λ�� 
					} else {
						cout<<"��" ;
						square[cursor_row][cursor_col]=obstacle;
						//��λ�ñ��Ϊ�ϰ��� 
					}
					count++;
				} else if(square[cursor_row][cursor_col]==obstacle) {
					cout<<"  ";
					square[cursor_row][cursor_col]=avaliable;
					//�����λ��Ϊ�ϰ���ٴ�spaceȡ���ϰ�����±�Ϊ�ɸı�״̬ 
				}
			} else if(command==13) {//��������ΪEnter�����Զ�Ѱ·��ʼ
				if(count==0||count==1)command='1';//�������յ�δȷ����Enter����Ч 
				else {
					pos.X=0,pos.Y=board_size;
					SetConsoleCursorPosition(hOut,pos);
					cout<<"������Ŷ������";	
				}
			}
		}
	}
}
//*********************************
bool Board::unguarded(int i) {
	switch(i) {
		case 1:
			if(move_row==0)return false;//����λ�ڵ�һ�У���������Ч 
			else if(square[move_row-1][move_col]==restrict||
			        square[move_row-1][move_col]==obstacle)return false;
					//������Ϊ�ϰ�����߱��������� ����������Ч 
			else if(move_count_square[move_row-1][move_col]!=0)return false;
			//�����ߵ�����Ϊ�Ѿ�����������������Ч 
			else return true;
			break;
		case 2:
			if(move_row==(board_size-1)/2-1)return false;//����λ�����һ�У���������Ч 
			else if(square[move_row+1][move_col]==restrict
			        ||square[move_row+1][move_col]==obstacle)return false;
			        //������Ϊ�ϰ�����߱��������� ����������Ч  
			else if(move_count_square[move_row+1][move_col]!=0)return false;
			//�����ߵ�����Ϊ�Ѿ�����������������Ч 
			else return true;
			break;
		case 3:
			if(move_col==0)return false;//����λ�ڵ�һ�У���������Ч 
			else if(square[move_row][move_col-1]==restrict
			        ||square[move_row][move_col-1]==obstacle)return false;
			        //������Ϊ�ϰ�����߱��������� ����������Ч 
			else if(move_count_square[move_row][move_col-1]!=0)return false;
			//�����ߵ�����Ϊ�Ѿ�����������������Ч 
			else return true;
			break;
		case 4:
			if(move_col==(board_size-1)/2-1)return false;//����λ�����һ�У���������Ч
			else if(square[move_row][move_col+1]==restrict
			        ||square[move_row][move_col+1]==obstacle)return false;
			        //������Ϊ�ϰ�����߱��������� ����������Ч 
			else if(move_count_square[move_row][move_col+1]!=0)return false;
			//�����ߵ�����Ϊ�Ѿ�����������������Ч 
			else return true;
			break;
	}
}
//********************************
int Board::better_step() {
	int best_way;
	if(move_row<destination_row)best_way=2;//����յ��������·ţ������� 
	else if(move_row>destination_row)best_way=1;//��Ȼ����յ��������Ϸţ������� 
	else if(move_col<destination_col)best_way=4;//��Ȼ����������յ��󷽣������� 
	else best_way=3;//��Ȼ������ 
	if(!unguarded(best_way)) {
		switch(best_way) {
			case 1:
			case 2:
			//�������������Ϊ��Ч�߷��������������յ��󷽻��ҷ������������һ������� 
				if(move_col<destination_col)best_way=4;
				else best_way=3;
				break;
			case 3:
			case 4:
			//�������������Ϊ��Ч�߷��������������յ��Ϸ����·������������»�������
				if(move_col<destination_col)best_way=2;
				else best_way=1;
				break;
		}
	}
	return best_way;
}
//*********************************
void Board::go_forward(int i) {
	//Sleep(sleep_time);
	square[move_row][move_col]=restrict;//ǰ��֮ǰ��λ����Ϊ���������ֹ���ӻ��� 
	pos.X=move_col*4+2,pos.Y=move_row*2+1;
	SetConsoleCursorPosition(hOut,pos);
	switch(i) {
		case 1:
			move_row--;
			cout<<"��";
			break;
		case 2:
			move_row++;
			cout<<"��";
			break;
		case 3:
			move_col--;
			cout<<"��";
			break;
		case 4:
			move_col++;
			cout<<"��";
			break;
	}
	pos.X=move_col*4+2,pos.Y=move_row*2+1;
	SetConsoleCursorPosition(hOut,pos);
	cout<<"��";
	move_count++;//������һ 
	move_count_square[move_row][move_col]++;//��λ�����Ӿ����Ĵ�����һ 
}
//***********************************
void Board::go_back(int i) {
	//Sleep(sleep_time);
	pos.X=move_col*4+2,pos.Y=move_row*2+1;
	SetConsoleCursorPosition(hOut,pos);
	switch(i) {
		case 1:
			cout<<"  ";
			move_row++;
			break;
		case 2:
			cout<<"  ";
			move_row--;
			break;
		case 3:
			cout<<"  ";
			move_col++;
			break;
		case 4:
			cout<<"  ";
			move_col--;
			break;
	}
	pos.X=move_col*4+2,pos.Y=move_row*2+1;
	SetConsoleCursorPosition(hOut,pos);
	cout<<"��";
	square[move_row][move_col]=avaliable;//���غ��λ�����±�Ϊ���������� 
	move_count--;//������һ 
}
//*********************************
bool Board::is_solved() {
	if(square[move_row][move_col]==destination)return true;
	//�ҵ��յ㣡�����ٲ����Աȡ��������߷����滻�����߷��� 
	return false;
}
//********************************
void Board::result() {
	pos.X=0,pos.Y=board_size;
	SetConsoleCursorPosition(hOut,pos);
	if(/*least_steps*/move_count==0) 
	cout<<"�����Ҳ����յ���::>_<::"<<endl;//������ӱ������̻ص�ԭ�����δ�ҵ��յ� 
	else cout<<"��������"<<(now-start)/CLOCKS_PER_SEC+0.0001 
	<<" s ������ "<<move_count<<" ��,�����ҵ��յ���@_@"<<endl;
}

