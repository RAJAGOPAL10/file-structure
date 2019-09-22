#pragma once


// Insert dialog

class Insert : public CDialogEx
{
	DECLARE_DYNAMIC(Insert)

public:
	Insert(CWnd* pParent = nullptr);   // standard constructor
	virtual ~Insert();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG2 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnEnChangeEdit2();
	afx_msg void OnBnClickedButton1();
	CString acno;
	CString name;
	CString address;
//	CEdit balance;
	CString balance;
	afx_msg void OnBnClickedButton2();
};
