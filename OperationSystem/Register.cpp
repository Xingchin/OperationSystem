#include "pch.h"
#include "Register.h"

// ���ֵ�ǰ�����״̬
void Register::SvaePCBState()
{
	// TODO: �ڴ˴����ʵ�ִ���.
	pcb->PC = PC;
	pcb->Date = DR;
	pcb->PState = PSW;
}
Register::Register() {
	DR = 0;
	PC = 0;
	PSW = Ready;
	pcb = NULL;
	BlockedTime = 0;
}

// ��ȡ��ǰ�Ĵ�����״̬
void Register::GetPcbState(PPCB curPCB)
{
	PC = curPCB->PC;
	PSW = curPCB->PState = Running;
}


void Register::LoadPCB(PPCB _pcb)
{
	// TODO: �ڴ˴����ʵ�ִ���.
}


