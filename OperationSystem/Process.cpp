#include "pch.h"
#include <fstream>
#include "Process.h"
#include "Global.h"
void Process::Create(string FileName) {
	PPCB pcb = SeekBlankPCB();
	if (!pcb) {
		//���̿��Ѿ�����
		AfxMessageBox("���̿�����������ʧ��", MB_OK | MB_ICONERROR);  return;
	}	
	string file = path + FileName;
	ifstream ifs(file);
	string temp;
	getline(ifs, temp);
	//��ȡ�˴����ĳ���
	int length = atoi(temp.c_str()), addr;
	
	//��ȡ�����ڴ棬����ʹ�ø��ڴ������PCB
	pcb->Config(TheMemory.Malloc(length), FileName);
	addr = pcb->page->Start;
	//����ַ��ֵ
	for (int i = 0; i < length; i++) {
		getline(ifs, TheMemory.Memory[i].command);
	}
	
	ifs.close();
	pcb->ID = ID++;
	if (pcb->ID) {
		pcb->TranformStates(Ready);
	}
	//���½��Ľ��̼���ľ�������
	//int length = atoi();
}
PPCB Process::SeekBlankPCB()
{
	for (int i = 0; i < 9; i++) {
		if (pcbArray[i].flag)
			continue;
		return &pcbArray[i];
	}  return NULL;
}


// ��������
int Process::Block()
{
	//���뵽��������
	PCB_Blocked.Push(theRegister.pcb);
	// TODO: �ڴ˴����ʵ�ִ���.
	return 0;
}


// ���н��̻���
int Process::WeakUp()
{
	// TODO: �ڴ˴����ʵ�ִ���.
	PPCB p = PCB_Blocked.Pop();

	//��������ʾ�ڶԻ�����
	CString temp;
	temp.Format(_T("%s ->%d\n"), p->Name.c_str(), p->Date);
	Result += temp;

	p->PState = Ready;
	PCB_Ready.Push(p);
	return 0;
}


// ���ٽ��̵ĺ���
void Process::Destery()
{
	// TODO: �ڴ˴����ʵ�ִ���.
	PPCB temp= theRegister.pcb;
	//�ͷŽ��̵���ռ���ڴ�
	TheMemory.Free(temp->page);
	//��ʼ������
	temp->Initialize();
}
