//��������һ�¹��б���
#include "pch.h"
#include "PCB.h"
#include "Define.cpp"
#include "queue.h"
#include <iostream>
#include "MemoryManager.h"
#ifndef _GLOBAL_H_
#define _GLOBAL_H_
//���̵�������һ��9��һ�����н���
#define PNum 9
static PCB pcbArray[PNum];
static queue PCB_Ready;
static queue PCB_Blocked;
static MemoryManager TheMemory;
static string path = "res\\process_code\\";
#endif // !_Global_
