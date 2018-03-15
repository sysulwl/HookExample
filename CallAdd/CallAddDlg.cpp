// CallAddDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "CallAdd.h"
#include "CallAddDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// �Ի�������
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
END_MESSAGE_MAP()


// CCallAddDlg �Ի���




CCallAddDlg::CCallAddDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CCallAddDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CCallAddDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CCallAddDlg, CDialog)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
	ON_BN_CLICKED(IDC_BTN_CALL_ADD, &CCallAddDlg::OnBnClickedBtnCallAdd)
	ON_BN_CLICKED(IDC_BTN_START_HOOK, &CCallAddDlg::OnBnClickedBtnStartHook)
	ON_BN_CLICKED(IDC_BTN_STOP_HOOK, &CCallAddDlg::OnBnClickedBtnStopHook)
END_MESSAGE_MAP()


// CCallAddDlg ��Ϣ�������

BOOL CCallAddDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// ���ô˶Ի����ͼ�ꡣ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void CCallAddDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CCallAddDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CCallAddDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


HINSTANCE hAddDll=NULL;
//����dll���� add(int a,int b)
void CCallAddDlg::OnBnClickedBtnCallAdd()
{
	typedef int (WINAPI*AddProc)(int a,int b);//����ԭ�Ͷ���
	AddProc add;
	if (hAddDll==NULL)
	{
		hAddDll=::LoadLibrary(_T("Add.dll"));//����dll
	}
	add=(AddProc)::GetProcAddress(hAddDll,"add");//��ȡ����add��ַ

	int a=1;
	int b=2;
	int c=add(a,b);//���ú���
	CString tem;
	tem.Format(_T("%d+%d=%d"),a,b,c);
	AfxMessageBox(tem);
}


HINSTANCE hinst=NULL;
//��װ��깳�ӣ�����HOOK
void CCallAddDlg::OnBnClickedBtnStartHook()
{
	typedef BOOL (CALLBACK *inshook)(); //����ԭ�Ͷ���
	inshook insthook;
	
	hinst=LoadLibrary(_T("Hook.dll"));//����dll�ļ�
	if(hinst==NULL)
	{
		AfxMessageBox(_T("no Hook.dll!"));
		return;
	}
	insthook=::GetProcAddress(hinst,"InstallHook");//��ȡ������ַ
	if(insthook==NULL)
	{
		AfxMessageBox(_T("func not found!"));
		return;
	}
	insthook();//��ʼHOOK
}

//ж����깳�ӣ�ֹͣHOOK
void CCallAddDlg::OnBnClickedBtnStopHook()
{
	if (hinst==NULL)
	{
		return;
	}
	typedef BOOL (CALLBACK *UnhookProc)(); //����ԭ�Ͷ���
	UnhookProc UninstallHook;

	UninstallHook=::GetProcAddress(hinst,"UninstallHook");//��ȡ������ַ
	if(UninstallHook!=NULL) 
	{
		UninstallHook();
	}
	if (hinst!=NULL)
	{
		::FreeLibrary(hinst);
	}
}
