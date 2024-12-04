#pragma once
#include <string>
#include<iostream>
#include <fstream>
#include <string>
#include <conio.h>
#include <iostream>
#include <string>
#include <regex>
#include<windows.h>
#include <easyx.h>

#define SIZE 100//最大用户容量

using namespace std;

void enter();
class Userbase
{
public:

	virtual void Registers()=0;//注册
	virtual int Login()=0;//登录
	
};
class User:virtual public Userbase
{
private:
	string email;//邮箱
	string password;//密码
public:
	User() {};
	
	bool CheckEmail( char* ph);		//邮箱验证
	void Registers();//注册
	int Login();//登录
	void save();//保存
	void read();//读取
	
};
User user[SIZE];
