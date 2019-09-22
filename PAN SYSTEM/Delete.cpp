// Delete.cpp : implementation file
//

#include "pch.h"
#include "mybank.h"
#include "Delete.h"
#include "afxdialogex.h"
#include "Option.h"
#include"Header1.h"


// Delete dialog

IMPLEMENT_DYNAMIC(Delete, CDialogEx)

Delete::Delete(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG3, pParent)
{

}

Delete::~Delete()
{
}

void Delete::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(Delete, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &Delete::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &Delete::OnBnClickedButton2)
END_MESSAGE_MAP()


// Delete message handlers


void Delete::OnBnClickedButton1()
{
	UpdateData(TRUE);
	CString c;
	GetDlgItem(IDC_EDIT1)->GetWindowTextW(c);
	std::string result = CW2A(c);
	int res = del(result);
	if (res)
	{
		MessageBeep(1);
		MessageBox(L"DELETION SUCCESSFUL!!!");
		this->OnOK();
		Option o;
		o.DoModal();
		
	}
	MessageBox(L"UNSUCCESSFUL!!!");
	this->OnOK();
	Option o;
	o.DoModal();
	// TODO: Add your control notification handler code here
}


void Delete::OnBnClickedButton2()
{
	// TODO: Add your control notification handler code here
	this->OnOK();
	Option o;
	o.DoModal();
}
