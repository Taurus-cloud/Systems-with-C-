#include "speechManager.h"

SpeechManager::SpeechManager()
{
	this->initSpeech();

	this->createSpeaker();
	//加载往届记录
	this->loadRecord();
}

//菜单功能
void SpeechManager::show_Menu()
{
	cout << "******************************" << endl;
	cout << "***** 欢迎参加演讲比赛！ *****" << endl;
	cout << "****** 1、开始演讲比赛   *****" << endl;
	cout << "****** 2、查看往届记录   *****" << endl;
	cout << "****** 3、清空比赛记录   *****" << endl;
	cout << "****** 0、退出比赛程序   *****" << endl;
	cout << endl;
}

//退出系统
void  SpeechManager::exitSystem()
{
	cout << "欢迎下次使用" << endl;
	system("pause");
	exit(0);
}

SpeechManager::~SpeechManager()
{

}

void SpeechManager::initSpeech()
{
	this->v1.clear();
	this->v2.clear();
	this->vVictory.clear();
	this->m_Speaker.clear();
	this->m_Record.clear();

	this->m_Index = 1;
}


//创建12名选手
void SpeechManager::createSpeaker()
{
	string nameSeed = "ABCDEFGHIJKL";
	for (int i = 0; i < nameSeed.size(); i++)
	{
		string name = "选手";
		name += nameSeed[i];
		//创建具体的选手
		Speaker sp;
		sp.m_Name = name;

		for (int j = 0; j < 2; j++)
		{
			sp.m_Score[j] = 0;
		}
		this->v1.push_back(i + 10001);
		this->m_Speaker.insert(make_pair(i + 10001, sp));
	}
}

//比赛流程控制函数
void SpeechManager::startSpeech()
{
	//第一轮开始比赛
	
	//抽签
	this->speechDraw();
	//比赛
	this->speechContest();
	//显示晋级结果
	this->showScore();
	//第二轮开始比赛
	this->m_Index++;
	//抽签
	this->speechDraw();
	//比赛
	this->speechContest();
	//显示最终结果
	this->showScore();
	//保存分数到文件
	this->saveRecord();

	//重置比赛，获取记录
	this->initSpeech();

	this->createSpeaker();
	//加载往届记录
	this->loadRecord();
	cout << "本届比赛完毕！" << endl;
	system("pause");
	system("cls");
}

//抽签
void  SpeechManager::speechDraw()
{
	cout << "第 << " << this->m_Index << " >> 轮比赛选手正在抽签" << endl;
	cout << "-------------------------------------"<<endl;
	cout << "抽签后演讲顺序如下： " << endl;

	if (this->m_Index == 1)
	{
		random_shuffle(v1.begin(), v1.end());
		for (vector<int>::iterator it = v1.begin(); it != v1.end(); it++)
		{
			cout << *it << " ";
		}
		cout << endl;
	}
	else
	{
		random_shuffle(v2.begin(), v2.end());
		for (vector<int>::iterator it = v2.begin(); it != v2.end(); it++)
		{
			cout << *it << " ";
		}
		cout << endl;
	}
	cout << "-------------------------------------" << endl;
	system("pause");
	cout << endl;
}
//比赛
void SpeechManager::speechContest()
{
	cout << "第 << " << this->m_Index << " >> 轮比赛正式开始" << endl;
	cout << "-------------------------------------" << endl;

	//准备临时容器，存放小组成绩
	multimap<double, int, greater<double>>groupScore;
	int num = 0;//6人一组，记录人员个数

	vector<int>v_Src;//比赛选手容器
	if (this->m_Index == 1)
	{
		v_Src = v1;
	}
	else
	{
		v_Src = v2;
	}

	for (vector<int>::iterator it = v_Src.begin(); it != v_Src.end(); it++)
	{
		num++;

		deque<double>d;

		for (int i = 0; i < 10; i++)
		{
			double score = (rand() % 401 + 600)/10.f;
			//cout << score << " ";
			d.push_back(score);
		}
		//cout << endl;

		sort(d.begin(), d.end(), greater<double>());
		d.pop_back();
		d.pop_front();

		double sum = accumulate(d.begin(), d.end(), 0.0f);
		double avg = sum /(double)d.size();

		//cout << "编号： " << *it << " 选手： " << this->m_Speaker[*it].m_Name << " 平均分： " << avg << endl;

		this->m_Speaker[*it].m_Score[this->m_Index - 1] = avg;

		//将打分数据 放入临时小组容器中
		groupScore.insert(make_pair(avg, *it));
		//每6人取出前三名
		if (num%6 == 0)
		{
			cout << "第" << num / 6 << "小组名次如下： " << endl;
			for (multimap<double, int, greater<double>>::iterator it = groupScore.begin(); it != groupScore.end(); it++)
			{
				cout << "编号： " << it->second << " 姓名： " << this->m_Speaker[it->second].m_Name << " 成绩： " << this->m_Speaker[it->second].m_Score[this->m_Index - 1] << endl;
			}
			//取走前三名
			int count = 0;
			for (multimap<double, int, greater<double>>::iterator it = groupScore.begin(); it != groupScore.end()&&count<3; it++,count++)
			{
				if (this->m_Index == 1)
				{
					v2.push_back((*it).second);
				}
				else
				{
					vVictory.push_back((*it).second);
				}
			}
			groupScore.clear();
			cout << endl;
		}
	}
	cout << "第 << " << this->m_Index << " >> 轮比赛顺利结束" << endl;
	cout << "-------------------------------------" << endl;
	system("pause");
}

//显示得分
void SpeechManager::showScore()
{
	cout << "第 << " << this->m_Index << " >> 轮比赛晋级选手信息如下：" << endl;
	cout << "-------------------------------------" << endl;

	vector<int>v;
	if (this->m_Index == 1)
	{
		v = v2;
	}
	else
	{
		v = vVictory;
	}
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << "编号： " << *it << " 姓名： " << this->m_Speaker[*it].m_Name << " 得分： " << this->m_Speaker[*it].m_Score[this->m_Index - 1] << endl;

	}
	cout << endl;

	system("pause");
	system("cls");
	this->show_Menu();
}
//保存记录
void SpeechManager::saveRecord()
{
	ofstream ofs;
	ofs.open("speech.csv", ios::out | ios::app);

	for (vector<int>::iterator it = vVictory.begin(); it != vVictory.end(); it++)
	{
		ofs << *it << "," << this->m_Speaker[*it].m_Score[1] << ",";
	}
	ofs << endl;

	ofs.close();
	cout << "记录已经保存！" << endl;

	this->fileIsEmpty = false;
}
//读取记录
void  SpeechManager::loadRecord()
{
	ifstream ifs("speech.csv", ios::in);
	if (!ifs.is_open())
	{
		this->fileIsEmpty = true;
		cout << "文件不存在" << endl;
		ifs.close();
		return;
	}
	
	char ch;
	ifs >> ch;
	if (ifs.eof())
	{
		this->fileIsEmpty = true;
		cout << "文件为空" << endl;
		ifs.close();
		return;
	}

	//文件不为空
	this->fileIsEmpty = false;
	ifs.putback(ch);

	string data;
	int index = 0;

	while (ifs >> data)
	{
		vector<string>v;

		int pos = -1;
		int start = 0;

		while (true)
		{
			pos = data.find(",", start);
			if (pos == -1)
			{
				break;
			}
			string temp = data.substr(start, pos - start);
			v.push_back(temp);

			start = pos + 1;
		}
		this->m_Record.insert(make_pair(index, v));
		index++;
	}
	ifs.close();
}
//显示往届记录
void  SpeechManager::showRecord()
{
	if (this->fileIsEmpty)
	{
		cout << "文件不存在，或记录为空！" << endl;
	}
	else
	{
		for (int i = 0; i < this->m_Record.size(); i++)
		{
			cout << "第" << i + 1 << "届"
				<< "冠军编号： " << this->m_Record[i][0] << " 得分： " << this->m_Record[i][1] << " "
				<< "亚军编号： " << this->m_Record[i][2] << " 得分： " << this->m_Record[i][3] << " "
				<< "季军编号： " << this->m_Record[i][4] << " 得分： " << this->m_Record[i][5] << endl;
		}
	}
	system("pause");
	system("cls");
}
//清空
void SpeechManager::clearRecord()
{
	ofstream ofs("speech.csv", ios::trunc);
	ofs.close();

	this->initSpeech();

	this->createSpeaker();
	//加载往届记录
	this->loadRecord();

	cout << "清空成功！" << endl;

	system("pause");
	system("cls");
}