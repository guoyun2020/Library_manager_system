#include"user.h"



void user::user_register() {
	cout << "----用户注册----" << endl;
	cout << "请设置：用户名  密码  用户类型 (读者:0/图书管理员:1/系统管理员:2)" << endl;
	cin >> user_name >> code >> user_class;

}

void user::user_register(int a) {
	cout << "----用户注册----" << endl;
	cout << "请设置：用户名  密码" << endl;
	cin >> user_name >> code;
	user_class = a;

}

void user::user_change() {
	cout << "----修改信息----" << endl;
	cout << "请修改：用户名  密码  用户类型（读者:0/图书管理员:1/系统管理员:2）:" << endl;
	cin >> user_name >> code >> user_class;
}

void user::log_out() {

}

void reader::borrow_book(book&a) {
	if (can_borrow) {
		a.borrow_people = user_name;
		a.borrowed = true;
		a.borrow_time = set_borrow_time();
		a.borrow_days = 30;
		borrowed_books[book_num] = a;
		book_num++;

		string info[3];
		string book_name = "D:\\borrowed_book_Info\\" + a.name+".txt";
		ofstream outfile(book_name, ios::out);
		
		info[0]= a.borrow_people;
		outfile << "借阅人：" <<info[0] << "   ";
		char* s = a.borrow_time;
		outfile << "借阅时间：" << s ;
		info[1] = to_string(a.borrow_days);
		outfile << "借阅时长：" << info[1] << "天";
		outfile.close();
		cout << "借阅成功！" << endl;
	}
	else {
		cout << "该用户没有借阅权限！" << endl;
	}
}

char* reader::set_borrow_time() {
	// 基于当前系统的当前日期/时间
	time_t now = time(0);
	// 把 now 转换为字符串形式
	char* dt = ctime(&now);
	return dt;
}

void reader::return_book(book&a) {
	a.borrowed = false;
	
}

void reader::review_book() {
	for (int i = 0; i < book_num; ++i) {
		cout << "书籍编号:" << i << endl;
		borrowed_books[i].book_display(borrowed_books[i]);
	}
}

void book_manager::add_book(book&a) {
	if (can_manage) { a.book_init(); }
	else { cout << "没有管理权限！" << endl; }
}

void book_manager::remove_book(book&a) {
	if (can_manage) {
		a.borrowed = false;
		a.name = "该书目已被清除";
	}
	else {
		cout << "没有管理权限！" << endl;
	}
}

void book_manager::change_book(book&a) {
	if (can_manage) {
		cout << "请输入修改后的：书名  借阅状态（0为未借出/1为借出）" << endl;
		cin >> a.name >> a.borrowed;
		cout << "书目修改完成！" << endl;
	}
	else {
		cout << "没有管理权限！" << endl;
	}
}

void book_manager::book_statistic() {

};

void book_manager::check_details(book&a) {
	if (can_manage) {
		a.book_display(a);
	}
	else {
		cout << "没有管理权限！" << endl;
	}
}

void system_manager::add_reader(reader&a){
	a.user_register(0);
}

void system_manager::remove_reader(reader&a) {
	vector<book> null(10);
	a.user_name = "该用户已被删除";
	a.code = "无";
	a.user_class = -1;
	a.borrowed_books = null;
	a.can_borrow = false;
}

void system_manager::add_book_manager(book_manager&a) {
	a.user_register(1);
}

void system_manager::remove_book_manager(book_manager&a) {
	a.user_name = "该用户已被删除";
	a.code = "无";
	a.user_class = -1;
	a.can_manage = false;
}

void system_manager::change_reader_ability(user&a,bool b) {
	a.can_borrow = b;
};

void system_manager::change_manager_ability(user&a, bool b) {
	a.can_manage = b;
};

