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
	string Name;
	// ���ֵ�ǰ�����״̬
	void SvaePCBState();
	int DR;
	Register();
	
	int BlockedTime;
	// ��ȡ��ǰ�Ĵ�����״̬
	void GetPcbState(PPCB curPCB);
	void LoadPCB(PPCB _pcb);

};

