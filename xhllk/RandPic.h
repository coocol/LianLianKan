#pragma once
class CRandPic
{
public:
	CRandPic(void);
	virtual ~CRandPic(void);
	void get_match_pos(int &irandrow,int &irandcol);//�õ�ƥ��λ�ã�������������������
	void get_randnum_for_pos();//�ͼ�ģʽ
	void get_randnum_for_pos(bool level);//�߼�ģʽ
	int m_PosName[12][16];//��ά�����ʾλ��
	//������������ȥ�㷨
	bool is_link_nopoint();
	bool is_link_onepoint();
	bool is_link_twopoint();
	bool is_empty();//�ж��Ƿ�ȫ����ȥ
	bool clear();//�������λ��
};

