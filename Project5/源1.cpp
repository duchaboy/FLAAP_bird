
#include <string.h>
#include <conio.h>   //导入EasyX库文件
#include <graphics.h>
#include <stdio.h>
//用于书写main函数之中的子函数

void Show();  //显示函数
void Init();  //初始化函数
void updateWithoutInput();//更新和用户输入无关的数据
void updateAboutInput();   //更新和用户输入有关的数据
void GNAMOVER();     //结束函数

					 //定义全局变量
int bird_x, bird_y;  //小鸟坐标
IMAGE img_bk, img_bd1, img_bd2, img_bar_up1, img_bar_up2, img_bar_down1, img_bar_down2;   //图片定义

																						  
//书写函数
void Init()
{
	initgraph(350, 600);						   //初始画布
	loadimage(&img_bk, _T("C:\\background.jpg"));  //初始化图片
	loadimage(&img_bd1, _T("C:\\bird1.jpg"));
	loadimage(&img_bd2, _T("C:\\bird2.jpg"));
	loadimage(&img_bar_up1, _T("C:\\bar_up1.jpg"));
	loadimage(&img_bar_up2, _T("C:\\bar_up2.jpg"));
	loadimage(&img_bar_down1, _T("C:\\bar_down1.jpg"));
	loadimage(&img_bar_down2, _T("C:\\bar_down2jpg"));
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
	putimage(150, -300, &img_bar_up1, NOTSRCERASE);		//显示障碍物上半部分
	putimage(150, -300, &img_bar_up2, SRCINVERT);
	putimage(150, 400, &img_bar_down1, NOTSRCERASE);		//障碍物下半部分
	putimage(150, 400, &img_bar_down2, SRCINVERT);
	FlushBatchDraw();   //集中处理图片
	Sleep(50);
}

void updateAbout()
{


}
void updateWithoutInput()
{



}
void GAMEOVER()
{
	_getch();
	EndBatchDraw();
	closegraph();
}




