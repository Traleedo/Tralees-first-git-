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

#define SIZE 100//����û�����

using namespace std;

void enter();
class Userbase
{
public:

	virtual void Registers()=0;//ע��
	virtual int Login()=0;//��¼
	
};
class User:virtual public Userbase
{
private:
	string email;//����
	string password;//����
public:
	User() {};
	
	bool CheckEmail( char* ph);		//������֤
	void Registers();//ע��
	int Login();//��¼
	void save();//����
	void read();//��ȡ
	
};
User user[SIZE];
