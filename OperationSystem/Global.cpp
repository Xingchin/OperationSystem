//��������һ�¹��б���
#include "pch.h"
#include "Global.h"


PCB pcbArray[PNum];
//static PCB IdlePCB("Idle");
queue PCB_Ready;
queue PCB_Blocked;
MemoryManager TheMemory;
Process process;
Register theRegister;
//IO�豸�ļĴ���
Register IORegister;

CString Result = "";
CPU cpu;

