#pragma once
#include "pch.h"
#include "Define.h"

class Process
{
public:
	int ID = 0;
	// ��������
	void Create(string FileName);
	// Ѱ�ҿհ׽��̿�
	PPCB SeekBlankPCB();
	// ��������
	int Block();
	// ���н��̻���
	int WeakUp();
	// ���ٽ��̵ĺ���
	void Destery();
	void Initialize();
};

