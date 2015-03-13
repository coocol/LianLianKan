#pragma once
class CSound
{
public:
	CSound(void);
	virtual ~CSound(void);
	void play_startSND(bool flag);//开始
	void play_bgSND(bool flag);//背景
	void play_collegeSND(int val);//读出大学名字
	void play_tipSND(int n);//播放提示音
	void playSND(const TCHAR *p,bool is);//播放界面声音
	void play_clickSND(int v);//按钮声音
	void CSound::pauseSND(const TCHAR *p);//暂停播放失败音乐
	void CSound::stopSND(const TCHAR *p);//停止播放音乐
};

