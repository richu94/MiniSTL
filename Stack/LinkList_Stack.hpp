#pragma once
#include "LinkList.hpp"


template<class T>
class LinkList_Stack
{
public:
	/*���캯��*/
	LinkList_Stack(int len);

	/*��������*/
	~LinkList_Stack();

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
int LinkList_Stack<T>::StackSizeLinkList()
{
	return this->len;
}

/*��ȡջ��Ԫ��*/
template<class T>
T LinkList_Stack<T>::StackTopLinkList()
{
	return this->Linklist->getvalLinkList(this->Linklist,this->len - 1);
}

/*���캯��*/
template<class T>
LinkList_Stack<T>::LinkList_Stack(int len)
{
	this->len = len;
	this->Linklist = new LinkList<T>(len);
}

/*��������*/
template<class T>
LinkList_Stack<T>::~LinkList_Stack()
{
	free(this->Linklist);
}

/*�ж�ջΪ��ջ*/
template<class T>
bool LinkList_Stack<T>::StackEmptyLinkList()
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
void LinkList_Stack<T>::StackPushLinkList(T val)
{
	std::cout << "��ջ" << std::endl;
	this->Linklist->InsertValue(this->Linklist,len+1,val);
	this->len++;
}

/*��ջ*/
template<class T>
void LinkList_Stack<T>::StackPopLinkList()
{
	std::cout << "��ջ" << std::endl;
	this->Linklist->deleteLinkListbyid(this->Linklist,len);
}

/*��ӡջ*/
template<class T>
void LinkList_Stack<T>::StackPrintLinkList()
{
	this->Linklist->LinkListprint();
}