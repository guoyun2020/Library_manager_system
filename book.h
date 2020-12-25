#pragma once
//author:郭赟 version:1.0 time:12/18/20
#include<iostream>
#include<string>


using namespace std;

/*@对book基类的定义
//参数
@ name			 书名 
@ borrow_people  借阅人
@ borrow_time    借阅时间
@ borrow_days    借阅时长
//函数
@ book_init() 增加书目
@ book_display() 图书信息显示
*/
class book {
public:
	void book_init();
	void book_init(string a, bool b) {
		name = a; borrowed = b;
	};
	friend ostream& operator << (ostream& output, book &b);
	void book_display(book&);
	
	string borrow_people;
	string name;
	bool borrowed;
	char* borrow_time;
	int borrow_days;
};