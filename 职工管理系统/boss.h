#pragma once
#include<iostream>
using namespace std;
#include"worker.h"

//普通员工类
class Boss :public Worker
{
public:
	Boss(int id, string name, int dId);
	//显示个人信息
	virtual void showInfo();
	//获取岗位名称
	virtual string getDeptName();
};

