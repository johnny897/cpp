
// TestMutexDlg.h : header file
//

#pragma once


// CTestMutexDlg dialog
class CTestMutexDlg : public CDialogEx
{
// Construction
public:
	CTestMutexDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_TESTMUTEX_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON	m_hIcon;
	CButton	m_Bn;
	bool	m_Pushed;

	HANDLE	m_hActivate;
	HANDLE	m_hUnactivate;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	void SendState(LPARAM lParam);
	afx_msg LRESULT OnState(WPARAM wParam, LPARAM lParam);
	
	void WaitToActivate();
	void WaitToUnactivate();
};
