#include <afxwin.h>
#include <afxtempl.h>
#include "resource.h"
class MyFrame : public CFrameWnd
{
private:
	CPoint bPoint;
	CArray<CPoint, CPoint> point1A;
	CArray<CPoint, CPoint> point2A;
	CArray<COLORREF, COLORREF> colorA;
	CArray<int, int> DotArray;
	CArray<int, int> PenStyle;
	int Dot = 1;
	int Pen = 0;
	COLORREF color;
	CMenu* pMenu;

public:
	MyFrame()
	{
		Create(NULL, "Hello MFC");
		pMenu = new CMenu();
		pMenu->LoadMenu(IDR_MENU1);
		SetMenu(pMenu);
		color = RGB(255, 0, 0);
		pMenu->CheckMenuItem(ID_COLOR_RED, MF_CHECKED);
	}

	afx_msg void OnLButtonDown(UINT nFlags, CPoint point)
	{
		SetCapture();
		bPoint = point;
	}
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point)
	{
		ReleaseCapture();
		point1A.Add(bPoint);
		point2A.Add(point);
		colorA.Add(color);
		DotArray.Add(Dot);
		PenStyle.Add(Pen);
		Invalidate();
	}
	afx_msg void OnPaint()
	{
		CPaintDC dc(this);
		int n = point1A.GetSize();
		for (int i = 0; i<n; i++)
		{
				CPen pen(PenStyle[i], DotArray[i], colorA[i]);
				dc.SelectObject(&pen);
				dc.MoveTo(point1A[i]);
				dc.LineTo(point2A[i]);
		}
	}
	afx_msg void OnRed()
	{
		color = RGB(255, 0, 0);
	}
	afx_msg void OnGreen()
	{
		color = RGB(0, 255, 0);
	}
	afx_msg void OnBlue()
	{
		color = RGB(0, 0, 255);
	}
	afx_msg void UpdateRed(CCmdUI* aCmdUI)
	{
		aCmdUI->SetCheck(color == RGB(255, 0, 0));
	}
	afx_msg void UpdateGreen(CCmdUI* aCmdUI)
	{
		aCmdUI->SetCheck(color == RGB(0, 255, 0));
	}
	afx_msg void UpdateBlue(CCmdUI* aCmdUI)
	{
		aCmdUI->SetCheck(color == RGB(0, 0, 255));
	}

	afx_msg void OnLoad()
	{
		CFile file("file.txt", CFile::modeRead);
		CArchive ar(&file, CArchive::load);
		point1A.RemoveAll();
		point2A.RemoveAll();
		colorA.RemoveAll();
		DotArray.RemoveAll();
		PenStyle.RemoveAll();
		int n;
		ar >> n;
		CPoint p1, p2;
		COLORREF color1;
		for (int i = 0; i<n; i++)
		{
			ar >> p1 >> p2 >> color1 >> Dot >> Pen;
			point1A.Add(p1);
			point2A.Add(p2);
			colorA.Add(color1);
			DotArray.Add(Dot);
			PenStyle.Add(Pen);
		}
		Invalidate();
	}
	afx_msg void OnSave()
	{
		CFile file("file.txt", CFile::modeWrite | CFile::modeCreate);
		CArchive ar(&file, CArchive::store);
		int n = point1A.GetSize();
		ar << n;
		for (int i = 0; i < n; i++)
			ar << point1A[i] << point2A[i] << colorA[i] << DotArray[i] << PenStyle[i];
	}
	afx_msg void OnClear()
	{
		point1A.RemoveAll();
		point2A.RemoveAll();
		colorA.RemoveAll();
		DotArray.RemoveAll();
		PenStyle.RemoveAll();
		Invalidate();
	}
	afx_msg void OnExit()
	{
		MessageBox("Exit"); //show the MessageBox
		DestroyWindow();	//destroy the window
	}

	afx_msg void OnSolid()
	{
		Pen = 0;
	}
	afx_msg void OnDash()
	{
		Pen = 1;
	}
	afx_msg void On1()
	{
		Dot = 1;
	}
	afx_msg void On2()
	{
		Dot = 2;
	}
	afx_msg void On3()
	{
		Dot = 3;
	}
	afx_msg void On4()
	{
		Dot = 4;
	}
	afx_msg void On5()
	{
		Dot = 5;
	}

	DECLARE_MESSAGE_MAP()
};
BEGIN_MESSAGE_MAP(MyFrame, CFrameWnd)
	ON_WM_PAINT()
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_COMMAND(ID_COLOR_RED, OnRed)
	ON_COMMAND(ID_COLOR_GREEN, OnGreen)
	ON_COMMAND(ID_COLOR_BLUE, OnBlue)
	ON_COMMAND(ID_FILE_SAVE, OnSave)
	ON_COMMAND(ID_FILE_LOAD, OnLoad)
	ON_COMMAND(ID_FILE_CLEAR, OnClear)
	ON_COMMAND(ID_FILE_EXIT, OnExit)
	ON_COMMAND(ID_LINE_SOLID, OnSolid)
	ON_COMMAND(ID_LINE_DASH, OnDash)
	ON_COMMAND(ID_LINE_1, On1)
	ON_COMMAND(ID_LINE_2, On2)
	ON_COMMAND(ID_LINE_3, On3)
	ON_COMMAND(ID_LINE_4, On4)
	ON_COMMAND(ID_LINE_5, On5)
	ON_UPDATE_COMMAND_UI(ID_COLOR_RED, UpdateRed)
	ON_UPDATE_COMMAND_UI(ID_COLOR_GREEN, UpdateGreen)
	ON_UPDATE_COMMAND_UI(ID_COLOR_BLUE, UpdateBlue)
END_MESSAGE_MAP()

class MyApp : public CWinApp
{
public:
	BOOL InitInstance()
	{
		CFrameWnd *frame = new MyFrame();
		m_pMainWnd = frame;
		frame->ShowWindow(SW_SHOW);
		return true;
	}
};
MyApp a_app;
