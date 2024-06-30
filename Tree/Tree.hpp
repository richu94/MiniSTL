#pragma once
#include "Array.hpp"
#include "LinkList_Stack.hpp"

template<class T>
class Tree {
public:
	Tree(T value,Array<Tree*> child);
	~Tree();
	Array<Tree<T>*> TreeTraverse();
private:
	T val;
	Array<Tree*> child;
};

//���캯��
template<class T>
Tree<T>::Tree(T value, Array<Tree*> child) {
	this->child = child;
	this->val = value;
}

//��������
template<class T>
Tree<T>::~Tree() {
	delete this->val;
	delete this->child;
}

//�������
template<class T>
Array<Tree<T>*> Tree<T>::TreeTraverse() {
	
}

void dfs() {

}