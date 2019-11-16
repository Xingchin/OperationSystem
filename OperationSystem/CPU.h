#pragma once
class CPU
{
public:
	// ����������ָ��
	void Deal();
	// ����IR�е�ָ��
	void DealIR();
	bool Power = false;
	// //���г������
	void Dispatch();
	// ����IR�е�ָ��
	void UpdateIR();
	// �����ж�
	void DealInterrupt();
	int TimeSlice = 0;
	// ����ʱ��Ƭ�ĸ���
	void UpdateTime();
	// �������������еĽ���
	void UpdateBlockedProcess();
	void CheckProcessStates();
};

