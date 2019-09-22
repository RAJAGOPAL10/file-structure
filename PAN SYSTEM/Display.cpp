// Display.cpp : implementation file
//

#include "pch.h"
#include "mybank.h"
#include "Display.h"
#include "afxdialogex.h"
#include "Header1.h"
#include "Option.h"


// Display dialog

IMPLEMENT_DYNAMIC(Display, CDialogEx)

Display::Display(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG5, pParent)
	, acno(_T(""))
	, name(_T(""))
	, address(_T(""))
	, balance(_T(""))
{

}

Display::~Display()
{
}

void Display::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT2, acno);
	DDX_Text(pDX, IDC_EDIT3, name);
	DDX_Text(pDX, IDC_EDIT4, address);
	//  DDX_Control(pDX, IDC_EDIT4, balance);
	DDX_Text(pDX, IDC_EDIT5, balance);
}


BEGIN_MESSAGE_MAP(Display, CDialogEx)
	ON_BN_CLICKED(ID_MODIFY, &Display::OnBnClickedModify)
	ON_BN_CLICKED(ID_BACK, &Display::OnBnClickedBack)
	ON_BN_CLICKED(IDC_CURRENT, &Display::OnBnClickedCurrent)
END_MESSAGE_MAP()


// Display message handlers


void Display::OnBnClickedModify()
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	std::string values[4];
	values[0] = (CT2CA)acno;
	values[1] = (CT2CA)name;
	values[2] = (CT2CA)address;
	values[3] = (CT2CA)balance;
	CString c;
	std::string res = modify(values);
	smi();
	c = res.c_str();
	MessageBeep(1);
	MessageBox(c);
	Option o;
	o.DoModal();
	this->OnOK();
}


void Display::OnBnClickedBack()
{
	// TODO: Add your control notification handler code here
	this->OnOK();
	Option o;
	o.DoModal();
}


void Display::OnBnClickedCurrent()
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	CString c;
	GetDlgItem(IDC_EDIT2)->GetWindowTextW(c);
	std::string result = CW2A(c);
	result = Search_m(result);
	c = result.c_str();
	GetDlgItem(IDC_EDIT1)->SetWindowTextW(c);
}
