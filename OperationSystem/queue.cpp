#include "pch.h"
#include "queue.h"
void queue::Push(PPCB pcb)
{
	Nail->Next = pcb;
	Nail = pcb;
	pcb->Next = NULL;
	// TODO: �ڴ˴����ʵ�ִ���.
}
queue::queue() {
	Head = (PPCB)malloc(sizeof(PCB));
	//Nail = Head;
	Head->Next =NULL;
	Nail = Head;
}

PPCB queue::Pop()
{
	if (Empty()) {
		return NULL;
	}
	// TODO: �ڴ˴����ʵ�ִ���.
	PPCB temp = Head->Next;
	if (!temp->Next) {
		Nail = Head;
	}
	Head->Next = temp->Next;
	return temp;
}


bool queue::Empty()
{
	// TODO: �ڴ˴����ʵ�ִ���.
	return !Head->Next;
}


// ��ȡͷ�ڵ�
PPCB queue::GetHead()
{
	// TODO: �ڴ˴����ʵ�ִ���.
	return Head->Next;
}
