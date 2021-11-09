#pragma once
#include<iostream>

class LinearList {
public:
    LinearList();				                   //构造函数
    ~LinearList();			                       //析构函数
    virtual int Size() const = 0;	               //求表最大体积
    virtual int Length() const = 0;	               //求表长度
    virtual int Search(int& x) const = 0;            //搜索
    virtual bool getData(int i, int& x) const = 0;   //取值
    virtual void setData(int i, int& x) = 0;         //赋值  
    virtual bool Insert(int i, int& x) = 0;          //插入固定位置后
    virtual bool Insert(int& x) = 0;          //插入表后
    virtual bool Remove(int i, int& x) = 0;	       //删除
    virtual bool IsEmpty() const = 0;	           //判表空 
    virtual bool IsFull() const = 0;               //判表满
    virtual void Sort() = 0;			           //排序
    virtual void input() = 0;			           //输入
    virtual void output() = 0;			           //输出
    //virtual LinearList operator=  (LinearList& L) = 0;	 //复制
};