#include"pch.h"
#include"LinkClass.h"

//LinkList����ʵ��
LinkList::LinkList(LinkList& L) {
	//���ƹ��캯��
	int value;
	LinkNode* srcptr = L.getHead();          //�����Ʊ�ĸ���ͷ����ַ
	LinkNode* destptr = first = new LinkNode;
	while (srcptr->link != NULL) {              //�����㸴��
		value = srcptr->link->data;
		destptr->link = new LinkNode(value);
		destptr = destptr->link;
		srcptr = srcptr->link;
	}
	destptr->link = NULL;
}

void LinkList::makeEmpty() {
	//��������Ϊ��
	LinkNode* q;
	while (first->link != NULL) {
		q = first->link;
		first->link = q->link;
		delete q;
	}
}

int LinkList::Length()const {
	//���������ͷ���ĵ�������
	LinkNode* p = first->link; int count = 0;
	while (p != NULL)
	{
		p = p->link; count++;
	}
	return count;
}

LinkNode* LinkList::Search(int x) {
	//��������x�Ľ�㣬���ظý���ַ
	LinkNode* current = first->link;
	while (current != NULL)
		if (current->data == x)break;
		else current = current->link;
	return current;
}

LinkNode* LinkList::Locate(int i)const {
	//��λ���������ص�i��Ԫ�صĵ�ַ
	if (i < 0)return NULL;//iֵ������
	LinkNode* current = first; int k = 0;
	while (current != NULL && k < i)
	{
		current = current->link; k++;
	}
	return current;
}

int LinkList::Search(int& x)const {
	LinkNode* current = first; 
	while (current != NULL ||current->data!=x)
	{
		current = current->link;
	}
	return current->data;
}

bool LinkList::getData(int i, int& x)const {
	//ȡ�������е�i��Ԫ�ص�ֵ
	if (i <= 0) return NULL;//iֵ̫С
	LinkNode* current = Locate(i);
	if (current == NULL)return false;//iֵ̫��
	else { x = current->data; return true; }
}

void LinkList::setData(int i, int& x) {
	//�������е�i��Ԫ�ظ�ֵx
	if (i <= 0)return;//iֵ̫С
	LinkNode* current = Locate(i);
	if (current == NULL)return;//iֵ̫��
	else current->data = x;
}

bool LinkList::Insert(int i, int& x) {
	//����Ԫ��x�����������е�i�����֮��
	LinkNode* current = Locate(i);
	if (current == NULL)return false;//���벻�ɹ�
	LinkNode* newNode = new LinkNode(x);
	if (newNode == NULL) { MessageBoxA(NULL, "�洢�������", "��ʾ", MB_OK); exit(1); }
	newNode->link = current->link;
	current->link = newNode;
	return true;
}

bool LinkList::Insert(int& x) {
	//����Ԫ��x�����������
	LinkNode* current;
	for (current = first; current->link != NULL;)
	{
		current = current->link;
	}
	if (current == NULL)return false;//���벻�ɹ�
	LinkNode* newNode = new LinkNode(x);
	if (newNode == NULL) { MessageBoxA(NULL,"�洢�������","��ʾ",MB_OK); exit(1); }
	newNode->link = current->link;
	current->link = newNode;
	return true;
}

bool LinkList::Remove(int i, int& x) {
	//�������е�i��Ԫ��ɾ������ͨ��x���ظ�Ԫ�ص�ֵ
	LinkNode* current = Locate(i - 1);
	if (current == NULL || current->link == NULL)return false;//ɾ�����ɹ�
	LinkNode* del = current->link;
	x = del->data; delete del;
	return true;
}

void LinkList::Sort() {

}

void LinkList::input() {

}

void LinkList::output() {
	//�������������
	LinkNode* current = first->link;
	while (current != NULL) {
		/*cout << current->data << endl;*/
		current = current->link;
	}
}

LinkList& LinkList::operator=(LinkList& L) {
	//���ظ�ֵ����
	int value;
	LinkNode* srcptr = L.getHead();
	LinkNode* destptr = first = new LinkNode;
	while (srcptr->link != NULL) {
		value = srcptr->link->data;
		destptr->link = new LinkNode(value);
		destptr = destptr->link;
		srcptr = srcptr->link;
	}
	destptr->link = NULL;
	return *this;//���ز��������ַ
}
