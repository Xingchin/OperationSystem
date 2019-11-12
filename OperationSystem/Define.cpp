//用来定义各个文件都会需要的类和结构体
#include "pch.h"
#include "PCB.h"
//声明最短的内存块长度
#define MinSize 2

//防止代码重编译
#ifndef _Define_
#define _Define_

//程序的三种基本状态
enum PStates
{
	Ready,Running,Blocked
};

typedef class PCB *PPCB;
//内存块的指针
typedef struct PageNode* Page;

typedef string COMMAND;
struct PageNode {
	//内存块的开始地址
	int Start;
	//内存块的长度
	int Length;
	//下一个地址的位置
	Page Next;
};
/*
内存块
*/
struct MemoryNode
{
	//该地址上所储存的指令
	COMMAND command;
	//地址是否被占用
	bool flag;
};
#endif // !_Global_

