#include "pch.h"
#include "CPU.h"
#include"Global.h"
#include "Define.h"
void CPU::Deal() {
	if (theRegister.PSW>1) {
		process.Block();
		Dispatch();
	}
	UpdateIR();
	DealIR();
	theRegister.PC++;
	
}

// ����IR�е�ָ��
void CPU::DealIR()
{
	// TODO: �ڴ˴����ʵ�ִ���.
	if (theRegister.IR[1] == '=') {
		theRegister.DR = theRegister.IR[2] - '0';
	}
	else if (theRegister.IR[1] == '+') {
		theRegister.DR++;
	}
	else if (theRegister.IR[1] == '-') {
		theRegister.DR--;
	}
	else if (theRegister.IR[0] == '!') {
		theRegister.PSW = Blocked_IO;
		//��ȡ����ʱ��
		theRegister.BlockedTime = theRegister.IR[2] - '0';
	}
	else if (theRegister.IR[0] == 'E') {
		theRegister.PSW = Blocked_Destroy;
	}
	else if (theRegister.IR[0] == 'g') {
		theRegister.PC -= 2;
	}
}

// //���г������
void CPU::Dispatch()
{
	//������һ�������״̬
	//theRegister.SvaePCBState();
	//�����µĽ��̣�����������Ϊ�գ������idle����
	if (!PCB_Ready.Empty()) {
		theRegister.LoadPCB(PCB_Ready.Pop());
	}
	else {
		theRegister.LoadPCB(&pcbArray[0]);
	}
}


// ����IR�е�ָ��
void CPU::UpdateIR()
{
	// TODO: �ڴ˴����ʵ�ִ���.
	theRegister.IR = TheMemory.Memory[theRegister.PC].command;
}


// �����ж�
void CPU::DealInterrupt()
{
	// TODO: �ڴ˴����ʵ�ִ���.
	theRegister.SvaePCBState();
}




// ����ʱ��Ƭ�ĸ���
void CPU::UpdateTime()
{
	// TODO: �ڴ˴����ʵ�ִ���.
}
