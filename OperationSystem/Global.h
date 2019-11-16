//��������һ�¹��б���
#include "pch.h"
#include "PCB.h"
#include "Define.h"
#include "queue.h"
#include "Process.h"
#include <iostream>
#include "MemoryManager.h"
#include "Register.h"
#include "CPU.h"

#ifndef _GLOBAL_H_
#define _GLOBAL_H_
#define TheID 10;
//���̵�������һ��9��һ�����н���
#define PNum 9
extern PCB pcbArray[PNum];
//static PCB IdlePCB("Idle");
extern queue PCB_Ready;
extern queue PCB_Blocked;
extern MemoryManager TheMemory;
static string path = "res\\process_code\\";
extern Process process;
extern Register theRegister;
//IO�豸�ļĴ���
extern Register IORegister;

extern CString Result;
extern CPU cpu;

#endif // !_Global_
