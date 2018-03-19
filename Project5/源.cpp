#include <graphics.h>
#include <conio.h>
#include <stdio.h>
#include <string.h>
#include <windows.h>
#include <time.h>
#pragma comment(lib,"winmm.lib")
/**
功能：用户控制一个小鸟，空格或者鼠标让小鸟上移，播放音乐，碰到障碍物就死亡，障碍物随机出现，提示当前通过的障碍物的数量
*/



void Show();  //显示函数
void Init();  //初始化函数
void updateWithoutInput();//更新和用户输入无关的数据
void updateAboutInput();   //更新和用户输入有关的数据
void GAMEOVER();     //结束函数

					 //定义全局变量
int bird_x, bird_y;  //小鸟坐标
int bar_x;    //障碍物坐标
int bar_up_y, bar_down_y; //上下障碍物坐标
int x, y;     //障碍物随机增量

IMAGE img_bk, img_bd1, img_bd2, img_bar_up1, img_bar_up2, img_bar_down1, img_bar_down2;   //图片定义
int main()
{
	Init();  //初始化
	while (1)
	{
		Show();  //显示
		updateAboutInput();    //更新数据
		updateWithoutInput();
	}
	GAMEOVER();   //结束函数

	return 0;
}

	//书写函数
	void Init()
	{	
		//让时间作为种子，每次产生不同的障碍物坐标
		srand(time(NULL));

		mciSendString("open C:\\background.mp3 alias bkmusic", NULL, 0, NULL);    //播放背景音乐
		mciSendString("play bkmusic repeat", NULL, 0, NULL);
		bar_x = 150;     //初始化障碍物坐标                              
		bar_up_y = -300;
		bar_down_y = 400;
		initgraph(350, 600);						   //初始画布
		loadimage(&img_bk, _T("C:\\background.jpg"));  //初始化图片
		loadimage(&img_bd1, _T("C:\\bird1.jpg"));
		loadimage(&img_bd2, _T("C:\\bird2.jpg"));
		loadimage(&img_bar_up1, _T("C:\\bar_up1.gif"));
		loadimage(&img_bar_up2, _T("C:\\bar_up2.gif"));
		loadimage(&img_bar_down1, _T("C:\\bar_down1.gif"));
		loadimage(&img_bar_down2, _T("C:\\bar_down2.gif"));
		bird_x = 50;   //初始化小鸟坐标
		bird_y = 250;
		BeginBatchDraw();  //开始
	}
	//显示画面
	void Show()
	{	
		putimage(0, 0, &img_bk);
		putimage(bird_x, bird_y, &img_bd1, NOTSRCERASE);		//显示小鸟
		putimage(bird_x, bird_y, &img_bd2, SRCINVERT);
		putimage(bar_x, bar_up_y, &img_bar_up1, NOTSRCERASE);		//显示障碍物上半部分
		putimage(bar_x, bar_up_y, &img_bar_up2, SRCINVERT);
		putimage(bar_x, bar_down_y, &img_bar_down1, NOTSRCERASE);		//障碍物下半部分
		putimage(bar_x, bar_down_y, &img_bar_down2, SRCINVERT);
		FlushBatchDraw();   //集中处理图片
		Sleep(50);
	}

	void updateAboutInput()
	{
		char input;
		if (_kbhit())
		{
			input = _getch();
			if (input == ' ' && bird_y > 20)   //用户输入空格时，小鸟向上移动
			{
				bird_y -= 30;
				mciSendString("close jpmusic",NULL,0,NULL);
				mciSendString("open C:\\jump.mp3 alias jpmusic", NULL, 0, NULL);    //播放跳动音乐
				mciSendString("play jpmusic", NULL, 0, NULL);
			}
		}

	}
	void updateWithoutInput()
	{
		//小鸟自动下落
		if(bird_y<580)
			bird_y += 3;
		else if (bird_y >= 580)
		{
			printf("游戏结束！");
			exit(0);
		}
		//下面实现障碍物的向左移动和随机宽度
		if (bar_x >= -140)   //没有走出边界情况，直到完全消失
		{
			bar_x -= 3;  
		}
		else if(bar_x <140)                //更新障碍物
		{
			bar_x = 350;      //重回最右边界
			bar_up_y = ((rand() % 300) - 200);
			bar_down_y = rand() % 400 + 100;
		}
	}
	void GAMEOVER()
	{
		EndBatchDraw();
		_getch();
		closegraph();
	}




