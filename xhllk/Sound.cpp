#include "stdafx.h"
#include "Sound.h"
#include <mmsystem.h>
#pragma comment(lib, "winmm.lib")

CSound::CSound(void)
{
}

void CSound::play_startSND(bool flag)
{
	if(flag)
	{
		mciSendString(TEXT("open res\\music\\��ʼ.mp3"),0,NULL,NULL);
		mciSendString(TEXT("play res\\music\\��ʼ.mp3 repeat"),0,NULL,NULL);
	}
	else
	{
		mciSendString(TEXT("pause res\\music\\��ʼ.mp3"),0,NULL,NULL);
	}
}

void CSound::play_bgSND(bool flag)
{
	if(flag)
	{
		mciSendString(TEXT("open res\\music\\����.mp3"),0,NULL,NULL);
		mciSendString(TEXT("play res\\music\\����.mp3 repeat"),0,NULL,NULL);
	}
	else
	{
		mciSendString(TEXT("pause res\\music\\����.mp3"),0,NULL,NULL);
		
	}
}

void CSound::play_clickSND(int v)
{
	if(v!=0)
		mciSendString(TEXT("play res\\music\\���.wav"),0,NULL,NULL);
}

void CSound::play_collegeSND(int val)
{
	
	const TCHAR *p[24]={
							TEXT("play res\\music\\1.wav"),TEXT("play res\\music\\2.wav"),TEXT("play res\\music\\3.wav"),TEXT("play res\\music\\4.wav"),
							TEXT("play res\\music\\5.wav"),TEXT("play res\\music\\6.wav"),TEXT("play res\\music\\7.wav"),TEXT("play res\\music\\8.wav"),
							TEXT("play res\\music\\9.wav"),TEXT("play res\\music\\10.wav"),TEXT("play res\\music\\11.wav"),TEXT("play res\\music\\12.wav"),
							TEXT("play res\\music\\13.wav"),TEXT("play res\\music\\14.wav"),TEXT("play res\\music\\15.wav"),TEXT("play res\\music\\16.wav"),
							TEXT("play res\\music\\17.wav"),TEXT("play res\\music\\18.wav"),TEXT("play res\\music\\19.wav"),TEXT("play res\\music\\20.wav"),
							TEXT("play res\\music\\21.wav"),TEXT("play res\\music\\22.wav"),TEXT("play res\\music\\23.wav"),TEXT("play res\\music\\24.wav")
						};
	if(val>=0&&val<=23)
	{
		mciSendString(p[val],0,NULL,NULL);
	}

}

void CSound::playSND(const TCHAR *p,bool is)
{
	if(is)
		mciSendString(p,0,NULL,NULL);
}

void CSound::play_tipSND(int n)
{
	const TCHAR *p[3]={TEXT("play res\\music\\��ʾ2.wav"),TEXT("play res\\music\\��ʾ1.wav"),TEXT("play res\\music\\��ʾ0.wav")};
	mciSendString(p[n],0,NULL,NULL);
}
void CSound::pauseSND(const TCHAR *p)
{
	mciSendString(p,0,NULL,NULL);
}
void CSound::stopSND(const TCHAR *p)
{
	mciSendString(p,0,NULL,NULL);
}

CSound::~CSound(void)
{
}


