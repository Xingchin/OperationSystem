#pragma once
#include "Define.h"

class Register
{
public:
	// ����״̬�Ĵ���
	PStates PSW;
	//	ָ��Ĵ���	
	string IR;
	// //��ַ�Ĵ���
	int PC;
	// ����ִ�е�ָ����ƿ�
	PCB pcb;
	// ���ֵ�ǰ�����״̬
	void SvaePCBState();
	int DR;
	Register();
	// ��ȡ��ǰ�Ĵ�����״̬
	void GetPcbState(PCB curPCB);
};

