#include"pch.h"
#include"LinkClass.h"

//LinkList函数实现
LinkList::LinkList(LinkList& L) {
	//复制构造函数
	int value;
	LinkNode* srcptr = L.getHead();          //被复制表的附加头结点地址
	LinkNode* destptr = first = new LinkNode;
	while (srcptr->link != NULL) {              //逐个结点复制
		value = srcptr->link->data;
		destptr->link = new LinkNode(value);
		destptr = destptr->link;
		srcptr = srcptr->link;
	}
	destptr->link = NULL;
}

void LinkList::makeEmpty() {
	//将链表置为空
	LinkNode* q;
	while (first->link != NULL) {
		q = first->link;
		first->link = q->link;
		delete q;
	}
}

int LinkList::Length()const {
	//计算带附加头结点的单链表长度
	LinkNode* p = first->link; int count = 0;
	while (p != NULL)
	{
		p = p->link; count++;
	}
	return count;
}

LinkNode* LinkList::Search(int x) {
	//搜索数据x的结点，返回该结点地址
	LinkNode* current = first->link;
	while (current != NULL)
		if (current->data == x)break;
		else current = current->link;
	return current;
}

LinkNode* LinkList::Locate(int i)const {
	//定位函数，返回第i个元素的地址
	if (i < 0)return NULL;//i值不合理
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
	//取出链表中第i个元素的值
	if (i <= 0) return NULL;//i值太小
	LinkNode* current = Locate(i);
	if (current == NULL)return false;//i值太大
	else { x = current->data; return true; }
}

void LinkList::setData(int i, int& x) {
	//给链表中第i个元素赋值x
	if (i <= 0)return;//i值太小
	LinkNode* current = Locate(i);
	if (current == NULL)return;//i值太大
	else current->data = x;
}

bool LinkList::Insert(int i, int& x) {
	//将新元素x插入在链表中第i个结点之后
	LinkNode* current = Locate(i);
	if (current == NULL)return false;//插入不成功
	LinkNode* newNode = new LinkNode(x);
	if (newNode == NULL) { MessageBoxA(NULL, "存储分配错误！", "提示", MB_OK); exit(1); }
	newNode->link = current->link;
	current->link = newNode;
	return true;
}

bool LinkList::Insert(int& x) {
	//将新元素x插入在链表后
	LinkNode* current;
	for (current = first; current->link != NULL;)
	{
		current = current->link;
	}
	if (current == NULL)return false;//插入不成功
	LinkNode* newNode = new LinkNode(x);
	if (newNode == NULL) { MessageBoxA(NULL,"存储分配错误！","提示",MB_OK); exit(1); }
	newNode->link = current->link;
	current->link = newNode;
	return true;
}

bool LinkList::Remove(int i, int& x) {
	//将链表中第i个元素删除，并通过x返回该元素的值
	LinkNode* current = Locate(i - 1);
	if (current == NULL || current->link == NULL)return false;//删除不成功
	LinkNode* del = current->link;
	x = del->data; delete del;
	return true;
}

void LinkList::Sort() {

}

void LinkList::input() {

}

void LinkList::output() {
	//单链表输出函数
	LinkNode* current = first->link;
	while (current != NULL) {
		/*cout << current->data << endl;*/
		current = current->link;
	}
}

LinkList& LinkList::operator=(LinkList& L) {
	//重载赋值操作
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
	return *this;//返回操作对象地址
}
