#pragma once
#include<iostream>
#include"LinearClass.h"

const int defaultSize = 100;

class SeqList :public LinearList {
protected:
	int* data;		     		                    //存放数组
	int maxSize;	                          		//最大可容纳表项的项数
	int last;	    			                    //当前已存表项的最后位置(从0开始)
	void reSize(int newSize);		                //改变数组空间大小
public:
	SeqList(int sz = defaultSize);          	    //构造函数
	SeqList(SeqList& L);	                     	//复制构造函数
	~SeqList() { delete[] data; }	           	    //析构函数
	virtual int Size() const { return maxSize; }	        //求表最大容量
	virtual int Length() const { return last + 1; }        	//计算表长度
	virtual int Search(int& x) const;      		            //搜索x在表中位置，函数返回表项序号
	virtual int Locate(int i) const;       		            //定位第 i 个表项，函数返回表项序号
	virtual bool Insert(int i, int& x);		            	//插入x在第i个表项之后
	virtual bool Insert(int& x);		            	    //插入x在顺序表后
	virtual bool Remove(int i, int& x);	                   	//删除第i个表项
	virtual bool getData(int i, int& x)const                    //取第i个表项的值
	{
		if (i > 0 && i <= last + 1) { x = data[i - 1]; return true; }
		else return false;
	}
	virtual void setData(int i, int& x)                       //用x修改第i个表项的值
	{
		if (i > 0 && i <= last + 1) { data[i - 1] = x; }
	}
	virtual bool IsEmpty()const { return(last == -1) ? true : false; }
	//判断表是否为空 
	virtual bool IsFull()const { return(last == maxSize - 1) ? true : false; }
	//判断表是否已满 
	virtual void Sort();                                    //排序
	virtual void input();                                   //输入
	virtual void output();                                  //输出
	SeqList& operator = (SeqList& L);             //整体赋值
};