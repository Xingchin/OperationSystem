#pragma once
#include "Define.h"
class MemoryManager
{
public:
	// //���ڴ��ʼ��	Mem RAM[128];
	int Initialize();
	MemoryManager();

	MemoryNode Memory[128];
	// ҳ���ͷ��
	Page Head;
	// ���ٵ�ַ
	Page Malloc(int size);
	void Free(Page _page);
};

