
// TestMutex.h : main header file for the PROJECT_NAME application
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// CTestMutexApp:
// See TestMutex.cpp for the implementation of this class
//

class CTestMutexApp : public CWinApp
{
public:
	CTestMutexApp();

// Overrides
public:
	virtual BOOL InitInstance();
	void SendState(LPARAM lParam);
	afx_msg void OnState(WPARAM wParam, LPARAM lParam);

// Implementation

	DECLARE_MESSAGE_MAP()
};

extern CTestMutexApp theApp;