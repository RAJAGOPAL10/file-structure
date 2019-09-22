


// Delete dialog

class Delete : public CDialogEx

{

	DECLARE_DYNAMIC(Delete)

public:
	Delete(CWnd* pParent = nullptr);   // standard constructor
	virtual ~Delete();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG3 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
};
