#include "stdafx.h"
#include "DrawWnd.h"
#include "RandPic.h"
#include "atlimage.h"


CDrawWnd::CDrawWnd(void)
{
	m_pBmpPath[0]=_T("res\\map\\1.bmp");
	m_pBmpPath[1]=_T("res\\map\\2.bmp");
	m_pBmpPath[2]=_T("res\\map\\3.bmp");
	m_pBmpPath[3]=_T("res\\map\\4.bmp");
	m_pBmpPath[4]=_T("res\\map\\5.bmp");
	m_pBmpPath[5]=_T("res\\map\\6.bmp");
	m_pBmpPath[6]=_T("res\\map\\7.bmp");
	m_pBmpPath[7]=_T("res\\map\\8.bmp");
	m_pBmpPath[8]=_T("res\\map\\9.bmp");
	m_pBmpPath[9]=_T("res\\map\\10.bmp");
	m_pBmpPath[10]=_T("res\\map\\11.bmp");
	m_pBmpPath[11]=_T("res\\map\\12.bmp");
	m_pBmpPath[12]=_T("res\\map\\13.bmp");
	m_pBmpPath[13]=_T("res\\map\\14.bmp");
	m_pBmpPath[14]=_T("res\\map\\15.bmp");
	m_pBmpPath[15]=_T("res\\map\\16.bmp");
	m_pBmpPath[16]=_T("res\\map\\17.bmp");
	m_pBmpPath[17]=_T("res\\map\\18.bmp");
	m_pBmpPath[18]=_T("res\\map\\19.bmp");
	m_pBmpPath[19]=_T("res\\map\\20.bmp");
	m_pBmpPath[20]=_T("res\\map\\21.bmp");
	m_pBmpPath[21]=_T("res\\map\\22.bmp");
	m_pBmpPath[22]=_T("res\\map\\23.bmp");
	m_pBmpPath[23]=_T("res\\map\\24.bmp");
	for(int row=0;row<12;row++)
		for(int column=0;column<16;column++)
			m_PicPos[row][column]=0;
}

void CDrawWnd::set(HDC &hdc,HINSTANCE &hinst)
{
	m_hdc=hdc;
	m_hinst=hinst;
}

void CDrawWnd::get_picname(int val[12][16])
{
	for(int row=0;row<12;row++)
		for(int column=0;column<16;column++)
			m_PicPos[row][column]=val[row][column];
}

CDrawWnd::CDrawWnd(HDC &hdc,HINSTANCE &hinst)
	:m_hdc(hdc),m_hinst(hinst)
{
	m_pBmpPath[0]=_T("res\\map\\1.bmp");
	m_pBmpPath[1]=_T("res\\map\\2.bmp");
	m_pBmpPath[2]=_T("res\\map\\3.bmp");
	m_pBmpPath[3]=_T("res\\map\\4.bmp");
	m_pBmpPath[4]=_T("res\\map\\5.bmp");
	m_pBmpPath[5]=_T("res\\map\\6.bmp");
	m_pBmpPath[6]=_T("res\\map\\7.bmp");
	m_pBmpPath[7]=_T("res\\map\\8.bmp");
	m_pBmpPath[8]=_T("res\\map\\9.bmp");
	m_pBmpPath[9]=_T("res\\map\\10.bmp");
	m_pBmpPath[10]=_T("res\\map\\11.bmp");
	m_pBmpPath[11]=_T("res\\map\\12.bmp");
	m_pBmpPath[12]=_T("res\\map\\13.bmp");
	m_pBmpPath[13]=_T("res\\map\\14.bmp");
	m_pBmpPath[14]=_T("res\\map\\15.bmp");
	m_pBmpPath[15]=_T("res\\map\\16.bmp");
	m_pBmpPath[16]=_T("res\\map\\17.bmp");
	m_pBmpPath[17]=_T("res\\map\\18.bmp");
	m_pBmpPath[18]=_T("res\\map\\19.bmp");
	m_pBmpPath[19]=_T("res\\map\\20.bmp");
	m_pBmpPath[20]=_T("res\\map\\21.bmp");
	m_pBmpPath[21]=_T("res\\map\\22.bmp");
	m_pBmpPath[22]=_T("res\\map\\23.bmp");
	m_pBmpPath[23]=_T("res\\map\\24.bmp");
	for(int row=0;row<12;row++)
		for(int column=0;column<16;column++)
			m_PicPos[row][column]=0;
}



int a = 0,b = 0,c = 0,d = 0,e = 0,f = 0,g = 0,h = 0,aa = 0,bb = 0,cc = 0,dd = 0;
bool CDrawWnd::is_link_nopoint(int x1,int y1,int v1,int x2,int y2,int v2)
{
	if((v1!=v2) || !v1 || !v2)//图不相同
		return false;
	/*if(m_picpos[y1][x1] == 0 && m_picpos[y2][x2] == 0 && x1 > 0 && y1 > 0 && x2 > 0 && y2 > 0)
		return false;*/
	else//图相同
	{
		if(((abs(x1-1)==x2||abs(x2-1)==x1)&&(y1==y2)) || ((abs(y1-1)==y2||abs(y2-1)==y1)&&(x1==x2)))//相邻
		{
			a = x1,b = y1,c = x2,d = y2;
			return true;
		}
		if(x1==x2 && y1==y2)//重合
			return false;
		if(x1 != x2 && y1 == y2)//同一水平线上
		{
			for(int i=1;i<=abs(x2-x1)-1;i++)
			{
				if(m_PicPos[y1][min(x1,x2)+i]==0)
					continue;
				else
					return false;
			}
			a = x1,b = y1,c = x2,d = y2;
			return true;
		}
		if(x1 == x2 && y1 != y2)//同一垂直线上
		{
			for(int i=1;i<=abs(y2-y1)-1;i++)
			{
				if(m_PicPos[min(y1,y2)+i][x1]==0)
					continue;
				else
					return false;
			}
			a = x1,b = y1,c = x2,d = y2;
			return true;
		}
		return false;
	}
}

bool CDrawWnd::is_link_onepoint(int x1,int y1,int v1,int x2,int y2,int v2)
{
	if((v1!=v2) || !v1 || !v2)//图不相同
		return false;

	else//图相同
	{
		if(x1==x2 && y1==y2)//重合
			return false;
		if(m_PicPos[y1][x2]!=0 && m_PicPos[y2][x1]!=0)
			return false;
		else
		{
			if(m_PicPos[y2][x1] == 0)
			{
				bool link3 = is_link_nopoint(x1,y1,v1,x1,y2,v1);
				aa = a,bb = b,cc = c,dd = d;
				bool link4 = is_link_nopoint(x1,y2,v1,x2,y2,v2);
				if(link3 && link4)
					return true;
			}
			else
			{
				bool link5 = is_link_nopoint(x1,y1,v1,x2,y1,v2);
				aa = a,bb = b,cc = c,dd = d;
				bool link6 = is_link_nopoint(x2,y1,v2,x2,y2,v2);
				if(link5 && link6)
					return true;
			}
		}
		return false;
	}
}

bool CDrawWnd::is_link_twopoint(int x1,int y1,int v1,int x2,int y2,int v2)
{
	if((v1!=v2) || !v1 || !v2)
		return false;
	else  
	{
		if(x1==x2 && y1==y2)//重合
			return false;
		int n=1;
		while(y1-n>=0)
		{
			bool boo1 =is_link_nopoint(x1,y1-n,v1,x1,y1,v1);
			e = a,f = b,g = c,h = d;
			bool boo2 =is_link_nopoint(x2,y1-n,v1,x2,y2,v2);
			aa = a,bb = b,cc = c,dd = d;
			bool boo3 =is_link_nopoint(x1,y1-n,v1,x2,y1-n,v2);
			if(m_PicPos[y1-n][x1]==0 && m_PicPos[y1-n][x2]==0 && boo1 && boo2 && boo3)
				return true;
			else
				n++;
		}
		n=1;
		while(y1+n<12)
		{
			bool boo1 = is_link_nopoint(x1,y1+n,v1,x1,y1,v1);
			e = a,f = b,g = c,h = d;
			bool boo2 = is_link_nopoint(x2,y1+n,v1,x2,y2,v2);
			aa = a,bb = b,cc = c,dd = d;
			bool boo3 = is_link_nopoint(x1,y1+n,v1,x2,y1+n,v2);
			if(m_PicPos[y1+n][x1]==0 && m_PicPos[y1+n][x2]==0 && boo1 && boo2 && boo3)
				return true;
			else
				n++;
		}
		n=1;
		while(x1-n>=0)
		{
			bool boo1 = is_link_nopoint(x1-n,y1,v1,x1,y1,v1);
			e = a,f = b,g = c,h = d;
			bool boo2 = is_link_nopoint(x1-n,y2,v1,x2,y2,v2);
			aa = a,bb = b,cc = c,dd = d;
			bool boo3 = is_link_nopoint(x1-n,y1,v1,x1-n,y2,v1);
			if(m_PicPos[y1][x1-n]==0 && m_PicPos[y2][x1-n]==0 && boo1 && boo2 && boo3)
				return true;
			else
				n++;
		}
		n=1;
		while(x1+n<16)
		{
			bool boo1 = is_link_nopoint(x1+n,y1,v1,x1,y1,v1);
			e = a,f = b,g = c,h = d;
			bool boo2 = is_link_nopoint(x1+n,y2,v1,x2,y2,v2);
			aa = a,bb = b,cc = c,dd = d;
			bool boo3 = is_link_nopoint(x1+n,y1,v1,x1+n,y2,v1);
			if(m_PicPos[y1][x1+n]==0 && m_PicPos[y2][x1+n]==0 && boo1 && boo2 && boo3)
				return true;
			else
				n++;
		}
	}
	return false;
}


bool CDrawWnd::is_link_twomorepoint()
{
	a = 0,b = 0,c = 0,d = 0,e = 0,f = 0,g = 0,h = 0,aa = 0,bb = 0,cc = 0,dd = 0;
	return false;
}

void CDrawWnd::draw_game_face(HWND hWnd,int TimeLength,int score)
{
	HDC hdc;
	hdc = GetDC(hWnd);
	HDC bgDC = CreateCompatibleDC(m_hdc);
	RECT rect;
	GetClientRect(hWnd,&rect);
	HBITMAP allBitmap = CreateCompatibleBitmap(hdc,rect.right - rect.left,
			rect.bottom - rect.top);
	SelectObject(bgDC, allBitmap);
	HBRUSH hBrush = CreateSolidBrush(RGB(255,255,255));
	SelectObject(bgDC,hBrush);
	Rectangle(bgDC,rect.left,rect.top,rect.right,rect.bottom);
	CImage image;
	image.Load( _T("res\\map\\游戏.bmp"));
	image.Draw(bgDC,0,0,image.GetWidth(),image.GetHeight());
	image.Destroy(); //释放image

	HPEN hPen1,hPen2,pen;
	pen = CreatePen(PS_SOLID,3,RGB(255,255,0));
	SelectObject(bgDC,pen);
	MoveToEx(bgDC,(a * 40 + 60),(b * 40 + 60),NULL);
	LineTo(bgDC,(c * 40 + 60),(d * 40 + 60));
	MoveToEx(bgDC,(e * 40 + 60),(f * 40 + 60),NULL);
	LineTo(bgDC,(g * 40 + 60),(h * 40 + 60));
	MoveToEx(bgDC,(aa * 40 + 60),(bb * 40 + 60),NULL);
	LineTo(bgDC,(cc * 40 + 60),(dd * 40 + 60));
	a = 0,b = 0,c = 0,d = 0,e = 0,f = 0,g = 0,h = 0,aa = 0,bb = 0,cc = 0,dd = 0;
	hPen2 = CreatePen(PS_NULL, 1, RGB(0, 0, 0));   //画笔 
	SelectObject(bgDC, hPen2); 
    hBrush = CreateSolidBrush(RGB(211, 211, 211)); //实心画刷 灰色
	SelectObject(bgDC, hBrush); 
	Rectangle(bgDC, 100, 20,640, 50); 

	hPen1 = CreatePen(PS_NULL, 1, RGB(0, 0, 0));   //画笔 
	SelectObject(bgDC, hPen1); 
	if(TimeLength>=20)
		hBrush = CreateSolidBrush(RGB(0, 128, 0)); //实心画刷 绿色
	else
		hBrush = CreateSolidBrush(RGB(255, 0, 0));////实心画刷 红色
	SelectObject(bgDC, hBrush); 
	Rectangle(bgDC, 100, 20,100+TimeLength*3, 50); 

	for (int iRow=0;iRow<12;iRow++)
	{
		for (int iCol=0;iCol<16;iCol++)
		{
			if(m_PicPos[iRow][iCol]!=0)
			{
				HDC memDC = CreateCompatibleDC(m_hdc);
				const TCHAR *p= m_pBmpPath[m_PicPos[iRow][iCol]-1];
				HBITMAP hh=(HBITMAP)LoadImage(m_hinst,p,IMAGE_BITMAP,0,0,LR_LOADFROMFILE);
				SelectObject(memDC,hh);

				CImage image;
				image.Load( p);
				image.Draw(memDC,0,0,image.GetWidth(),image.GetHeight());

				BitBlt(bgDC,40+iCol*40,40+iRow*40,40,40,memDC,0,0,SRCCOPY);
				DeleteObject(hh);
				DeleteDC(memDC);
			}
		}
	}

	int tscore=score;
	int tem=int(tscore/200);
	if(tscore>=1200)
		tem=0;
	for(int i=0;i<tem;i++)
	{
		HDC bgDC1 = CreateCompatibleDC(m_hdc);
		BITMAP temBmp;
		HBITMAP hStartBmp=(HBITMAP)LoadImage(m_hinst,TEXT("res\\map\\草1.bmp"),IMAGE_BITMAP,0,0,LR_LOADFROMFILE);
		::GetObject(hStartBmp,sizeof(temBmp),&temBmp);
		SelectObject(bgDC1,hStartBmp);
		TransparentBlt(bgDC,120+i*60,500,60,60,bgDC1,0,0,temBmp.bmWidth,temBmp.bmHeight,RGB(255,255,255));
		DeleteObject(hStartBmp);
		//DeleteDC(bgDC);
	}
	if(tscore>=1200&&tscore<1600)
	{
		for(int i=0;i<6;i++)
		{
			HDC bgDC1 = CreateCompatibleDC(m_hdc);
			BITMAP temBmp;
			HBITMAP hStartBmp=(HBITMAP)LoadImage(m_hinst,TEXT("res\\map\\草1.bmp"),IMAGE_BITMAP,0,0,LR_LOADFROMFILE);
			::GetObject(hStartBmp,sizeof(temBmp),&temBmp);
			SelectObject(bgDC1,hStartBmp);
			TransparentBlt(bgDC,120+i*60,500,60,60,bgDC1,0,0,temBmp.bmWidth,temBmp.bmHeight,RGB(255,255,255));
			DeleteObject(hStartBmp);
		}
	}
	if(tscore>=1600&&tscore<3600)
	{
		int n=int((tscore-1200)/400);
		for (int i=0;i<n;i++)
		{
			HDC bgDC1 = CreateCompatibleDC(m_hdc);
			BITMAP temBmp;
			HBITMAP hStartBmp=(HBITMAP)LoadImage(m_hinst,TEXT("res\\map\\草2.bmp"),IMAGE_BITMAP,0,0,LR_LOADFROMFILE);
			::GetObject(hStartBmp,sizeof(temBmp),&temBmp);
			SelectObject(bgDC1,hStartBmp);
			TransparentBlt(bgDC,120+i*60,500,60,60,bgDC1,0,0,temBmp.bmWidth,temBmp.bmHeight,RGB(255,255,255));
			DeleteObject(hStartBmp);

		}
	}
	if(tscore>=3600&&tscore<4200)
	{
		for (int i=0;i<5;i++)
		{
			HDC bgDC1 = CreateCompatibleDC(m_hdc);
			BITMAP temBmp;
			HBITMAP hStartBmp=(HBITMAP)LoadImage(m_hinst,TEXT("res\\map\\草2.bmp"),IMAGE_BITMAP,0,0,LR_LOADFROMFILE);
			::GetObject(hStartBmp,sizeof(temBmp),&temBmp);
			SelectObject(bgDC1,hStartBmp);
			TransparentBlt(bgDC,120+i*60,500,60,60,bgDC1,0,0,temBmp.bmWidth,temBmp.bmHeight,RGB(255,255,255));
			DeleteObject(hStartBmp);
		}
	}
	if(tscore>=4200)
	{
		int n=int((tscore-3600)/600);
		for (int i=0;i<n;i++)
		{
			HDC bgDC1 = CreateCompatibleDC(m_hdc);
			BITMAP temBmp;
			HBITMAP hStartBmp=(HBITMAP)LoadImage(m_hinst,TEXT("res\\map\\草3.bmp"),IMAGE_BITMAP,0,0,LR_LOADFROMFILE);
			::GetObject(hStartBmp,sizeof(temBmp),&temBmp);
			SelectObject(bgDC1,hStartBmp);
			TransparentBlt(bgDC,120+i*60,500,60,60,bgDC1,0,0,temBmp.bmWidth,temBmp.bmHeight,RGB(255,255,255));
			DeleteObject(hStartBmp);
		}
	}
	BitBlt(m_hdc,0,0,900,600,bgDC,0,0,SRCCOPY);
	DeleteObject(allBitmap);
	DeleteObject(hBrush);
	DeleteDC(bgDC);
	DeleteObject(pen);
}


void CDrawWnd::draw_bang(int x1, int y1, int x2, int y2)
{
	HDC bgDC1 = CreateCompatibleDC(m_hdc);
	BITMAP temBmp1;
	HBITMAP hStartBmp1 = (HBITMAP) LoadImage(m_hinst,TEXT("res\\map\\爆炸.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
	::GetObject(hStartBmp1, sizeof(temBmp1), &temBmp1);
	SelectObject(bgDC1, hStartBmp1);
	TransparentBlt(m_hdc, 40 + 40 * x1 , 40 + 40 * y1 , temBmp1.bmWidth, temBmp1.bmHeight, bgDC1, 0, 0, temBmp1.bmWidth, temBmp1.bmHeight, RGB(255, 255, 255));
	DeleteDC(bgDC1);
	HDC bgDC = CreateCompatibleDC(m_hdc);
	BITMAP temBmp;
	HBITMAP hStartBmp = (HBITMAP) LoadImage(m_hinst, TEXT("res\\map\\爆炸.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
	::GetObject(hStartBmp, sizeof(temBmp), &temBmp);
	SelectObject(bgDC, hStartBmp);
	TransparentBlt(m_hdc, 40 + 40 * x2 , 40 + 40 * y2 , temBmp.bmWidth, temBmp.bmHeight, bgDC, 0, 0, temBmp.bmWidth, temBmp.bmHeight, RGB(255, 255, 255));

	DeleteDC(bgDC);
}
void CDrawWnd::draw_game_face()
{
	HDC bgDC = CreateCompatibleDC(m_hdc);
	HBITMAP hbgBmp=(HBITMAP)LoadImage(m_hinst,_T("res\\map\\游戏.bmp"),IMAGE_BITMAP,0,0,LR_LOADFROMFILE);
	SelectObject(bgDC,hbgBmp);
	BitBlt(m_hdc,0,0,900,600,bgDC,0,0,SRCCOPY);
	DeleteDC(bgDC);
	for (int iRow=0;iRow<12;iRow++)
	{
		for (int iCol=0;iCol<16;iCol++)
		{
			if(m_PicPos[iRow][iCol]!=0)
			{
				HDC memDC = CreateCompatibleDC(m_hdc);
				const TCHAR *p= m_pBmpPath[m_PicPos[iRow][iCol]-1];
				HBITMAP hh=(HBITMAP)LoadImage(m_hinst,p,IMAGE_BITMAP,0,0,LR_LOADFROMFILE);
				SelectObject(memDC,hh);
				BitBlt(m_hdc,40+iCol*40,40+iRow*40,40,40,memDC,0,0,SRCCOPY);
				DeleteDC(memDC);
			}
		}
	}
}

void CDrawWnd::draw_onepic(int x,int y,int val,bool mark)
{
	if(mark && val!=0)
	{
		const TCHAR *p[24] = {
								TEXT("res\\map\\31.bmp"), TEXT("res\\map\\32.bmp"), TEXT("res\\map\\33.bmp"), TEXT("res\\map\\34.bmp"),
								TEXT("res\\map\\35.bmp"), TEXT("res\\map\\36.bmp"), TEXT("res\\map\\37.bmp"), TEXT("res\\map\\38.bmp"),
								TEXT("res\\map\\39.bmp"), TEXT("res\\map\\40.bmp"), TEXT("res\\map\\41.bmp"), TEXT("res\\map\\42.bmp"),
								TEXT("res\\map\\43.bmp"), TEXT("res\\map\\44.bmp"), TEXT("res\\map\\45.bmp"), TEXT("res\\map\\46.bmp"),
								TEXT("res\\map\\47.bmp"), TEXT("res\\map\\48.bmp"), TEXT("res\\map\\49.bmp"), TEXT("res\\map\\50.bmp"),
								TEXT("res\\map\\51.bmp"), TEXT("res\\map\\52.bmp"), TEXT("res\\map\\53.bmp"), TEXT("res\\map\\54.bmp")
							};
		HDC memDC = CreateCompatibleDC(m_hdc);
		HBITMAP hh=(HBITMAP)LoadImage(m_hinst,p[val-1],IMAGE_BITMAP,0,0,LR_LOADFROMFILE);
		SelectObject(memDC,hh);
		BitBlt(m_hdc,40+40*x-10,40+40*y-10,60,60,memDC,0,0,SRCCOPY);
		DeleteDC(memDC);
	}
	if(mark==0 && val!=0)
	{
		HDC memDC = CreateCompatibleDC(m_hdc);
		const TCHAR *p= m_pBmpPath[val-1];
		HBITMAP hh=(HBITMAP)LoadImage(m_hinst,p,IMAGE_BITMAP,0,0,LR_LOADFROMFILE);
		SelectObject(memDC,hh);
		BitBlt(m_hdc,40+40*x,40+40*y,40,40,memDC,0,0,SRCCOPY);
		DeleteDC(memDC);
	}
}

void CDrawWnd::draw_face(const TCHAR *pPic)
{
	HDC bgDC = CreateCompatibleDC(m_hdc);
	BITMAP temBmp;
	HBITMAP hStartBmp=(HBITMAP)LoadImage(m_hinst,pPic,IMAGE_BITMAP,0,0,LR_LOADFROMFILE);
	::GetObject(hStartBmp,sizeof(temBmp),&temBmp);
	SelectObject(bgDC,hStartBmp);
	BitBlt(m_hdc,0,0,temBmp.bmWidth,temBmp.bmHeight,bgDC,0,0,SRCCOPY);
	DeleteDC(bgDC);
}

void CDrawWnd::draw_score(int score)
{
	int tscore=score;
	int tem=int(tscore/200);
	if(tscore>=1200)
		tem=0;
	for(int i=0;i<tem;i++)
	{
		HDC bgDC = CreateCompatibleDC(m_hdc);
		BITMAP temBmp;
		HBITMAP hStartBmp=(HBITMAP)LoadImage(m_hinst,TEXT("res\\map\\草1.bmp"),IMAGE_BITMAP,0,0,LR_LOADFROMFILE);
		::GetObject(hStartBmp,sizeof(temBmp),&temBmp);
		SelectObject(bgDC,hStartBmp);
		TransparentBlt(m_hdc,120+i*60,500,60,60,bgDC,0,0,temBmp.bmWidth,temBmp.bmHeight,RGB(255,255,255));
		DeleteDC(bgDC);
	}
	if(tscore>=1200&&tscore<1600)
	{
		for(int i=0;i<6;i++)
		{
			HDC bgDC = CreateCompatibleDC(m_hdc);
			BITMAP temBmp;
			HBITMAP hStartBmp=(HBITMAP)LoadImage(m_hinst,TEXT("res\\map\\草1.bmp"),IMAGE_BITMAP,0,0,LR_LOADFROMFILE);
			::GetObject(hStartBmp,sizeof(temBmp),&temBmp);
			SelectObject(bgDC,hStartBmp);
			TransparentBlt(m_hdc,120+i*60,500,60,60,bgDC,0,0,temBmp.bmWidth,temBmp.bmHeight,RGB(255,255,255));
			DeleteDC(bgDC);
		}
	}
	if(tscore>=1600&&tscore<3600)
	{
		int n=int((tscore-1200)/400);
		for (int i=0;i<n;i++)
		{
			HDC bgDC = CreateCompatibleDC(m_hdc);
			BITMAP temBmp;
			HBITMAP hStartBmp=(HBITMAP)LoadImage(m_hinst,TEXT("res\\map\\草2.bmp"),IMAGE_BITMAP,0,0,LR_LOADFROMFILE);
			::GetObject(hStartBmp,sizeof(temBmp),&temBmp);
			SelectObject(bgDC,hStartBmp);
			TransparentBlt(m_hdc,120+i*60,500,60,60,bgDC,0,0,temBmp.bmWidth,temBmp.bmHeight,RGB(255,255,255));
			DeleteDC(bgDC);
		}
	}
	if(tscore>=3600&&tscore<4200)
	{
		for (int i=0;i<5;i++)
		{
			HDC bgDC = CreateCompatibleDC(m_hdc);
			BITMAP temBmp;
			HBITMAP hStartBmp=(HBITMAP)LoadImage(m_hinst,TEXT("res\\map\\草2.bmp"),IMAGE_BITMAP,0,0,LR_LOADFROMFILE);
			::GetObject(hStartBmp,sizeof(temBmp),&temBmp);
			SelectObject(bgDC,hStartBmp);
			TransparentBlt(m_hdc,120+i*60,500,60,60,bgDC,0,0,temBmp.bmWidth,temBmp.bmHeight,RGB(255,255,255));
			DeleteDC(bgDC);
		}
	}
	if(tscore>=4200)
	{
		int n=int((tscore-3600)/600);
		for (int i=0;i<n;i++)
		{
			HDC bgDC = CreateCompatibleDC(m_hdc);
			BITMAP temBmp;
			HBITMAP hStartBmp=(HBITMAP)LoadImage(m_hinst,TEXT("res\\map\\草3.bmp"),IMAGE_BITMAP,0,0,LR_LOADFROMFILE);
			::GetObject(hStartBmp,sizeof(temBmp),&temBmp);
			SelectObject(bgDC,hStartBmp);
			TransparentBlt(m_hdc,120+i*60,500,60,60,bgDC,0,0,temBmp.bmWidth,temBmp.bmHeight,RGB(255,255,255));
			DeleteDC(bgDC);
		}
	}
}

bool CDrawWnd::get_tip()
{
	for(int cur_row=1;cur_row<11;cur_row++)
	{
		for(int cur_column=1;cur_column<15;cur_column++)
		{
			for(int row=1;row<11;row++)
			{
				for(int column=1;column<15;column++)
				{
					if(m_PicPos[cur_row][cur_column]!=0&&m_PicPos[row][column]!=0&&(cur_column!=column || cur_row!=row))
					{
						bool is_nop = is_link_nopoint(cur_column,cur_row,m_PicPos[cur_row][cur_column],column,row,m_PicPos[row][column]);
						bool is_onep = is_link_onepoint(cur_column,cur_row,m_PicPos[cur_row][cur_column],column,row,m_PicPos[row][column]);
						bool is_twop = is_link_twopoint(cur_column,cur_row,m_PicPos[cur_row][cur_column],column,row,m_PicPos[row][column]);
						if(is_nop || is_onep || is_twop)
						{
							HPEN pen = CreatePen(PS_SOLID,25,RGB(0,0,0));
							SelectObject(m_hdc,pen);
							MoveToEx(m_hdc,40+40*cur_column+18,40+40*cur_row+18,NULL);
							LineTo(m_hdc,40+40*cur_column+22,40+40*cur_row+22);
							MoveToEx(m_hdc,40+40*column+18,40+40*row+18,NULL);
							LineTo(m_hdc,40+40*column+22,40+40*row+22);
							DeleteObject(pen);
							return true;
						}
						else
							continue;
					}
				}
			}
		}
	}
	return false;
}

CDrawWnd::~CDrawWnd(void)
{
	DeleteDC(m_hdc);
}
