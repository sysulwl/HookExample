// CallAdd.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CCallAddApp:
// �йش����ʵ�֣������ CallAdd.cpp
//

class CCallAddApp : public CWinApp
{
public:
	CCallAddApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CCallAddApp theApp;