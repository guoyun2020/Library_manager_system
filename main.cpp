//author:郭赟 version:1.0 time:12/18/20

#include"book.h"
#include"user.h"
#include <stdlib.h>
#include<stdio.h>
#include <io.h>

//建立图书馆容器
vector<book> book_list(10);
int list_num = 4;
//建立用户库容器
vector<user> user_list(10);
int user_num = 0; 

void Title() {
	system("CLS");
	cout << "				*****************************************" << endl;
	cout << "				*             图书馆管理系统            *" << endl;
	cout << "				* author:郭赟 version:1.5 time:12/20/20 *" << endl;
	cout << "				*           版权所有，禁止抄袭！        *" << endl;
	cout << "				*****************************************" << endl;
	cout << " " << endl;
}

void user_menu(user&a) {
	if (a.user_class == 0) {//读者菜单
		bool log_in=true;
		reader r1;
		r1.user_name = a.user_name;
		r1.code = a.code;
		r1.user_class = a.user_class;
		r1.can_borrow = a.can_borrow;
		while (log_in) {
			Title();
			cout << "----读者菜单----" << endl;
			cout << "1.图书借阅" << endl;
			cout << "2.图书归还" << endl;
			cout << "3.已借书目查询" << endl;
			cout << "4.退出账号" << endl;
			int option2;
			cin >> option2;

			//图书借阅
			if (r1.can_borrow) {
				while (option2 == 1) {
					Title();
					for (int i = 0; i < list_num; i++) {
						cout << "书籍编号:" << i << endl;
						book_list[i].book_display(book_list[i]);
					}
					int borrow_num, book_id1;
					cout << "请输入借阅书籍的数量:" << endl;
					cin >> borrow_num;
					cout << "请输入借阅书籍的序号（每输入一个号码按Enter键确认）:" << endl;
					for (int j = 0; j < borrow_num; j++) {
						cin >> book_id1;
						r1.borrow_book(book_list[book_id1]);
					}
					break;
				}
			}
			else {
				Title();
				cout << "无借阅权限！" << endl;
				system("pause");
			}

			//图书归还
			while (option2 == 2) {
				Title();
				r1.review_book();
				int return_num, book_id2;
				cout << "请输入归还书籍的数量:" << endl;
				cin >> return_num;
				for (int j = 0; j < return_num; j++) {
					Title();
					r1.review_book();
					cout << "请输入归还书籍的序号（每输入一个号码按Enter键确认）:" << endl;
					cin >> book_id2;
					for (int m = 0; m < list_num; m++) {
						if (book_list[m].name == r1.borrowed_books[book_id2].name) {
							r1.return_book(book_list[m]);
							break;
						}
						else continue;
					}
					r1.borrowed_books.erase(r1.borrowed_books.begin() + book_id2);
					cout << "归还成功" << endl;
					r1.book_num--;	
				}
				break;
			}

			//已借书目查询
			while (option2 == 3) {
				Title();
				r1.review_book();
				system("pause");
				break;
			}
			//用户退出
			while (option2 == 4) {
				Title();
				log_in=false;
				break;
			}
			//输入异常
			while (option2 != 1 && option2 != 2 && option2 != 3 && option2 != 4) {
				Title();
				cout << "输入有误，请重新输入！" << endl;
				system("pause");
				break;
			}
		}
	}
	else if (a.user_class == 1) {//图书管理员菜单
		bool log_in = true;
		book_manager b1;
		b1.user_name = a.user_name;
		b1.code = a.code;
		b1.user_class = a.user_class;
		b1.can_manage = a.can_manage;
		while (log_in) {
			Title();
			cout << "----图书管理员菜单----" << endl;
			cout << "1.增加图书" << endl;
			cout << "2.删除图书" << endl;
			cout << "3.更改图书信息" << endl;
			cout << "4.查看图书状态" << endl;
			cout << "5.退出账号" << endl;
			int option3;
			cin >> option3;

			//增加图书
			while (option3 == 1 && b1.can_manage) {
				Title();
				string new_name;
				cout << "请输入书名：" << endl;
				cin >> new_name;
				book new_book;
				new_book.book_init(new_name, 0);
				book_list[list_num] = new_book;
				cout << book_list[list_num] << endl;
				list_num++;
				cout << "添加成功" << endl;
				system("pause");
				break;
			}

			//删除图书
			while (option3 == 2 && b1.can_manage) {
				Title();
				for (int k = 0; k < list_num; k++) {
					cout << "书籍编号:" << k << endl;
					book_list[k].book_display(book_list[k]);
				}
				int remove_num, book_id3;
				cout << "请输入删除书籍的数量:" << endl;
				cin >> remove_num;
				for (int j = 0; j < remove_num; j++) {
					Title();
					for (int k = 0; k < list_num; k++) {
						cout << "书籍编号:" << k << endl;
						book_list[k].book_display(book_list[k]);
					}
					cout << "请输入删除书籍的序号（每输入一个号码按Enter键确认）:" << endl;
					cin >> book_id3;
					book_list.erase(book_list.begin() + book_id3);
					list_num--;
					cout << "删除成功！" << endl;
					system("pause");
				}
				break;
			}

			//更改图书信息
			while (option3 == 3 && b1.can_manage) {
				Title();
				for (int k = 0; k < list_num; k++) {
					cout << "书籍编号:" << k << endl;
					book_list[k].book_display(book_list[k]);
				}
				int book_id4;
				cout << "请输入待修改书籍的序号:" << endl;
				cin >> book_id4;
				b1.change_book(book_list[book_id4]);
				cout << book_list[book_id4] << endl;
				system("pause");
				break;
			}

			//查看图书状态
			while (option3 == 4 && b1.can_manage) {
				Title();
				for (int d = 0; d < list_num; d++) {
					cout << "书籍编号:" << d << endl;
					b1.check_details(book_list[d]);
				}
				system("pause");
				break;

			}

			//用户退出
			while (option3 == 5) {
				Title();
				log_in = false;
				break;
			}
			//输入异常
			while ((option3 != 1 && option3 != 2 && option3 != 3 && option3 != 4 && option3 != 5)|| !b1.can_manage) {
				Title();
				cout << "输入有误或无管理权限！" << endl;
				system("pause");
				break;
			}
		}
	}
	else {//系统管理员菜单
		bool log_in = true;
		system_manager s1;
		s1.user_name = a.user_name;
		s1.code = a.code;
		s1.user_class = a.user_class;
		while (log_in) {
			Title();
			cout << "----系统管理员菜单----" << endl;
			cout << "1.增加用户" << endl;
			cout << "2.删除用户" << endl;
			cout << "3.查看成员列表" << endl;
			cout << "4.修改成员权限" << endl;
			cout << "5.用户退出" << endl;
			int option4;
			cin >> option4;

			//增加用户
			while (option4 == 1) {
				Title();
				int title;
				cout << "请选择用户类型：0为读者/1为图书管理员" << endl;
				cin >> title;
				if (!title) {//增加读者
					Title();
					reader new_reader;
					s1.add_reader(new_reader);
					user_list[user_num] = new_reader;
					cout << "新读者姓名：" << new_reader.user_name << " " << "权限设置（1为可借阅/0为不可借阅）:" << new_reader.can_borrow << endl;
					user_num++;
				}
				else {//增加图书管理员
					Title();
					book_manager new_manager;
					s1.add_book_manager(new_manager);
					user_list[user_num] = new_manager;
					cout << "新图书管理员姓名：" << new_manager.user_name << " " << "权限设置（1为可管理/0为不可管理）:" << new_manager.can_manage << endl;
					user_num++;
				}
				break;
			}

			//删除成员
			while (option4 == 2) {
				Title();
				for (int q = 0; q < user_num; q++) {
					cout << "用户序号:" << q << endl;
					cout << "姓名：" << user_list[q].user_name << "  "<<"用户类别:"<< user_list[q].user_class << "  (读者:0/图书管理员:1/系统管理员:2)" << endl;
				}
				int remove_num, user_id;
				cout << "请输入删除成员的数量:" << endl;
				cin >> remove_num;
				for (int f = 0; f < remove_num; f++) {
					Title();
					cout << "请输入删除成员的序号（每输入一个号码按Enter键确认）:" << endl;
					cin >> user_id;
					user_list.erase(user_list.begin() + user_id);
					user_num--;
					cout << "删除成功！" << endl;
					for (int q = 0; q < user_num; q++) {
						cout << "用户序号:" << q << endl;
						cout << "姓名：" << user_list[q].user_name << "  " << "用户类别:" << user_list[q].user_class << endl;
					}
				}
				break;
			}

			//查看成员列表
			while (option4 == 3) {
				Title();
				for (int q = 0; q < user_num; q++) {
					cout << "用户序号:" << q << endl;
					cout << "姓名：" << user_list[q].user_name << "  " << "用户类别:" << user_list[q].user_class << "  (读者:0/图书管理员:1/系统管理员:2)" << endl;
				}
				system("pause");
				break;
			}

			//修改成员权限
			while (option4 == 4) {
				Title();
				for (int q = 0; q < user_num; q++) {
					cout << "用户序号:" << q << endl;
					cout << "姓名：" << user_list[q].user_name << "  " << "用户类别:" << user_list[q].user_class << "  (读者:0/图书管理员:1/系统管理员:2)" << endl;
				}
				cout << "请选择需要修改权限的用户的序号：" << endl;
				int choose;
				cin >> choose;
				if (user_list[choose].user_class == 0) {//修改读者借阅权限
					Title();
					cout << "请选择赋予或取消该读者的借阅权限：（0为取消/1为赋予）" << endl;
					int right1;
					cin >> right1;
					if (right1 == 0 || right1 == 1) {
						s1.change_reader_ability(user_list[choose], right1);
						cout << "读者权限修改成功！" << endl;
					}
					else {
						cout << "输入有误!" << endl;
					}
				}
				else if (user_list[choose].user_class == 1) {//修改图书管理员管理权限
					Title();
					cout << "请选择赋予或取消该图书管理员的管理权限：（0为取消/1为赋予）" << endl;
					int right2;
					cin >> right2;
					if (right2 == 0 || right2 == 1) {
						s1.change_manager_ability(user_list[choose], right2);
						cout << "管理员权限修改成功！" << endl;
					}
					else {
						cout << "输入有误!" << endl;
						system("pause");
					}
				}
				else {
					cout << "无法修改自身权限或输入有误！" << endl;
					system("pause");
				}
				break;
			}

			//用户退出
			while (option4 == 5) {
				Title();
				log_in = false;
				break;
			}
			//输入异常
			while (option4 != 1 && option4 != 2 && option4 != 3 && option4 != 4 && option4 != 5) {
				Title();
				cout << "输入有误，请重新输入！" << endl;
				system("pause");
				break;
			}
		}
	}
}


int main() {
	//建立书库
	book b0, b1, b2, b3;
	b0.book_init("《三国演义》", 0);
	b1.book_init("《水浒传》", 0);
	b2.book_init("《红楼梦》", 0);
	b3.book_init("《西游记》", 0);
	book_list[0] = b0;
	book_list[1] = b1;
	book_list[2] = b2;
	book_list[3] = b3;

	//读取用户数据库

	//目标文件夹路径
	std::string inPath = "D:\\user\\*.txt";
	//用于查找的句柄
	intptr_t  handle;
	struct _finddata_t fileinfo;
	//第一次查找
	handle = _findfirst(inPath.c_str(), &fileinfo);
	if (handle == -1)
		return -1;
	
	while (!_findnext(handle, &fileinfo))
	{
		//找到的文件的文件名
		//printf("%s\n", fileinfo.name);
		string path = "D:/user/";
		path.append(fileinfo.name);
		ifstream infile(path, ios::out);
		string data[3];
		infile >> data[0];
		user_list[user_num].user_name = data[0];
		infile >> data[1];
		user_list[user_num].code = data[1];
		infile >> data[2];
		user_list[user_num].user_class = atoi(data[2].c_str());
		user_list[user_num].can_borrow = true;
		user_list[user_num].can_manage = true;

		user_num++;
	}
	_findclose(handle);

	user u1;
	//主菜单
	while (true) {
		Title();
		cout << "----主菜单----" << endl;
		cout << "1.用户注册" << endl;
		cout << "2.用户登录" << endl;
		cout << "3.退出系统" << endl;
		int option1;
		cin >> option1;
		while (option1==1||option1==2){
			if (option1 == 1) {
				Title();
				u1.user_register();
				user_list[user_num]=u1;
				string head;
				head = "D:\\user\\user" + to_string(user_num)+".txt";

				ofstream user_info(head, ios::out | ios::out | ios::binary);
				string save_user[3];
				save_user[0] = u1.user_name;
				save_user[1] = u1.code;
				save_user[2] = to_string(u1.user_class);
				for (int i = 0; i < 3; i++) {
					user_info << save_user[i] << " ";
				}
				user_info.close();

				user_num++;
				Title();
				cout << u1.user_name<<","<<"注册成功！" << endl;
				system("pause");
				break;
			}
			else {
				Title();
				cout << "----用户登录----" << endl;
				cout << "请输入：用户名  密码  用户类型" << endl;
				string name1, code1;
				int class1;
				bool log_in_ok = false;
				cin >> name1 >> code1 >> class1;
				
				for (int i = 0; i < user_num; i++) {
					log_in_ok = log_in_ok+(user_list[i].user_name == name1 && user_list[i].code == code1 && user_list[i].user_class == class1);
					if ((user_list[i].user_name == name1 && user_list[i].code == code1 && user_list[i].user_class == class1)) {
						Title();
						cout << "登陆成功！" << endl;
						system("pause");
						user_menu((user_list[i]));
						break;
					}
					else if((i == user_num - 1) && !log_in_ok){
						Title();
						cout << "登陆失败！" << endl;
						system("pause");
						break;
					}
				}
				break;
			}
		}
		if (option1 == 3) {
			Title();
			cout << "欢迎下次使用！" << endl;
			system("pause");
			exit(0);
		}
	}
	
	return 0;
}