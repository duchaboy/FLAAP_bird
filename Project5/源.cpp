#include <graphics.h>
#include <conio.h>
#include <stdio.h>
#include <string.h>


int main()
{	
	Init();  //初始化
	while(1)
	{
		Show();  //显示
		updateAboutInput();    //更新数据
		updateWithoutInput();
	}
	GAMEOVER();   //结束函数

	return 0;
}