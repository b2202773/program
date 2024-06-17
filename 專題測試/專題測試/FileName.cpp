# include <iostream>
# include <conio.h>
# include "2048.h"
using namespace std;

void move(a2048 b, char a) {
	while (true) {
		switch (a) {
		case 's':
		case 'S':
			b.downmove();
			break;
		case 'd':
		case 'D':
			b.rightmove();
			break;
		case 'a':
		case 'A':
			b.leftmove();
			break;
		case 'w':
		case 'W':
			b.upmove();
			break;
		default:
			return; 
		}

		b.clean();
		b.printnum();

		if (!b.cheak()) {
			break; 
		}

		a = _getch();// ·s¿é¤J
		if (!(a == 'a' || a == 's' || a == 'd' || a == 'w' ||
			a == 'A' || a == 'S' || a == 'D' || a == 'W')) {
			break; 
		}
	}
}

int main() {
	while (true) {
		char a;
		a2048 b;
		b.makeframe();
		b.creatnum();
		b.creatnum();
		b.printnum();
		while (true) {
			a = _getch();
			if (a == 'a' || a == 's' || a == 'd' || a == 'w' ||
				a == 'A' || a == 'S' || a == 'D' || a == 'W')
				break;
		}
		move(b, a);
		cout << endl;
		cout << "play again ? yes(y) : no(n)" << endl;
		while (1) {
			a = _getch();
			if (a == 'y' || a == 'n' || a == 'Y' || a == 'N')
				break;
		}
		if (a == 'y' || a == 'Y')          
			continue;
		else                              
			break;
	}
	return 0;
}