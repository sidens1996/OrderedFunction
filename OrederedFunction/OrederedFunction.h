
// OrederedFunction.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// COrederedFunctionApp: 
// �йش����ʵ�֣������ OrederedFunction.cpp
//

class COrederedFunctionApp : public CWinApp
{
public:
	COrederedFunctionApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern COrederedFunctionApp theApp;