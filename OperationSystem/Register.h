#pragma once
#include "Define.cpp"

class Register
{
public:
	// ����״̬�Ĵ���
	PStates PSW;
	//	ָ��Ĵ���	
	COMMAND IR;
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

