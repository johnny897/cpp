
// TestMutexDlg.cpp : implementation file
//

#include "stdafx.h"
#include "TestMutex.h"
#include "TestMutexDlg.h"
#include "afxdialogex.h"
#include "afxmt.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CTestMutexDlg dialog

CTestMutexDlg::CTestMutexDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_TESTMUTEX_DIALOG, pParent)
	, m_Pushed(false)
	, m_hActivate(NULL)
	, m_hUnactivate(NULL)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CTestMutexDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_CHECK1, m_Bn);
}

static UINT DlgMessage = ::RegisterWindowMessage(_T("ONDLGMESSAGE"));

BEGIN_MESSAGE_MAP(CTestMutexDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_CHECK1, &CTestMutexDlg::OnBnClickedButton1)
	ON_REGISTERED_MESSAGE(DlgMessage, &CTestMutexDlg::OnState)
END_MESSAGE_MAP()


// CTestMutexDlg message handlers

BOOL CTestMutexDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	m_Bn.EnableWindow(TRUE);

	return TRUE;  // return TRUE  unless you set the focus to a control
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CTestMutexDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CTestMutexDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

enum ButtonState {
	eActivate = 0,
	eUnactivate
};

void CTestMutexDlg::OnBnClickedButton1()
{
	CTestMutexApp* pApp = (CTestMutexApp*)AfxGetApp();
	LPARAM lParam = 0;

	if (BST_CHECKED == m_Bn.GetCheck()) {
		m_Pushed = true;
		lParam = ButtonState::eUnactivate;
	}
	else {
		m_Pushed = false;
		lParam = ButtonState::eActivate;
	}

	pApp->SendState(lParam);
}

void CTestMutexDlg::SendState(LPARAM lParam) {
	// ::SendMessage(HWND_BROADCAST, WM_STATE, 0, lParam);
	//::SendMessage(HWND_BROADCAST, m_WinMsg_ui, 0, 0);
//	SendMessage(MyMessage, 0, 0);
}

LRESULT CTestMutexDlg::OnState(WPARAM wParam, LPARAM lParam) {
	//if (m_Pushed)
	//	return 0;

	//ButtonState state = (ButtonState)lParam;
	//if (state == ButtonState::eActivate) {
	//	m_Bn.EnableWindow(TRUE);
	//}
	//else {
	//	m_Bn.EnableWindow(FALSE);
	//}

	return 0;
}