#pragma once
#include<stdlib.h>
#include<iostream>
#include<conio.h>
#include<time.h>
#include<windows.h>
#define MAX_GRID 4
#define GRID_WIDTH 100
#define INTERVAL 10
#include <graphics.h>
#include<fstream>
#include<math.h>
#include<string>
using namespace std;
template<class T>class Stack
{
private:
	struct Node
	{
		T data;
		Node* next;
	};
	Node* head;
	Node* p;
	int length;

public:
	Stack()
	{
		head = NULL;
		length = 0;
	}
	void push(T n)//入栈
	{
		Node* q = new Node;
		q->data = n;
		if (head == NULL)
		{
			q->next = head;
			head = q;
			p = q;
		}
		else
		{
			q->next = p;
			p = q;
		}
		length++;
	}

	T pop()//出栈并且将出栈的元素返回
	{
		if (length <= 0)
		{
			abort();
		}
		Node* q;
		T data;
		q = p;
		data = p->data;
		p = p->next;
		delete(q);
		length--;
		return data;
	}
	int size()//返回元素个数
	{
		return length;
	}
	T top()//返回栈顶元素
	{
		return p->data;
	}
	bool isEmpty()//判断栈是不是空的
	{
		if (length == 0)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	void clear()//清空栈中的所有元素
	{
		while (length > 0)
		{
			pop();
		}
	}
};
class gamebase 
{
public:

	virtual void up()=0;
	virtual void down()=0;
	virtual void right()=0;
	virtual void left()=0;
	virtual bool ifgameover()=0;
	virtual void place()=0;


};
class  game:virtual public gamebase
{
public:
	int getscore()
	{
		return score;
	}
	int twoorfour();
	void CreateNumber();
	void GameInit();
	void control(char k);
	void up();
	void down();
	void right();
	void left();
	bool ifgameover();
	void place();
	void place2();
	void zhixing();
	void zhixing2();
	void born();
	int showstep();
	void back();
	void history();
	string judge();
	void print();

	int getnumber(int a, int b);
	~game() {
		cc = 0;
		step = 0;
		score = 0;
	
	}
	game()
	{
		cc = 0;
		step = 0;
		score = 0;
	}
	int cc;
private:
	Stack<int> sta;
	int step;
	int score;
};
