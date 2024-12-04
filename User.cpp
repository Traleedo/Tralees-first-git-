#include "User.h"
#include <windows.h>
#include <cstdlib>
#include <conio.h>
#include <cstring>
#include <mmsystem.h>
#include <string>
#include <fstream>
#pragma comment(lib,"winmm.lib")       
static int scount = 0;//用作储存当前已注册用户数



bool User::CheckEmail(char* ph)
{
	
	return regex_match(ph, regex("^\\w+([-+.]\\w+)*@\\w+([-.]\\w+)*\\.\\w+([-.]\\w+)*$"));//判断账户格式是否为邮箱，防止非法输入
}

void User::Registers()
{
	read();//读取已储存用户数据
	char ph[64];//邮箱
	//string pw1;//密码1
	//string pw2;//密码2
	for (int i = scount; i < SIZE; i++)
	{
	                                                                                                                                                                                   here:
		
		

		InputBox(ph, 20, "请输入邮箱名");
		if (ph[0] == '\0')break;//想退出返回菜单输入空即可
		while (CheckEmail(ph) == 0)
		{
			
			InputBox(ph, 20, "请输入合法邮箱名");
			if (ph[0] == '\0')break;
		}
		if (ph[0] == '\0')break;
		//判断新输入的用户信息是否已存在（如果已存在则重新输入）
		for (int i = 0; i < scount; i++)
		{
			if (ph == user[i].email)
			{
				
				HWND SignError = GetHWnd();                                       //输出提示框
				int isok = MessageBox(SignError, "邮箱名已存在！", "提示", MB_OK);//
				                                                                                                                                                                              goto here;
			}
		}
		user[i].email = ph;

		
		
		

		
		char pword[64];
		char pword1[64];
	
		int x = 0;
		
		
		int x1 = 0;
		
		
		
			
			InputBox(pword, 20, "请输入密码");
			if (pword[0] == '\0')break;
			user[i].password = pword;
			
			InputBox(pword, 20, "请再次输入密码");
			if (pword[0] == '\0')break;
			if (strcmp(user[i].password.data(), pword1) == 0)
			{
				
				
				HWND SignError = GetHWnd();
				int isok = MessageBox(SignError, "密码不一致！", "提示", MB_OK);
				                                                                                                                                                                                             goto here;
			}
			else
			{
				scount++;//已注册用户加1
				
				HWND SignError = GetHWnd();
				int isok = MessageBox(SignError, "注册成功！", "提示", MB_OK);
				save();//保存用户数据
			}
			
		
		
		
		
		
			break;
		
	}
	
	
}

int User::Login()
{

	
	read();//读取已储存用户数据
		//string ph;//邮箱
		//string pw;//密码
	int time = 0;//统计比较次数
	while (1)
	{
		
		char ph[64];
		
		InputBox(ph, 20, "请输入用户名");
		if (ph[0] == '\0')break;

		while (CheckEmail(ph) == 0)
		{
			
			

			InputBox(ph, 20, "请输入合法用户名");
			if (ph[0] == '\0')break;
		}
		
		if (ph[0] == '\0')break;
		

		

		char pword[64];
		
		char ch, passwords0[20];
		int x = 0;
		
		
			
			InputBox(pword, 20, "请输入密码");
			if (ph[0] == '\0')break;
			for (int i = 0; i < scount; i++)
			{
				if (ph == user[i].email && pword == user[i].password)
				{
					time++;
					
					
					HWND SignError = GetHWnd();
					int isok = MessageBox(SignError, "登录成功！", "提示", MB_OK);
					return 1;
					//break;
				}
			}
			if (time == 0)
			{
				HWND SignError = GetHWnd();
				int isok = MessageBox(SignError, "用户名或密码错误!", "提示", MB_OK);
				
				
				return 2;
				break;
			}
			
		
			
			
		
		break;
	}
	

	
}

void User::save()
{
	ofstream ofile;
	ofile.open("user.txt", ios::out);

	for (int i = 0; i < scount; i++)
	{
		ofile << user[i].email << endl;
		ofile << user[i].password << endl;
	}
	ofile.close();
}

void User::read()
{
	ifstream ifile;
	ifile.open("user.txt", ios::in);

	scount = 0;

	if (!ifile.is_open())
	{
		//cout << "文件打开失败！" << endl;
		return;
	}

	for (int i = 0; !ifile.eof(); i++)
	{
		ifile >> user[i].email;
		ifile >> user[i].password;
		scount++;
	}
	scount--;
	ifile.close();
	
}





