
// OrederedFunctionDlg.h : 头文件
//

#pragma once


// COrederedFunctionDlg 对话框
class COrederedFunctionDlg : public CDialogEx
{
// 构造
public:
	COrederedFunctionDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_OREDEREDFUNCTION_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;
	

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();

	//自定义消息映射函数

	DECLARE_MESSAGE_MAP()
public:
	//afx_msg void OnIddOrederedfunctionDialog();
	
	CMenu m_Menu1;
	BOOL LoadDLL1(int x, int y, int& result);
	BOOL LoadDLL2(int x, int y, int& result);
	BOOL LoadDLL3(int x, int y, int& result);
	void OnSystem();
	void OnTest1();
	void OnTest2();
	void OnTest3();
	
	afx_msg void OnTimer(UINT_PTR nIDEvent);
};

