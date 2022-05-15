
// FinalProjectDlg.cpp : implementation file
//

#include "stdafx.h"
#include "FinalProject.h"
#include "FinalProjectDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CAboutDlg dialog used for App About
int Saved_dc;
class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

	// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CFinalProjectDlg dialog



CFinalProjectDlg::CFinalProjectDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_FINALPROJECT_DIALOG, pParent)
	, isThin(FALSE)
{
	futureFigKIND = RECTANGLE;
	curColor = RGB(255, 0, 0);
	f = NULL;
	isPressed = false;
	indexMAX = 0;
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CFinalProjectDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Check(pDX, IDC_CHECK1, isThin);
}

BEGIN_MESSAGE_MAP(CFinalProjectDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
	ON_BN_CLICKED(IDC_CHECK1, &CFinalProjectDlg::OnBnClickedCheck1)
	ON_BN_CLICKED(IDC_RADIO1, &CFinalProjectDlg::OnBnClickedRadio1)
	ON_WM_RBUTTONDOWN()
	ON_BN_CLICKED(IDC_RADIO2, &CFinalProjectDlg::OnBnClickedRadio2)
	ON_BN_CLICKED(IDC_RADIO3, &CFinalProjectDlg::OnBnClickedRadio3)
	ON_BN_CLICKED(IDC_RADIO4, &CFinalProjectDlg::OnBnClickedRadio4)
	ON_BN_CLICKED(IDC_BUTTON1, &CFinalProjectDlg::OnBnClickedButton1)
	ON_COMMAND(ID_FILE_SAVE32771, &CFinalProjectDlg::OnFileSave)
	ON_COMMAND(ID_FILE_LOAD, &CFinalProjectDlg::OnFileLoad)
END_MESSAGE_MAP()


// CFinalProjectDlg message handlers

BOOL CFinalProjectDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here
	CheckRadioButton(IDC_RADIO1, IDC_RADIO2, IDC_RADIO1);

	return TRUE;  
}

void CFinalProjectDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

void CFinalProjectDlg::ClearScreen()
{
	CPaintDC dc(this);
	CRect rect;
	GetClientRect(&rect);
	for (int i = 0; i < 255; i++)
		for (int j = 0; j < 255; j++)
			dc.SetPixel(rect.right - i, rect.bottom - j, RGB(i, j, 0));
	for (int i = 0; i < figs.GetSize(); i++)
		figs[i]->Draw(&dc);

	CFont font;
	font.CreatePointFont(150, _T("Ariel"));
	CFont *oldFont = dc.SelectObject(&font);
	dc.SetBkMode(TRANSPARENT);
	CString string = _T("Paint Gallery                                          Please Select fill color with right clicking the color you want from the Table");
	rect.OffsetRect(8, 8);
	dc.SetTextColor(RGB(0, 0, 0));
	dc.DrawText(string, &rect, DT_SINGLELINE |
		DT_LEFT);
	rect.OffsetRect(1, 1);
	dc.SetTextColor(RGB(0, 0, 0));
	dc.DrawText(string, &rect, DT_SINGLELINE |
		DT_LEFT);
	dc.SelectObject(oldFont);
}

void CFinalProjectDlg::OnPaint()
{
	ClearScreen();
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CFinalProjectDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

CFinalProjectDlg::~CFinalProjectDlg()
{
	for (int i = 0; i < indexMAX; i++)
		delete figs[i];
}

void CFinalProjectDlg::OnBnClickedCheck1()
{
	UpdateData(true); 
}

void CFinalProjectDlg::OnBnClickedRadio1()
{
	futureFigKIND = RECTANGLE;
}

void CFinalProjectDlg::OnBnClickedRadio2()
{
	futureFigKIND = ELLIPSE;
}

void CFinalProjectDlg::OnLButtonDown(UINT nFlags, CPoint point)
{
	endP = startP = point;
	isPressed = true;
	CDialog::OnLButtonDown(nFlags, point);
}
void CFinalProjectDlg::OnLButtonUp(UINT nFlags, CPoint point)
{
	if (isPressed)
	{
		endP = point;
		isPressed = false;
		switch (futureFigKIND)
		{
		case RECTANGLE:
			figs.Add(new RectangleM(startP, endP));
			break;
		case ELLIPSE:
			figs.Add(new EllipseM(startP, endP));
			break;

		case ROUND_RECT:
			figs.Add(new RoundRectM(startP, endP, 20, 20));
			break;

		case PIE:
			figs.Add(new PieM(startP, endP, 200, 100));
			break;
		}
	}
	CDialog::OnLButtonUp(nFlags, point);
}
void CFinalProjectDlg::OnMouseMove(UINT nFlags, CPoint point)
{
	if (isPressed)
	{
		CClientDC dc(this);
		CBrush myBrush, *oldBrush;
		myBrush.CreateSolidBrush(curColor);
		oldBrush = dc.SelectObject(&myBrush);
		CPen myPen1(PS_SOLID, isThin ? 1 : 3, RGB(0, 0, 255));
		CPen *oldPen;
		oldPen = dc.SelectObject(&myPen1);
		dc.SetROP2(R2_NOTXORPEN);
		switch (futureFigKIND)
		{
		case RECTANGLE:
			dc.Rectangle(startP.x, startP.y, endP.x, endP.y);
			endP = point;
			dc.Rectangle(startP.x, startP.y, endP.x, endP.y);
			break;
		case ELLIPSE:
			dc.Ellipse(startP.x, startP.y, endP.x, endP.y);
			endP = point;
			dc.Ellipse(startP.x, startP.y, endP.x, endP.y);
			break;
		case ROUND_RECT:
			dc.RoundRect(startP.x, startP.y, endP.x, endP.y, 20, 20);
			endP = point;
			dc.RoundRect(startP.x, startP.y, endP.x, endP.y, 20, 20);
			break;
		case PIE:
			dc.Pie(startP.x, startP.y, endP.x, endP.y, 200, 200, 200, 100);
			endP = point;
			dc.Pie(startP.x, startP.y, endP.x, endP.y, 200, 200, 200, 100);
			break;
		}
		
			dc.SelectObject(oldPen);
		dc.SetROP2(R2_COPYPEN);
		dc.SelectObject(oldBrush);
	}
	CDialog::OnMouseMove(nFlags, point);
}

void CFinalProjectDlg::OnRButtonDown(UINT nFlags, CPoint point)
{
	CClientDC dc(this);
	curColor = dc.GetPixel(point);
	CDialog::OnRButtonDown(nFlags, point);
}

void CFinalProjectDlg::OnBnClickedRadio3()
{
	futureFigKIND = ROUND_RECT;
}

void CFinalProjectDlg::OnBnClickedRadio4()
{
	futureFigKIND = PIE;
}

void CFinalProjectDlg::OnBnClickedButton1()
{
	figs.RemoveAll();
	Invalidate();
}


void CFinalProjectDlg::OnFileSave()
{
	
					 // FALSE to SAVE
	CFileDialog dlg(FALSE, _T(".figs"), NULL, 0, _T("Figures (*.figs)|*.figs|All Files (*.*)|*.*||"));
	CString filename;
	if (dlg.DoModal() == IDOK)
	{
		filename = dlg.GetPathName(); // return full path and filename
		CFile file(filename, CFile::modeCreate | CFile::modeWrite);
		CArchive ar(&file, CArchive::store);
		figs.Serialize(ar);
		ar.Close();
		file.Close();
	}

}


void CFinalProjectDlg::OnFileLoad()
{
	CFileDialog dlg(TRUE, _T(".figs"), NULL, 0, _T("Figures (*.figs)|*.figs|All Files (*.*)|*.*||"));
	CString filename;
	if (dlg.DoModal() == IDOK)
	{
		filename = dlg.GetPathName();
		CFile file(filename, CFile::modeRead);
		CArchive ar(&file, CArchive::load);
		figs.Serialize(ar);
		ar.Close();
		file.Close();
		Invalidate();
	}
}
