#include"libOne.h"

//�K������߂�ċA�Ăяo��
int factorial(int n) {
	if (n <= 1)	return 1;
	return n * factorial( n - 1);		
}
//�O���t�B�J���ȍċA�Ăяo��
void draw(float px, float radius, int level) {
	circle(px, height / 2, radius * 2);
	if (level >= 2) {
		draw(px - radius/2, radius/2, level - 1);
		draw(px + radius/2, radius/2, level - 1);
	}
}

void gmain()
{
	window(1920, 1080, full);
	hideCursor();
	int level = 1;
	while (notQuit)
	{
		clear(200, 200, 170);
		//�K��
		fill(0);
		printPosX(50);
		printPosY(50);
		for (int n = 0; n <= 5; n++) {
			print((let)n + "! = " + factorial(n));
		}
		//�O���t�B�b�N
		if (isTrigger(KEY_D))level++;
		if (isTrigger(KEY_A))level--;
		if (level < 1)level = 1;
		fill(0, 0, 0, 0);
		strokeWeight(10);
		draw(width / 2, 400, level);
	}
}
