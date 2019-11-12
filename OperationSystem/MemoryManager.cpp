#include "pch.h"
#include "MemoryManager.h"
#include "Define.h"

//���ڴ��ʼ��
int MemoryManager::Initialize()
{
	// TODO: �ڴ˴����ʵ�ִ���.
	for (int i = 0; i < 128; i++) {
		Memory[i].flag= false;
	}
	return 0;
}

MemoryManager::MemoryManager() {
	Initialize();
}
// ���ٵ�ַ
Page MemoryManager::malloc(int size)
{
	Page temp = Head;
	/**
	Ѱ����һ����ַ��
	Ҫ��
	��ַ�����
	δ��ʹ��
	�������ó��ȴ���size
	*/
	while (temp && Memory[temp->Start].flag && temp->Length < size) {
		temp = temp->Next;
	}

	//�ж��ҵ��ĵ�ַ���Ƿ�Ϊ��
	if (!temp)return NULL;

	//���õ�ַ��Ĺ���������зָ�
	if (temp->Length - size <= MinSize) {
		Page p = (Page)malloc(sizeof(PageNode));
		p->Start = temp->Start + size;
		p->Length = temp->Length - size;
		p->Next = temp->Next;
		temp->Next = p;
		temp->Length = size;
	}
	return temp;
};


