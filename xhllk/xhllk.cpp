// xhllk.cpp : 定义应用程序的入口点。
//

#include "stdafx.h"
#include "xhllk.h"
#include "DrawWnd.h"
#include "RandPic.h"
#include "Sound.h"
#include <mmsystem.h>
#define MAX_LOADSTRING 100

#define TotalTime   180    //每局游戏时间
#define IDT_TIMER1  1		//定时器ID	

// 全局变量:
HINSTANCE hInst;								// 当前实例
TCHAR szTitle[MAX_LOADSTRING];					// 标题栏文本
TCHAR szWindowClass[MAX_LOADSTRING];			// 主窗口类名


//自定义全局变量

//当前界面标识
bool iStart(1),iIntial(1),iHelp(1),iAbout(1),iSelect(0),iVictory(0),iFail(0),iPause(0),iGoon(0);
int iClickNum(0);//点击次数
int iPreX,iPreY,iPreVal,iCurX,iCurY,iCurVal;//上一点击点与当前点击点
bool bStart(0);//游戏开始标志
int iScore(0);//分数
int iTipNum(0);//提示次数
CRandPic CShowPic;//随机贴图类
int iTime = TotalTime;//游戏规定时间
int iState = 0;//避免闪屏
CDrawWnd *pDrawWnd;//绘制窗口类



// 此代码模块中包含的函数的前向声明:
ATOM				MyRegisterClass(HINSTANCE hInstance);
BOOL				InitInstance(HINSTANCE, int);
LRESULT CALLBACK	WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK	About(HWND, UINT, WPARAM, LPARAM);

int APIENTRY _tWinMain(HINSTANCE hInstance,
                     HINSTANCE hPrevInstance,
                     LPTSTR    lpCmdLine,
                     int       nCmdShow)
{
	UNREFERENCED_PARAMETER(hPrevInstance);
	UNREFERENCED_PARAMETER(lpCmdLine);

 	// TODO: 在此放置代码。
	MSG msg;
	HACCEL hAccelTable;

	// 初始化全局字符串
	LoadString(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
	LoadString(hInstance, IDC_XHLLK, szWindowClass, MAX_LOADSTRING);
	MyRegisterClass(hInstance);

	// 执行应用程序初始化:
	if (!InitInstance (hInstance, nCmdShow))
	{
		return FALSE;
	}

	hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_XHLLK));

	// 主消息循环:
	while (GetMessage(&msg, NULL, 0, 0))
	{
		if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
	}

	return (int) msg.wParam;
}



//
//  函数: MyRegisterClass()
//
//  目的: 注册窗口类。
//
//  注释:
//
//    仅当希望
//    此代码与添加到 Windows 95 中的“RegisterClassEx”
//    函数之前的 Win32 系统兼容时，才需要此函数及其用法。调用此函数十分重要，
//    这样应用程序就可以获得关联的
//    “格式正确的”小图标。
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
	WNDCLASSEX wcex;

	wcex.cbSize = sizeof(WNDCLASSEX);

	wcex.style			= CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc	= WndProc;
	wcex.cbClsExtra		= 0;
	wcex.cbWndExtra		= 0;
	wcex.hInstance		= hInstance;
	wcex.hIcon			= LoadIcon(hInstance, MAKEINTRESOURCE(IDI_XHLLK));
	wcex.hCursor		= LoadCursorFromFile(TEXT("鼠标.ani"));
	wcex.hbrBackground	= (HBRUSH)(COLOR_WINDOW+1);
	wcex.lpszMenuName	= NULL;
	wcex.lpszClassName	= szWindowClass;
	wcex.hIconSm		= LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

	return RegisterClassEx(&wcex);
}

//
//   函数: InitInstance(HINSTANCE, int)
//
//   目的: 保存实例句柄并创建主窗口
//
//   注释:
//
//        在此函数中，我们在全局变量中保存实例句柄并
//        创建和显示主程序窗口。
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   HWND hWnd;

   hInst = hInstance; // 将实例句柄存储在全局变量中

   hWnd = CreateWindow(szWindowClass,TEXT("连连看__BY__!!*****F5*****!!"), WS_DLGFRAME|WS_SYSMENU|WS_MINIMIZEBOX,
      CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, NULL, NULL, hInstance, NULL);

   if (!hWnd)
   {
      return FALSE;
   }
   SetWindowPos(hWnd,NULL,0,0,916,638,SWP_NOMOVE);
   ShowWindow(hWnd, nCmdShow);
   UpdateWindow(hWnd);

   return TRUE;
}

//
//  函数: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  目的: 处理主窗口的消息。
//
//  WM_COMMAND	- 处理应用程序菜单
//  WM_PAINT	- 绘制主窗口
//  WM_DESTROY	- 发送退出消息并返回
//
//



LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	int wmId, wmEvent;
	PAINTSTRUCT ps;
	HDC hdc;
	CSound sound;//声音控制类

	switch (message)
	{
	case WM_COMMAND:
		wmId    = LOWORD(wParam);
		wmEvent = HIWORD(wParam);
		// 分析菜单选择:
		switch (wmId)
		{
		case IDM_ABOUT:
			DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
			break;
		case IDM_EXIT:
			DestroyWindow(hWnd);
			break;
		default:
			return DefWindowProc(hWnd, message, wParam, lParam);
		}
		break;
	case WM_CREATE:
		{
			HDC hdc1 = GetDC(hWnd);
			pDrawWnd = new CDrawWnd(hdc1,hInst);
			if(iState == 0)
				sound.play_startSND(true);
		}
		break;	
	case WM_PAINT:
		{
			hdc = BeginPaint(hWnd, &ps);
		// TODO: 在此添加任意绘图代码...
			if(iState == 0)		
				pDrawWnd->draw_face(TEXT("res\\map\\初始.bmp"));			
			if(iState == 1)
				pDrawWnd->draw_face(TEXT("res\\map\\模式.bmp"));
			if(iState == 2)
				pDrawWnd->draw_game_face(hWnd,iTime,iScore);
			if(iState == 3)
				pDrawWnd->draw_face(TEXT("res\\map\\帮助.bmp"));
			if(iState == 4)
				pDrawWnd->draw_face(TEXT("res\\map\\关于.bmp"));
			if(iState == 5)
				pDrawWnd->draw_face(TEXT("res\\map\\胜利.bmp"));
			if(iState == 6)
				pDrawWnd->draw_face(TEXT("res\\map\\失败.bmp"));
			
			EndPaint(hWnd, &ps);
		}
		break;
	case WM_LBUTTONDOWN:
		{
			int x = LOWORD(lParam);//鼠标点的X坐标
			int y = HIWORD(lParam);//鼠标点的Y坐标
			hdc = GetDC(hWnd);
	
			pDrawWnd->get_picname(CShowPic.m_PosName);//为每个位置随机指定图片

			if(x>=280 && x<=600 && y>=240 && y<=320 && iIntial==1)//点击开始游戏
			{
				sound.playSND(TEXT("play res\\music\\按钮.wav"),true);
				pDrawWnd->draw_face(TEXT("res\\map\\模式.bmp"));
				iState = 1;
				iIntial=0;
				iHelp=0;
				iAbout=0;
				iSelect=1;
				iScore=0;
			}
			
			else if(x>=200 && x<=360 && y>=240 && y<=320 && iSelect==1)//经典模式选择
			{
				sound.playSND(TEXT("play res\\music\\按钮.wav"),true);
				sound.play_startSND(false);
				sound.play_bgSND(true);
				sound.playSND(TEXT("play res\\music\\关于.wav"),false);
				sound.playSND(TEXT("play res\\music\\帮助.wav"),false);
				pDrawWnd->m_bMode=0;
				CShowPic.clear();
				CShowPic.get_randnum_for_pos();
				pDrawWnd->get_picname(CShowPic.m_PosName);
				pDrawWnd->draw_game_face(hWnd,iTime,iScore);
				iIntial=0;
				iHelp=0;
				iAbout=0;
				iSelect=0;
				bStart=1;
				iScore=0;
				SetTimer(hWnd,IDT_TIMER1,1000,NULL);	
			}
			if(x>=520 && x<=680 && y>=400 && y<=480 && iSelect==1 )//挑战模式
			{
				sound.playSND(TEXT("play res\\music\\按钮.wav"),true);
				sound.play_startSND(false);
				sound.play_bgSND(true);
				sound.playSND(TEXT("play res\\music\\关于.wav"),false);
				sound.playSND(TEXT("play res\\music\\帮助.wav"),false);
				pDrawWnd->m_bMode=1;
				CShowPic.clear();
				CShowPic.get_randnum_for_pos(pDrawWnd->m_bMode);
				pDrawWnd->get_picname(CShowPic.m_PosName);
				pDrawWnd->draw_game_face(hWnd,iTime,iScore);
				iIntial=0;
				iHelp=0;
				iAbout=0;
				iSelect=0;
				bStart=1;
				iScore=0;
				SetTimer(hWnd,IDT_TIMER1,1000,NULL);
			}
			if(x>=280 && x<=600 && y>=360 &&y<=440 && iHelp==1)//帮助界面
			{
				sound.play_startSND(true);
				sound.playSND(TEXT("play res\\music\\按钮.wav"),true);
				pDrawWnd->draw_face(TEXT("res\\map\\帮助.bmp"));
				iState = 3;
				iIntial=0;
				iHelp=0;
				iAbout=0;
				iSelect=0;
			}
			if(x>=280 && x<=600 && y>=480 && y<=560 && iAbout==1)//关于界面
			{
				sound.play_startSND(false);
				sound.playSND(TEXT("play res\\music\\按钮.wav"),true);
				pDrawWnd->draw_face(TEXT("res\\map\\关于.bmp"));
				iState = 4;
				sound.playSND(TEXT("play res\\music\\关于.wav"),true);
				iIntial=0;
				iHelp=0;
				iAbout=0;
				iSelect=0;
			}
			if(x>=40 && x<=120 && y>=40 && y<=80 && !bStart)//左上角返回按钮
			{
				
				sound.playSND(TEXT("play res\\music\\按钮.wav"),true);
				sound.play_startSND(true);
				sound.play_bgSND(false);
				sound.pauseSND(TEXT("stop res\\music\\关于.wav"));
				pDrawWnd->draw_face(TEXT("res\\map\\初始.bmp"));
				iState = 0;
				iAbout=1;
				iIntial=1;
				iHelp=1;
				iSelect=0;
				iVictory=0;
				bStart=false;
				iScore=0;
			}
			if (x>=760 && x<=840 && y>=300 && y<=340 && bStart)//重新开始
			{
				sound.playSND(TEXT("play res\\music\\按钮.wav"),true);
				int tip = MessageBox(hWnd,TEXT("确定要重新开始？"),TEXT("提示"),MB_OKCANCEL);
				if(IDOK==tip)
				{
					CShowPic.clear();
					CShowPic.get_randnum_for_pos(pDrawWnd->m_bMode);
					pDrawWnd->get_picname(CShowPic.m_PosName);
					iTime = TotalTime;
					iScore = 0;
					pDrawWnd->draw_game_face(hWnd,iTime,iScore);
					iTipNum=0;
					SetTimer(hWnd,IDT_TIMER1,1000,NULL);
				}
			}
			if (x>=760 && x<=840 && y>=360 && y<=400 && bStart)//右下角返回按钮
			{
				sound.playSND(TEXT("play res\\music\\按钮.wav"),true);
				sound.play_startSND(true);
				sound.play_bgSND(false);
				CShowPic.clear();
				CShowPic.get_randnum_for_pos();
				pDrawWnd->get_picname(CShowPic.m_PosName);
				pDrawWnd->draw_face(TEXT("res\\map\\初始.bmp"));
				iState = 0;
				iAbout=1;
				iIntial=1;
				iHelp=1;
				iSelect=0;
				bStart=false;
				iTipNum=0;
			}
			if(x>=760 && x<=840 && y>=180 && y<=220 && bStart)//游戏界面右边暂停按钮
			{
			    iPause = true;
				
			}
            if(x>=760 && x<=840 && y>=240 && y<=280 && !bStart)//游戏界面右边继续按钮
			{				
				SetTimer(hWnd,IDT_TIMER1,1000,NULL);
				iPause = false;
				bStart = true;
			}
			if(x>30 && x<90 && y>20 && y<50 && bStart)//游戏界面左上角提示按钮
			{
				if(iTipNum==0)
				{
					pDrawWnd->get_tip();
					sound.play_tipSND(iTipNum);
					iTipNum++;
				}
				else if(iTipNum!=0&&iTipNum<=2)
				{
					pDrawWnd->get_tip();
					sound.play_tipSND(iTipNum);
					iTipNum++;
				}
				else
					sound.play_tipSND(2);
			}
			if(x>40 && x<680 && y>40 && y<520 && bStart)//校徽界面
			{
				int icol = int(x/40)-1;
				int irow = int(y/40)-1;
				int mm=pDrawWnd->m_PicPos[irow][icol];
				sound.play_collegeSND(pDrawWnd->m_PicPos[irow][icol]-1);
				bool is_nop,is_onep,is_twop;//局部变量记录是否联通
				if(iClickNum%2!=0)//单次点击不消去
				{
					if(iClickNum!=1)
						pDrawWnd->draw_onepic(iCurX,iCurY,iCurVal,false);
					pDrawWnd->draw_onepic(icol,irow,pDrawWnd->m_PicPos[irow][icol],true);
					iPreX = icol;
					iPreY = irow;
					iPreVal=pDrawWnd->m_PicPos[irow][icol];
				}
				if(iClickNum%2==0)//双次点击，联通则消去
				{
					iCurX = icol;
					iCurY = irow;
					iCurVal = pDrawWnd->m_PicPos[irow][icol];
					if(!(is_nop = pDrawWnd->is_link_nopoint(iPreX,iPreY,iPreVal,icol,irow,pDrawWnd->m_PicPos[irow][icol])))
					if(!(is_onep = pDrawWnd->is_link_onepoint(iPreX,iPreY,iPreVal,icol,irow,pDrawWnd->m_PicPos[irow][icol])))
					if(!(is_twop = pDrawWnd->is_link_twopoint(iPreX,iPreY,iPreVal,icol,irow,pDrawWnd->m_PicPos[irow][icol])))
					pDrawWnd->is_link_twomorepoint();

					if(is_nop || is_onep || is_twop)//联通
					{
						pDrawWnd->m_PicPos[irow][icol]=0;
						pDrawWnd->m_PicPos[iPreY][iPreX]=0;
						CShowPic.m_PosName[irow][icol]=0;
						CShowPic.m_PosName[iPreY][iPreX]=0;
						iCurVal=0;
						pDrawWnd->draw_game_face(hWnd,iTime,iScore);
						sound.playSND(TEXT("play res\\music\\消去.wav"),true);
						pDrawWnd->draw_bang(iPreX, iPreY, iCurX, iCurY);
						iScore+=100;//消去一对得100分
						pDrawWnd->draw_game_face(hWnd,iTime,iScore);
						if(CShowPic.is_empty())//判断所有图片是否都已消去
							iVictory=1;//若全部消去，激活胜利界面
						
						if(CShowPic.is_empty()&&iVictory==1)//绘制胜利界面
						{
							bStart = false;
							pDrawWnd->draw_face(TEXT("res\\map\\胜利.bmp"));
							iState = 5;
							sound.playSND(TEXT("play res\\music\\胜利.wav"),true);
							sound.play_bgSND(false);
							iIntial=0;
							iHelp=0;
							iAbout=0;
							iSelect=0;
							iVictory=1;
							iScore=0;
							iTipNum=0;
						}
					}
					else//不连通则绘制选中标志
					{
						pDrawWnd->draw_onepic(iPreX,iPreY,iPreVal,false);
						pDrawWnd->draw_onepic(icol,irow,pDrawWnd->m_PicPos[irow][icol],true);
					}
				}
				iClickNum++;
			}
			if(x>=80&&x<=240&&y>=240&&y<=320&&iVictory)//胜利界面下一关按钮
			{
				sound.play_startSND(false);
				sound.pauseSND(TEXT("res\\music\\胜利.wav"));
				sound.play_bgSND(true);
				pDrawWnd->m_bMode=1;
				CShowPic.clear();
				CShowPic.get_randnum_for_pos(pDrawWnd->m_bMode);
				pDrawWnd->get_picname(CShowPic.m_PosName);
				pDrawWnd->draw_game_face(hWnd,iTime,iScore);
				iIntial=0;
				iHelp=0;
				iAbout=0;
				iSelect=0;
				bStart=1;
				iVictory=0;
				iScore=0;
				iState = 2;
			}
			if(x>=80&&x<=240&&y>=360&&y<=440&&iVictory)//胜利界面继续按钮
			{
				CShowPic.clear();
				CShowPic.get_randnum_for_pos();
				pDrawWnd->get_picname(CShowPic.m_PosName);
				pDrawWnd->draw_game_face(hWnd,iTime,iScore);
				iVictory=0;
				bStart=1;
				iScore=0;
				iState = 2;
				sound.pauseSND(TEXT("res\\music\\胜利.wav"));
			}
			if(x>=80&&x<=240&&y>=480&&y<=560&&iVictory)//胜利界面返回按钮									
			{                                          //回到初始化界面
				sound.play_startSND(true);
				sound.play_bgSND(false);
				pDrawWnd->draw_face(TEXT("res\\map\\初始.bmp"));
					iState = 0;
				iAbout=1;
				iIntial=1;
				iHelp=1;
				iSelect=1;
				iVictory=0;
				bStart=false;
				iScore=0;
			}
			if(x>=80&&x<=240&&y>=320&&y<=400&&iFail)//失败界面重玩按钮
			{
				CShowPic.clear();
				CShowPic.get_randnum_for_pos();
				pDrawWnd->get_picname(CShowPic.m_PosName);
				sound.play_bgSND(true);
				sound.pauseSND(TEXT("stop res\\music\\失败.wav"));
				iScore = 0;
				pDrawWnd->draw_game_face(hWnd,iTime,iScore);
				SetTimer(hWnd,IDT_TIMER1,1000,NULL);
				iFail=0;
				bStart=true;
				iScore=0;
				iTipNum=0;
			}
			if(x>=80&&x<=240&&y>=440&&y<=520&&iFail)//失败界面返回按钮
			{
				sound.playSND(TEXT("play res\\music\\按钮.wav"),true);
				sound.play_startSND(true);
				sound.play_bgSND(false);
				pDrawWnd->draw_face(TEXT("res\\map\\初始.bmp"));
				sound.pauseSND(TEXT("stop res\\music\\失败.wav"));//////////
				iState = 0;
				iAbout=1;
				iIntial=1;
				iHelp=1;
				iSelect=1;
				iVictory=0;
				bStart=false;
				iFail=0;
				iScore=0;
				iTipNum=0;
			}
			if (x>=760 && x<=840 && y>=400 && y<=460 && bStart)//右下角退出界面
			{                                                   //停止程序
				SendMessage(hWnd,WM_CLOSE,0,0);
			}
			if (x>=800 && x<=840 && y>=40 && y<=60)
			{
				if(bStart)
				{
					sound.play_startSND(false);
					sound.play_bgSND(bStart);
				}
				else
				{
					sound.play_startSND(true);
					sound.play_bgSND(false);
				}
				    
			}
			if (x>=800 && x<=840 && y>=60 && y<=80)
			{
				sound.play_bgSND(false);
				sound.play_startSND(false);
			}
			ReleaseDC(hWnd,hdc);
		}
		break;
		case WM_ERASEBKGND:
		return 0;
	case WM_TIMER:
		{
			if(IDT_TIMER1 == wParam )
			{
				iTime--;
				if(bStart)
				{
					if(iTime>0)
					{		
						pDrawWnd->draw_game_face(hWnd,iTime,iScore);
						iState = 2;
						if(iVictory)
						{
							iTime = TotalTime;							
							pDrawWnd->draw_face(TEXT("res\\map\\胜利.bmp"));
							iState = 5;
							KillTimer(hWnd,IDT_TIMER1);
						}
						else if(iPause)
						{
							KillTimer(hWnd,IDT_TIMER1);
							bStart = false;
						}						
				     }
					else 
					{
						iTime = TotalTime;
						CSound CS1;
						CS1.play_bgSND(false);						
						bStart = false;
						pDrawWnd->draw_face(TEXT("res\\map\\失败.bmp"));
						mciSendString(TEXT("play res\\music\\失败.wav"),0,NULL,NULL);
						iState = 6;
						iFail = true;
						KillTimer(hWnd,IDT_TIMER1);
					}
				}
				else
				{
					iTime = TotalTime;					
					break;
				}
		    }
		}
		break;
	case WM_DESTROY:
		{
			PostQuitMessage(0);
			delete pDrawWnd;
		}
		break;
	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}
	return 0;
}

// “关于”框的消息处理程序。
INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
	UNREFERENCED_PARAMETER(lParam);
	switch (message)
	{
	case WM_INITDIALOG:
		return (INT_PTR)TRUE;

	case WM_COMMAND:
		if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
		{
			EndDialog(hDlg, LOWORD(wParam));
			return (INT_PTR)TRUE;
		}
		break;
	}
	return (INT_PTR)FALSE;
}
