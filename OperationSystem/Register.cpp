#include "pch.h"
#include "Register.h"


// ���ֵ�ǰ�����״̬
void Register::SvaePCBState()
{
	// TODO: �ڴ˴����ʵ�ִ���.
	pcb.PC = PC;
	pcb.Date = DR;
	pcb.PState = PSW;
}
Register::Register() {

}

// ��ȡ��ǰ�Ĵ�����״̬
void Register::GetPcbState(PCB curPCB)
{
	// TODO: �ڴ˴����ʵ�ִ���.
	pcb = curPCB;
	PC = curPCB.PC;
	PSW = curPCB.PState = Running;
}
