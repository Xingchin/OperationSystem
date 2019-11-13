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
		getline(ifs, TheMemory.Memory[addr].command);
	}
	
	ifs.close();
	//int length = atoi();
}
PPCB Process::SeekBlankPCB()
{
	for (int i = 1; i < 9; i++) {
		if (pcbArray[i].flag)
			continue;
		return &pcbArray[i];
	}  return NULL;
}
