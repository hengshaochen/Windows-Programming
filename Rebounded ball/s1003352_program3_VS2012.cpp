#include <afxwin.h>
#include <cstdlib>
#include <cstdio>
#include "resource.h"

class MyFrame : public CFrameWnd
{
private:
	int time, x_ball, y_ball, x_panel;
	int xPos, yPos;
	char a[20];
	CMenu *pMenu;
public:
	MyFrame()
	{
		Create(NULL, "Ball Game");
		pMenu = new CMenu();
		pMenu->LoadMenu(IDR_MENU1);
		SetMenu(pMenu);
		time = 0;
		x_ball = 150;
		y_ball = 50;
		x_panel = 150;
		xPos = rand() % 20;
		yPos = rand() % 20;
		SetTimer(1, 1000, NULL);
		SetTimer(2, 100, NULL);
	}

	afx_msg void OnPaint()
	{
		CPaintDC dc(this);
		dc.Rectangle(0, 30, 300, 300);
		sprintf(a, "%d seconds", time);
		dc.TextOut(10, 10, a);
		CBrush brush(RGB(255, 0, 0));
		dc.SelectObject(brush);
		dc.Ellipse(x_ball - 10, y_ball - 10, x_ball + 10, y_ball + 10);
		CBrush brush1(RGB(255, 0, 0));
		dc.SelectObject(brush1);
		dc.Rectangle(x_panel - 20, 300, x_panel + 20, 320);

		if (y_ball > 300)
			dc.TextOut(400, 200, "YOU FAIL!");
	}

	afx_msg void OnTimer(UINT_PTR nIDEvent)
	{
		if (nIDEvent == 1)
		{
			time++;
			if (time % 5 == 0)
			{
				if (xPos < 0)
					xPos -= 2;
				else
					xPos += 2;
				if (yPos < 0)
					yPos -= 2;
				else
					yPos += 2;
			}
		}
		else if (nIDEvent == 2)
		{
			y_ball = y_ball + yPos;
			x_ball = x_ball + xPos;
			if (y_ball > 290)
			{
				// panel接住,反彈(y方向由下變上)
				if (x_panel - 20 <= x_ball && x_panel + 20 >= x_ball)
				{
					y_ball = 290;
					yPos = 0 - yPos;
				}
				else if (y_ball > 300)
				{
					KillTimer(1);
					KillTimer(2);
				}
			}
			else if (y_ball < 290)
			{
				// 右邊界
				if (x_ball > 290)
				{
					x_ball = 290;
					xPos = 0 - xPos;// x方向右變左
				}
				// 左邊界
				else if (x_ball < 10)
				{
					x_ball = 10;
					xPos = 0 - xPos;// x方向左變右
				}
				// 碰到頂邊
				if (y_ball < 40)
				{
					y_ball = 40;
					yPos = 0 - yPos;// y方向上變下
				}
			}
		}
		Invalidate();
	}

	afx_msg void OnMouseMove(UINT nFlags, CPoint point)
	{
		x_panel = point.x;
		if (x_panel < 10)
			x_panel = 10;
		else if (x_panel > 290)
			x_panel = 290;
	}

	afx_msg void OnExit()
	{
		MessageBox("Exit"); //show the MessageBox
		DestroyWindow();	//destroy the window
	}

	afx_msg void OnReStart()
	{
		time = 0;
		x_ball = 150;
		y_ball = 50;
		x_panel = 150;
		SetTimer(1, 1000, NULL);
		SetTimer(2, 100, NULL);
		xPos = rand() % 20;
		yPos = rand() % 20;
	}

	DECLARE_MESSAGE_MAP()
};

BEGIN_MESSAGE_MAP(MyFrame, CFrameWnd)
	ON_WM_PAINT()
	ON_WM_TIMER()
	ON_WM_MOUSEMOVE()
	ON_COMMAND(ID_GAME_EXIT, OnExit)
	ON_COMMAND(ID_GAME_NEW, OnReStart)
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

