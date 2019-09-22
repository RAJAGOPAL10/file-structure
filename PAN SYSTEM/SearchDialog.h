#pragma once


// SearchDialog dialog

class SearchDialog : public CDialogEx
{
	DECLARE_DYNAMIC(SearchDialog)

public:
	SearchDialog(CWnd* pParent = nullptr);   // standard constructor
	virtual ~SearchDialog();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG4 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	afx_msg void OnEnChangeEdit1();
	afx_msg void OnBnClickedButton2();
};
