#include "User.h"
#include <windows.h>
#include <cstdlib>
#include <conio.h>
#include <cstring>
#include <mmsystem.h>
#include <string>
#include <fstream>
#pragma comment(lib,"winmm.lib")       
static int scount = 0;//�������浱ǰ��ע���û���



bool User::CheckEmail(char* ph)
{
	
	return regex_match(ph, regex("^\\w+([-+.]\\w+)*@\\w+([-.]\\w+)*\\.\\w+([-.]\\w+)*$"));//�ж��˻���ʽ�Ƿ�Ϊ���䣬��ֹ�Ƿ�����
}

void User::Registers()
{
	read();//��ȡ�Ѵ����û�����
	char ph[64];//����
	//string pw1;//����1
	//string pw2;//����2
	for (int i = scount; i < SIZE; i++)
	{
	                                                                                                                                                                                   here:
		
		

		InputBox(ph, 20, "������������");
		if (ph[0] == '\0')break;//���˳����ز˵�����ռ���
		while (CheckEmail(ph) == 0)
		{
			
			InputBox(ph, 20, "������Ϸ�������");
			if (ph[0] == '\0')break;
		}
		if (ph[0] == '\0')break;
		//�ж���������û���Ϣ�Ƿ��Ѵ��ڣ�����Ѵ������������룩
		for (int i = 0; i < scount; i++)
		{
			if (ph == user[i].email)
			{
				
				HWND SignError = GetHWnd();                                       //�����ʾ��
				int isok = MessageBox(SignError, "�������Ѵ��ڣ�", "��ʾ", MB_OK);//
				                                                                                                                                                                              goto here;
			}
		}
		user[i].email = ph;

		
		
		

		
		char pword[64];
		char pword1[64];
	
		int x = 0;
		
		
		int x1 = 0;
		
		
		
			
			InputBox(pword, 20, "����������");
			if (pword[0] == '\0')break;
			user[i].password = pword;
			
			InputBox(pword, 20, "���ٴ���������");
			if (pword[0] == '\0')break;
			if (strcmp(user[i].password.data(), pword1) == 0)
			{
				
				
				HWND SignError = GetHWnd();
				int isok = MessageBox(SignError, "���벻һ�£�", "��ʾ", MB_OK);
				                                                                                                                                                                                             goto here;
			}
			else
			{
				scount++;//��ע���û���1
				
				HWND SignError = GetHWnd();
				int isok = MessageBox(SignError, "ע��ɹ���", "��ʾ", MB_OK);
				save();//�����û�����
			}
			
		
		
		
		
		
			break;
		
	}
	
	
}

int User::Login()
{

	
	read();//��ȡ�Ѵ����û�����
		//string ph;//����
		//string pw;//����
	int time = 0;//ͳ�ƱȽϴ���
	while (1)
	{
		
		char ph[64];
		
		InputBox(ph, 20, "�������û���");
		if (ph[0] == '\0')break;

		while (CheckEmail(ph) == 0)
		{
			
			

			InputBox(ph, 20, "������Ϸ��û���");
			if (ph[0] == '\0')break;
		}
		
		if (ph[0] == '\0')break;
		

		

		char pword[64];
		
		char ch, passwords0[20];
		int x = 0;
		
		
			
			InputBox(pword, 20, "����������");
			if (ph[0] == '\0')break;
			for (int i = 0; i < scount; i++)
			{
				if (ph == user[i].email && pword == user[i].password)
				{
					time++;
					
					
					HWND SignError = GetHWnd();
					int isok = MessageBox(SignError, "��¼�ɹ���", "��ʾ", MB_OK);
					return 1;
					//break;
				}
			}
			if (time == 0)
			{
				HWND SignError = GetHWnd();
				int isok = MessageBox(SignError, "�û������������!", "��ʾ", MB_OK);
				
				
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
		//cout << "�ļ���ʧ�ܣ�" << endl;
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





