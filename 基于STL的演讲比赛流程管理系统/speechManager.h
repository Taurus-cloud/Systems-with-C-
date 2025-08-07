#pragma once
#include<iostream>
#include<vector>
#include<map>
#include "speaker.h"
#include<algorithm>
#include<deque>
#include<numeric>
#include<fstream>
using namespace std;

class SpeechManager
{
public:
	SpeechManager();

	//�˵�����
	void show_Menu();

	//�˳�ϵͳ
	void exitSystem();

	~SpeechManager();

	//��ʼ������������
	void initSpeech();

	//����12��ѡ��
	void createSpeaker();

	//�������̿��ƺ���
	void startSpeech();

	//��ǩ
	void speechDraw();
	//����
	void speechContest();
	//��ʾ�÷�
	void showScore();
	//�����¼
	void saveRecord();
	//��ȡ��¼
	void loadRecord();
	//��ʾ�����¼
	void showRecord();
	//���
	void clearRecord();

	//��Ա����
	vector<int>v1;
	vector<int>v2;
	vector<int>vVictory;

	bool fileIsEmpty;
	//��������¼������
	map<int, vector<string>>m_Record;

	map<int, Speaker>m_Speaker;//��ű���Լ���Ӧ����ѡ�ֵ�����

	//��ű�������
	int m_Index;
};

