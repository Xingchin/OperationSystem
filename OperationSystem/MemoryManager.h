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
	// ���г���Ľ��̿�
	//Page Idle;
	// ���ٵ�ַ
	Page Malloc(int size);
	void Free(Page _page);
	// ����ҳ��
	Page ConfigPage(Page p,int length,int start, Page front, Page next);
};

