#include <afxwin.h>
#include <atlimage.h>
#include "resource.h"

class MyFrame : public CFrameWnd
{
private:
	CMenu *pMenu;
	int width;
	CImage image[9];
	int bingo[4][4];
	bool choose[4][4];

	bool lockBetween;
	int clickImg1, clickImg2;
	int R1,R2;
	int C1, C2;
	int timeCount1, timeCount2;
	bool isTimeNow;
public:
	MyFrame()
	{
		Create(NULL, "Matching");
		pMenu = new CMenu();
		pMenu->LoadMenu(IDR_MENU1);
		SetMenu(pMenu);

		width = 100;
		lockBetween = false;
		timeCount1 = 0;
		timeCount2 = 0;
		isTimeNow = true;

		// 讀圖
		image[0].Load("8_0.jpg");
		image[1].Load("8_1.jpg");
		image[2].Load("8_2.jpg");
		image[3].Load("8_3.jpg");
		image[4].Load("8_4.jpg");
		image[5].Load("8_5.jpg");
		image[6].Load("8_6.jpg");
		image[7].Load("8_7.jpg");
		image[8].Load("8_8.jpg");

		// 初始化圖片配對
		srand(time(0));
		int checkImage[8] = { 0 };
		for (int j = 0; j < 4; j++) {
			// 初始值-->不選
			for (int i = 0; i < 4; i++) {
				choose[i][j] = false;
				int randNum;
				do {
					randNum = rand() % 8;
				} while (checkImage[randNum] == 2);
				bingo[i][j] = randNum + 1;
				checkImage[randNum]++;
			}
		}

		SetTimer(1, 1000, NULL);
	}

	afx_msg void OnPaint()
	{
		CPaintDC dc(this);
		CPen pen(PS_SOLID, 3, RGB(0, 0, 0));
		dc.SelectObject(&pen);

		for (int j = 0; j < 4; j++) {
			for (int i = 0; i < 4; i++) {
				dc.Rectangle(width*i, width*j, width*i + width, width*j + width);
				if (choose[i][j])
					image[bingo[i][j]].Draw(dc, width*i + 3, width*j + 3, 94, 94);
				else
					image[0].Draw(dc, width*i + 3, width*j + 3, 94, 94);
			}
		}

		char showTime[20];
		sprintf(showTime, "%d Seconds", timeCount1);
		dc.TextOut(10, 410, showTime);
	}

	afx_msg void OnLButtonDown(UINT flags, CPoint point)
	{
		CClientDC dc(this);
		if (isTimeNow)
		{
			if (!lockBetween)
			{
				int row = -1, column = -1;
				for (int j = 0; j < 4; j++) {
					for (int i = 0; i < 4; i++) {
						if (point.x >= width*i + 3 && point.y >= width*j + 3 && point.x < width*i + 94 && point.y < width*j + 94 && choose[i][j] != true) {
							clickImg1 = bingo[i][j];
							choose[i][j] = true;
							R1 = i;
							C1 = j;
							lockBetween = true;
							Invalidate();
							break;
						}
					}
				}
			}
			else
			{
				int row = -1, column = -1;
				for (int j = 0; j < 4; j++) {
					for (int i = 0; i < 4; i++) {
						if (point.x >= width*i + 3 && point.y >= width*j + 3 && point.x < width*i + 94 && point.y < width*j + 94 && choose[i][j] != true) {
							clickImg2 = bingo[i][j];
							choose[i][j] = true;
							R2 = i;
							C2 = j;
							lockBetween = false;
							Invalidate();
							if (clickImg1 != clickImg2)
							{
								isTimeNow = false;
								SetTimer(2, 1000, NULL);
								timeCount2 = 0;
							}
							break;
						}
					}
				}
			}
		}
	}

	afx_msg void OnTimer(UINT_PTR nIDEvent)
	{
		if (nIDEvent == 1)
		{
			timeCount1++;
			bool gameOver = true;
			for (int j = 0; j < 4; j++)
			for (int i = 0; i < 4; i++)
			if (choose[i][j] == false) gameOver = false;
			if (gameOver) KillTimer(1);
			Invalidate();
		}
		else if (nIDEvent == 2)
		{
			timeCount2++;
			if (timeCount2 >= 1)
			{
				isTimeNow = true;
				choose[R1][C1] = false;
				choose[R2][C2] = false;
				Invalidate();
				KillTimer(2);
			}
		}
	}

	afx_msg void OnRestart()
	{
		timeCount1 = 0;
		SetTimer(1, 1000, NULL);
		int checkImage[8] = { 0 };
		for (int j = 0; j < 4; j++) {
			for (int i = 0; i < 4; i++) {
				choose[i][j] = false;
				int randNum;
				do {
					randNum = rand() % 8;
				} while (checkImage[randNum] == 2);
				bingo[i][j] = randNum + 1;
				checkImage[randNum]++;
			}
		}
		Invalidate();
	}

	DECLARE_MESSAGE_MAP()
};

BEGIN_MESSAGE_MAP(MyFrame, CFrameWnd)
	ON_WM_PAINT()
	ON_WM_LBUTTONDOWN()
	ON_WM_TIMER()
	ON_COMMAND(ID_GAME_RESTART, OnRestart)
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

MyApp app;