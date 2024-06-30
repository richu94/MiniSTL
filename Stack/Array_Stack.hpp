#pragma once
#include "Array.hpp"


template<class T>
class Array_Stack
{
public:
	/*���캯��*/
	Array_Stack(int len);

	/*��������*/
	~Array_Stack();

	/*��ȡ����*/
	int StackSize();

	/*��ȡջ��Ԫ��*/
	T StackTop();

	/*�ж�ջΪ��ջ*/
	bool StackEmpty();

	/*��ջ*/
	void StackPush(T val);

	/*��ջ*/
	void StackPop();

	/*��ӡջ*/
	void StackPrint();
private:
	int len;
	Array<T>* array;
};


/*��ȡջ��Ԫ��*/
template<class T>
int Array_Stack<T>::StackSize()
{
	return this->len;
}

/*��ȡջ��Ԫ��*/
template<class T>
T Array_Stack<T>::StackTop()
{
	return array->ArrayGetById(this->len);
}

/*���캯��*/
template<class T>
Array_Stack<T>::Array_Stack(int len)
{
	this->len = len;
	this->array = new Array<T>(len);
}

/*��������*/
template<class T>
Array_Stack<T>::~Array_Stack()
{
	free(this->array);
}

/*�ж�ջΪ��ջ*/
template<class T>
bool Array_Stack<T>::StackEmpty()
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
void Array_Stack<T>::StackPush(T val)
{
	std::cout << "��ջ" << std::endl;
	this->array->InsertEnd(val);
	++this->len;
}

/*��ջ*/
template<class T>
void Array_Stack<T>::StackPop()
{
	std::cout << "��ջ" << std::endl;
	this->array->ArrayDelete(this->len-1);
}

/*��ӡջ*/
template<class T>
void Array_Stack<T>::StackPrint()
{
	this->array->PrintArray();
}