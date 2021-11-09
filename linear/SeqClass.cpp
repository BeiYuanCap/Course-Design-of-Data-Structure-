#include"pch.h"
#include"SeqClass.h"
//成员函数实现

SeqList::SeqList(int sz) {
	//构造函数，sz为数组长度
	if (sz > 0) {
		maxSize = sz; last = -1;
		data = new int[maxSize];
		if (data == NULL)
		{
			MessageBoxA(NULL, "存储分配错误！", "提示", MB_OK); exit(1);
		}
	}
}

SeqList::SeqList(SeqList& L) {
	//复制构造函数
	maxSize = L.Size(); last = L.Length() - 1; int value;
	data = new int[maxSize];
	if (data == NULL)
	{
		MessageBoxA(NULL, "存储分配错误！", "提示", MB_OK); exit(1);
	}
	for (int i = 1; i <= last + 1; i++)
	{
		L.getData(i, value); data[i - 1] = value;
	}
}

void SeqList::reSize(int newSize) {
	//私有函数，扩充顺序表存储数组空间大小
	if (newSize <= 0)
	{
		MessageBoxA(NULL, "无效的数组大小！", "提示", MB_OK); return;
	}
	if (newSize != maxSize) {        //修改
		int* newarray = new int[newSize];//建立新数组
		if (newarray == NULL)
		{
			MessageBoxA(NULL, "存储分配错误！", "提示", MB_OK); exit(1);
		}
		int n = last + 1;
		int* srcptr = data;            //源数组首地址
		int* destptr = newarray;       //目的数组首地址
		while (n--)*destptr++ = *srcptr++;//复制
		delete[]data;                //删老数组
		data = newarray; maxSize = newSize;//复制新数组
	}
}

int SeqList::Search(int& x)const {
	//搜索函数：搜索与x匹配的表项，找到后返回是第几个元素
	//否则返回0
	for (int i = 0; i <= last; i++)
		if (data[i] == x)return i + 1;//顺序搜索
	return 0;                         //搜索失败
}

int SeqList::Locate(int i)const {
	//定位函数：函数返回第i个表项的位置，否则返回0；
	if (i >= 1 && i <= last + 1)return i;
	else return 0;
}

bool SeqList::Insert(int i, int& x) {
	//将x插入到第i个表项后
	if (last == maxSize - 1)return false;//表满
	if (i<0 || i>last + 1)return false;//参数i不合理
	for (int j = last; j >= i; j--)
		data[j + 1] = data[j];//依次后移
	data[i] = x;              //插入
	last++;                   //最后位置加1
	return true;              //插入成功
}

bool SeqList::Insert(int& x) {
	//将x插入到第i个表项后
	if (last == maxSize - 1)return false;//表满
	data[last] = x;              //插入
	last++;                   //最后位置加1
	return true;              //插入成功
}

bool SeqList::Remove(int i, int& x) {
	//将第i个表项删除，通过x返回元素值
	if (last == -1)return false;//表空
	if (i<1 || i>last + 1)return false;//参数i不合理
	x = data[i - 1];          //存被删元素
	for (int j = i; j <= last; j--)
		data[j - 1] = data[j];//依次前移
	last--;                   //最后位置减1
	return true;              //删除成功
}

void SeqList::input() {
	//从键盘逐个数据输入，建立顺序表，遇到@停止

}

void SeqList::output() {
	//将顺序表全部元素输出到屏幕上
	/*cout << "顺序表当前元素最后位置为：" << last << endl;*/
	/*for (int i = 0; i <= last; i++)
		cout << "#" << i + 1 << ":" << data[i] << endl;*/
}

SeqList& SeqList::operator=(SeqList& L) {
	maxSize = L.Size(); last = L.Length() - 1; int value;
	data = new int[maxSize];
	if (data == NULL)
	{
		MessageBoxA(NULL, "存储分配错误！", "提示", MB_OK); exit(1);
	}
	for (int i = 1; i <= last + 1; i++)
	{
		L.getData(i, value); data[i - 1] = value;
	}
}