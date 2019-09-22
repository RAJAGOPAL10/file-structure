// Insert.cpp : implementation file
//

#include "pch.h"
#include "mybank.h"
#include "Insert.h"
#include "afxdialogex.h"
#include "Option.h"
#include<string>
#include "Header1.h"

IMPLEMENT_DYNAMIC(Insert, CDialogEx)

Insert::Insert(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG2, pParent)
	, acno(_T(""))
	, name(_T(""))
	, address(_T(""))
	, balance(_T(""))
{

}

Insert::~Insert()
{
}

void Insert::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, acno);
	DDX_Text(pDX, IDC_EDIT2, name);
	DDX_Text(pDX, IDC_EDIT3, address);
	//  DDX_Control(pDX, IDC_EDIT4, balance);
	DDX_Text(pDX, IDC_EDIT4, balance);
}


BEGIN_MESSAGE_MAP(Insert, CDialogEx)
	ON_EN_CHANGE(IDC_EDIT2, &Insert::OnEnChangeEdit2)
	ON_BN_CLICKED(IDC_BUTTON1, &Insert::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &Insert::OnBnClickedButton2)
END_MESSAGE_MAP()


// Insert message handlers


void Insert::OnEnChangeEdit2()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialogEx::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
}


void Insert::OnBnClickedButton1()
{
	
	UpdateData(TRUE);
	std::string values[4];
	values[0] = (CT2CA)acno;
	values[1] = (CT2CA)name;
	values[2] = (CT2CA)address;
	values[3] = (CT2CA)balance;
	CString c;
	std::string res=add(values);
	smi();
	c = res.c_str();
	MessageBeep(1);
	MessageBox(c);
	Option o;
	o.DoModal();
	this->OnOK();
	// TODO: Add your control notification handler code here
}


void Insert::OnBnClickedButton2()
{
	// TODO: Add your control notification handler code here
	Option o;
	o.DoModal();
	this->OnOK();
}
