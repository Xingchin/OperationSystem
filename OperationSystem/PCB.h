
#pragma once

#include "Define.cpp"
#include <string>
using namespace std;
class PCB
{
public:
	// ����ǰ��״̬
	PStates PState;
	// ����ǰִ�еĵ�ַ
	int PC;
	// �����ID���
	int ID;
	// �����г������һ��ָ��
	PPCB Next;
	// ����Ľ��
	int Date;
	// ��������ҳ��
	Page page;
	int Initialize();
	// �ý��̿��Ƿ����ڱ�ʹ�ã�true���ڱ�ʹ�ã�false�������
	bool flag;
	// Ҫ���ص��ļ�����
	string flieName;
	// ����ָ��ڴ���
	int LoadCommand();
};

