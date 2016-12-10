#include <afxwin.h>
#include <afxtempl.h>
#include "resource.h"
#include <time.h>
CArray<CPoint, CPoint> array1;
class MyFrame : public CFrameWnd
{
private:
	CMenu *pMenu;
public:
	int r, g, b;
	MyFrame()
	{
		Create(NULL, "Draw Rect");
		pMenu = new CMenu();
		pMenu->LoadMenu(IDR_MENU1);
		SetMenu(pMenu);
	}
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point)
	{
		CClientDC dc(this);
		CRect rect1(0, 0, 50, 50);
		CRect rect2(50, 0, 100, 50);
		CRect rect3(100, 0, 150, 50);

		CRect rect4(0, 50, 50, 100);
		CRect rect5(50, 50, 100, 100);
		CRect rect6(100, 50, 150, 100);

		CRect rect7(0, 100, 50, 150);
		CRect rect8(50, 100, 100, 150);
		CRect rect9(100, 100, 150, 150);

		r = rand() % 256; g = rand() % 256; b = rand() % 256;
		CBrush brush(RGB(r, g, b));
		dc.SelectObject(&brush);

		if (rect1.PtInRect(point) && (nFlags & MK_LBUTTON))
			dc.Rectangle(0, 0, 50, 50);
		if (rect2.PtInRect(point) && (nFlags & MK_LBUTTON))
			dc.Rectangle(50, 0, 100, 50);
		if (rect3.PtInRect(point) && (nFlags & MK_LBUTTON))
			dc.Rectangle(100, 0, 150, 50);

		if (rect4.PtInRect(point) && (nFlags & MK_LBUTTON))
			dc.Rectangle(0, 50, 50, 100);
		if (rect5.PtInRect(point) && (nFlags & MK_LBUTTON))
			dc.Rectangle(50, 50, 100, 100);
		if (rect6.PtInRect(point) && (nFlags & MK_LBUTTON))
			dc.Rectangle(100, 50, 150, 100);

		if (rect7.PtInRect(point) && (nFlags & MK_LBUTTON))
			dc.Rectangle(0, 100, 50, 150);
		if (rect8.PtInRect(point) && (nFlags & MK_LBUTTON))
			dc.Rectangle(50, 100, 100, 150);
		if (rect9.PtInRect(point) && (nFlags & MK_LBUTTON))
			dc.Rectangle(100, 100, 150, 150);
	}


	afx_msg void OnPaint()
	{
		CPaintDC dc(this);

		int x1, x2, y1, y2;
		y1 = 0;
		y2 = 50;
		for(int i = 0; i < 3; i++)
		{
			x1 = 0;
			x2 = 50;
			for (int j = 0; j < 3; j++)
			{
				r = rand() % 256;
				g = rand() % 256;
				b = rand() % 256;
				CBrush brush(RGB(r, g, b));
				dc.SelectObject(&brush);
				dc.Rectangle(x1, y1, x2, y2);
				x1 += 50;
				x2 += 50;
			}
			y1 += 50;
			y2 += 50;
		}
	}

	afx_msg void ChangeALL()
	{
		CClientDC dc(this);

		r = rand() % 256; g = rand() % 256; b = rand() % 256;
		CBrush brush(RGB(r, g, b));
		dc.SelectObject(&brush);
		dc.Rectangle(0, 0, 50, 50);

		r = rand() % 256; g = rand() % 256; b = rand() % 256;
		CBrush brush2(RGB(r, g, b));
		dc.SelectObject(&brush2);
		dc.Rectangle(50, 0, 100, 50);

		r = rand() % 256; g = rand() % 256; b = rand() % 256;
		CBrush brush3(RGB(r, g, b));
		dc.SelectObject(&brush3);
		dc.Rectangle(100, 0, 150, 50);
			 
		r = rand() % 256; g = rand() % 256; b = rand() % 256;
		CBrush brush4(RGB(r, g, b));
		dc.SelectObject(&brush4);
		dc.Rectangle(0, 50, 50, 100); 

		r = rand() % 256; g = rand() % 256; b = rand() % 256;
		CBrush brush5(RGB(r, g, b));
		dc.SelectObject(&brush5);
		dc.Rectangle(50, 50, 100, 100); 

		r = rand() % 256; g = rand() % 256; b = rand() % 256;
		CBrush brush6(RGB(r, g, b));
		dc.SelectObject(&brush6);
		dc.Rectangle(100, 50, 150, 100);
			     
		r = rand() % 256; g = rand() % 256; b = rand() % 256;
		CBrush brush7(RGB(r, g, b));
		dc.SelectObject(&brush7);
		dc.Rectangle(0, 100, 50, 150); 

		r = rand() % 256; g = rand() % 256; b = rand() % 256;
		CBrush brush8(RGB(r, g, b));
		dc.SelectObject(&brush8);
		dc.Rectangle(50, 100, 100, 150);

		r = rand() % 256; g = rand() % 256; b = rand() % 256;
		CBrush brush9(RGB(r, g, b));
		dc.SelectObject(&brush9);
		dc.Rectangle(100, 100, 150, 150);
	}

	afx_msg void Change1()
	{
		CClientDC dc(this);

		r = rand() % 256; g = rand() % 256; b = rand() % 256;
		CBrush brush(RGB(r, g, b));
		dc.SelectObject(&brush);
		dc.Rectangle(0, 0, 50, 50);
	}
	afx_msg void Change2()
	{
		CClientDC dc(this);

		r = rand() % 256; g = rand() % 256; b = rand() % 256;
		CBrush brush(RGB(r, g, b));
		dc.SelectObject(&brush);
		dc.Rectangle(50, 0, 100, 50);
	}
	afx_msg void Change3()
	{
		CClientDC dc(this);

		r = rand() % 256; g = rand() % 256; b = rand() % 256;
		CBrush brush(RGB(r, g, b));
		dc.SelectObject(&brush);
		dc.Rectangle(100, 0, 150, 50);
	}
	afx_msg void Change4()
	{
		CClientDC dc(this);

		r = rand() % 256; g = rand() % 256; b = rand() % 256;
		CBrush brush(RGB(r, g, b));
		dc.SelectObject(&brush);
		dc.Rectangle(0, 50, 50, 100);
	}
	afx_msg void Change5()
	{
		CClientDC dc(this);

		r = rand() % 256; g = rand() % 256; b = rand() % 256;
		CBrush brush(RGB(r, g, b));
		dc.SelectObject(&brush);
		dc.Rectangle(50, 50, 100, 100);
	}
	afx_msg void Change6()
	{
		CClientDC dc(this);

		r = rand() % 256; g = rand() % 256; b = rand() % 256;
		CBrush brush(RGB(r, g, b));
		dc.SelectObject(&brush);
		dc.Rectangle(100, 50, 150, 100);
	}
	afx_msg void Change7()
	{
		CClientDC dc(this);

		r = rand() % 256; g = rand() % 256; b = rand() % 256;
		CBrush brush(RGB(r, g, b));
		dc.SelectObject(&brush);
		dc.Rectangle(0, 100, 50, 150);
	}
	afx_msg void Change8()
	{
		CClientDC dc(this);

		r = rand() % 256; g = rand() % 256; b = rand() % 256;
		CBrush brush(RGB(r, g, b));
		dc.SelectObject(&brush);
		dc.Rectangle(50, 100, 100, 150);
	}
	afx_msg void Change9()
	{
		CClientDC dc(this);

		r = rand() % 256; g = rand() % 256; b = rand() % 256;
		CBrush brush(RGB(r, g, b));
		dc.SelectObject(&brush);
		dc.Rectangle(100, 100, 150, 150);
	}


	DECLARE_MESSAGE_MAP()
};
BEGIN_MESSAGE_MAP(MyFrame, CFrameWnd)
	ON_WM_LBUTTONDOWN()
	ON_WM_MOUSEMOVE()
	ON_WM_PAINT()

	ON_COMMAND(ID_CHANGE_ALL, ChangeALL)
	ON_COMMAND(ID_CHANGE_1, Change1)
	ON_COMMAND(ID_CHANGE_2, Change2)
	ON_COMMAND(ID_CHANGE_3, Change3)
	ON_COMMAND(ID_CHANGE_4, Change4)
	ON_COMMAND(ID_CHANGE_5, Change5)
	ON_COMMAND(ID_CHANGE_6, Change6)
	ON_COMMAND(ID_CHANGE_7, Change7)
	ON_COMMAND(ID_CHANGE_8, Change8)
	ON_COMMAND(ID_CHANGE_9, Change9)

END_MESSAGE_MAP()

class MyApp : public CWinApp
{
public:
	BOOL InitInstance()
	{
		CFrameWnd *frame = new MyFrame();
		m_pMainWnd = frame;
		frame->ShowWindow(SW_SHOW);
		srand(time(NULL));
		return true;
	}
};
MyApp a_app;
