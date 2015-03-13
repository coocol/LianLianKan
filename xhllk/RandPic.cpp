#include "stdafx.h"
#include "RandPic.h"
#include "stdlib.h"
#include "time.h"

CRandPic::CRandPic(void)
{
	for(int row=0;row<12;row++)
		for(int column=0;column<16;column++)
			m_PosName[row][column]=0;
	get_randnum_for_pos();
}

bool CRandPic::is_empty()
{
	for(int row=1;row<11;row++)
	{
		for(int column=1;column<15;column++)
		{
			if(m_PosName[row][column]==0)
				continue;
			else 
				return false;
		}
	}
	return true;
}

void CRandPic::get_match_pos(int &irandrow,int &irandcol)  
{
	irandcol = rand()%14+1;
	irandrow = rand()%10+1;
}

void CRandPic::get_randnum_for_pos()
{
	srand((unsigned)time(NULL));
	for(int row=1;row<11;row++)
	{
		for(int column=1;column<15;column++)
		{
			int irandnum = (rand()%16)+1;
			if(m_PosName[row][column]==0)
			{
				int x,y;
				m_PosName[row][column] = irandnum;
				get_match_pos(x,y);
				if (m_PosName[x][y]==0)
					m_PosName[x][y] = irandnum;
				else
				{
					while(m_PosName[x][y]!=0)
						get_match_pos(x,y);
					m_PosName[x][y]=irandnum;
				}
			}
		}
	}
}

void CRandPic::get_randnum_for_pos(bool level)
{
	if(level)
	{
		srand((unsigned)time(NULL));
		for(int row=1;row<11;row++)
		{
			for(int column=1;column<15;column++)
			{
				int irandnum = (rand()%24)+1;
				if(m_PosName[row][column]==0)
				{
					int x,y;
					m_PosName[row][column] = irandnum;
					get_match_pos(x,y);
					if (m_PosName[x][y]==0)
						m_PosName[x][y] = irandnum;
					else
					{
						while(m_PosName[x][y]!=0)
							get_match_pos(x,y);
						m_PosName[x][y]=irandnum;
					}
				}
			}
		}
	}
	else
		get_randnum_for_pos();
}

bool CRandPic::clear()
{
	for(int row=0;row<12;row++)
		for(int column=0;column<16;column++)
			m_PosName[row][column]=0;
	return true;
}

CRandPic::~CRandPic(void)
{
}
