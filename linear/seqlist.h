#pragma once
#include<iostream>
#include"SeqClass.h"

// seqlist 对话框


class seqlist : public CDialogEx
{
	DECLARE_DYNAMIC(seqlist)

public:
	seqlist(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~seqlist();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void CreateSeqlist();
	CEdit m_edit;
	CListCtrl m_list;
	LinearList* L;
	afx_msg void Push_back();
	afx_msg void Inswanted();
	afx_msg void Delwanted();
	afx_msg void Delwantedpos();
	afx_msg void Delallwanted();
	afx_msg void Reverse();
	afx_msg void Show();
	afx_msg void Insafterawanted();
	afx_msg void Insafterallwanted();
};
