#pragma once


// Display dialog

class Display : public CDialogEx
{
	DECLARE_DYNAMIC(Display)

public:
	Display(CWnd* pParent = nullptr);   // standard constructor
	virtual ~Display();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG5 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedModify();
	afx_msg void OnBnClickedBack();
	afx_msg void OnBnClickedCurrent();
	CString acno;
	CString name;
	CString address;
	CString balance;
};
