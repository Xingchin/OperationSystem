#pragma once
#include "Define.h"
class queue
{
private:
	PPCB Head;
	PPCB Nail;
public:
	queue();
	
	void Push(PPCB pcb);
	PPCB Pop();
	bool Empty();
	// ��ȡͷ�ڵ�
	PPCB GetHead();
	// ��ն����е�Ԫ��
	void Clear();
};


