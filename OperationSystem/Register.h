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
	// ����ִ�е�ָ����ƿ�ָ��
	PPCB pcb;
	// ���ֵ�ǰ�����״̬
	void SvaePCBState();
	int DR;
	Register();
	// ��ȡ��ǰ�Ĵ�����״̬
	void GetPcbState(PPCB curPCB);
};

