//������������ļ�������Ҫ����ͽṹ��
#include "pch.h"
#include "PCB.h"
#include <iostream>
using namespace std;
//������̵��ڴ�鳤��
#define MinSize 2

//��ֹ�����ر���
#ifndef _Define_
#define _Define_

//��������ֻ���״̬
enum PStates
{
	Ready,Running,Blocked
};

typedef class PCB *PPCB;
//�ڴ���ָ��
typedef struct PageNode* Page;

struct PageNode {
	//�ڴ��Ŀ�ʼ��ַ
	int Start;
	//�ڴ��ĳ���
	int Length;
	//ǰһ���ڴ��
	Page Front;
	//��һ���ڴ��
	Page Next;
};
/*
�ڴ��
*/
struct MemoryNode
{
	//�õ�ַ���������ָ��
	string command;
	//��ַ�Ƿ�ռ��
	bool flag;
};
#endif // !_Global_

