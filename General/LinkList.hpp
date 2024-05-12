#pragma once
#include <iostream>

template<class T>
class LinkList
{
public:
	LinkList();
	~LinkList();
	//��������--ͷ�巨
	//����һ����ͷ��������
	LinkList* CreatLinkList_head(int length);

	//��������β�巨
	LinkList* CreatLinkList_back(int length);

	//ͳ������ĳ���
	int LinkListlength(LinkList* L);

	//��ӡ����
	void LinkListprint(LinkList* L);

	//��������ĺ���
	//��ø�λ�õ�ָ����
	LinkList* LinkListTraverse(LinkList* L, int n);

	//����һ�����
	//eΪ�����λ��,������e-1��λ��
	LinkList* InsertLinkList(LinkList* L, int e);

	//���ָ��������ֵ
	T getvalLinkList(LinkList* L, int e);

	//�������
	LinkList* ClearLinkList(LinkList* L);

	//ɾ������
	void DeleteLinkList(LinkList* L);

	//�ϲ�����
	LinkList* groupLinkList(LinkList* L1, LinkList* L2);

	//��ת����
	LinkList* reverseLinkList(LinkList* L);

	//��������ϵ���
	T countLinkList(LinkList* L);

	//�����������ϵ���
	LinkList* exchangeLinkList(LinkList* L1, int l1, int l2);

	//ɾ��ָ���ڵ�
	LinkList* deleteLinkListbyid(LinkList* L, int l1);
private:
	T val;
	LinkList* Ln;
};
template<class T>
LinkList<T>::LinkList()
{
	this->val = 0;
	this->Ln = NULL;
}
template<class T>
LinkList<T>::~LinkList()
{
	free(this->Ln);
}
//��������--ͷ�巨
//����һ����ͷ��������

template<class T>
LinkList<T>* LinkList<T>::CreatLinkList_head(int length)
{
	//ͷ���
	LinkList* L1 = new LinkList();
	L1->Ln = NULL;
	//ͷָ��
	LinkList* p = L1;
	for (int i = length - 1; i >= 0; i--)
	{
		LinkList* temp = new LinkList();
		std::cout << "�÷���Ϊͷ�巨�Ӻ���ǰ����";
		std::cout << "�������" << i + 1 << "��Ԫ��" << std::endl;
		std::cin >> temp->val;
		//��ʼͷ��
		//���޸Ĳ��������ָ����
		temp->Ln = p->Ln;
		//���޸�ͷ����ָ����
		p->Ln = temp;
	}
	return p;
}

//��������β�巨
template<class T>
LinkList<T>* LinkList<T>::CreatLinkList_back(int length)
{
	//ͷ���
	LinkList* L1 = new LinkList();
	//ͷָ��
	LinkList* p = L1;
	p->Ln = NULL;
	//����һ����¼ָ�����ڼ�¼����λ��ǰһ������ָ����
	LinkList* t = new LinkList();
	t = p;
	for (int i = 0; i < length; i++)
	{
		LinkList* temp = new LinkList();
		std::cout << "�÷���Ϊβ�巨��ǰ�������";
		std::cout << "�������" << i + 1 << "��Ԫ��" << std::endl;
		std::cin >> temp->val;
		//�Ƚ�ָ���ָ����ֵ����ʱ����
		t->Ln = temp;
		//��ָ��������к���λ
		t = temp;
		//����һ���ÿգ��ؼ�һ��
		t->Ln = NULL;
	}
	return p;
}

//ͳ������ĳ���
template<class T>
int LinkList<T>::LinkListlength(LinkList* L)
{
	int len = 0;
	if (L == NULL || L->Ln == NULL)
	{
		std::cout << "error" << std::endl;
		return -1;
	}
	L = L->Ln;
	while (L != NULL)
	{
		len++;
		L = L->Ln;
	}
	return len;
}

//��ӡ����
template<class T>
void LinkList<T>::LinkListprint(LinkList* L)
{
	int i = 0;
	if (L == NULL || L->Ln == NULL)
	{
		std::cout << "error" << std::endl;
		return;
	}
	L = L->Ln;
	while (L != NULL)
	{
		std::cout << "��" << ++i << "��Ԫ��Ϊ";
		std::cout << L->val << std::endl;
		L = L->Ln;
	}
}

//��������ĺ���
//��ø�λ�õ�ָ����
template<class T>
LinkList<T>* LinkList<T>::LinkListTraverse(LinkList* L, int n)
{
	L = L->Ln;
	if (n == 0)
	{
		return L;
	}
	for (int i = 0; i < n; i++)
	{
		if (L != NULL)
		{
			L = L->Ln;
		}
		else
		{
			std::cout << "���������λ��û�н��" << std::endl;
			return 0;
		}
	}
	return L;
}

//����һ�����
//eΪ�����λ��,������e-1��λ��
template<class T>
LinkList<T>* LinkList<T>::InsertLinkList(LinkList* L, int e)
{
	if (e <= 0)
	{
		std::cout << "ERROR" << std::endl;
		return 0;
	}
	LinkList* p = new LinkList();
	p->Ln = NULL;
	std::cout << "���������ֵ" << std::endl;
	std::cin >> p->val;
	//ͷ������һ��Ϊ�գ���ֻ��һ��ͷ���
	if (L->Ln == NULL)
	{
		L->Ln = p;
	}
	//ȡ��ǰһ��Ԫ�ص�ָ����
	else
	{
		LinkList* temp = LinkListTraverse(L, e - 1);
		//�½�����ָ����ָ������ǰ��ָ����
		p->Ln = temp->Ln;
		//�޸�����ǰ��ָ����ָ���½�ָ��
		temp->Ln = p;
	}
	return L;
}

//���ָ��������ֵ
template<class T>
T LinkList<T>::getvalLinkList(LinkList* L, int e)
{
	int length = LinkListlength(L);
	if (e > length - 1 || e < 0)
	{
		std::cout << "û�и�����" << std::endl;
		return -1;
	}
	LinkList* l1 = LinkListTraverse(L, e + 1);
	return l1->val;
}

//�������
template<class T>
LinkList<T>* LinkList<T>::ClearLinkList(LinkList* L)
{
	LinkList* nLn = new LinkList();
	nLn->Ln = NULL;
	int length = LinkListlength(L);

	for (int i = 0; i < length - 1; i++)
	{
		LinkList* temp = L->Ln;

		delete L;

		L = temp->Ln;
	}
	delete L;
	return nLn;
}

//ɾ������
template<class T>
void LinkList<T>::DeleteLinkList(LinkList* L)
{
	int length = LinkListlength(L);
	for (int i = 0; i < length - 1; i++)
	{
		LinkList* temp = L->Ln;
		delete L;
		L = temp->Ln;
	}
}

//�ϲ�����
template<class T>
LinkList<T>* LinkList<T>::groupLinkList(LinkList* L1, LinkList* L2)
{
	int length1 = LinkListlength(L1);
	int length2 = LinkListlength(L2);
	LinkList* temp = L1;
	for (int i = 0; i < length1; i++)
	{
		temp = temp->Ln;
	}
	temp->Ln = L2->Ln;
	return L1;
}

//��ת����
template<class T>
LinkList<T>* LinkList<T>::reverseLinkList(LinkList* L)
{
	LinkList* nL = new LinkList();
	nL->Ln = NULL;
	int length = LinkListlength(L);
	L = L->Ln;

	for (int i = 0; i < length; i++)
	{
		int val = L->val;

		LinkList* temp2 = new LinkList();

		temp2->val = val;

		temp2->Ln = nL->Ln;

		nL->Ln = temp2;

		L = L->Ln;
	}
	return nL;
}

//��������ϵ���
template<class T>
T LinkList<T>::countLinkList(LinkList* L)
{
	int length = LinkListlength(L);
	L = L->Ln;
	int count = 0;
	for (int i = 0; i < length; i++)
	{
		count += L->val;
		L = L->Ln;
	}
	return count;
}

//�����������ϵ���
template<class T>
LinkList<T>* LinkList<T>::exchangeLinkList(LinkList* L1, int l1, int l2)
{

	LinkList* nL1 = LinkListTraverse(L1, l1);
	LinkList* nL2 = LinkListTraverse(L1, l2);
	int temp = 0;
	temp = nL1->val;
	nL1->val = nL2->val;
	nL2->val = temp;
	return L1;
}

//ɾ��ָ���ڵ�
template<class T>
LinkList<T>* LinkList<T>::deleteLinkListbyid(LinkList* L, int l1)
{
	LinkList* temp1 = LinkListTraverse(L, l1 - 1);
	LinkList* temp2 = LinkListTraverse(L, l1);
	temp1->Ln = temp2->Ln;
	delete temp2;
	return L;
}