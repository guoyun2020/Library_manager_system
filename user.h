#pragma once
//author:郭赟 version:1.0 time:12/18/20

#include"book.h"
#include<ctime>
#include<string>
#include<vector>
#include<fstream>

/*@对user基类的定义
//参数
@ user_name	 用户名
@ user_class 用户类型
@ code		 密码
//函数
@ user_register() 用户注册
@ user_change()  修改用户信息
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

/*@对派生类reader（读者）的定义
//参数
@ can_borrow  借阅权限
//函数
@ borrow_book() 借书
@ return_book() 还书
@ review_book() 已借书目查询
@ set_borrow_time() 设定借阅时间与时长
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

/*@对派生类book_manager（图书管理员）的定义
//参数
@ can_manage 管理权限
//函数
@ add_book() 增加书目
@ remove_book() 删除书目
@ change_book() 修改书目
@ book_statistic() 书目统计
@ check_details() 查看信息
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

/*@对派生类system_manager（系统管理员）的定义
//参数
@ ...
@ ...
//函数
@ add_reader() 增加读者
@ remove_reader() 删除读者
@ add_book_manager() 增加图书管理员
@ remove_book_manager() 减少图书管理员
@ change_ability() 修改权限（读者）
@ change_ability() 修改权限（图书管理员）
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

