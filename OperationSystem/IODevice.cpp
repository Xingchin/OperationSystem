#include "pch.h"
#include "IODevice.h"
#include "Global.h"

// ���������������
void IODevice::Deal()
{
	// TODO: �ڴ˴����ʵ�ִ���.
	if (!IORegister.pcb||IORegister.BlockedTime == 0) {
		GetNextPCB();
	}
	//ȷ���ɹ������һ��ַ
	if (IORegister.pcb) {
		if (--IORegister.BlockedTime == 0) {
			PrintResult();
			IORegister.PSW = Ready;
			process.WeakUp();
		}
	}
}


// ��ȡ��һ��Ҫ���д�ӡ�Ľ���
void IODevice::GetNextPCB()
{
	// TODO: �ڴ˴����ʵ�ִ���.
	if (!PCB_Blocked.Empty()) {
		IORegister.LoadPCB(PCB_Blocked.Pop());
	}
	else {
		IORegister.pcb = NULL;      
	}
}


// ��ӡ���
void IODevice::PrintResult()
{
	CString temp;
	//���ý����ʾ�ڶԻ�����
	
}
