#ifndef a2048_h
#define a2048_h

class a2048{
private:
	int a[4][4];
public:
	a2048();               //�غc�禡�A��l�Ƹ�ơC
	void makeframe();     //�C�L�~�ب禡�C
	void printnum();       //�C�L�Ʀr�禡�C
	void creatnum();      //�H�����ͼƦr�禡
	void clean();          //�M�z��ܥX�Ӫ��Ʀr
	void rightmove();      //�k���禡
	void leftmove();       //�����禡
	void upmove();		   //�W���禡
	void downmove();	   //�U���禡
	int cheak();           //�ˬd�C���O�_�����禡
};
#endif