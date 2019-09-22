// Option.cpp : implementation file
//

#include "pch.h"
#include "mybank.h"
#include "Option.h"
#include "Insert.h"
#include "login.h"
#include "afxdialogex.h"
#include "Delete.h"
#include "SearchDialog.h"
#include "Header1.h"
#include "Display.h"
#include <fstream>

// Option dialog

IMPLEMENT_DYNAMIC(Option, CDialogEx)

Option::Option(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG1, pParent)
{
	std::ifstream track("track");
	std::ifstream record("index.txt");
	char* num = new char[30];
	if (track) {
		track.getline(num, 10, '\0');
		nor = atoi(num);

	}
	track.close();
	for (int h = 0; h < nor; h++) {
		record.getline(num, 30, '|');
		index[h] = num;
		record.getline(num, 30, '\n');
		indexadd[h] = num;
	}
}

Option::~Option()
{
}

void Option::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(Option, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &Option::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON6, &Option::OnBnClickedButton6)
	ON_BN_CLICKED(IDC_BUTTON3, &Option::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON5, &Option::OnBnClickedButton5)
//	ON_BN_CLICKED(IDC_BUTTON4, &Option::OnBnClickedButton4)
ON_BN_CLICKED(IDC_BUTTON2, &Option::OnBnClickedButton2)
ON_BN_CLICKED(IDC_MOD, &Option::OnBnClickedMod)
END_MESSAGE_MAP()


// Option message handlers


void Option::OnBnClickedButton1()
{
	this->OnOK();
	Insert i;
	i.DoModal();
	// TODO: Add your control notification handler code here
}


void Option::OnBnClickedButton6()
{
	this->OnOK();
	Login l;
	l.DoModal();// TODO: Add your control notification handler code here
}


void Option::OnBnClickedButton3()
{
	this->OnOK();
	Delete o1;
	o1.DoModal();
	// TODO: Add your control notification handler code here
}


void Option::OnBnClickedButton5()
{
	this->OnOK();
	SearchDialog s;
	s.DoModal();
	// TODO: Add your control notification handler code here
}


void Option::OnBnClickedButton4()
{
	
	// TODO: Add your control notification handler code here
}


void Option::OnBnClickedButton2()
{
	char * results=disp();
	CString c(results);
	GetDlgItem(IDC_DISPLAY)->SetWindowTextW(c);
	// TODO: Add your control notification handler code here
}


void Option::OnBnClickedMod()
{
	// TODO: Add your control notification handler code here
	this->OnOK();
	Display dis;
	dis.DoModal();
}
