
// OrederedFunctionDlg.h : ͷ�ļ�
//

#pragma once


// COrederedFunctionDlg �Ի���
class COrederedFunctionDlg : public CDialogEx
{
// ����
public:
	COrederedFunctionDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_OREDEREDFUNCTION_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;
	

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();

	//�Զ�����Ϣӳ�亯��

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

