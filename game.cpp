#include "game.h"



bool isInRect(ExMessage* mouse, int x, int y, int w, int h);
enum Color {

	zero = RGB(205, 193, 180),
	two1 = RGB(238, 228, 218),
	two2 = RGB(237, 224, 200),
	two3 = RGB(242, 177, 121),
	two4 = RGB(245, 149, 99),
	two5 = RGB(246, 124, 95),
	two6 = RGB(246, 94, 59),
	two7 = RGB(242, 177, 121),
	two8 = RGB(237, 204, 97),
	two9 = RGB(255, 0, 128),
	two10 = RGB(145, 0, 72),
	two11 = RGB(242, 17, 158),
	back1 = RGB(187, 173, 160),


	zero_ = RGB(250, 255, 240),
	two1_ = RGB(255, 235, 205),
	two2_ = RGB(255, 255, 0),
	two3_ = RGB(240, 230, 140),
	two4_ = RGB(255, 128, 0),
	two5_ = RGB(255, 97, 0),
	two6_ = RGB(255, 0, 255),
	two7_ = RGB(255, 99, 71),
	two8_ = RGB(255, 69, 0),
	two9_ = RGB(255, 0, 0),
	two10_ = RGB(227, 13, 13),
	two11_ = RGB(178, 34, 34),
	back2 = RGB(255, 250, 250),


	zero__ = RGB(240, 255, 255),
	two1__ = RGB(135, 206, 235),
	two2__ = RGB(64, 224, 208),
	two3__ = RGB(0, 255, 255),
	two4__ = RGB(30, 144, 255),
	two5__ = RGB(65, 105, 225),
	two6__ = RGB(127, 255, 0),
	two7__ = RGB(0, 255, 0),
	two8__ = RGB(50, 205, 50),
	two9__ = RGB(0, 201, 87),
	two10__ = RGB(48, 128, 20),
	two11__ = RGB(3, 168, 158),
	back3 = RGB(255, 235, 205),
};
Color arr[39] = { zero,two1,two2, two3, two4, two5, two6, two7, two8, two9, two10,two11,back1,zero_,two1_,two2_, two3_, two4_, two5_, two6_, two7_, two8_, two9_, two10_,two11_,back2,zero__,two1__,two2__, two3__, two4__, two5__, two6__, two7__, two8__, two9__, two10__,two11__,back3 };
int num[12] = { 0,2,4,8,16,32,64,128,256,512,1024,2048 };
int map[MAX_GRID][MAX_GRID];
POINT pos[MAX_GRID][MAX_GRID];

static int score1;
static int size = 4;
//游戏初始界面，随机产生2或者4
int game::twoorfour() {
	if (rand() % 10 == 1) {
		return 4;
	}
	else {
		return 2;
	}

}
//随机位置，把数放在数组里面

void game::CreateNumber() {

	while (1) {
		
		int x = rand() % MAX_GRID;
		int y = rand() % MAX_GRID;
	
		if (map[x][y] == 0) {
			

			map[x][y] = twoorfour();
			break;
		}
	}
}

void game::GameInit() {
	//设置随机数种子
	srand(GetTickCount());
	for (int i = 0; i < MAX_GRID; i++)
	{
		for (int k = 0; k < MAX_GRID; k++)
		{
			pos[i][k].x = k * GRID_WIDTH + (k + 1) * INTERVAL;//左右间隔
			pos[i][k].y = i * GRID_WIDTH + (i + 1) * INTERVAL;//上下间隔
		}
	}
	
	CreateNumber();
	
	CreateNumber();
	
}
int game::getnumber(int m, int n)
{
	return map[m][n];
}
string game::judge()
{
	
	ifstream fin;
	fin.open("history.txt", ios::in);
	string buf;
		getline(fin, buf);
	
		return buf;
	fin.close();
}
int game::showstep()
{
	return step;
}
void game::born()
{
	int m, n, i, j, k, flag = 0;
	srand(time(0));
	for (m = 0; m < 4; m++)
	{
		for (n = 0; n < 4; n++)
		{
			if (map[m][n] == 0)
			{
				flag = 1;
			}
		}
	}
	if (flag == 1)
	{
		do
		{
			i = rand() % 4;
			j = rand() % 4;

		} while (map[i][j] != 0);
		k = rand() % 8;
		if (k < 7)
		{
			map[i][j] = 2;
		}
		else
		{
			map[i][j] = 4;
		}
	}
}
void game::back()
{

}

void game::up()
{
	for (int y = 0; y < 4; y++)
	{
		for (int j = 0; j < 4; j++)
		{
			for (int i = 0; i < 3; i++)
			{
				if (map[i][j] == 0)
				{
					map[i][j] = map[i + 1][j];
					map[i + 1][j] = 0;
				}
			}
		}
	}
	for (int j = 0; j < 4; j++) {

		for (int i = 0; i < 3; i++)
		{
			if (map[i][j] == map[i + 1][j])
			{
				map[i + 1][j] = 0;
				map[i][j] *= 2;
				score += map[i][j];
			}

		}
	}
	for (int y = 0; y < 4; y++)
	{
		for (int j = 0; j < 4; j++)
		{
			for (int i = 0; i < 3; i++)
			{
				if (map[i][j] == 0)
				{
					map[i][j] = map[i + 1][j];
					map[i + 1][j] = 0;
				}
			}
		}
	}
}
void game::down()
{
	for (int y = 0; y < 4; y++)
	{
		for (int j = 0; j < 4; j++)
		{
			for (int i = 3; i > 0; i--)
			{
				if (map[i][j] == 0)
				{
					map[i][j] = map[i - 1][j];
					map[i - 1][j] = 0;
				}
			}
		}
	}


	for (int j = 0; j < 4; j++) {

		for (int i = 3; i > 0; i--)
		{
			if (map[i][j] == map[i - 1][j])
			{
				map[i - 1][j] = 0;
				map[i][j] *= 2;
				score += map[i][j];
			}

		}
	}


	for (int y = 0; y < 4; y++)
	{
		for (int j = 0; j < 4; j++)
		{
			for (int i = 3; i > 0; i--)
			{
				if (map[i][j] == 0)
				{
					map[i][j] = map[i - 1][j];
					map[i - 1][j] = 0;
				}
			}
		}
	}


}
void game::left()
{
	for (int y = 0; y < 4; y++)
	{
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				if (map[i][j] == 0)
				{
					map[i][j] = map[i][j + 1];
					map[i][j + 1] = 0;
				}
			}
		}
	}
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 3; j++)

		{
			if (map[i][j] == map[i][j + 1])
			{
				map[i][j] *= 2;
				map[i][j + 1] = 0;
				score += map[i][j];

			}

		}
	}

	for (int y = 0; y < 4; y++)
	{
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				if (map[i][j] == 0)
				{
					map[i][j] = map[i][j + 1];
					map[i][j + 1] = 0;
				}
			}
		}
	}
}
void game::right()
{
	for (int y = 0; y < 4; y++)
	{
		for (int i = 0; i < 4; i++)
		{
			for (int j = 3; j > 0; j--)
			{
				if (map[i][j] == 0)
				{
					map[i][j] = map[i][j - 1];
					map[i][j - 1] = 0;
				}
			}
		}
	}
	for (int i = 0; i < 4; i++)
	{
		for (int j = 3; j > 0; j--)

		{
			if (map[i][j] == map[i][j - 1])
			{
				map[i][j] *= 2;
				map[i][j - 1] = 0;
				score += map[i][j];

			}

		}
	}

	for (int y = 0; y < 4; y++)
	{
		for (int i = 0; i < 4; i++)
		{
			for (int j = 3; j > 0; j--)
			{
				if (map[i][j] == 0)
				{
					map[i][j] = map[i][j - 1];
					map[i][j - 1] = 0;
				}
			}
		}
	}

}
void game::control(char k)
{
	
	switch (k) {
	case 'w':
		up();
		break;
	case 's':
		down();
		break;
	case 'a':
		left();
		break;
	case 'd':
		right();
		break;
	case 'q':
		break;
	//case 'b':
	//	break;
	default:
		char w;
		w = _getch();
		control(w);
		break;
	}

}
void game::print()
{
	score1 = getscore();
	settextcolor(WHITE);
	settextstyle(30, 0, "黑体");
	cleardevice();
	char text[20];
	sprintf_s(text, "Score:%d", score1);
	outtextxy(INTERVAL, MAX_GRID * GRID_WIDTH + 5 * INTERVAL - 10, text);
	sprintf_s(text, "Step:%d", step);
	outtextxy(INTERVAL, MAX_GRID * GRID_WIDTH + 10 * INTERVAL - 10, text);
	outtextxy(INTERVAL, MAX_GRID * GRID_WIDTH + 30 * INTERVAL - 10, "按Q键退出");
}
bool game::ifgameover()
{
	int k = 0;
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (map[i][j] == 0)
				return true;
			if (i > 0 && map[i][j] == map[i - 1][j])
				return true;
			if (j > 0 && map[i][j] == map[i][j - 1])
				return true;


		}
	}
	return false;
}

void game::zhixing()
{
	for (int m = 0; m < 4; m++)
	{
		for (int n = 0; n < 4; n++)
		{
			map[m][n] = 0;
		}
}
	char k;
	GameInit();
	place();
	int b[4][4];
	
	int flag = 0;
	//a.print();
	
	
		for (int m = 0; m < 4; m++)
		{
			for (int n = 0; n < 4; n++)
			{
				map[m][n] = 0;
			}
		}
		
		GameInit();
	
	
	while (ifgameover())
	{
		flag = 0;
		for (int m = 0; m < 4; m++)
		{
			for (int n = 0; n < 4; n++)
			{
				b[m][n] = map[m][n];
			}
		}
		k = _getch();
		control(k);
		if (k == 'q')
		break;
		

		for (int m = 0; m < 4; m++)
		{
			for (int n = 0; n < 4; n++)
			{
				if (b[m][n] == map[m][n])
				{
					flag += 1;
				}
			}
		}
		/*if (k == 'b') {


			for (int m = 3; m >= 0; m--)
			{
				for (int n = 3; n >= 0; n--)
				{
					map[m][n] = sta.pop();
				}
			}
			step -= 1;
			flag = 16;
		}*/
		if (flag != 16)
		{
			born();
			for (int m = 0; m < 4; m++)
			{
				for (int n = 0; n < 4; n++)
				{
					sta.push(map[m][n]);
				}
			}
		}
	


		if (flag != 16)
		{
			
			step += 1;
		}
		
		system("cls");
		print();
		place();
	}
	print();
	char jieshu[20] = { 'G','A','M','E','O','V','E','R' };
	settextcolor(RGB(255, 0, 0));//设置数字颜色
	outtextxy(INTERVAL, MAX_GRID * GRID_WIDTH + 15 * INTERVAL - 10, jieshu);
	place();
	
	
	
	
}
void game::zhixing2()
{
	for (int m = 0; m < 4; m++)
	{
		for (int n = 0; n < 4; n++)
		{
			map[m][n] = 0;
		}
	}
	game a;
	
	a.GameInit();
	int b[4][4];
	a.place2();
	int flag = 0;
	char k;
	for (int m = 0; m < 4; m++)
	{
		for (int n = 0; n < 4; n++)
		{
			map[m][n] = 0;
		}
	}

	GameInit();
	//a.print();
	while (a.ifgameover())
	{
		flag = 0;
		for (int m = 0; m < 4; m++)
		{
			for (int n = 0; n < 4; n++)
			{
				b[m][n] = map[m][n];
			}
		}
		k = _getch();
		a.control(k);
		if (k == 'q')
			break;
		for (int m = 0; m < 4; m++)
		{
			for (int n = 0; n < 4; n++)
			{
				if (b[m][n] == map[m][n])
				{
					flag += 1;
				}
			}
		}
		/*if (k == 'b') {


			for (int m = 3; m >= 0; m--)
			{
				for (int n = 3; n >= 0; n--)
				{
					map[m][n] = sta.pop();
				}
			}
			step -= 1;
			flag = 16;
		}*/


		if (flag != 16)
		{
			a.born();
			for (int m = 0; m < 4; m++)
			{
				for (int n = 0; n < 4; n++)
				{
					sta.push(map[m][n]);
				}
			}
		}


		if (flag != 16)
		{
			
			a.step += 1;
		}
		
		system("cls");
		a.print();
		a.place2();
	}
	
	
	a.print();
	char jieshu[20] = { 'G','A','M','E','O','V','E','R' };
	settextcolor(RGB(255, 0, 0));//设置数字颜色
	outtextxy(INTERVAL, MAX_GRID * GRID_WIDTH + 15 * INTERVAL - 10, jieshu);
	a.place2();
	
	
}
void game::history()
{
	int sum = 0;
	int i;
	int o;
	int buf1;
	ifstream fin;
	fin.open("history.txt", ios::in);
	char buff[10];
	fin.getline(buff, 10);
	buf1 = strlen(buff);
	for (i = buf1, o = 0; i > 0; i--, o++)
		sum += (buff[o] - 48) * pow(10, i - 1);
	if (score1 > sum)
	{
		ofstream fout;
		fout.open("history.txt");
		fout << score1;
		fout.close();
	}
	fin.close();
}
void game::place() {

	//计算格子坐标
	for (int i = 0; i < MAX_GRID; i++)
	{
		for (int k = 0; k < MAX_GRID; k++)
		{
			for (int q = 0; q < 12; q++) {
				if (map[i][k] == num[q]) {
					setfillcolor(arr[q+13*cc]);
					//solidcircle((2 * pos[i][k].x + GRID_WIDTH) / 2, (2 * pos[i][k].y + GRID_WIDTH) / 2, 55);
					solidrectangle(pos[i][k].x, pos[i][k].y, pos[i][k].x + GRID_WIDTH, pos[i][k].y + GRID_WIDTH);

					if (map[i][k] != 0)
					{
						char number[5] = " ";//字符数组，最大为2048/0

						settextcolor(RGB(119, 110, 101));//设置数字颜色
						settextstyle(50, 0, "楷体");//设置字体风格
						setbkmode(TRANSPARENT);//设置数字背景颜色是否透明
						sprintf_s(number, "%d", map[i][k]);//将数字放入字符数组
						int tempx = textwidth(number);//根据数字大小调整方格大小，获取字符串宽度
						tempx = GRID_WIDTH / 2 - tempx / 2;
						int tempy = textheight(number);//获取字符串长度
						tempy = GRID_WIDTH / 2 - tempy / 2;//文字居中
						outtextxy(pos[i][k].x + tempx, pos[i][k].y + tempy, number);//将字符串中数字打印在方格中
					}
				}
			}

		}
	}

}

void game::place2()
{
	//计算格子坐标
	
	for (int i = 0; i < MAX_GRID; i++)
	{
		for (int k = 0; k < MAX_GRID; k++)
		{
			for (int q = 0; q < 12; q++) {
				if (map[i][k] == num[q]) {
					setfillcolor(arr[q+13*cc]);

					solidcircle((2 * pos[i][k].x + GRID_WIDTH) / 2, (2 * pos[i][k].y + GRID_WIDTH) / 2, 55);

					if (map[i][k] != 0)
					{
						settextcolor(RGB(119, 110, 101));//设置数字颜色
						settextstyle(50, 0, "楷体");//设置字体风格
						setbkmode(TRANSPARENT);//设置数字背景颜色是否透明
						int tempx, tempy;
						switch (map[i][k])
						{
						case 2: tempx = textwidth("夏");//根据数字大小调整方格大小，获取字符串宽度
							tempx = GRID_WIDTH / 2 - tempx / 2;
							tempy = textheight("夏");//获取字符串长度
							tempy = GRID_WIDTH / 2 - tempy / 2;//文字居中
							outtextxy(pos[i][k].x + tempx, pos[i][k].y + tempy, "夏");//将字符串中数字打印在方格中
							break;
						case 4: tempx = textwidth("商");//根据数字大小调整方格大小，获取字符串宽度
							tempx = GRID_WIDTH / 2 - tempx / 2;
							tempy = textheight("商");//获取字符串长度
							tempy = GRID_WIDTH / 2 - tempy / 2;//文字居中
							outtextxy(pos[i][k].x + tempx, pos[i][k].y + tempy, "商");//将字符串中数字打印在方格中
							break;
						case 8: tempx = textwidth("周");//根据数字大小调整方格大小，获取字符串宽度
							tempx = GRID_WIDTH / 2 - tempx / 2;
							tempy = textheight("周");//获取字符串长度
							tempy = GRID_WIDTH / 2 - tempy / 2;//文字居中
							outtextxy(pos[i][k].x + tempx, pos[i][k].y + tempy, "周");//将字符串中数字打印在方格中
							break;
						case 16: tempx = textwidth("春秋");//根据数字大小调整方格大小，获取字符串宽度
							tempx = GRID_WIDTH / 2 - tempx / 2;
							tempy = textheight("春秋");//获取字符串长度
							tempy = GRID_WIDTH / 2 - tempy / 2;//文字居中
							outtextxy(pos[i][k].x + tempx, pos[i][k].y + tempy, "春秋");//将字符串中数字打印在方格中
							break;
						case 32: tempx = textwidth("战国");//根据数字大小调整方格大小，获取字符串宽度
							tempx = GRID_WIDTH / 2 - tempx / 2;
							tempy = textheight("战国");//获取字符串长度
							tempy = GRID_WIDTH / 2 - tempy / 2;//文字居中
							outtextxy(pos[i][k].x + tempx, pos[i][k].y + tempy, "战国");//将字符串中数字打印在方格中
							break;
						case 64: tempx = textwidth("秦");//根据数字大小调整方格大小，获取字符串宽度
							tempx = GRID_WIDTH / 2 - tempx / 2;
							tempy = textheight("秦");//获取字符串长度
							tempy = GRID_WIDTH / 2 - tempy / 2;//文字居中
							outtextxy(pos[i][k].x + tempx, pos[i][k].y + tempy, "秦");//将字符串中数字打印在方格中
							break;
						case 128: tempx = textwidth("汉");//根据数字大小调整方格大小，获取字符串宽度
							tempx = GRID_WIDTH / 2 - tempx / 2;
							tempy = textheight("汉");//获取字符串长度
							tempy = GRID_WIDTH / 2 - tempy / 2;//文字居中
							outtextxy(pos[i][k].x + tempx, pos[i][k].y + tempy, "汉");//将字符串中数字打印在方格中
							break;
						case 256: tempx = textwidth("三国");//根据数字大小调整方格大小，获取字符串宽度
							tempx = GRID_WIDTH / 2 - tempx / 2;
							tempy = textheight("三国");//获取字符串长度
							tempy = GRID_WIDTH / 2 - tempy / 2;//文字居中
							outtextxy(pos[i][k].x + tempx, pos[i][k].y + tempy, "三国");//将字符串中数字打印在方格中
							break;
						case 512: tempx = textwidth("晋");//根据数字大小调整方格大小，获取字符串宽度
							tempx = GRID_WIDTH / 2 - tempx / 2;
							tempy = textheight("晋");//获取字符串长度
							tempy = GRID_WIDTH / 2 - tempy / 2;//文字居中
							outtextxy(pos[i][k].x + tempx, pos[i][k].y + tempy, "晋");//将字符串中数字打印在方格中
							break;
						case 1024: tempx = textwidth("南北朝");//根据数字大小调整方格大小，获取字符串宽度
							tempx = GRID_WIDTH / 2 - tempx / 2;
							tempy = textheight("南北朝");//获取字符串长度
							tempy = GRID_WIDTH / 2 - tempy / 2;//文字居中
							outtextxy(pos[i][k].x + tempx, pos[i][k].y + tempy, "南北朝");//将字符串中数字打印在方格中
							break;
						case 2048: tempx = textwidth("隋唐");//根据数字大小调整方格大小，获取字符串宽度
							tempx = GRID_WIDTH / 2 - tempx / 2;
							tempy = textheight("隋唐");//获取字符串长度
							tempy = GRID_WIDTH / 2 - tempy / 2;//文字居中
							outtextxy(pos[i][k].x + tempx, pos[i][k].y + tempy, "隋唐");//将字符串中数字打印在方格中
							break;
						}

					}
				}
			}

		}
	}


}


