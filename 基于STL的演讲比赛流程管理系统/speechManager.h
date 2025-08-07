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

	//菜单功能
	void show_Menu();

	//退出系统
	void exitSystem();

	~SpeechManager();

	//初始化容器和属性
	void initSpeech();

	//创建12名选手
	void createSpeaker();

	//比赛流程控制函数
	void startSpeech();

	//抽签
	void speechDraw();
	//比赛
	void speechContest();
	//显示得分
	void showScore();
	//保存记录
	void saveRecord();
	//读取记录
	void loadRecord();
	//显示往届记录
	void showRecord();
	//清空
	void clearRecord();

	//成员属性
	vector<int>v1;
	vector<int>v2;
	vector<int>vVictory;

	bool fileIsEmpty;
	//存放往届记录的容器
	map<int, vector<string>>m_Record;

	map<int, Speaker>m_Speaker;//存放编号以及对应具体选手的容器

	//存放比赛轮数
	int m_Index;
};

