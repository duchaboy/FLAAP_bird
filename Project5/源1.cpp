
#include <string.h>
#include <conio.h>   //����EasyX���ļ�
#include <graphics.h>
#include <stdio.h>
//������дmain����֮�е��Ӻ���

void Show();  //��ʾ����
void Init();  //��ʼ������
void updateWithoutInput();//���º��û������޹ص�����
void updateAboutInput();   //���º��û������йص�����
void GNAMOVER();     //��������

					 //����ȫ�ֱ���
int bird_x, bird_y;  //С������
IMAGE img_bk, img_bd1, img_bd2, img_bar_up1, img_bar_up2, img_bar_down1, img_bar_down2;   //ͼƬ����

																						  
//��д����
void Init()
{
	initgraph(350, 600);						   //��ʼ����
	loadimage(&img_bk, _T("C:\\background.jpg"));  //��ʼ��ͼƬ
	loadimage(&img_bd1, _T("C:\\bird1.jpg"));
	loadimage(&img_bd2, _T("C:\\bird2.jpg"));
	loadimage(&img_bar_up1, _T("C:\\bar_up1.jpg"));
	loadimage(&img_bar_up2, _T("C:\\bar_up2.jpg"));
	loadimage(&img_bar_down1, _T("C:\\bar_down1.jpg"));
	loadimage(&img_bar_down2, _T("C:\\bar_down2jpg"));
	bird_x = 50;   //��ʼ��С������
	bird_y = 250;
	BeginBatchDraw();  //��ʼ
}
//��ʾ����
void Show()
{
	putimage(0, 0, &img_bk);
	putimage(bird_x, bird_y, &img_bd1, NOTSRCERASE);		//��ʾС��
	putimage(bird_x, bird_y, &img_bd2, SRCINVERT);
	putimage(150, -300, &img_bar_up1, NOTSRCERASE);		//��ʾ�ϰ����ϰ벿��
	putimage(150, -300, &img_bar_up2, SRCINVERT);
	putimage(150, 400, &img_bar_down1, NOTSRCERASE);		//�ϰ����°벿��
	putimage(150, 400, &img_bar_down2, SRCINVERT);
	FlushBatchDraw();   //���д���ͼƬ
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




