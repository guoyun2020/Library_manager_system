#include"book.h"

/*@�ֶ�����������Ŀ
*/
void book::book_init() {
	cout << "�����룺����/����״̬��0Ϊδ���/1Ϊ�����" << endl;
	cin >> name >> borrowed;
	cout << "��Ŀ�����ɣ�" << endl;
}

/*@������������<<
*/
ostream& operator << (ostream& output, book &b) {
	string Property;
	b.borrowed == true ? Property = "��" : Property = "��";
	output << "������" << b.name << " " << "����״̬��" << Property << endl;
	return output;
}

/*@��ʾ��Ŀ��Ϣ
*/
void book::book_display(book&a) {
	cout << a ;
	if (a.borrowed) {
		cout << "�����ˣ�" << a.borrow_people <<"  "<< "����ʱ�䣺" << a.borrow_time;
		cout << "����ʱ����" << a.borrow_days <<"��"<< endl;
		cout << "" << endl;
	}
}