#include"pch.h"
#include"SeqClass.h"
//��Ա����ʵ��

SeqList::SeqList(int sz) {
	//���캯����szΪ���鳤��
	if (sz > 0) {
		maxSize = sz; last = -1;
		data = new int[maxSize];
		if (data == NULL)
		{
			MessageBoxA(NULL, "�洢�������", "��ʾ", MB_OK); exit(1);
		}
	}
}

SeqList::SeqList(SeqList& L) {
	//���ƹ��캯��
	maxSize = L.Size(); last = L.Length() - 1; int value;
	data = new int[maxSize];
	if (data == NULL)
	{
		MessageBoxA(NULL, "�洢�������", "��ʾ", MB_OK); exit(1);
	}
	for (int i = 1; i <= last + 1; i++)
	{
		L.getData(i, value); data[i - 1] = value;
	}
}

void SeqList::reSize(int newSize) {
	//˽�к���������˳���洢����ռ��С
	if (newSize <= 0)
	{
		MessageBoxA(NULL, "��Ч�������С��", "��ʾ", MB_OK); return;
	}
	if (newSize != maxSize) {        //�޸�
		int* newarray = new int[newSize];//����������
		if (newarray == NULL)
		{
			MessageBoxA(NULL, "�洢�������", "��ʾ", MB_OK); exit(1);
		}
		int n = last + 1;
		int* srcptr = data;            //Դ�����׵�ַ
		int* destptr = newarray;       //Ŀ�������׵�ַ
		while (n--)*destptr++ = *srcptr++;//����
		delete[]data;                //ɾ������
		data = newarray; maxSize = newSize;//����������
	}
}

int SeqList::Search(int& x)const {
	//����������������xƥ��ı���ҵ��󷵻��ǵڼ���Ԫ��
	//���򷵻�0
	for (int i = 0; i <= last; i++)
		if (data[i] == x)return i + 1;//˳������
	return 0;                         //����ʧ��
}

int SeqList::Locate(int i)const {
	//��λ�������������ص�i�������λ�ã����򷵻�0��
	if (i >= 1 && i <= last + 1)return i;
	else return 0;
}

bool SeqList::Insert(int i, int& x) {
	//��x���뵽��i�������
	if (last == maxSize - 1)return false;//����
	if (i<0 || i>last + 1)return false;//����i������
	for (int j = last; j >= i; j--)
		data[j + 1] = data[j];//���κ���
	data[i] = x;              //����
	last++;                   //���λ�ü�1
	return true;              //����ɹ�
}

bool SeqList::Insert(int& x) {
	//��x���뵽��i�������
	if (last == maxSize - 1)return false;//����
	data[last] = x;              //����
	last++;                   //���λ�ü�1
	return true;              //����ɹ�
}

bool SeqList::Remove(int i, int& x) {
	//����i������ɾ����ͨ��x����Ԫ��ֵ
	if (last == -1)return false;//���
	if (i<1 || i>last + 1)return false;//����i������
	x = data[i - 1];          //�汻ɾԪ��
	for (int j = i; j <= last; j--)
		data[j - 1] = data[j];//����ǰ��
	last--;                   //���λ�ü�1
	return true;              //ɾ���ɹ�
}

void SeqList::input() {
	//�Ӽ�������������룬����˳�������@ֹͣ

}

void SeqList::output() {
	//��˳���ȫ��Ԫ���������Ļ��
	/*cout << "˳���ǰԪ�����λ��Ϊ��" << last << endl;*/
	/*for (int i = 0; i <= last; i++)
		cout << "#" << i + 1 << ":" << data[i] << endl;*/
}

SeqList& SeqList::operator=(SeqList& L) {
	maxSize = L.Size(); last = L.Length() - 1; int value;
	data = new int[maxSize];
	if (data == NULL)
	{
		MessageBoxA(NULL, "�洢�������", "��ʾ", MB_OK); exit(1);
	}
	for (int i = 1; i <= last + 1; i++)
	{
		L.getData(i, value); data[i - 1] = value;
	}
}