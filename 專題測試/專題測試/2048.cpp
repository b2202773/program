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
HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);     //�������N�X
void mouse(HANDLE h, int x, int y){            //�����Ъ��禡	
	COORD m;
	m.X = x;
	m.Y = y;
	SetConsoleCursorPosition(h, m);
}
void a2048::makeframe(){                       //�L�ج[

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
void a2048::printnum() {                        //�L�Ʀr
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			int x = 6 * j + 3;  
			int y = 2 * i + 2; 
			mouse(h, x, y);
			cout << a[i][j];
		}
	}
}
void a2048::creatnum(){     //�H������ 2 �� 4
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
		int b[4] = { 0 };                 //�w�q�@���{�ɰ}�C���x�s�ۥ[���᪺���p
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
		for (int j = 0; j < 4; j++)      //�N���G�л\�^�h
			a[j][i] = b[j];
	}
	if (tag)
		creatnum();
	
}
void a2048::downmove(){     //�U��
	int k, tag = 0;
	for (int i = 0; i < 4; i++){           //�q�C�@�C�}�l
		int b[4] = { 0 };				 //�w�q�@���{�ɰ}�C���x�s�ۥ[���᪺���p
		k = 3;
		for (int j = 3; j > 0; j--){
			if (a[j][i] != 0){
				int flag = 0;
				for (int l = j - 1; l >= 0; l--){    //��O�_���ۦP����
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
		b[k] = a[0][i];                 //�̫�@�ӨS���ˬd�A��ȹL�h�A���ެO�_��0�A���L�ҿת�
		for (int j = 0; j < 4; j++){     //�ˬd�O�_������
			if (a[j][i] != b[j]){
				tag = 1;
				break;
			}
		}
		for (int j = 0; j < 4; j++)    //�N���G�л\�^�h
			a[j][i] = b[j];
	}
	if (tag)                          //�s�b���ʡA���ͷs����
		creatnum();

}

void a2048::leftmove() {    //����
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
	
void a2048::rightmove(){    //�k��
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

void a2048::clean(){		//�M�z�X�����Ʀr	
	int k = 0, l = 0;
	for (int i = 2; i < 21, k < 4; i = i + 6){    //���������ءA��J�Ů�
		l = 0;
		for (int j = 2; j < 9; j = j + 2){
			mouse(h, i, j);
			cout<<("   ");
			l++;
		}
		k++;
	}
}
int a2048::cheak(){			//�ˬd���S������
	int i, j, flag = 0, tag = 0;
	for (i = 0; i < 4; i++){                  //�ˬd�O�_�٦���m�A���Atag = 1
		for (j = 0; j < 4; j++){
			if (a[i][j] == 0){
				tag = 1;
				break;
			}
		}
		if (tag == 1)
			break;
	}
	if (tag)                               //���A��^1
		return 1;
	for (i = 0; i < 4; i++){                //�ˬd���k����l�O�_���۵��A�O�Aflag = 1�A�h�X�j��
		for (j = 0; j < 3; j++){
			if (a[i][j] == a[i][j + 1]){
				flag = 1;
				break;
			}
		}
		if (flag == 1)
			break;
	}
	for (j = 0; j < 4; j++){               //�ˬd�W�U����l�O�_���Q���A�O�Aflag = 1�A�h�X�j��
	
		for (i = 0; i < 3; i++){
			if (a[i][j] == a[i + 1][j]){
				flag = 1;
				break;
			}
		}
		if (flag == 1)
			break;
	}
	if (tag == 0 && flag == 0)            //flag = 0 �M tag = 0�A�C������
		return 0;
	else                                  //�_�h�A�~��C��
		return 1;
}