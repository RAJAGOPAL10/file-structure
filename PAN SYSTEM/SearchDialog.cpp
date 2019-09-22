// SearchDialog.cpp : implementation file
//

#include "pch.h"
#include "mybank.h"
#include "SearchDialog.h"
#include "afxdialogex.h"
#include "Option.h"
#include "Header1.h"


// SearchDialog dialog

IMPLEMENT_DYNAMIC(SearchDialog, CDialogEx)

SearchDialog::SearchDialog(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG4, pParent)
{

}

SearchDialog::~SearchDialog()
{
}

void SearchDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(SearchDialog, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &SearchDialog::OnBnClickedButton1)
	ON_EN_CHANGE(IDC_EDIT1, &SearchDialog::OnEnChangeEdit1)
	ON_BN_CLICKED(IDC_BUTTON2, &SearchDialog::OnBnClickedButton2)
END_MESSAGE_MAP()


// SearchDialog message handlers


void SearchDialog::OnBnClickedButton1()
{
	UpdateData(TRUE);
	CString c;
	GetDlgItem(IDC_EDIT1)->GetWindowTextW(c);
	std::string result = CW2A(c);
	result = Search(result);
	c = result.c_str();
	GetDlgItem(IDC_RESULTS)->SetWindowTextW(c);

	// TODO: Add your control notification handler code hereDta
}


void SearchDialog::OnEnChangeEdit1()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialogEx::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
}


void SearchDialog::OnBnClickedButton2()
{
	// TODO: Add your control notification handler code here
	this->OnOK();
	Option o;
	o.DoModal();
}
