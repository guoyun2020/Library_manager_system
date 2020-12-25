#include"user.h"



void user::user_register() {
	cout << "----�û�ע��----" << endl;
	cout << "�����ã��û���  ����  �û����� (����:0/ͼ�����Ա:1/ϵͳ����Ա:2)" << endl;
	cin >> user_name >> code >> user_class;

}

void user::user_register(int a) {
	cout << "----�û�ע��----" << endl;
	cout << "�����ã��û���  ����" << endl;
	cin >> user_name >> code;
	user_class = a;

}

void user::user_change() {
	cout << "----�޸���Ϣ----" << endl;
	cout << "���޸ģ��û���  ����  �û����ͣ�����:0/ͼ�����Ա:1/ϵͳ����Ա:2��:" << endl;
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
		outfile << "�����ˣ�" <<info[0] << "   ";
		char* s = a.borrow_time;
		outfile << "����ʱ�䣺" << s ;
		info[1] = to_string(a.borrow_days);
		outfile << "����ʱ����" << info[1] << "��";
		outfile.close();
		cout << "���ĳɹ���" << endl;
	}
	else {
		cout << "���û�û�н���Ȩ�ޣ�" << endl;
	}
}

char* reader::set_borrow_time() {
	// ���ڵ�ǰϵͳ�ĵ�ǰ����/ʱ��
	time_t now = time(0);
	// �� now ת��Ϊ�ַ�����ʽ
	char* dt = ctime(&now);
	return dt;
}

void reader::return_book(book&a) {
	a.borrowed = false;
	
}

void reader::review_book() {
	for (int i = 0; i < book_num; ++i) {
		cout << "�鼮���:" << i << endl;
		borrowed_books[i].book_display(borrowed_books[i]);
	}
}

void book_manager::add_book(book&a) {
	if (can_manage) { a.book_init(); }
	else { cout << "û�й���Ȩ�ޣ�" << endl; }
}

void book_manager::remove_book(book&a) {
	if (can_manage) {
		a.borrowed = false;
		a.name = "����Ŀ�ѱ����";
	}
	else {
		cout << "û�й���Ȩ�ޣ�" << endl;
	}
}

void book_manager::change_book(book&a) {
	if (can_manage) {
		cout << "�������޸ĺ�ģ�����  ����״̬��0Ϊδ���/1Ϊ�����" << endl;
		cin >> a.name >> a.borrowed;
		cout << "��Ŀ�޸���ɣ�" << endl;
	}
	else {
		cout << "û�й���Ȩ�ޣ�" << endl;
	}
}

void book_manager::book_statistic() {

};

void book_manager::check_details(book&a) {
	if (can_manage) {
		a.book_display(a);
	}
	else {
		cout << "û�й���Ȩ�ޣ�" << endl;
	}
}

void system_manager::add_reader(reader&a){
	a.user_register(0);
}

void system_manager::remove_reader(reader&a) {
	vector<book> null(10);
	a.user_name = "���û��ѱ�ɾ��";
	a.code = "��";
	a.user_class = -1;
	a.borrowed_books = null;
	a.can_borrow = false;
}

void system_manager::add_book_manager(book_manager&a) {
	a.user_register(1);
}

void system_manager::remove_book_manager(book_manager&a) {
	a.user_name = "���û��ѱ�ɾ��";
	a.code = "��";
	a.user_class = -1;
	a.can_manage = false;
}

void system_manager::change_reader_ability(user&a,bool b) {
	a.can_borrow = b;
};

void system_manager::change_manager_ability(user&a, bool b) {
	a.can_manage = b;
};

