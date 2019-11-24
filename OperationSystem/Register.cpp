#include "pch.h"
#include "Register.h"
#include "Global.h"

// ���ֵ�ǰ�����״̬
void Register::SvaePCBState()
{
	// TODO: �ڴ˴����ʵ�ִ���.
	pcb->PC = PC;
	pcb->Date = DR;
	pcb->PState = PSW;
	pcb->BlockedTime = BlockedTime;
}
Register::Register() {
	Initalize();
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
	PC = _pcb->PC;
	DR = _pcb->Date;
	pcb = _pcb;
	PSW = _pcb->PState;
	Name = _pcb->Name;
}



void Register::Initalize()
{
	// TODO: �ڴ˴����ʵ�ִ���.
	DR = 0;
	PC = 0;
	PSW = Ready;
	pcb = &pcbArray[0];
	BlockedTime = 0;
	Name = "idle.c";
}
