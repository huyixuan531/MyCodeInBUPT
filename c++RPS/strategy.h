#pragma once
//#include"game.h"
class Game;
//����Strategy
class Strategy {
public:
	virtual int strategy();
};
//Strategy����������
class Random: public Strategy {//�����ȭ����
public:
	virtual int strategy();
};
class WinLast : public Strategy {//Ӯ��һ�ֲ���
public:
	virtual int strategy(int, int, Random&, Game&);
};
class UseLeast : public Strategy {//��ĿǰΪֹʹ���������ٵĲ���
public:
	virtual int strategy(Game&);
};