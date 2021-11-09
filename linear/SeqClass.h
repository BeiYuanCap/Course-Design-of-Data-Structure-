#pragma once
#include<iostream>
#include"LinearClass.h"

const int defaultSize = 100;

class SeqList :public LinearList {
protected:
	int* data;		     		                    //�������
	int maxSize;	                          		//�������ɱ��������
	int last;	    			                    //��ǰ�Ѵ��������λ��(��0��ʼ)
	void reSize(int newSize);		                //�ı�����ռ��С
public:
	SeqList(int sz = defaultSize);          	    //���캯��
	SeqList(SeqList& L);	                     	//���ƹ��캯��
	~SeqList() { delete[] data; }	           	    //��������
	virtual int Size() const { return maxSize; }	        //����������
	virtual int Length() const { return last + 1; }        	//�������
	virtual int Search(int& x) const;      		            //����x�ڱ���λ�ã��������ر������
	virtual int Locate(int i) const;       		            //��λ�� i ������������ر������
	virtual bool Insert(int i, int& x);		            	//����x�ڵ�i������֮��
	virtual bool Insert(int& x);		            	    //����x��˳����
	virtual bool Remove(int i, int& x);	                   	//ɾ����i������
	virtual bool getData(int i, int& x)const                    //ȡ��i�������ֵ
	{
		if (i > 0 && i <= last + 1) { x = data[i - 1]; return true; }
		else return false;
	}
	virtual void setData(int i, int& x)                       //��x�޸ĵ�i�������ֵ
	{
		if (i > 0 && i <= last + 1) { data[i - 1] = x; }
	}
	virtual bool IsEmpty()const { return(last == -1) ? true : false; }
	//�жϱ��Ƿ�Ϊ�� 
	virtual bool IsFull()const { return(last == maxSize - 1) ? true : false; }
	//�жϱ��Ƿ����� 
	virtual void Sort();                                    //����
	virtual void input();                                   //����
	virtual void output();                                  //���
	SeqList& operator = (SeqList& L);             //���帳ֵ
};