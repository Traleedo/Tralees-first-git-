// c++课设.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <easyx.h>
#include <conio.h>//键盘
#include <mmsystem.h>//系统多媒体头文件
#pragma comment(lib,"winmm.lib")//window库文件
#include<time.h>
#include<windows.h>
#define MAX_GRID 4
#define GRID_WIDTH 100
#define INTERVAL 15
#include <stdio.h>
#include<fstream>
#include<math.h>
#include<string>
#include"game.h"


#include "User.h"

//#include "HiEasyX.h"
#include<stdio.h>
#include<stdlib.h>
#include<graphics.h>
#include<string.h>
#include<ctype.h>//检测字符
using namespace std;
bool isInRect(ExMessage* mouse, int x, int y, int w, int h);
class Managementbase
{
	public:

	virtual void run() = 0;
	virtual int menu() = 0;

};




class Management:virtual public Managementbase
{
	
public:
	//启动管理类
	 void run();
	 int menu();

	void menu1();
	void menu2();
	void about();
	void close();
	void omusic();
	void cmusic();
	void jieshao();
	void zuigao();
	

};
void Management::run()
{
	while(1)
	{
	int op = -1;
	 op = menu();
	
	switch (op)
	{
	case 1:
		menu1();
		break;
	case 2:
		menu2();
		break;
	case 3:
		about();
		break;
	case 4:
		jieshao();
		break;
	case 5:
		zuigao();
		break;
	case 6:
		close();
		break;	
	case 7:
		omusic();
		break;
	case 8:
		cmusic();
		break;
	default:
		break;
	}
	}
}

int Management::menu()
{
	
	IMAGE img_bk;
	loadimage(&img_bk, "photo.jpg");
	putimage(0, 0, &img_bk);

	IMAGE omusic;
	loadimage(&omusic, "omusic.jpg");
	putimage(10, 700, &omusic);

	IMAGE cmusic;
	loadimage(&cmusic, "cmusic.jpg");
	putimage(10, 735, &cmusic);
	//画方框 左上角 （150，80) 右下角（350，160）
	// 
	// 
	settextstyle(90, 0, "华文彩云");
	outtextxy(0, 200, "2048小游戏");
	//setfillcolor(RED);
	settextstyle(30, 0, "华文宋体");
	//solidrectangle(220, 410, 410, 440);
	rectangle(230, 410, 340, 440);
	outtextxy(230, 410, "经典模式");

	rectangle(230, 450, 340, 480);
	outtextxy(230, 450, "朝代模式");

	rectangle(230, 490, 340, 520);
	outtextxy(230, 490, "关于2048");

	rectangle(230, 530, 340, 560);
	outtextxy(230, 530, "玩法介绍");

	rectangle(230, 570, 340, 600);
	outtextxy(230, 570, "历史最高");

	rectangle(230, 610, 340, 640);
	outtextxy(230, 610, "退出游戏");

	settextstyle(15, 0, "华文宋体");

	rectangle(10, 700, 40, 730);
	rectangle(10, 735, 40, 765);

	while (1)
	{

		//	system("cls");
		ExMessage m;
		peekmessage(&m, EX_MOUSE);


		if (isInRect(&m, 230, 410, 110, 30))
		{

			if (m.message == WM_LBUTTONDOWN)
			{


				return 1;
				//

			}
		}

		if (isInRect(&m, 230, 450, 110, 30))
		{
			if (m.message == WM_LBUTTONDOWN)
			{
				return 2;
			}

		}
		if (isInRect(&m, 230, 490, 110, 30))
		{
			if (m.message == WM_LBUTTONDOWN)
			{
				return 3;
			}

		}
		
		if (isInRect(&m, 230, 530, 110, 30))
		{
			if (m.message == WM_LBUTTONDOWN)
			{
				return 4;
			}

		}
		if (isInRect(&m, 230, 570, 110, 30))
		{
			if (m.message == WM_LBUTTONDOWN)
			{
				return 5;
			}

		}
		if (isInRect(&m, 230, 600, 110, 30))
		{
			if (m.message == WM_LBUTTONDOWN)
			{
				return 6;
			}

		}
		if (isInRect(&m, 10, 700, 30, 30))
		{
			if (m.message == WM_LBUTTONDOWN)
			{
				return 7;

			}

		}
		if (isInRect(&m, 10, 735, 30, 30))
		{
			if (m.message == WM_LBUTTONDOWN)
			{
				return 8;
			}

		}
	}
	
}

void Management::menu1()
{
	time_t start;
	time_t end;
	
	
	int a = 1;
	while (a)
	{
		game aa;
		
		IMAGE img_bk;
		loadimage(&img_bk, "photo.jpg");
		putimage(0, 0, &img_bk);

		

		settextstyle(30, 0, "华文宋体");
		rectangle(230, 410, 335, 440);
		outtextxy(230, 410, "经典色彩");

		rectangle(230, 450, 335, 480);
		outtextxy(230, 450, "粉色回忆");

		rectangle(230, 490, 335, 520);
		outtextxy(230, 490, "蓝色海洋");


		ExMessage m;
		while (1)
		{
			peekmessage(&m, EX_MOUSE);
			if (isInRect(&m, 225, 410, 100, 30) && m.message == WM_LBUTTONDOWN)
			{
				aa.cc = 0;
				setbkcolor(RGB(187, 173, 160));
				break;
			}
			if (isInRect(&m, 225, 450, 100, 30) && m.message == WM_LBUTTONDOWN)
			{
				aa.cc = 1;
				setbkcolor(RGB(221, 160, 221));
				break;
			}
			if (isInRect(&m, 230, 490, 100, 30) && m.message == WM_LBUTTONDOWN)
			{
				aa.cc = 2;
				setbkcolor(RGB(106, 90, 205));

				break;
			}
		}

				
		//initgraph(MAX_GRID * GRID_WIDTH + 5 * INTERVAL, MAX_GRID * GRID_WIDTH + 10 * INTERVAL);//设置界面大小
		//initgraph(MAX_GRID * GRID_WIDTH + 5 * INTERVAL, MAX_GRID * GRID_WIDTH + 10 * INTERVAL);//设置界面大小
		
		cleardevice();//清屏
		start = clock();



		aa.print();

		aa.place();

		aa.zhixing();
		aa.history();
		aa.~game();
		end = clock();
		int  t = (end - start) / 1000;
		int  m1 = (end - start) / 1000;
		
		
		m1 /= 60;
		if (t >= 60)
		{


			t = t % 60;
		}
		char text[20] = { '\0' };
		settextstyle(30, 0, "黑体");
		if (m1 != 0) {
			sprintf_s(text, "Time:%d", m1);
			outtextxy(INTERVAL, MAX_GRID * GRID_WIDTH + 20 * INTERVAL - 10, text);
			outtextxy(INTERVAL + 130, MAX_GRID * GRID_WIDTH + 20 * INTERVAL - 10, "min");
			sprintf_s(text, "%d", t);
			outtextxy(INTERVAL + 190, MAX_GRID * GRID_WIDTH + 20 * INTERVAL - 10, text);
			outtextxy(INTERVAL + 260, MAX_GRID * GRID_WIDTH + 20 * INTERVAL - 10, "s");
		}
		if (m1 == 0) {
			sprintf_s(text, "Time:%d", t);
			outtextxy(INTERVAL, MAX_GRID * GRID_WIDTH + 20 * INTERVAL - 10, text);
			outtextxy(INTERVAL + 130, MAX_GRID * GRID_WIDTH + 20 * INTERVAL - 10, "s");
		}
		rectangle(400, 700, 450, 730);
		settextstyle(30, 0, "华文宋体");
		outtextxy(400, 700, "返回");
		rectangle(200, 700, 300, 730);
		settextstyle(30, 0, "华文宋体");
		outtextxy(200, 700, "再来一局");
		
		while (1)
		{
			ExMessage m;
			peekmessage(&m, EX_MOUSE);
			if (isInRect(&m, 400, 700, 50, 30))
			{
				if (m.message == WM_LBUTTONDOWN)
				{
					a = 0;
					break;
				}

			}
			if (isInRect(&m, 200, 700, 100, 30))
			{
				if (m.message == WM_LBUTTONDOWN)
				{

					break;
				}

			}


		}
	}
}

void Management::menu2()
{
	time_t start;
	time_t end;


	int a = 1;
	while (a)
	{
		game aa;

		IMAGE img_bk;
		loadimage(&img_bk, "photo.jpg");
		putimage(0, 0, &img_bk);



		settextstyle(30, 0, "华文宋体");
		rectangle(230, 410, 335, 440);
		outtextxy(230, 410, "经典色彩");

		rectangle(230, 450, 335, 480);
		outtextxy(230, 450, "粉色回忆");

		rectangle(230, 490, 335, 520);
		outtextxy(230, 490, "蓝色海洋");


		ExMessage m;
		while (1)
		{
			peekmessage(&m, EX_MOUSE);
			if (isInRect(&m, 225, 410, 100, 30) && m.message == WM_LBUTTONDOWN)
			{
				aa.cc = 0;
				setbkcolor(RGB(187, 173, 160));
				break;
			}
			if (isInRect(&m, 225, 450, 100, 30) && m.message == WM_LBUTTONDOWN)
			{
				aa.cc = 1;
				setbkcolor(RGB(221, 160, 221));
				break;
			}
			if (isInRect(&m, 230, 490, 100, 30) && m.message == WM_LBUTTONDOWN)
			{
				aa.cc = 2;
				setbkcolor(RGB(106, 90, 205));

				break;
			}
		}


		//initgraph(MAX_GRID * GRID_WIDTH + 5 * INTERVAL, MAX_GRID * GRID_WIDTH + 10 * INTERVAL);//设置界面大小
		//initgraph(MAX_GRID * GRID_WIDTH + 5 * INTERVAL, MAX_GRID * GRID_WIDTH + 10 * INTERVAL);//设置界面大小

		cleardevice();//清屏
		start = clock();

		aa.print();
		aa.place2();
		aa.zhixing2();
		aa.history();
		aa.~game();
		end = clock();
		int  t = (end - start) / 1000;
		int  m1 = (end - start) / 1000;


		m1 /= 60;
		if (t >= 60)
		{


			t = t % 60;
		}
		char text[20] = { '\0' };
		settextstyle(30, 0, "黑体");
		if (m1 != 0) {
			sprintf_s(text, "Time:%d", m1);
			outtextxy(INTERVAL, MAX_GRID * GRID_WIDTH + 20 * INTERVAL - 10, text);
			outtextxy(INTERVAL + 130, MAX_GRID * GRID_WIDTH + 20 * INTERVAL - 10, "min");
			sprintf_s(text, "%d", t);
			outtextxy(INTERVAL + 190, MAX_GRID * GRID_WIDTH + 20 * INTERVAL - 10, text);
			outtextxy(INTERVAL + 260, MAX_GRID * GRID_WIDTH + 20 * INTERVAL - 10, "s");
		}
		if (m1 == 0) {
			sprintf_s(text, "Time:%d", t);
			outtextxy(INTERVAL, MAX_GRID * GRID_WIDTH + 20 * INTERVAL - 10, text);
			outtextxy(INTERVAL + 130, MAX_GRID * GRID_WIDTH + 20 * INTERVAL - 10, "s");
		}
		rectangle(400, 700, 450, 730);
		settextstyle(30, 0, "华文宋体");
		outtextxy(400, 700, "返回");
		rectangle(200, 700, 300, 730);
		settextstyle(30, 0, "华文宋体");
		outtextxy(200, 700, "再来一局");
		
		while (1)
		{
			ExMessage m;
			peekmessage(&m, EX_MOUSE);
			if (isInRect(&m, 400, 700, 50, 30))
			{
				if (m.message == WM_LBUTTONDOWN)
				{
					a = 0;
					break;
				}

			}
			if (isInRect(&m, 200, 700, 100, 30))
			{
				if (m.message == WM_LBUTTONDOWN)
				{

					break;
				}

			}


		}
	}
}

void Management::about()
{
	IMAGE about;
	loadimage(&about, "about.jpg");
	putimage(0, 0, &about);
	rectangle(400, 700, 450, 730);
	settextstyle(30, 0, "华文宋体");
	outtextxy(400, 700, "返回");
	while (1)
	{
		ExMessage m;
		peekmessage(&m, EX_MOUSE);
		if (isInRect(&m, 400, 700, 50, 30))
		{
			if (m.message == WM_LBUTTONDOWN)
			{
				break;
			}

		}

	}
}

void Management::close()
{
	exit(-1);
}
void Management::omusic()
{
	mciSendString("play 告白气球.mp3", 0, 0, 0);
}
void Management::cmusic()
{
	mciSendString("pause 告白气球.mp3", 0, 0, 0);
}
void Management::jieshao()
{
	IMAGE jieshao;
	loadimage(&jieshao, "jieshao.jpg");
	putimage(0, 0, &jieshao);
	rectangle(400, 700, 450, 730);
	settextstyle(30, 0, "华文宋体");
	outtextxy(400, 700, "返回");
	while (1)
	{
		ExMessage m;
		peekmessage(&m, EX_MOUSE);
		if (isInRect(&m, 400, 700, 50, 30))
		{
			if (m.message == WM_LBUTTONDOWN)
			{
				break;
			}

		}

	}
}
void Management::zuigao()
{
	IMAGE img_bk;
	loadimage(&img_bk, "photo.jpg");
	putimage(0, 0, &img_bk);
	game aa;
	
	rectangle(400, 700, 450, 730);
	settextstyle(30, 0, "华文宋体");
	outtextxy(150, 200, "历史最高分数");
	
	outtextxy(400, 700, "返回");
	string a = aa.judge();
	
	settextstyle(80, 0, "华文宋体");
	outtextxy(155, 300, a.c_str());//c_str为string转LPCTSTR
	
	while (1)
	{
		ExMessage m;
		peekmessage(&m, EX_MOUSE);
		if (isInRect(&m, 400, 700, 50, 30))
		{
			if (m.message == WM_LBUTTONDOWN)
			{
				break;
			}

		}

	}
}
//鼠标是否在方框
bool isInRect(ExMessage* mouse, int x, int y, int w, int h)
{

	if (mouse->x > x && mouse->x<x + w && mouse->y>y && mouse->y < y + h)
	{
		return true;

	}
	else return false;
}



		









void enter()
{
	initgraph(450, 800, NOCLOSE);
	IMAGE img_bk;
	loadimage(&img_bk, "photo.jpg");
	putimage(0, 0, &img_bk);
	
	settextstyle(90, 0, "华文彩云");
	outtextxy(0, 200, "2048小游戏");

	settextstyle(30, 0, "华文宋体");
	rectangle(230, 410, 285, 440);
	outtextxy(230, 410, "登录");

	rectangle(230, 450, 285, 480);
	outtextxy(230, 450, "注册");

	rectangle(230, 490, 285, 520);
	outtextxy(230, 490, "关闭");
					
	
	ExMessage m;
	while (1)
	{
		peekmessage(&m, EX_MOUSE);
		if (isInRect(&m, 225, 410, 60, 30) && m.message == WM_LBUTTONDOWN)
		{
			User u;
			Userbase* uu = &u;
	      
			
		   
		  if (uu->Login() == 1)
		   {
			   cleardevice();
			   Management m;
			   Managementbase* ptr = &m;
			   ptr->run();
		  }
			
		}
		if (isInRect(&m, 225, 450, 60, 30) && m.message == WM_LBUTTONDOWN)
		{
			User u;
			Userbase* uu = &u;
			uu->Registers();
		}
		if (isInRect(&m, 230, 490, 60, 30) && m.message == WM_LBUTTONDOWN)
		{
			exit(-1);
		}
	}
	
	
}

 
int main()
{

     
	enter();
	
	return 0;
}




