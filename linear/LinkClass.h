#pragma once
#include<iostream>
#include"LinearClass.h"

//linklist���ݽṹʵ��
struct LinkNode {//��������Ķ���
	int data;                //������
	LinkNode* link;     //��ָ����
	LinkNode(LinkNode* ptr = NULL)
	{
		link = ptr;
	} 			//����ʼ��ָ���Ա�Ĺ��캯��
	LinkNode(const int& item, LinkNode* ptr = NULL)
	{
		data = item;   link = ptr;
	} 		//��ʼ��������ָ���Ա�Ĺ��캯�� 
};

class LinkList:public LinearList {
	//�������ඨ��, ���ü̳�Ҳ��ʵ��
protected:
	LinkNode* first;	 //��ͷָ��
public:
	LinkList() { first = new LinkNode; }  //���캯��
	LinkList(const int& x) { first = new LinkNode(x); }
	LinkList(LinkList& L);		//���ƹ��캯��
	~LinkList() { makeEmpty(); }       //��������
	void makeEmpty();	     //��������Ϊ�ձ�
	virtual int Length() const;	     //��������ĳ���
	LinkNode* getHead() const  //���ظ���ͷ����ַ
	{
		return first;
	}
	LinkNode* Search(int x);	//������xԪ��
	LinkNode* Locate(int i)const; //������i��Ԫ�صĵ�ַ
	virtual int Size()const { return -1; }//���ر�������������Ϊ�������Ϊ-1��
	virtual int Search(int& x)const;//������x��λ�ã�������ʹ�ã�
	virtual bool getData(int i, int& x)const;      	//ȡ����iԪ��ֵ
	virtual void setData(int i, int& x);		//���µ�iԪ��ֵ
	virtual bool Insert(int i, int& x);	    	//�ڵ�iԪ�غ����
	virtual bool Insert(int& x);      //����������
	virtual bool Remove(int i, int& x);	 //ɾ����i��Ԫ��
	virtual bool IsEmpty() const 		 //�б�շ�
	{
		return first->link == NULL ? true : false;
	}
	virtual bool IsFull() const { return false; }	 //�б�����
	virtual void Sort();			 //����
	virtual void input();
	virtual void output();
	LinkList& operator=(LinkList& L);   //���غ�������ֵ
};
