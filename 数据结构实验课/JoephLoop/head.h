#pragma once
#include <iostream>

using namespace std;

struct People {//人的信息
	int number; //编号
	int password;//密码
	People* next; //指向下一个节点
};

class Joseph {//循环单链表
private:
	int myPeopleNumber;//参与的人数
	int myDeleteNumber;//要删除的序号
	int myOverNumber;//报数上限
	People* head= NULL;//链表的头结点
public:
	Joseph(int peopleNumber, int deleteNumber, int overNumber) {
		myPeopleNumber = peopleNumber;
		myDeleteNumber = deleteNumber;
		myOverNumber = overNumber;
		People* temp1=NULL, * temp2=NULL; //创建两个空指针
		for (int i = 1; i <= myPeopleNumber; i++) {//初始化循环链表 
			int inputPassword;
			cout << "请输入第" << i << " 个人的密码：";
			cin >> inputPassword;
			temp1 = new People;//录入一个人的信息
			temp1->number = i;
			temp1->password = inputPassword;
			if (i == 1) {//如果当前链表为空,头指针指向第一个人  
				head = temp1;
				temp2 = temp1;
			}
			else {//如果不为空,temp2指向尾结点,新结点都插入到temp2之后
				temp2->next = temp1;
				temp2 = temp1;
			}
		}
		cout<<"被删除的顺序依次为："<<endl;
		temp2->next = head;//首尾相连，连成循环链表
	}
	~Joseph() {
		delete head;
	}
	bool game() {//游戏开始
		//如果要删的人编号大于上限或者不大于0
		if (myDeleteNumber >= myOverNumber || myDeleteNumber <= 0) {
			cout << "Your number is over!!" << endl;//显示错误信息
			return false;
		}
		People* temp1, * temp2=NULL, * temp; //创建空指针
		temp1 = head;
		int count;
		int a = myDeleteNumber;
		for (int i = 1; i <= myPeopleNumber; i++) {
			count = 1;
			while (count < a) {
				temp2 = temp1;
				temp1 = temp1->next;
				count++;
			}
			cout << temp1->number << "  ";//按序打印被删除人的编号
			temp = temp1;
			a = temp->password;//记录被删人的密码
			temp2->next = temp1->next;  //链接前后指针
			temp1 = temp->next;//从下一个人开始数
			delete temp;//从链表中删除此人，释放内存
		}
		cout << endl;
		head = NULL;//游戏结束时链表为空
		return true;
	}
};