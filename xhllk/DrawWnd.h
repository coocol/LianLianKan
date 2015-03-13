#pragma once
class CDrawWnd
{
public:
	CDrawWnd(void);
	CDrawWnd(HDC &hdc,HINSTANCE &hinst);
	void set(HDC &hdc,HINSTANCE &hinst);
	virtual ~CDrawWnd(void);
	void get_picname(int val[12][16]);//随机贴图，指定图片
	void draw_game_face();
	void draw_game_face(HWND hWnd,int TimeLength,int score);
	bool get_tip();//获得提示
	void draw_face(const TCHAR *pPic);//绘制界面
	void draw_score(int score);//绘制得分效果
	void draw_onepic(int x,int y,int val,bool mark);//绘制选中标志
	bool is_link_nopoint(int x1,int y1,int v1,int x2,int y2,int v2);//无拐点联通
	bool is_link_onepoint(int x1,int y1,int v1,int x2,int y2,int v2);//一拐点联通
	bool is_link_twopoint(int x1,int y1,int v1,int x2,int y2,int v2);//二拐点联通
	bool is_link_twomorepoint();//	
	HDC m_hdc;//窗口DC
	HINSTANCE m_hinst;//实例句柄
	const TCHAR *m_pBmpPath[24];//图片路径
	int m_PicPos[12][16];//格子中的图片
	bool m_bMode;//模式
	void draw_bang(int x1,int y1,int x2,int y2);
	
};


