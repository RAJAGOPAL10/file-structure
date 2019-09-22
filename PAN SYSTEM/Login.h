#pragma once


// Login dialog

class Login : public CDialogEx
{
	DECLARE_DYNAMIC(Login)

public:
	Login(CWnd* pParent = nullptr);   // standard constructor
	virtual ~Login();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MYBANK_DIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
};
