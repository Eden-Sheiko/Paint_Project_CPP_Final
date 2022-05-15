
// CFinalProjectDlg.h : header file
//
#include "Figure.h"
#include "EllipseM.h"
#include "RectangleM.h"
#include "PieM.h"
#include "RoundRectM.h"
using namespace std;
#pragma once
// CFinalProjectDlg dialog
class CFinalProjectDlg : public CDialogEx
{
	// Construction
public:
	CFinalProjectDlg(CWnd* pParent = nullptr); // standard constructor
	~CFinalProjectDlg();
	// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_FINALPROJECT_DIALOG };
#endif
	void ClearScreen();
	enum  FIGURES { RECTANGLE, ELLIPSE, ROUND_RECT, PIE }; 
	FIGURES futureFigKIND;
	COLORREF curColor;
	Figure *f;
	CTypedPtrArray<CObArray, Figure*> figs;
	int indexMAX;
	bool isPressed;
	CPoint startP;
	CPoint endP;
protected:
	virtual void DoDataExchange(CDataExchange* pDX); // DDX/DDV/support
		// Implementation
protected:
	HICON m_hIcon;
	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnBnClickedRadio1();
	afx_msg void OnBnClickedRadio2();
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
	BOOL isThin;
	afx_msg void OnBnClickedCheck1();
	afx_msg void OnBnClickedRadio3();
	afx_msg void OnBnClickedRadio4();
	afx_msg void OnBnClickedButton1();
	afx_msg void OnFileSave();
	afx_msg void OnFileLoad();
};
