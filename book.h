#pragma once
//author:���S version:1.0 time:12/18/20
#include<iostream>
#include<string>


using namespace std;

/*@��book����Ķ���
//����
@ name			 ���� 
@ borrow_people  ������
@ borrow_time    ����ʱ��
@ borrow_days    ����ʱ��
//����
@ book_init() ������Ŀ
@ book_display() ͼ����Ϣ��ʾ
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