#pragma once
//#include"game.h"
class Game;
//父类Strategy
class Strategy {
public:
	virtual int strategy();
};
//Strategy的三种子类
class Random: public Strategy {//随机出拳策略
public:
	virtual int strategy();
};
class WinLast : public Strategy {//赢上一局策略
public:
	virtual int strategy(int, int, Random&, Game&);
};
class UseLeast : public Strategy {//到目前为止使用招数最少的策略
public:
	virtual int strategy(Game&);
};