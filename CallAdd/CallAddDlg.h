// CallAddDlg.h : ͷ�ļ�
//

#pragma once


// CCallAddDlg �Ի���
class CCallAddDlg : public CDialog
{
// ����
public:
	CCallAddDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_CALLADD_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedBtnCallAdd();
	afx_msg void OnBnClickedBtnStartHook();
	afx_msg void OnBnClickedBtnStopHook();
};
