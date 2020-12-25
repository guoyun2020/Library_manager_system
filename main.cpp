//author:���S version:1.0 time:12/18/20

#include"book.h"
#include"user.h"
#include <stdlib.h>
#include<stdio.h>
#include <io.h>

//����ͼ�������
vector<book> book_list(10);
int list_num = 4;
//�����û�������
vector<user> user_list(10);
int user_num = 0; 

void Title() {
	system("CLS");
	cout << "				*****************************************" << endl;
	cout << "				*             ͼ��ݹ���ϵͳ            *" << endl;
	cout << "				* author:���S version:1.5 time:12/20/20 *" << endl;
	cout << "				*           ��Ȩ���У���ֹ��Ϯ��        *" << endl;
	cout << "				*****************************************" << endl;
	cout << " " << endl;
}

void user_menu(user&a) {
	if (a.user_class == 0) {//���߲˵�
		bool log_in=true;
		reader r1;
		r1.user_name = a.user_name;
		r1.code = a.code;
		r1.user_class = a.user_class;
		r1.can_borrow = a.can_borrow;
		while (log_in) {
			Title();
			cout << "----���߲˵�----" << endl;
			cout << "1.ͼ�����" << endl;
			cout << "2.ͼ��黹" << endl;
			cout << "3.�ѽ���Ŀ��ѯ" << endl;
			cout << "4.�˳��˺�" << endl;
			int option2;
			cin >> option2;

			//ͼ�����
			if (r1.can_borrow) {
				while (option2 == 1) {
					Title();
					for (int i = 0; i < list_num; i++) {
						cout << "�鼮���:" << i << endl;
						book_list[i].book_display(book_list[i]);
					}
					int borrow_num, book_id1;
					cout << "����������鼮������:" << endl;
					cin >> borrow_num;
					cout << "����������鼮����ţ�ÿ����һ�����밴Enter��ȷ�ϣ�:" << endl;
					for (int j = 0; j < borrow_num; j++) {
						cin >> book_id1;
						r1.borrow_book(book_list[book_id1]);
					}
					break;
				}
			}
			else {
				Title();
				cout << "�޽���Ȩ�ޣ�" << endl;
				system("pause");
			}

			//ͼ��黹
			while (option2 == 2) {
				Title();
				r1.review_book();
				int return_num, book_id2;
				cout << "������黹�鼮������:" << endl;
				cin >> return_num;
				for (int j = 0; j < return_num; j++) {
					Title();
					r1.review_book();
					cout << "������黹�鼮����ţ�ÿ����һ�����밴Enter��ȷ�ϣ�:" << endl;
					cin >> book_id2;
					for (int m = 0; m < list_num; m++) {
						if (book_list[m].name == r1.borrowed_books[book_id2].name) {
							r1.return_book(book_list[m]);
							break;
						}
						else continue;
					}
					r1.borrowed_books.erase(r1.borrowed_books.begin() + book_id2);
					cout << "�黹�ɹ�" << endl;
					r1.book_num--;	
				}
				break;
			}

			//�ѽ���Ŀ��ѯ
			while (option2 == 3) {
				Title();
				r1.review_book();
				system("pause");
				break;
			}
			//�û��˳�
			while (option2 == 4) {
				Title();
				log_in=false;
				break;
			}
			//�����쳣
			while (option2 != 1 && option2 != 2 && option2 != 3 && option2 != 4) {
				Title();
				cout << "�����������������룡" << endl;
				system("pause");
				break;
			}
		}
	}
	else if (a.user_class == 1) {//ͼ�����Ա�˵�
		bool log_in = true;
		book_manager b1;
		b1.user_name = a.user_name;
		b1.code = a.code;
		b1.user_class = a.user_class;
		b1.can_manage = a.can_manage;
		while (log_in) {
			Title();
			cout << "----ͼ�����Ա�˵�----" << endl;
			cout << "1.����ͼ��" << endl;
			cout << "2.ɾ��ͼ��" << endl;
			cout << "3.����ͼ����Ϣ" << endl;
			cout << "4.�鿴ͼ��״̬" << endl;
			cout << "5.�˳��˺�" << endl;
			int option3;
			cin >> option3;

			//����ͼ��
			while (option3 == 1 && b1.can_manage) {
				Title();
				string new_name;
				cout << "������������" << endl;
				cin >> new_name;
				book new_book;
				new_book.book_init(new_name, 0);
				book_list[list_num] = new_book;
				cout << book_list[list_num] << endl;
				list_num++;
				cout << "��ӳɹ�" << endl;
				system("pause");
				break;
			}

			//ɾ��ͼ��
			while (option3 == 2 && b1.can_manage) {
				Title();
				for (int k = 0; k < list_num; k++) {
					cout << "�鼮���:" << k << endl;
					book_list[k].book_display(book_list[k]);
				}
				int remove_num, book_id3;
				cout << "������ɾ���鼮������:" << endl;
				cin >> remove_num;
				for (int j = 0; j < remove_num; j++) {
					Title();
					for (int k = 0; k < list_num; k++) {
						cout << "�鼮���:" << k << endl;
						book_list[k].book_display(book_list[k]);
					}
					cout << "������ɾ���鼮����ţ�ÿ����һ�����밴Enter��ȷ�ϣ�:" << endl;
					cin >> book_id3;
					book_list.erase(book_list.begin() + book_id3);
					list_num--;
					cout << "ɾ���ɹ���" << endl;
					system("pause");
				}
				break;
			}

			//����ͼ����Ϣ
			while (option3 == 3 && b1.can_manage) {
				Title();
				for (int k = 0; k < list_num; k++) {
					cout << "�鼮���:" << k << endl;
					book_list[k].book_display(book_list[k]);
				}
				int book_id4;
				cout << "��������޸��鼮�����:" << endl;
				cin >> book_id4;
				b1.change_book(book_list[book_id4]);
				cout << book_list[book_id4] << endl;
				system("pause");
				break;
			}

			//�鿴ͼ��״̬
			while (option3 == 4 && b1.can_manage) {
				Title();
				for (int d = 0; d < list_num; d++) {
					cout << "�鼮���:" << d << endl;
					b1.check_details(book_list[d]);
				}
				system("pause");
				break;

			}

			//�û��˳�
			while (option3 == 5) {
				Title();
				log_in = false;
				break;
			}
			//�����쳣
			while ((option3 != 1 && option3 != 2 && option3 != 3 && option3 != 4 && option3 != 5)|| !b1.can_manage) {
				Title();
				cout << "����������޹���Ȩ�ޣ�" << endl;
				system("pause");
				break;
			}
		}
	}
	else {//ϵͳ����Ա�˵�
		bool log_in = true;
		system_manager s1;
		s1.user_name = a.user_name;
		s1.code = a.code;
		s1.user_class = a.user_class;
		while (log_in) {
			Title();
			cout << "----ϵͳ����Ա�˵�----" << endl;
			cout << "1.�����û�" << endl;
			cout << "2.ɾ���û�" << endl;
			cout << "3.�鿴��Ա�б�" << endl;
			cout << "4.�޸ĳ�ԱȨ��" << endl;
			cout << "5.�û��˳�" << endl;
			int option4;
			cin >> option4;

			//�����û�
			while (option4 == 1) {
				Title();
				int title;
				cout << "��ѡ���û����ͣ�0Ϊ����/1Ϊͼ�����Ա" << endl;
				cin >> title;
				if (!title) {//���Ӷ���
					Title();
					reader new_reader;
					s1.add_reader(new_reader);
					user_list[user_num] = new_reader;
					cout << "�¶���������" << new_reader.user_name << " " << "Ȩ�����ã�1Ϊ�ɽ���/0Ϊ���ɽ��ģ�:" << new_reader.can_borrow << endl;
					user_num++;
				}
				else {//����ͼ�����Ա
					Title();
					book_manager new_manager;
					s1.add_book_manager(new_manager);
					user_list[user_num] = new_manager;
					cout << "��ͼ�����Ա������" << new_manager.user_name << " " << "Ȩ�����ã�1Ϊ�ɹ���/0Ϊ���ɹ���:" << new_manager.can_manage << endl;
					user_num++;
				}
				break;
			}

			//ɾ����Ա
			while (option4 == 2) {
				Title();
				for (int q = 0; q < user_num; q++) {
					cout << "�û����:" << q << endl;
					cout << "������" << user_list[q].user_name << "  "<<"�û����:"<< user_list[q].user_class << "  (����:0/ͼ�����Ա:1/ϵͳ����Ա:2)" << endl;
				}
				int remove_num, user_id;
				cout << "������ɾ����Ա������:" << endl;
				cin >> remove_num;
				for (int f = 0; f < remove_num; f++) {
					Title();
					cout << "������ɾ����Ա����ţ�ÿ����һ�����밴Enter��ȷ�ϣ�:" << endl;
					cin >> user_id;
					user_list.erase(user_list.begin() + user_id);
					user_num--;
					cout << "ɾ���ɹ���" << endl;
					for (int q = 0; q < user_num; q++) {
						cout << "�û����:" << q << endl;
						cout << "������" << user_list[q].user_name << "  " << "�û����:" << user_list[q].user_class << endl;
					}
				}
				break;
			}

			//�鿴��Ա�б�
			while (option4 == 3) {
				Title();
				for (int q = 0; q < user_num; q++) {
					cout << "�û����:" << q << endl;
					cout << "������" << user_list[q].user_name << "  " << "�û����:" << user_list[q].user_class << "  (����:0/ͼ�����Ա:1/ϵͳ����Ա:2)" << endl;
				}
				system("pause");
				break;
			}

			//�޸ĳ�ԱȨ��
			while (option4 == 4) {
				Title();
				for (int q = 0; q < user_num; q++) {
					cout << "�û����:" << q << endl;
					cout << "������" << user_list[q].user_name << "  " << "�û����:" << user_list[q].user_class << "  (����:0/ͼ�����Ա:1/ϵͳ����Ա:2)" << endl;
				}
				cout << "��ѡ����Ҫ�޸�Ȩ�޵��û�����ţ�" << endl;
				int choose;
				cin >> choose;
				if (user_list[choose].user_class == 0) {//�޸Ķ��߽���Ȩ��
					Title();
					cout << "��ѡ�����ȡ���ö��ߵĽ���Ȩ�ޣ���0Ϊȡ��/1Ϊ���裩" << endl;
					int right1;
					cin >> right1;
					if (right1 == 0 || right1 == 1) {
						s1.change_reader_ability(user_list[choose], right1);
						cout << "����Ȩ���޸ĳɹ���" << endl;
					}
					else {
						cout << "��������!" << endl;
					}
				}
				else if (user_list[choose].user_class == 1) {//�޸�ͼ�����Ա����Ȩ��
					Title();
					cout << "��ѡ�����ȡ����ͼ�����Ա�Ĺ���Ȩ�ޣ���0Ϊȡ��/1Ϊ���裩" << endl;
					int right2;
					cin >> right2;
					if (right2 == 0 || right2 == 1) {
						s1.change_manager_ability(user_list[choose], right2);
						cout << "����ԱȨ���޸ĳɹ���" << endl;
					}
					else {
						cout << "��������!" << endl;
						system("pause");
					}
				}
				else {
					cout << "�޷��޸�����Ȩ�޻���������" << endl;
					system("pause");
				}
				break;
			}

			//�û��˳�
			while (option4 == 5) {
				Title();
				log_in = false;
				break;
			}
			//�����쳣
			while (option4 != 1 && option4 != 2 && option4 != 3 && option4 != 4 && option4 != 5) {
				Title();
				cout << "�����������������룡" << endl;
				system("pause");
				break;
			}
		}
	}
}


int main() {
	//�������
	book b0, b1, b2, b3;
	b0.book_init("���������塷", 0);
	b1.book_init("��ˮ䰴���", 0);
	b2.book_init("����¥�Ρ�", 0);
	b3.book_init("�����μǡ�", 0);
	book_list[0] = b0;
	book_list[1] = b1;
	book_list[2] = b2;
	book_list[3] = b3;

	//��ȡ�û����ݿ�

	//Ŀ���ļ���·��
	std::string inPath = "D:\\user\\*.txt";
	//���ڲ��ҵľ��
	intptr_t  handle;
	struct _finddata_t fileinfo;
	//��һ�β���
	handle = _findfirst(inPath.c_str(), &fileinfo);
	if (handle == -1)
		return -1;
	
	while (!_findnext(handle, &fileinfo))
	{
		//�ҵ����ļ����ļ���
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
	//���˵�
	while (true) {
		Title();
		cout << "----���˵�----" << endl;
		cout << "1.�û�ע��" << endl;
		cout << "2.�û���¼" << endl;
		cout << "3.�˳�ϵͳ" << endl;
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
				cout << u1.user_name<<","<<"ע��ɹ���" << endl;
				system("pause");
				break;
			}
			else {
				Title();
				cout << "----�û���¼----" << endl;
				cout << "�����룺�û���  ����  �û�����" << endl;
				string name1, code1;
				int class1;
				bool log_in_ok = false;
				cin >> name1 >> code1 >> class1;
				
				for (int i = 0; i < user_num; i++) {
					log_in_ok = log_in_ok+(user_list[i].user_name == name1 && user_list[i].code == code1 && user_list[i].user_class == class1);
					if ((user_list[i].user_name == name1 && user_list[i].code == code1 && user_list[i].user_class == class1)) {
						Title();
						cout << "��½�ɹ���" << endl;
						system("pause");
						user_menu((user_list[i]));
						break;
					}
					else if((i == user_num - 1) && !log_in_ok){
						Title();
						cout << "��½ʧ�ܣ�" << endl;
						system("pause");
						break;
					}
				}
				break;
			}
		}
		if (option1 == 3) {
			Title();
			cout << "��ӭ�´�ʹ�ã�" << endl;
			system("pause");
			exit(0);
		}
	}
	
	return 0;
}