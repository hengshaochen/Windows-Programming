#include <afxwin.h>
#include <afxtempl.h>
#include "resource3.h"
#include <time.h>
CArray<CPoint, CPoint> array1;
class MyFrame : public CFrameWnd
{
private:
	CMenu *pMenu;
public:
	int r, g, b;
	bool used[9];
	int computerRandom;
	int isFull;
	bool playerUsed[9];
	bool computerUsed[9];
	bool gameover;
	MyFrame()
	{
		for (int i = 0; i < 9; i++)
		{
			used[i] = false;
			playerUsed[i] = false;
			computerUsed[i] = false;
		}
		// 若isFull = 8 代表滿
		isFull = 0;
		gameover = false;

		Create(NULL, "Draw Rect");
		pMenu = new CMenu();
		pMenu->LoadMenu(IDR_MENU1);
		SetMenu(pMenu);
	}
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point)
	{
		CClientDC dc(this);
		CPen pen1(PS_SOLID, 5, RGB(85, 255, 255));
		dc.SelectObject(&pen1);
		// 0~8
		CRect blockPos[9] = { CRect(0, 0, 60, 60), CRect(60, 0, 120, 60), CRect(120, 0, 180, 60),
			CRect(0, 60, 60, 120), CRect(60, 60, 120, 120), CRect(120, 60, 180, 120),
			CRect(0, 120, 60, 180), CRect(60, 120, 120, 180), CRect(120, 120, 180, 180) };

		if (gameover == false)
		{
			if (blockPos[0].PtInRect(point) && (nFlags & MK_LBUTTON) && used[0] == false)
			{
				used[0] = true;
				dc.Ellipse(10, 10, 50, 50);
				playerUsed[0] = true;
				randomNumberAndDraw();
				playerWin();
				if (gameover == false)
					computerWim();
			}
			if (blockPos[1].PtInRect(point) && (nFlags & MK_LBUTTON) && used[1] == false)
			{
				used[1] = true;
				dc.Ellipse(70, 10, 110, 50);
				playerUsed[1] = true;
				randomNumberAndDraw();
				playerWin();
				if (gameover == false)
					computerWim();
			}
			if (blockPos[2].PtInRect(point) && (nFlags & MK_LBUTTON) && used[2] == false)
			{
				used[2] = true;
				dc.Ellipse(130, 10, 170, 50);
				playerUsed[2] = true;
				randomNumberAndDraw();
				playerWin();
				if (gameover == false)
					computerWim();
			}
			if (blockPos[3].PtInRect(point) && (nFlags & MK_LBUTTON) && used[3] == false)
			{
				used[3] = true;
				dc.Ellipse(10, 70, 50, 110);
				playerUsed[3] = true;
				randomNumberAndDraw();
				playerWin();
				if (gameover == false)
					computerWim();
			}
			if (blockPos[4].PtInRect(point) && (nFlags & MK_LBUTTON) && used[4] == false)
			{
				used[4] = true;
				dc.Ellipse(70, 70, 110, 110);
				playerUsed[4] = true;
				randomNumberAndDraw();
				playerWin();
				if (gameover == false)
					computerWim();
			}
			if (blockPos[5].PtInRect(point) && (nFlags & MK_LBUTTON) && used[5] == false)
			{
				used[5] = true;
				dc.Ellipse(130, 70, 170, 110);
				playerUsed[5] = true;
				randomNumberAndDraw();
				playerWin();
				if (gameover == false)
					computerWim();
			}
			if (blockPos[6].PtInRect(point) && (nFlags & MK_LBUTTON) && used[6] == false)
			{
				used[6] = true;
				dc.Ellipse(10, 130, 50, 170);
				playerUsed[6] = true;
				randomNumberAndDraw();
				playerWin();
				if (gameover == false)
					computerWim();
			}
			if (blockPos[7].PtInRect(point) && (nFlags & MK_LBUTTON) && used[7] == false)
			{
				used[7] = true;
				dc.Ellipse(70, 130, 110, 170);
				playerUsed[7] = true;
				randomNumberAndDraw();
				playerWin();
				if (gameover == false)
					computerWim();
			}
			if (blockPos[8].PtInRect(point) && (nFlags & MK_LBUTTON) && used[8] == false)
			{
				used[8] = true;
				dc.Ellipse(130, 130, 170, 170);
				playerUsed[8] = true;
				randomNumberAndDraw();
				playerWin();
				if ( gameover == false)
					computerWim();
			}
		}
	}

	void randomNumberAndDraw()
	{
		if (used[0] == true && used[1] == true && used[2] == true && used[3] == true && used[4] == true && used[5] == true && used[6] == true && used[7] == true && used[8] == true)
		{
			CClientDC dc(this);
			dc.TextOutA(200, 100, "Draw!");
			gameover = true;
		}
		else
		{
			computerRandom = rand() % 9;
			while (used[computerRandom] == true)
			{
				computerRandom = rand() % 10;
			}
			drawXX(computerRandom);
		}
	}

	void drawXX(int computerRandom)
	{
		CClientDC dc(this);
		CPen pen1(PS_SOLID, 5, RGB(0, 0, 255));
		dc.SelectObject(&pen1);

		if (computerRandom==0)
		{
			dc.MoveTo(10, 10);
			dc.LineTo(50, 50);
			dc.MoveTo(50, 10);
			dc.LineTo(10, 50);
			used[computerRandom] == true;
			computerUsed[0] = true;
		}
		else if(computerRandom==1)
		{
			dc.MoveTo(70, 10);
			dc.LineTo(110, 50);
			dc.MoveTo(110, 10);
			dc.LineTo(70, 50);
			used[computerRandom] == true;
			computerUsed[1] = true;
		}
		else if (computerRandom==2)
		{
			dc.MoveTo(130, 10);
			dc.LineTo(170, 50);
			dc.MoveTo(170, 10);
			dc.LineTo(130, 50);
			used[computerRandom] == true;
			computerUsed[2] = true;
		}
		else if (computerRandom == 3)
		{
			dc.MoveTo(10, 70);
			dc.LineTo(50, 110);
			dc.MoveTo(50, 70);
			dc.LineTo(10, 110);
			used[computerRandom] == true;
			computerUsed[3] = true;
		}
		else if (computerRandom == 4)
		{
			dc.MoveTo(70, 70);
			dc.LineTo(110, 110);
			dc.MoveTo(110, 70);
			dc.LineTo(70, 110);
			used[computerRandom] == true;
			computerUsed[4] = true;
		}
		else if (computerRandom == 5)
		{
			dc.MoveTo(130, 70);
			dc.LineTo(170, 110);
			dc.MoveTo(170, 70);
			dc.LineTo(130, 110);
			used[computerRandom] == true;
			computerUsed[5] = true;
		}
		else if (computerRandom == 6)
		{
			dc.MoveTo(10, 130);
			dc.LineTo(50, 170);
			dc.MoveTo(50, 130);
			dc.LineTo(10, 170);
			used[computerRandom] == true;
			computerUsed[6] = true;
		}
		else if (computerRandom == 7)
		{
			dc.MoveTo(70, 130);
			dc.LineTo(110, 170);
			dc.MoveTo(110, 130);
			dc.LineTo(70, 170);
			used[computerRandom] == true;
			computerUsed[7] = true;
		}
		else if (computerRandom == 8)
		{
			dc.MoveTo(130, 130);
			dc.LineTo(170, 170);
			dc.MoveTo(170, 130);
			dc.LineTo(130, 170);
			used[computerRandom] == true;
			computerUsed[8] = true;
		}
		used[computerRandom] = true;
	}

	void playerWin()
	{
		if (playerUsed[0] == true && playerUsed[1] == true && playerUsed[2] == true)
		{
			CClientDC dc(this);
			CPen pen1(PS_SOLID, 5, RGB(255, 0, 0));
			dc.SelectObject(&pen1);
			dc.MoveTo(0, 30);
			dc.LineTo(180, 30);
			dc.TextOutA(200, 100, "You Win!");
			gameover = true;
		}
		else if (playerUsed[3] == true && playerUsed[4] == true && playerUsed[5] == true)
		{
			CClientDC dc(this);
			CPen pen1(PS_SOLID, 5, RGB(255, 0, 0));
			dc.SelectObject(&pen1);
			dc.MoveTo(0, 90);
			dc.LineTo(180, 90);
			dc.TextOutA(200, 100, "You Win!");
			gameover = true;
		}
		else if (playerUsed[6] == true && playerUsed[7] == true && playerUsed[8] == true)
		{
			CClientDC dc(this);
			CPen pen1(PS_SOLID, 5, RGB(255, 0, 0));
			dc.SelectObject(&pen1);
			dc.MoveTo(0, 150);
			dc.LineTo(180, 150);
			dc.TextOutA(200, 100, "You Win!");
			gameover = true;
		}
		else if (playerUsed[0] == true && playerUsed[3] == true && playerUsed[6] == true)
		{
			CClientDC dc(this);
			CPen pen1(PS_SOLID, 5, RGB(255, 0, 0));
			dc.SelectObject(&pen1);
			dc.MoveTo(30, 0);
			dc.LineTo(30, 180);
			dc.TextOutA(200, 100, "You Win!");
			gameover = true;
		}
		else if (playerUsed[1] == true && playerUsed[4] == true && playerUsed[7] == true)
		{
			CClientDC dc(this);
			CPen pen1(PS_SOLID, 5, RGB(255, 0, 0));
			dc.SelectObject(&pen1);
			dc.MoveTo(90, 0);
			dc.LineTo(90, 180);
			dc.TextOutA(200, 100, "You Win!");
			gameover = true;
		}
		else if (playerUsed[2] == true && playerUsed[5] == true && playerUsed[8] == true)
		{
			CClientDC dc(this);
			CPen pen1(PS_SOLID, 5, RGB(255, 0, 0));
			dc.SelectObject(&pen1);
			dc.MoveTo(150, 0);
			dc.LineTo(150, 180);
			dc.TextOutA(200, 100, "You Win!");
			gameover = true;
		}
		else if (playerUsed[0] == true && playerUsed[4] == true && playerUsed[8] == true)
		{
			CClientDC dc(this);
			CPen pen1(PS_SOLID, 5, RGB(255, 0, 0));
			dc.SelectObject(&pen1);
			dc.MoveTo(0, 0);
			dc.LineTo(180, 180);
			dc.TextOutA(200, 100, "You Win!");
			gameover = true;
		}
		else if (playerUsed[2] == true && playerUsed[4] == true && playerUsed[6] == true)
		{
			CClientDC dc(this);
			CPen pen1(PS_SOLID, 5, RGB(255, 0, 0));
			dc.SelectObject(&pen1);
			dc.MoveTo(180, 0);
			dc.LineTo(0, 180);
			dc.TextOutA(200, 100, "You Win!");
			gameover = true;
		}

	}
	void computerWim()
	{
		if (computerUsed[0] == true && computerUsed[1] == true && computerUsed[2] == true)
		{
			CClientDC dc(this);
			CPen pen1(PS_SOLID, 5, RGB(255, 0, 0));
			dc.SelectObject(&pen1);
			dc.MoveTo(0, 30);
			dc.LineTo(180, 30);
			dc.TextOutA(200, 100, "You Lose!");
			gameover = true;
		}
		else if (computerUsed[3] == true && computerUsed[4] == true && computerUsed[5] == true)
		{
			CClientDC dc(this);
			CPen pen1(PS_SOLID, 5, RGB(255, 0, 0));
			dc.SelectObject(&pen1);
			dc.MoveTo(0, 90);
			dc.LineTo(180, 90);
			dc.TextOutA(200, 100, "You Lose!");
			gameover = true;
		}
		else if (computerUsed[6] == true && computerUsed[7] == true && computerUsed[8] == true)
		{
			CClientDC dc(this);
			CPen pen1(PS_SOLID, 5, RGB(255, 0, 0));
			dc.SelectObject(&pen1);
			dc.MoveTo(0, 150);
			dc.LineTo(180, 150);
			dc.TextOutA(200, 100, "You Lose!");
			gameover = true;
		}
		else if (computerUsed[0] == true && computerUsed[3] == true && computerUsed[6] == true)
		{
			CClientDC dc(this);
			CPen pen1(PS_SOLID, 5, RGB(255, 0, 0));
			dc.SelectObject(&pen1);
			dc.MoveTo(30, 0);
			dc.LineTo(30, 180);
			dc.TextOutA(200, 100, "You Lose!");
			gameover = true;
		}
		else if (computerUsed[1] == true && computerUsed[4] == true && computerUsed[7] == true)
		{
			CClientDC dc(this);
			CPen pen1(PS_SOLID, 5, RGB(255, 0, 0));
			dc.SelectObject(&pen1);
			dc.MoveTo(90, 0);
			dc.LineTo(90, 180);
			dc.TextOutA(200, 100, "You Lose!");
			gameover = true;
		}
		else if (computerUsed[2] == true && computerUsed[5] == true && computerUsed[8] == true)
		{
			CClientDC dc(this);
			CPen pen1(PS_SOLID, 5, RGB(255, 0, 0));
			dc.SelectObject(&pen1);
			dc.MoveTo(150, 0);
			dc.LineTo(150, 180);
			dc.TextOutA(200, 100, "You Lose!");
			gameover = true;
		}
		else if (computerUsed[0] == true && computerUsed[4] == true && computerUsed[8] == true)
		{
			CClientDC dc(this);
			CPen pen1(PS_SOLID, 5, RGB(255, 0, 0));
			dc.SelectObject(&pen1);
			dc.MoveTo(0, 0);
			dc.LineTo(180, 180);
			dc.TextOutA(200, 100, "You Lose!");
			gameover = true;
		}
		else if (computerUsed[2] == true && computerUsed[4] == true && computerUsed[6] == true)
		{
			CClientDC dc(this);
			CPen pen1(PS_SOLID, 5, RGB(255, 0, 0));
			dc.SelectObject(&pen1);
			dc.MoveTo(180, 0);
			dc.LineTo(0, 180);
			dc.TextOutA(200, 100, "You Lose!");
			gameover = true;
		}

	}
	afx_msg void OnPaint()
	{
		CPaintDC dc(this);

		int x1, x2, y1, y2;
		y1 = 0;
		y2 = 60;
		for (int i = 0; i < 3; i++)
		{
			x1 = 0;
			x2 = 60;
			for (int j = 0; j < 3; j++)
			{
				dc.Rectangle(x1, y1, x2, y2);
				x1 += 60;
				x2 += 60;
			}
			y1 += 60;
			y2 += 60;
		}
	}

	afx_msg void Restart()
	{
		Invalidate(true);
		for (int i = 0; i < 9; i++)
		{
			used[i] = false;
			playerUsed[i] = false;
			computerUsed[i] = false;
		}
		// 若isFull = 8 代表滿
		isFull = 0;
		gameover = false;
	}

	DECLARE_MESSAGE_MAP()
};
BEGIN_MESSAGE_MAP(MyFrame, CFrameWnd)
	ON_WM_LBUTTONDOWN()
	ON_WM_MOUSEMOVE()
	ON_WM_PAINT()
	ON_COMMAND(ID_GAME_RESTART, Restart)

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
