#include <graphics.h>
#include <conio.h>
#include <stdio.h>
#include <string.h>


int main()
{	
	Init();  //��ʼ��
	while(1)
	{
		Show();  //��ʾ
		updateAboutInput();    //��������
		updateWithoutInput();
	}
	GAMEOVER();   //��������

	return 0;
}