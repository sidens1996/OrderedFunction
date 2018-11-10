
// OrederedFunctionDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "OrederedFunction.h"
#include "OrederedFunctionDlg.h"
#include "afxdialogex.h"
#include "windows.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// �Ի�������
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
protected:
	DECLARE_MESSAGE_MAP()
public:
//	afx_msg void OnTimer(UINT_PTR nIDEvent);
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// COrederedFunctionDlg �Ի���

COrederedFunctionDlg::COrederedFunctionDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(COrederedFunctionDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void COrederedFunctionDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(COrederedFunctionDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//ON_COMMAND(IDD_OREDEREDFUNCTION_DIALOG, &COrederedFunctionDlg::OnIddOrederedfunctionDialog)
	//�Զ����¼�
	ON_COMMAND(IDR_MENU1, COrederedFunctionDlg::OnSystem)
	ON_COMMAND(ID_TEST1, COrederedFunctionDlg::OnTest1)
	ON_COMMAND(ID_TEST2, COrederedFunctionDlg::OnTest2)
	ON_COMMAND(ID_TEST3, COrederedFunctionDlg::OnTest3)

	ON_WM_TIMER()
END_MESSAGE_MAP()


// COrederedFunctionDlg ��Ϣ�������

BOOL COrederedFunctionDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// ���ô˶Ի����ͼ�ꡣ  ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO:  �ڴ���Ӷ���ĳ�ʼ������

	SetTimer(1, 100, NULL);
	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

BOOL COrederedFunctionDlg::LoadDLL1(int x, int y, int& result) {
	CString str;
	HMODULE hDll = LoadLibrary(L"1_DLL.dll");

	if (hDll != NULL) 
	{
		typedef int(*Fun1)(int &, int &);
		// ��ȡ������ַ
		Fun1 Add = (Fun1)GetProcAddress(hDll, "Add");
		if (Add != NULL)
		{
			result = Add(x, y);
			//MessageBox();
		}
		FreeLibrary(hDll); //�ͷ� DLL
		return TRUE;
	}
	return FALSE;

}

BOOL COrederedFunctionDlg::LoadDLL2(int x, int y, int& result) {
	CString str;
	HMODULE hDll = LoadLibrary(L"2_DLL.dll");

	if (hDll != NULL)
	{
		typedef int(*Fun1)(int &, int &);
		// ��ȡ������ַ
		Fun1 Decrease = (Fun1)GetProcAddress(hDll, "Decrease");
		if (Decrease != NULL)
		{
			result = Decrease(x, y);
		}
		FreeLibrary(hDll); //�ͷ� DLL
		return TRUE;
	}
	return FALSE;

}

BOOL COrederedFunctionDlg::LoadDLL3(int x, int y, int& result) {
	CString str;
	HMODULE hDll = LoadLibrary(L"3_DLL.dll");

	if (hDll != NULL)
	{
		typedef int(*Fun1)(int &, int &);
		// ��ȡ������ַ
		Fun1 Multiply = (Fun1)GetProcAddress(hDll, "Multiply");
		if (Multiply != NULL)
		{
			result = Multiply(x, y);
			//MessageBox();
		}
		FreeLibrary(hDll); //�ͷ� DLL
		return TRUE;
	}
	return FALSE;

}

void COrederedFunctionDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ  ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void COrederedFunctionDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR COrederedFunctionDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


//�Զ�����Ӧ����
void COrederedFunctionDlg::OnSystem()
{
	
	
}

void COrederedFunctionDlg::OnTest1()
{
	int x = 1, y = 2, result;
	CString msg;
	if (LoadDLL1(x, y, result)) 
	{
		msg.Format(_T("%d + %d = %d\n"), x, y, result);
		MessageBox(msg);
	}
}

void COrederedFunctionDlg::OnTest2()
{
	int x = 1, y = 2, result;
	CString msg;
	if (LoadDLL2(x, y, result))
	{
		msg.Format(_T("%d - %d = %d\n"), x, y, result);
		MessageBox(msg);
	}
}

void COrederedFunctionDlg::OnTest3()
{
	int x = 1, y = 2, result;
	CString msg;
	if (LoadDLL3(x, y, result))
	{
		msg.Format(_T("%d * %d = %d\n"), x, y, result);
		MessageBox(msg);
	}
}

void COrederedFunctionDlg::OnTimer(UINT_PTR nIDEvent)
{
	// TODO:  �ڴ������Ϣ�����������/�����Ĭ��ֵ
	if (nIDEvent == 1)
	{
		COrederedFunctionDlg *P = new COrederedFunctionDlg();
		P->m_Menu1.LoadMenu(IDR_MENU1);
		CMenu *subMenu = new CMenu();
		int result1, result2, result3;
		int a = 1, b = 2;
		subMenu->CreatePopupMenu();
		if (P->LoadDLL1(a, b, result1))
		{
			subMenu->AppendMenu(MF_STRING, ID_TEST1, _T("����1"));
			P->m_Menu1.ModifyMenu(0, MF_BYPOSITION | MF_POPUP | MF_STRING,
				(UINT)subMenu->m_hMenu, _T("ϵͳ")); //����Ӳ˵�
		}
		if (P->LoadDLL2(a, b, result2))
		{
			subMenu->AppendMenu(MF_STRING, ID_TEST2, _T("����2"));
			P->m_Menu1.ModifyMenu(0, MF_BYPOSITION | MF_POPUP | MF_STRING,
				(UINT)subMenu->m_hMenu, _T("ϵͳ")); //����Ӳ˵�
		}
		if (P->LoadDLL3(a, b, result3))
		{
			subMenu->AppendMenu(MF_STRING, ID_TEST3, _T("����3"));
			P->m_Menu1.ModifyMenu(0, MF_BYPOSITION | MF_POPUP | MF_STRING,
				(UINT)subMenu->m_hMenu, _T("ϵͳ")); //����Ӳ˵�
		}
		SetMenu(&P->m_Menu1);
	}
	CDialogEx::OnTimer(nIDEvent);
}
