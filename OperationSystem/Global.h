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
static PCB pcbArray[PNum];
//static PCB IdlePCB("Idle");
static queue PCB_Ready;
static queue PCB_Blocked;
static MemoryManager TheMemory;
static string path = "res\\process_code\\";
static Process process;
static Register theRegister;
//IO�豸�ļĴ���
static Register IORegister;

static CString Result;
static CPU cpu;

#endif // !_Global_
