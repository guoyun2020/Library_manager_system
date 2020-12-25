#include"book.h"

/*@手动输入增加书目
*/
void book::book_init() {
	cout << "请输入：书名/借阅状态（0为未借出/1为借出）" << endl;
	cin >> name >> borrowed;
	cout << "书目添加完成！" << endl;
}

/*@重载输出运算符<<
*/
ostream& operator << (ostream& output, book &b) {
	string Property;
	b.borrowed == true ? Property = "是" : Property = "否";
	output << "书名：" << b.name << " " << "借阅状态：" << Property << endl;
	return output;
}

/*@显示书目信息
*/
void book::book_display(book&a) {
	cout << a ;
	if (a.borrowed) {
		cout << "借阅人：" << a.borrow_people <<"  "<< "借阅时间：" << a.borrow_time;
		cout << "借阅时长：" << a.borrow_days <<"天"<< endl;
		cout << "" << endl;
	}
}