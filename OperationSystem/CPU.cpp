#include "pch.h"
#include "CPU.h"
#include"Global.h"
void CPU::Deal() {
	
}

// ����IR�е�ָ��
void CPU::DealIR()
{
	// TODO: �ڴ˴����ʵ�ִ���.
	if (theRegister.IR[1] == '=') {
		theRegister.DR = theRegister.IR[2] - '0';
	}
	else if (theRegister.IR[1] == '+') {
		theRegister.DR++;
	}
	else if (theRegister.IR[1] == '-') {
		theRegister.DR--;
	}
	else if (theRegister.IR[0] == '!') {

	}
	else if (theRegister.IR[0] == 'E') {

	}
}
