# include <iostream>
# include <Windows.h>
# include <time.h>
# include <conio.h>
# include "2048.h"
using namespace std;
a2048::a2048() {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			a[i][j] = 0;
		}
	}
}
HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);     //獲取控制代碼
void mouse(HANDLE h, int x, int y){            //控制游標的函式	
	COORD m;
	m.X = x;
	m.Y = y;
	SetConsoleCursorPosition(h, m);
}
void a2048::makeframe(){                       //印框架

	mouse(h, 0, 0);
	cout << endl;
	cout << "--------------------------" << endl;
	cout << "|     |     |     |      |" << endl;
	cout << "--------------------------" << endl;
	cout << "|     |     |     |      |" << endl;
	cout << "--------------------------" << endl;
	cout << "|     |     |     |      |" << endl;
	cout << "--------------------------" << endl;
	cout << "|     |     |     |      |" << endl;
	cout << "--------------------------" << endl;
}
void a2048::printnum() {                        //印數字
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			int x = 6 * j + 3;  
			int y = 2 * i + 2; 
			mouse(h, x, y);
			cout << a[i][j];
		}
	}
}
void a2048::creatnum(){     //隨機產生 2 或 4
	int i, j, num;
	srand(time(0));                   
	i = (rand() % 4);
	j = (rand() % 4);
	while (a[i][j]){
		i = (rand() % 4);
		j = (rand() % 4);
	}
	num = (rand() % 2);                
	if (num == 0)
		num=2;
	if (num == 1)
		num=4;
	a[i][j] = num;
}
void a2048::upmove(){		
	int k, tag = 0;
	for (int i = 0; i < 4; i++){
		int b[4] = { 0 };                 //定義一個臨時陣列來儲存相加之後的情況
		k = 0;
		for (int j = 0; j < 3; j++){
			if (a[j][i] != 0){
				int flag = 0;
				for (int l = j + 1; l < 4; l++)   {
					if (a[l][i] != 0){
						flag = 1;
						if (a[l][i] == a[j][i]){
							b[k++] = 2 * a[j][i];
							a[l][i] = a[j][i] = 0;
							break;
						}
						else{
							b[k++] = a[j][i];
							break;
						}
					}
				}
				if (flag == 0)
					b[k++] = a[j][i];
			}
		}
		b[k] = a[3][i];
		for (int j = 0; j < 4; j++){
			if (a[j][i] != b[j]){
				tag = 1;
				break;
			}
		}
		for (int j = 0; j < 4; j++)      //將結果覆蓋回去
			a[j][i] = b[j];
	}
	if (tag)
		creatnum();
	
}
void a2048::downmove(){     //下移
	int k, tag = 0;
	for (int i = 0; i < 4; i++){           //從每一列開始
		int b[4] = { 0 };				 //定義一個臨時陣列來儲存相加之後的情況
		k = 3;
		for (int j = 3; j > 0; j--){
			if (a[j][i] != 0){
				int flag = 0;
				for (int l = j - 1; l >= 0; l--){    //找是否有相同的數
					if (a[l][i] != 0){
						flag = 1;
						if (a[l][i] == a[j][i]){
							b[k--] = 2 * a[j][i];
							a[l][i] = a[j][i] = 0;
							break;
						}
						else{
							b[k] = a[j][i];
							k--;
							break;
						}
					}
				}
				if (flag == 0){
					b[k] = a[j][i];
					k--;
				}
			}
		}
		b[k] = a[0][i];                 //最後一個沒有檢查，賦值過去，不管是否為0，都無所謂的
		for (int j = 0; j < 4; j++){     //檢查是否有移動
			if (a[j][i] != b[j]){
				tag = 1;
				break;
			}
		}
		for (int j = 0; j < 4; j++)    //將結果覆蓋回去
			a[j][i] = b[j];
	}
	if (tag)                          //存在移動，產生新的數
		creatnum();

}

void a2048::leftmove() {    //左移
	int k, tag = 0;
	for (int i = 0; i < 4; i++){
		int b[4] = { 0 };
		k = 0;
		for (int j = 0; j < 3; j++){
			if (a[i][j] != 0){
				int flag = 0;
				for (int l = j + 1; l < 4; l++){
					if (a[i][l] != 0){
						flag = 1;
						if (a[i][l] == a[i][j]){
							b[k++] = 2 * a[i][j];
							a[i][j] = a[i][l] = 0;
							break;
						}
						else{
							b[k++] = a[i][j];
							break;
						}
					}
				}
				if (flag == 0)
					b[k++] = a[i][j];
			}
		}
		b[k] = a[i][3];
		for (int j = 0; j < 4; j++){
			if (a[i][j] != b[j]){
				tag = 1;
				break;
			}
		}
		for (int j = 0; j < 4; j++)
			a[i][j] = b[j];
	}
	if (tag)
		creatnum();
}
	
void a2048::rightmove(){    //右移
	int k, tag = 0;
	for (int i = 0; i < 4; i++){
		int b[4] = { 0 };
		k = 3;
		for (int j = 3; j > 0; j--){
			if (a[i][j] != 0){
				int flag = 0;
				for (int l = j - 1; l >= 0; l--){
					if (a[i][l] != 0){
						flag = 1;
						if (a[i][l] == a[i][j]){
							b[k--] = 2 * a[i][j];
							a[i][j] = a[i][l] = 0;
							break;
						}
						else{
							b[k--] = a[i][j];
							break;
						}
					}
				}
				if (flag == 0)
					b[k--] = a[i][j];
			}
		}
		b[k] = a[i][0];
		for (int j = 0; j < 4; j++)
		{
			if (a[i][j] != b[j])
			{
				tag = 1;
				break;
			}
		}
		for (int j = 0; j < 4; j++)
			a[i][j] = b[j];
	}
	if (tag)
		creatnum();
}

void a2048::clean(){		//清理合掉的數字	
	int k = 0, l = 0;
	for (int i = 2; i < 21, k < 4; i = i + 6){    //找到對應的框，輸入空格
		l = 0;
		for (int j = 2; j < 9; j = j + 2){
			mouse(h, i, j);
			cout<<("   ");
			l++;
		}
		k++;
	}
}
int a2048::cheak(){			//檢查有沒有結束
	int i, j, flag = 0, tag = 0;
	for (i = 0; i < 4; i++){                  //檢查是否還有位置，有，tag = 1
		for (j = 0; j < 4; j++){
			if (a[i][j] == 0){
				tag = 1;
				break;
			}
		}
		if (tag == 1)
			break;
	}
	if (tag)                               //有，返回1
		return 1;
	for (i = 0; i < 4; i++){                //檢查左右的格子是否有相等，是，flag = 1，退出迴圈
		for (j = 0; j < 3; j++){
			if (a[i][j] == a[i][j + 1]){
				flag = 1;
				break;
			}
		}
		if (flag == 1)
			break;
	}
	for (j = 0; j < 4; j++){               //檢查上下的格子是否有想等，是，flag = 1，退出迴圈
	
		for (i = 0; i < 3; i++){
			if (a[i][j] == a[i + 1][j]){
				flag = 1;
				break;
			}
		}
		if (flag == 1)
			break;
	}
	if (tag == 0 && flag == 0)            //flag = 0 和 tag = 0，遊戲結束
		return 0;
	else                                  //否則，繼續遊戲
		return 1;
}