#pragma once
class CRandPic
{
public:
	CRandPic(void);
	virtual ~CRandPic(void);
	void get_match_pos(int &irandrow,int &irandcol);//得到匹配位置，由以下两个函数调用
	void get_randnum_for_pos();//低级模式
	void get_randnum_for_pos(bool level);//高级模式
	int m_PosName[12][16];//二维数组表示位置
	//以下三个是消去算法
	bool is_link_nopoint();
	bool is_link_onepoint();
	bool is_link_twopoint();
	bool is_empty();//判断是否全部消去
	bool clear();//清空所有位置
};

