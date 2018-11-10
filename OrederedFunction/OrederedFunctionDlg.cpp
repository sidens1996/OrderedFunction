
// OrederedFunctionDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "OrederedFunction.h"
#include "OrederedFunctionDlg.h"
#include "afxdialogex.h"
#include "windows.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
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


// COrederedFunctionDlg 对话框

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
	//自定义事件
	ON_COMMAND(IDR_MENU1, COrederedFunctionDlg::OnSystem)
	ON_COMMAND(ID_TEST1, COrederedFunctionDlg::OnTest1)
	ON_COMMAND(ID_TEST2, COrederedFunctionDlg::OnTest2)
	ON_COMMAND(ID_TEST3, COrederedFunctionDlg::OnTest3)

	ON_WM_TIMER()
END_MESSAGE_MAP()


// COrederedFunctionDlg 消息处理程序

BOOL COrederedFunctionDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
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

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO:  在此添加额外的初始化代码

	SetTimer(1, 100, NULL);
	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

BOOL COrederedFunctionDlg::LoadDLL1(int x, int y, int& result) {
	CString str;
	HMODULE hDll = LoadLibrary(L"1_DLL.dll");

	if (hDll != NULL) 
	{
		typedef int(*Fun1)(int &, int &);
		// 获取函数地址
		Fun1 Add = (Fun1)GetProcAddress(hDll, "Add");
		if (Add != NULL)
		{
			result = Add(x, y);
			//MessageBox();
		}
		FreeLibrary(hDll); //释放 DLL
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
		// 获取函数地址
		Fun1 Decrease = (Fun1)GetProcAddress(hDll, "Decrease");
		if (Decrease != NULL)
		{
			result = Decrease(x, y);
		}
		FreeLibrary(hDll); //释放 DLL
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
		// 获取函数地址
		Fun1 Multiply = (Fun1)GetProcAddress(hDll, "Multiply");
		if (Multiply != NULL)
		{
			result = Multiply(x, y);
			//MessageBox();
		}
		FreeLibrary(hDll); //释放 DLL
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

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void COrederedFunctionDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR COrederedFunctionDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


//自定义响应函数
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
	// TODO:  在此添加消息处理程序代码和/或调用默认值
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
			subMenu->AppendMenu(MF_STRING, ID_TEST1, _T("功能1"));
			P->m_Menu1.ModifyMenu(0, MF_BYPOSITION | MF_POPUP | MF_STRING,
				(UINT)subMenu->m_hMenu, _T("系统")); //添加子菜单
		}
		if (P->LoadDLL2(a, b, result2))
		{
			subMenu->AppendMenu(MF_STRING, ID_TEST2, _T("功能2"));
			P->m_Menu1.ModifyMenu(0, MF_BYPOSITION | MF_POPUP | MF_STRING,
				(UINT)subMenu->m_hMenu, _T("系统")); //添加子菜单
		}
		if (P->LoadDLL3(a, b, result3))
		{
			subMenu->AppendMenu(MF_STRING, ID_TEST3, _T("功能3"));
			P->m_Menu1.ModifyMenu(0, MF_BYPOSITION | MF_POPUP | MF_STRING,
				(UINT)subMenu->m_hMenu, _T("系统")); //添加子菜单
		}
		SetMenu(&P->m_Menu1);
	}
	CDialogEx::OnTimer(nIDEvent);
}
