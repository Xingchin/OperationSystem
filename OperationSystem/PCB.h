
#pragma once

#include "Define.h"
#include <string>

using namespace std;
class PCB
{
public:
	// ����ǰ��״̬
	PStates PState;
	// ����ǰִ�еĵ�ַ
	int PC;
	// �����ID��ţ��ڲ�����
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
	// Ҫ���ص��ļ�����,�ⲿ����
	string Name;
	void Config(Page _page,string name);
	// �ı���̿��״̬�������뵽��ض���
	void TranformStates(PStates state);
	PCB();
	PCB(string name);
	// �ý���Ҫ������ʱ��
	int BlockedTime;
	// ����ʱ��

};

