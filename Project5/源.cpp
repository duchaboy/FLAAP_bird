#include <graphics.h>
#include <conio.h>
#include <stdio.h>
#include <string.h>
#include <windows.h>
#include <time.h>
#pragma comment(lib,"winmm.lib")
/**
���ܣ��û�����һ��С�񣬿ո���������С�����ƣ��������֣������ϰ�����������ϰ���������֣���ʾ��ǰͨ�����ϰ��������
*/



void Show();  //��ʾ����
void Init();  //��ʼ������
void updateWithoutInput();//���º��û������޹ص�����
void updateAboutInput();   //���º��û������йص�����
void GAMEOVER();     //��������

					 //����ȫ�ֱ���
int bird_x, bird_y;  //С������
int bar_x;    //�ϰ�������
int bar_up_y, bar_down_y; //�����ϰ�������
int x, y;     //�ϰ����������

IMAGE img_bk, img_bd1, img_bd2, img_bar_up1, img_bar_up2, img_bar_down1, img_bar_down2;   //ͼƬ����
int main()
{
	Init();  //��ʼ��
	while (1)
	{
		Show();  //��ʾ
		updateAboutInput();    //��������
		updateWithoutInput();
	}
	GAMEOVER();   //��������

	return 0;
}

	//��д����
	void Init()
	{	
		//��ʱ����Ϊ���ӣ�ÿ�β�����ͬ���ϰ�������
		srand(time(NULL));

		mciSendString("open C:\\background.mp3 alias bkmusic", NULL, 0, NULL);    //���ű�������
		mciSendString("play bkmusic repeat", NULL, 0, NULL);
		bar_x = 150;     //��ʼ���ϰ�������                              
		bar_up_y = -300;
		bar_down_y = 400;
		initgraph(350, 600);						   //��ʼ����
		loadimage(&img_bk, _T("C:\\background.jpg"));  //��ʼ��ͼƬ
		loadimage(&img_bd1, _T("C:\\bird1.jpg"));
		loadimage(&img_bd2, _T("C:\\bird2.jpg"));
		loadimage(&img_bar_up1, _T("C:\\bar_up1.gif"));
		loadimage(&img_bar_up2, _T("C:\\bar_up2.gif"));
		loadimage(&img_bar_down1, _T("C:\\bar_down1.gif"));
		loadimage(&img_bar_down2, _T("C:\\bar_down2.gif"));
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
		putimage(bar_x, bar_up_y, &img_bar_up1, NOTSRCERASE);		//��ʾ�ϰ����ϰ벿��
		putimage(bar_x, bar_up_y, &img_bar_up2, SRCINVERT);
		putimage(bar_x, bar_down_y, &img_bar_down1, NOTSRCERASE);		//�ϰ����°벿��
		putimage(bar_x, bar_down_y, &img_bar_down2, SRCINVERT);
		FlushBatchDraw();   //���д���ͼƬ
		Sleep(50);
	}

	void updateAboutInput()
	{
		char input;
		if (_kbhit())
		{
			input = _getch();
			if (input == ' ' && bird_y > 20)   //�û�����ո�ʱ��С�������ƶ�
			{
				bird_y -= 30;
				mciSendString("close jpmusic",NULL,0,NULL);
				mciSendString("open C:\\jump.mp3 alias jpmusic", NULL, 0, NULL);    //������������
				mciSendString("play jpmusic", NULL, 0, NULL);
			}
		}

	}
	void updateWithoutInput()
	{
		//С���Զ�����
		if(bird_y<580)
			bird_y += 3;
		else if (bird_y >= 580)
		{
			printf("��Ϸ������");
			exit(0);
		}
		//����ʵ���ϰ���������ƶ���������
		if (bar_x >= -140)   //û���߳��߽������ֱ����ȫ��ʧ
		{
			bar_x -= 3;  
		}
		else if(bar_x <140)                //�����ϰ���
		{
			bar_x = 350;      //�ػ����ұ߽�
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




