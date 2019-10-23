#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define MAX_ROW 3
#define MAX_COL 3

int Menu(){
	printf("==================\n");
	printf(" 1. 开始游戏\n");
	printf(" 0. 结束游戏\n");
	printf("==================\n");
	printf(" 请输入您的选择: ");
	int choice = 0;
	scanf("%d", &choice);
	return choice;
}



char chess_board[MAX_ROW][MAX_COL]; 

void Init(){
	// 棋盘使用 x 表示玩家落子，o 表示电脑落子
	//" "表示未落子
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
	printf("玩家落子！\n");
	while (1) {
		printf("请输入一组坐标(row col):");
		int row = 0;
		int col = 0;
		scanf("%d %d", &row, &col);
		if (row >= MAX_ROW || row < 0 || col >= MAX_COL || col < 0){
			printf("您的输入非法!\n");
			continue;
		}5555
		if (chess_board[row][col] != ' '){
			printf("您输入的坐标已被占用!\n");
			continue;
		}
		chess_board[row][col] = 'x';
		break;
	}
	
}



void ComputerMove(){
	printf("电脑落子!\n");
	while (1) {
		int row = rand() % MAX_ROW;
		int col = rand() % MAX_COL;
		if (chess_board[row][col] != ' '){
			//这个位置被占用
			//重新随机一次
			continue;
		}
		chess_board[row][col] = 'o';
		break;
	}
}

//如果棋盘满了，返回1，否则返回 0
int IsFull(){
	for (int row = 0; row < MAX_ROW; ++row){
		for (int col = 0; col < MAX_COL; ++col){
			if (chess_board[row][col] == ' '){
				return 0;
			}
		}
	}
	//只要找到一个位置为' '就认为没满
	//必须把所有位置找完也没空格，此时才满
	return 1;
}

//返回 x 表示玩家胜
//返回 o 表示电脑胜
//返回 q 表示和棋
//返回 ' ' 表示未分出胜负，也不是和棋，继续进行游戏
char CheckGameOver(){
	//检查所有的行
	for (int row = 0; row < MAX_ROW; ++row){
		if (chess_board[row][0] == chess_board[row][1]
			&& chess_board[row][0] == chess_board[row][2]){
			return chess_board[row][0];
		}
	}
	//检查所有的列
	for (int col = 0; col < MAX_COL; ++col){
		if (chess_board[0][col] == chess_board[1][col]
			&& chess_board[0][col] == chess_board[2][col]){
			return chess_board[0][col];
		}
	}
	//检查所有的对角线
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
	//1.创建并初始化一个棋盘
	Init();
	char winner = ' ';
	while (1) {
	  //2.打印棋盘
	  Print();
	  //3.玩家落子    
	  PlayerMove();
	  //4.检测游戏结束
	  winner = CheckGameOver();
	  if (winner != ' '){
		  //分出胜负或者和棋
		  break;
	  }
	  //5.电脑落子
	  ComputerMove();
	  //6.检测游戏结束
	  winner = CheckGameOver();
	  if (winner != ' '){
		  break;
	  }
	}
	if (winner == 'x'){
		printf("玩家胜利!\n");
	}
	else if (winner == 'o'){
		printf("你真菜，电脑都下不过!\n");
	}
	else if (winner == 'q'){
		printf("你还是真菜，和电脑五五开!\n");
	}
	else{
		printf("好像出错了!\n");
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
			printf("您的输入有误!\n");
		}
	}
	system("pause");
	return 0;
}