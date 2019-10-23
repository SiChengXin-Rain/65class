#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define MAX_ROW 3
#define MAX_COL 3

int Menu(){
	printf("==================\n");
	printf(" 1. ��ʼ��Ϸ\n");
	printf(" 0. ������Ϸ\n");
	printf("==================\n");
	printf(" ����������ѡ��: ");
	int choice = 0;
	scanf("%d", &choice);
	return choice;
}



char chess_board[MAX_ROW][MAX_COL]; 

void Init(){
	// ����ʹ�� x ��ʾ������ӣ�o ��ʾ��������
	//" "��ʾδ����
	for (int row = 0; row < MAX_ROW; ++row){
		for (int col = 0; col < MAX_COL; ++col){
			chess_board[row][col] = ' ';
		}
	}
}

void Print(){
	for (int row = 0; row < MAX_ROW; ++row){
		printf("| %c | %c | %c |\n",chess_board[row][0],
			chess_board[row][1],chess_board[row][2]);
		if (row != MAX_ROW - 1){
			printf("|---|---|---|\n");
		}	
	}
}

void PlayerMove(){
	printf("������ӣ�\n");
	while (1) {
		printf("������һ������(row col):");
		int row = 0;
		int col = 0;
		scanf("%d %d", &row, &col);
		if (row >= MAX_ROW || row < 0 || col >= MAX_COL || col < 0){
			printf("��������Ƿ�!\n");
			continue;
		}5555
		if (chess_board[row][col] != ' '){
			printf("������������ѱ�ռ��!\n");
			continue;
		}
		chess_board[row][col] = 'x';
		break;
	}
	
}



void ComputerMove(){
	printf("��������!\n");
	while (1) {
		int row = rand() % MAX_ROW;
		int col = rand() % MAX_COL;
		if (chess_board[row][col] != ' '){
			//���λ�ñ�ռ��
			//�������һ��
			continue;
		}
		chess_board[row][col] = 'o';
		break;
	}
}

//����������ˣ�����1�����򷵻� 0
int IsFull(){
	for (int row = 0; row < MAX_ROW; ++row){
		for (int col = 0; col < MAX_COL; ++col){
			if (chess_board[row][col] == ' '){
				return 0;
			}
		}
	}
	//ֻҪ�ҵ�һ��λ��Ϊ' '����Ϊû��
	//���������λ������Ҳû�ո񣬴�ʱ����
	return 1;
}

//���� x ��ʾ���ʤ
//���� o ��ʾ����ʤ
//���� q ��ʾ����
//���� ' ' ��ʾδ�ֳ�ʤ����Ҳ���Ǻ��壬����������Ϸ
char CheckGameOver(){
	//������е���
	for (int row = 0; row < MAX_ROW; ++row){
		if (chess_board[row][0] == chess_board[row][1]
			&& chess_board[row][0] == chess_board[row][2]){
			return chess_board[row][0];
		}
	}
	//������е���
	for (int col = 0; col < MAX_COL; ++col){
		if (chess_board[0][col] == chess_board[1][col]
			&& chess_board[0][col] == chess_board[2][col]){
			return chess_board[0][col];
		}
	}
	//������еĶԽ���
	if (chess_board[0][0] == chess_board[1][1]
		&& chess_board[0][0] == chess_board[2][2]){
		return chess_board[0][0];
	}
	if (chess_board[0][2] == chess_board[1][1]
		&& chess_board[0][2] == chess_board[2][0]){
		return chess_board[0][2];
	}
	if (IsFull()){
		return 'q';
	}
	return ' ';
}

void Game() {
	//1.��������ʼ��һ������
	Init();
	char winner = ' ';
	while (1) {
	  //2.��ӡ����
	  Print();
	  //3.�������    
	  PlayerMove();
	  //4.�����Ϸ����
	  winner = CheckGameOver();
	  if (winner != ' '){
		  //�ֳ�ʤ�����ߺ���
		  break;
	  }
	  //5.��������
	  ComputerMove();
	  //6.�����Ϸ����
	  winner = CheckGameOver();
	  if (winner != ' '){
		  break;
	  }
	}
	if (winner == 'x'){
		printf("���ʤ��!\n");
	}
	else if (winner == 'o'){
		printf("����ˣ����Զ��²���!\n");
	}
	else if (winner == 'q'){
		printf("�㻹����ˣ��͵������忪!\n");
	}
	else{
		printf("���������!\n");
	}
}

int main(){
	while (1){
		int choice = Menu();
		if (choice == 1) {
			Game();
		}
		else if (choice == 0){
			printf("goodbye\n");
			break;
		} else {
			printf("������������!\n");
		}
	}
	system("pause");
	return 0;
}