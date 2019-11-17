#include "pch.h"
#include "CPU.h"
#include"Global.h"
#include "Define.h"
void CPU::Deal() {
	//�������жϽ��е��ȣ�ʱ��Ƭ����ҲҪ���е���
	if (theRegister.PSW > 1 || TimeSlice == 4 || theRegister.pcb->ID == 0) {
		Dispatch();
		if (theRegister.pcb->ID || TimeSlice == 4) {
			TimeSlice = 0;
		}
	}
	//���������Ľ���
	UpdateBlockedProcess();
	CheckProcessStates();
	UpdateIR();
	DealIR();
	theRegister.PC++;
	TimeSlice++;
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
	else if (theRegister.IR[0] == 'e') {
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
	if (theRegister.pcb->ID) {
		theRegister.SvaePCBState();
		if (theRegister.PSW ==Blocked_IO) {
			process.Block();
		}
		else if(theRegister.PSW == Ready){
			PCB_Ready.Push(theRegister.pcb);
		}
		else if (theRegister.PSW == Blocked_Destroy) {
			process.Destery();
		}
	}
	if (!PCB_Ready.Empty()) {
		theRegister.LoadPCB(PCB_Ready.Pop());
	}
	else {
		//��鵱ǰ���е��Ƿ�Ϊidle����
		if (theRegister.pcb->ID)
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
	TimeSlice++;
}


// �������������еĽ���
void CPU::UpdateBlockedProcess()
{
	// TODO: �ڴ˴����ʵ�ִ���.
	PPCB p = PCB_Blocked.GetHead();
	while (p) {
		p->BlockedTime--;
		p = p->Next;
	}
}


void CPU::CheckProcessStates()
{
 	PPCB p = PCB_Blocked.GetHead();

	if (p && !p->BlockedTime) {
		process.WeakUp();
	}
}
