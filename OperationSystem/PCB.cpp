#include "pch.h"
#include "PCB.h"
#include "Global.h"

int PCB::Initialize()
{
	PC = 0;
	Date = 0;
	ID = 0;
	BlockedTime = 0;
	Next = NULL;
	page = NULL;
	PState = Ready;
	flag = false;
	Name = "";
	return 0;
}


void PCB::Config(Page _page,string name)
{
	// TODO: �ڴ˴����ʵ�ִ���.
	Name = name;
	page = _page;
	PC = _page->Start;

	flag = true;
	//Ĭ�ϳ����״̬Ϊ����
	//TranformStates(Ready);
}


// �ı���̿��״̬�������뵽��ض���
void PCB::TranformStates(PStates state)
{
	// TODO: �ڴ˴����ʵ�ִ���.
	PState = state;
	if (state == Ready) {
		PCB_Ready.Push(this);
	}
	else if(state == Blocked_IO){
		PCB_Blocked.Push(this);
	}
}
PCB::PCB() {
	Initialize();
}
PCB::PCB(string name) {
	Initialize();
	flag = true;
	this->Name = name;
}