#pragma once
#include<iostream>
#include"LinearClass.h"

//linklist数据结构实现
struct LinkNode {//链表结点类的定义
	int data;                //数据域
	LinkNode* link;     //链指针域
	LinkNode(LinkNode* ptr = NULL)
	{
		link = ptr;
	} 			//仅初始化指针成员的构造函数
	LinkNode(const int& item, LinkNode* ptr = NULL)
	{
		data = item;   link = ptr;
	} 		//初始化数据与指针成员的构造函数 
};

class LinkList:public LinearList {
	//单链表类定义, 不用继承也可实现
protected:
	LinkNode* first;	 //表头指针
public:
	LinkList() { first = new LinkNode; }  //构造函数
	LinkList(const int& x) { first = new LinkNode(x); }
	LinkList(LinkList& L);		//复制构造函数
	~LinkList() { makeEmpty(); }       //析构函数
	void makeEmpty();	     //将链表置为空表
	virtual int Length() const;	     //计算链表的长度
	LinkNode* getHead() const  //返回附加头结点地址
	{
		return first;
	}
	LinkNode* Search(int x);	//搜索含x元素
	LinkNode* Locate(int i)const; //搜索第i个元素的地址
	virtual int Size()const { return -1; }//返回表最大体积（链表为无穷大，设为-1）
	virtual int Search(int& x)const;//搜索数x的位置（链表不可使用）
	virtual bool getData(int i, int& x)const;      	//取出第i元素值
	virtual void setData(int i, int& x);		//更新第i元素值
	virtual bool Insert(int i, int& x);	    	//在第i元素后插入
	virtual bool Insert(int& x);      //在链表后插入
	virtual bool Remove(int i, int& x);	 //删除第i个元素
	virtual bool IsEmpty() const 		 //判表空否
	{
		return first->link == NULL ? true : false;
	}
	virtual bool IsFull() const { return false; }	 //判表满否
	virtual void Sort();			 //排序
	virtual void input();
	virtual void output();
	LinkList& operator=(LinkList& L);   //重载函数：赋值
};
