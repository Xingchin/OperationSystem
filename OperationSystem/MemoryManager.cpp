#include "pch.h"
#include "MemoryManager.h"
#include "Define.h"
#include <iostream>

//���ڴ��ʼ��
int MemoryManager::Initialize()
{
	Memory[0].command = "x=0;";
	Memory[1].command = "god;";
	Memory[0].flag = true;
	Memory[1].flag = true;
	// TODO: �ڴ˴����ʵ�ִ���.
	for (int i = 2; i < 128; i++) {
		Memory[i].flag= false;
	}
	Head = (Page)malloc(sizeof(PageNode));
	ConfigPage(Idle, 2,0, NULL, Head);
	ConfigPage(Head, 126,2, Idle, NULL);
	return 0;
}

MemoryManager::MemoryManager() {
	Initialize();
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
		Page p = ConfigPage(NULL, temp->Length - size,
			temp->Start + size, temp, temp->Next);
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


// ����ҳ��
Page MemoryManager::ConfigPage(Page p,int length,int start, Page front, Page next)
{
	// TODO: �ڴ˴����ʵ�ִ���.
	if (p == NULL) {
		p = (Page)malloc(sizeof(PageNode));
	}
	p->Length = length;
	p->Next = next;
	p->Front = front;
	p->Start = start;
	return p;
}
