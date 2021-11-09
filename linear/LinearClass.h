#pragma once
#include<iostream>

class LinearList {
public:
    LinearList();				                   //���캯��
    ~LinearList();			                       //��������
    virtual int Size() const = 0;	               //���������
    virtual int Length() const = 0;	               //�����
    virtual int Search(int& x) const = 0;            //����
    virtual bool getData(int i, int& x) const = 0;   //ȡֵ
    virtual void setData(int i, int& x) = 0;         //��ֵ  
    virtual bool Insert(int i, int& x) = 0;          //����̶�λ�ú�
    virtual bool Insert(int& x) = 0;          //������
    virtual bool Remove(int i, int& x) = 0;	       //ɾ��
    virtual bool IsEmpty() const = 0;	           //�б�� 
    virtual bool IsFull() const = 0;               //�б���
    virtual void Sort() = 0;			           //����
    virtual void input() = 0;			           //����
    virtual void output() = 0;			           //���
    //virtual LinearList operator=  (LinearList& L) = 0;	 //����
};