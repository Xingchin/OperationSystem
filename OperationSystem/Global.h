//用来定义一下公有变量
#include "pch.h"
#include "PCB.h"
#include "Define.h"
#include "queue.h"
#include "Process.h"
#include <iostream>
#include "MemoryManager.h"
#include "Register.h"
#ifndef _GLOBAL_H_
#define _GLOBAL_H_
#define TheID 10;
//进程的总数，一共9个一个空闲进程
#define PNum 9
static PCB pcbArray[PNum];
static queue PCB_Ready;
static queue PCB_Blocked;
static MemoryManager TheMemory;
static string path = "res\\process_code\\";
static Process process;
static Register theRegister;
#endif // !_Global_
