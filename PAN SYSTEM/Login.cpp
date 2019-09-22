// Login.cpp : implementation file
//

#include "pch.h"
#include "mybank.h"
#include "Login.h"
#include "afxdialogex.h"


// Login dialog

IMPLEMENT_DYNAMIC(Login, CDialogEx)

Login::Login(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MYBANK_DIALOG, pParent)
{

}

Login::~Login()
{
}

void Login::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(Login, CDialogEx)
END_MESSAGE_MAP()


// Login message handlers
