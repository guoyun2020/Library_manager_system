#pragma once
//author:���S version:1.0 time:12/18/20

#include"book.h"
#include<ctime>
#include<string>
#include<vector>
#include<fstream>

/*@��user����Ķ���
//����
@ user_name	 �û���
@ user_class �û�����
@ code		 ����
//����
@ user_register() �û�ע��
@ user_change()  �޸��û���Ϣ
*/
class user {
public:
	void user_register();
	void user_register(int);
	void user_change();
	void log_out();
	int user_class;
	bool can_borrow;
	bool can_manage;
	string user_name;
	string code;
	
};

/*@��������reader�����ߣ��Ķ���
//����
@ can_borrow  ����Ȩ��
//����
@ borrow_book() ����
@ return_book() ����
@ review_book() �ѽ���Ŀ��ѯ
@ set_borrow_time() �趨����ʱ����ʱ��
*/
class reader :public user {
public:
	reader() { book_num = 0; borrowed_books.resize(10); can_borrow = true; };
	void borrow_book(book&);
	void return_book(book&);
	void review_book();
	char* set_borrow_time();

	vector<book> borrowed_books;
	int book_num;

};

/*@��������book_manager��ͼ�����Ա���Ķ���
//����
@ can_manage ����Ȩ��
//����
@ add_book() ������Ŀ
@ remove_book() ɾ����Ŀ
@ change_book() �޸���Ŀ
@ book_statistic() ��Ŀͳ��
@ check_details() �鿴��Ϣ
*/
class book_manager :public user {
public:
	book_manager() { can_manage = true; };
	void add_book(book&);
	void remove_book(book&);
	void change_book(book&);
	void book_statistic();
	void check_details(book&);
	
};

/*@��������system_manager��ϵͳ����Ա���Ķ���
//����
@ ...
@ ...
//����
@ add_reader() ���Ӷ���
@ remove_reader() ɾ������
@ add_book_manager() ����ͼ�����Ա
@ remove_book_manager() ����ͼ�����Ա
@ change_ability() �޸�Ȩ�ޣ����ߣ�
@ change_ability() �޸�Ȩ�ޣ�ͼ�����Ա��
*/
class system_manager :public user {
public:
	void add_reader(reader&);
	void remove_reader(reader&);
	void add_book_manager(book_manager&);
	void remove_book_manager(book_manager&);
	void change_reader_ability(user& ,bool );
	void change_manager_ability(user&, bool);
	
};

