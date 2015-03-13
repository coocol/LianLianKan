#pragma once
class CDrawWnd
{
public:
	CDrawWnd(void);
	CDrawWnd(HDC &hdc,HINSTANCE &hinst);
	void set(HDC &hdc,HINSTANCE &hinst);
	virtual ~CDrawWnd(void);
	void get_picname(int val[12][16]);//�����ͼ��ָ��ͼƬ
	void draw_game_face();
	void draw_game_face(HWND hWnd,int TimeLength,int score);
	bool get_tip();//�����ʾ
	void draw_face(const TCHAR *pPic);//���ƽ���
	void draw_score(int score);//���Ƶ÷�Ч��
	void draw_onepic(int x,int y,int val,bool mark);//����ѡ�б�־
	bool is_link_nopoint(int x1,int y1,int v1,int x2,int y2,int v2);//�޹յ���ͨ
	bool is_link_onepoint(int x1,int y1,int v1,int x2,int y2,int v2);//һ�յ���ͨ
	bool is_link_twopoint(int x1,int y1,int v1,int x2,int y2,int v2);//���յ���ͨ
	bool is_link_twomorepoint();//	
	HDC m_hdc;//����DC
	HINSTANCE m_hinst;//ʵ�����
	const TCHAR *m_pBmpPath[24];//ͼƬ·��
	int m_PicPos[12][16];//�����е�ͼƬ
	bool m_bMode;//ģʽ
	void draw_bang(int x1,int y1,int x2,int y2);
	
};


