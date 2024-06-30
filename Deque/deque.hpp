#pragma once
#include "LinkList.hpp"

template<class T>
class deque {
public:
	deque(int len);
	deque(int len,T res);
	~deque();

	/*��ȡ����*/
	int DequeSizeLinkList();

	/*��ȡ��ͷԪ��*/
	T DequeTopLinkList();

	/*��ȡ��βԪ��*/
	T DequeBottomLinkList();

	/*�ж�ջΪ�ն���*/
	bool DequeEmptyLinkList();

	/*���*/
	void DeuqePushLinkList(T val);

	/*����*/
	void DequePopLinkList();

	/*��ӡ����*/
	void DequePrintLinkList();
private:
	int len;
	LinkList<T>* Linklist;
};

template<class T>
deque<T>::deque(int len) {
	this->Linklist = new LinkList<T>(len,0);
}

template<class T>
deque<T>::deque(int len,T res) {
	this->len = len;
	this->Linklist = new LinkList<T>(len, res);
}

template<class T>
deque<T>::~deque() {
	delete this->Linklist;
}

//��ȡ���еĳ���
template<class T>
int deque<T>::DequeSizeLinkList() {
	return this->len;
}

//��ȡ��ͷԪ��
template<class T>
T deque<T>::DequeTopLinkList() {
	return this->Linklist->getvalLinkList(this->Linklist, this->len);
}


//��ȡ�ӵ�Ԫ��
template<class T>
T deque<T>::DequeBottomLinkList() {
	return this->Linklist->getvalLinkList(this->Linklist, 0);
}

//�ж��Ƿ�Ϊ�ն���
template<class T>
bool deque<T>::DequeEmptyLinkList() {
	if (this->len != 0) {
		return false;
	}
	else {
		return true;
	}
}

//��ӡ����
template<class T>
void deque<T>::DequePrintLinkList() {
	this->Linklist->LinkListprint();
}

//����
template<class T>
void deque<T>::DequePopLinkList() {
	this->Linklist = this->Linklist->popLinkList(this->Linklist);
	this->len = this->len - 1;
}

//���
template<class T>
void deque<T>::DeuqePushLinkList(T value) {
	this->Linklist = this->Linklist->InsertValue(this->Linklist, this->len+1, value);
	this->len = this->len + 1;
}
