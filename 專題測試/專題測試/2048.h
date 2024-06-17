#ifndef a2048_h
#define a2048_h

class a2048{
private:
	int a[4][4];
public:
	a2048();               //建構函式，初始化資料。
	void makeframe();     //列印外框函式。
	void printnum();       //列印數字函式。
	void creatnum();      //隨機產生數字函式
	void clean();          //清理顯示出來的數字
	void rightmove();      //右移函式
	void leftmove();       //左移函式
	void upmove();		   //上移函式
	void downmove();	   //下移函式
	int cheak();           //檢查遊戲是否結束函式
};
#endif