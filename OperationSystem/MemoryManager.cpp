#include "pch.h"
#include "MemoryManager.h"
#include "Define.h"
#include <iostream>

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
	Head = (Page)malloc(sizeof(PageNode));
	Head->Front = NULL;
	Head->Next = NULL;
}
// ���ٵ�ַ
Page MemoryManager::Malloc(int size)
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
		Page p = (Page)Malloc(sizeof(PageNode));
		p->Start = temp->Start + size;
		p->Length = temp->Length - size;
		p->Next = temp->Next;
		p->Front = temp;
		temp->Next = p;
		temp->Length = size;
	}
	for (int i = temp->Start,j= i + temp->Length; i < j; i++) {
		Memory[i].flag = true;
	}
	return temp;
};

void MemoryManager::Free(Page _page)
{
	Page temp;
	for (int i = _page->Start, j = i + _page->Length; i < j; i++) {
		Memory[i].flag = false;
	}
	//���пɱ��ڴ��ĺϲ�
	temp = _page->Front;
	//����ǰ���кϲ�
	if (temp && !Memory[temp->Start].flag) {
		temp->Length += _page->Length;
		free(_page);
		_page = temp;
	}
	//�����кϲ�
	temp = _page->Next;
	if (temp && !Memory[temp->Start].flag) {
		_page->Length += temp->Length;
		free(temp);
	}
}
