#pragma once
class CSound
{
public:
	CSound(void);
	virtual ~CSound(void);
	void play_startSND(bool flag);//��ʼ
	void play_bgSND(bool flag);//����
	void play_collegeSND(int val);//������ѧ����
	void play_tipSND(int n);//������ʾ��
	void playSND(const TCHAR *p,bool is);//���Ž�������
	void play_clickSND(int v);//��ť����
	void CSound::pauseSND(const TCHAR *p);//��ͣ����ʧ������
	void CSound::stopSND(const TCHAR *p);//ֹͣ��������
};

