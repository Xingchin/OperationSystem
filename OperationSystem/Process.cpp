#include "pch.h"
#include "Process.h"
#include <fstream>
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
	atoi(temp.c_str());
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
