#include "pch.h"
#include "MemoryManager.h"
#include "Define.h"
#include <iostream>

//���ڴ��ʼ��
int MemoryManager::Initialize()
{

	for (int i = 0; i < 128; i++) {
		Memory[i].flag = 0;
	}
	Head = ConfigPage(NULL, 128, 0, NULL, NULL);
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
	while (temp) {
		if (!Memory[temp->Start].flag || temp->Length > size) {
			break;
		}
		temp = temp->Next;
	}

	//�ж��ҵ��ĵ�ַ���Ƿ�Ϊ��
	if (!temp)return NULL;

	//���õ�ַ��Ĺ���������зָ�
	if (temp->Length - size >= MinSize) {
		Page p = ConfigPage(NULL, temp->Length - size,
			temp->Start + size, temp, temp->Next);
		temp->Next = p;
		temp->Length = size;
	}
	for (int i = temp->Start, j = i + temp->Length; i < j; i++) {
		Memory[i].flag = 1;
	}
	return temp;
};

void MemoryManager::Free(Page _page)
{
	Page temp;
	for (int i = _page->Start, j = i + _page->Length; i < j; i++) {
		Memory[i].flag = 0;
	}
	//���пɱ��ڴ��ĺϲ�
	temp = _page->Front;
	//����ǰ���кϲ�
	if (temp && !Memory[temp->Start].flag) {
		temp->Length += _page->Length;
		temp->Next = _page->Next;
		if (_page->Next) {
			_page->Next->Front = temp;
		}
		free(_page);
		_page = temp;
	}

	//�����кϲ�
	temp = _page->Next;
	if (temp && !Memory[temp->Start].flag) {
		_page->Length += temp->Length;
		_page->Next = temp->Next;
		if (temp->Next) {
			temp->Next->Front = _page;
		}
		free(temp);
	}
}


// ����ҳ��
Page MemoryManager::ConfigPage(Page p, int length, int start, Page front, Page next)
{
	// TODO: �ڴ˴����ʵ�ִ���.
	if (p == NULL) {
		p = (Page)malloc(sizeof(PageNode));
	}

	p->Next = next;
	p->Front = front;
	p->Start = start;
	p->Length = length;
	return p;
}
