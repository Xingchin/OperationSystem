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
	// ����ʱ��Ƭ�ĸ���
	void UpdateTime();
};

