#include"head.h"

//单向循环链表实现约瑟夫环问题
int main() {
	int peopleNumber, deleteNumber, overNumber;
	cout << "欢迎来到约瑟夫环问题！\n-----------------------------"<<endl;
	cout << "请输入报数上限m：\n";
	cin >> overNumber;
	cout << "请输入总人数：\n";
	cin >> peopleNumber;
	cout << "请输入第一个被删除者的编号：\n";
	cin >> deleteNumber;
	Joseph J1(peopleNumber, deleteNumber, overNumber);//创建循环链表
	J1.game();//开始计算删除顺序
	return 0;
}