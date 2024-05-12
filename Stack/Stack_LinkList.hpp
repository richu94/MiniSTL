#pragma once
#include "LinkList.hpp"


template<class T>
class Stack_linklist
{
public:
	/*���캯��*/
	Stack_linklist(int len);

	/*��������*/
	~Stack_linklist();

	/*��ȡ����*/
	int StackSizeLinkList();

	/*��ȡջ��Ԫ��*/
	T StackTopLinkList();

	/*�ж�ջΪ��ջ*/
	bool StackEmptyLinkList();

	/*��ջ*/
	void StackPushLinkList(T val);

	/*��ջ*/
	void StackPopLinkList();

	/*��ӡջ*/
	void StackPrintLinkList();
private:
	int len;
	LinkList<T>* Linklist;
};


/*��ȡջ��С*/
template<class T>
int Stack_linklist<T>::StackSizeLinkList()
{
	return this->len;
}

/*��ȡջ��Ԫ��*/
template<class T>
T Stack_linklist<T>::StackTopLinkList()
{
	return this->Linklist->getvalLinkList(this->Linklist,this->len - 1);
}

/*���캯��*/
template<class T>
Stack_linklist<T>::Stack_linklist(int len)
{
	this->len = len;
	this->Linklist = new LinkList<T>(len);
}

/*��������*/
template<class T>
Stack_linklist<T>::~Stack_linklist()
{
	free(this->Linklist);
}

/*�ж�ջΪ��ջ*/
template<class T>
bool Stack_linklist<T>::StackEmptyLinkList()
{
	if (this->len == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

/*��ջ*/
template<class T>
void Stack_linklist<T>::StackPushLinkList(T val)
{
	std::cout << "��ջ" << std::endl;
	this->Linklist->InsertValue(this->Linklist,len+1,val);
	this->len++;
}

/*��ջ*/
template<class T>
void Stack_linklist<T>::StackPopLinkList()
{
	std::cout << "��ջ" << std::endl;
	this->Linklist->deleteLinkListbyid(this->Linklist,len);
}

/*��ӡջ*/
template<class T>
void Stack_linklist<T>::StackPrintLinkList()
{
	this->Linklist->LinkListprint();
}