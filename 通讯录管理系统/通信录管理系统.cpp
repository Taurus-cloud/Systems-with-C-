#include<iostream>
using namespace std;
#define MAX 1000

void showMenu()     //��ʾ�˵�����
{
	cout << "*****************************" << endl;
	cout << "*****   1�������ϵ��   *****" << endl;
	cout << "*****   2����ʾ��ϵ��   *****" << endl;
	cout << "*****   3��ɾ����ϵ��   *****" << endl;
	cout << "*****   4��������ϵ��   *****" << endl;
	cout << "*****   5���޸���ϵ��   *****" << endl;
	cout << "*****   6�������ϵ��   *****" << endl;
	cout << "*****   0���˳�ͨѶ¼   *****" << endl;
	cout << "*****************************" << endl;
}
struct Person        //��ϵ�˽ṹ��
{
	string m_Name;
	int m_Sex;
	int m_Age;
	string m_Phone;
	string m_Addr;
};

struct Addressbooks  //ͨѶ¼�ṹ��
{
	struct Person personArray[MAX];
	int m_Size;     //��ǰͨѶ¼��ϵ�˸���
};

void addPerson(struct Addressbooks * abs) //�����ϵ��
{
	if (abs->m_Size == MAX)
	{
		cout << "ͨѶ¼�������޷����" << endl;
		return ;
	}
	else
	{
		//�����û�����
		cout << "������������" << endl;
		string name;
		cin >> name;
		abs->personArray[abs->m_Size].m_Name = name;
		//�����û��Ա�
		cout << "�������Ա�" << endl;
		cout << "1---��  2---Ů" << endl;
		int sex = 0;
		while (true)
		{
			cin >> sex;
			if (sex == 1 || sex == 2)
			{
				abs->personArray[abs->m_Size].m_Sex = sex;
				break;
			}
			cout << "������������������" << endl;
		}
		//�����û�����
		cout << "���������䣺" << endl;
		int age = 0;
		cin >> age;
		abs->personArray[abs->m_Size].m_Age = age;
		//������ϵ�绰
		cout << "��������ϵ�绰��" << endl;
		string phone;
		cin >> phone;
		abs->personArray[abs->m_Size].m_Phone = phone;
		//�����ͥסַ
		cout << "�������ͥסַ��" << endl;
		string address;
		cin >> address;
		abs->personArray[abs->m_Size].m_Addr = address;

		//����ͨѶ¼����
		abs->m_Size++;

		cout << "��ӳɹ�" << endl;
		system("pause");         //�����������
		system("cls");           //��������
	}

};

void showPerson(struct Addressbooks* abs)   //��ʾ������ϵ��
{
	if (abs->m_Size == 0)
	{
		cout << "��ǰ�ļ�¼Ϊ��" << endl;
	}
	else
	{
		for (int i = 0; i < abs->m_Size; i++)
		{
			cout << "������" << abs->personArray[i].m_Name << "\t";
			cout << "�Ա�" << (abs->personArray[i].m_Sex == 1 ? "��" : "Ů") << "\t";
			cout << "���䣺" << abs->personArray[i].m_Age << "\t";
			cout << "�绰��" << abs->personArray[i].m_Phone << "\t";
			cout << "סַ��" << abs->personArray[i].m_Addr << endl;
		}
	}
	system("pause");         //�����������
	system("cls");           //��������
};

int isExist(struct Addressbooks* abs, string name)   //�ж���ϵ���Ƿ���ڣ������ڷ�����ϵ�����������λ�ã��������ڷ���-1
{
	for (int i = 0; i < abs->m_Size; i++)
	{
		if (abs->personArray[i].m_Name == name)
		{
			return i;
		}
	}
	return -1;
};

void deletePerson(struct Addressbooks* abs)        //ɾ��ָ����ϵ��
{
	cout << "��������Ҫɾ������ϵ��" << endl;
	string name;
	cin >> name;
	int ret = isExist(abs, name);
	if (ret != -1)
	{
		for (int i = ret; i < abs->m_Size; i++)
		{
			abs->personArray[i] = abs->personArray[i + 1];
		}
		abs->m_Size--;
		cout << "ɾ���ɹ�" << endl;
	}
	else
	{
		cout << "���޴���" << endl;
	}
	system("pause");         //�����������
	system("cls");           //��������
};

void findPerson(struct Addressbooks * abs)            //����ָ����ϵ����Ϣ
{
	cout << "��������Ҫ���ҵ���ϵ��" << endl;
	string name;
	cin >> name;
	int ret = isExist(abs, name);
	if (ret != -1)
	{
		cout << "������" << abs->personArray[ret].m_Name << "\t";
		cout << "�Ա�" << (abs->personArray[ret].m_Sex == 1 ? "��":"Ů") << "\t";
		cout << "���䣺" << abs->personArray[ret].m_Age << "\t";
		cout << "�绰��" << abs->personArray[ret].m_Phone << "\t";
		cout << "סַ��" << abs->personArray[ret].m_Addr << endl;
	}
	else
	{
		cout << "���޴���" << endl;
	}
	system("pause");         //�����������
	system("cls");           //��������
};

void modifyPerson(struct Addressbooks * abs)   //�޸�ָ����ϵ����Ϣ
{
	cout << "��������Ҫ�޸ĵ���ϵ��" << endl;
	string name;
	cin >> name;
	int ret = isExist(abs, name);
	if (ret != -1)
	{
		//�����û�����
		cout << "������������" << endl;
		string name;
		cin >> name;
		abs->personArray[ret].m_Name = name;
		//�����û��Ա�
		cout << "�������Ա�" << endl;
		cout << "1---��  2---Ů" << endl;
		int sex = 0;
		while (true)
		{
			cin >> sex;
			if (sex == 1 || sex == 2)
			{
				abs->personArray[ret].m_Sex = sex;
				break;
			}
			cout << "������������������" << endl;
		}
		//�����û�����
		cout << "���������䣺" << endl;
		int age = 0;
		cin >> age;
		abs->personArray[ret].m_Age = age;
		//������ϵ�绰
		cout << "��������ϵ�绰��" << endl;
		string phone;
		cin >> phone;
		abs->personArray[ret].m_Phone = phone;
		//�����ͥסַ
		cout << "�������ͥסַ��" << endl;
		string address;
		cin >> address;
		abs->personArray[ret].m_Addr = address;

		cout << "�޸ĳɹ�!" << endl;
	}
	else
	{
		cout << "���޴���" << endl;
	}
	system("pause");         //�����������
	system("cls");           //��������
};

void cleanPerson(struct Addressbooks* abs)
{
	abs->m_Size = 0;
	cout << "ͨѶ¼�����" << endl;
	system("pause");         //�����������
	system("cls");           //��������
};

int main()
{
	struct Addressbooks abs;  //����ͨѶ¼�ṹ�����
	abs.m_Size = 0;           //��ʼ����ϵ�˸���

	int select = 0; //�����û�ѡ������ı���
	while(true)
	{
		showMenu();     //��ʾ�˵���������
		cin >> select;
		switch (select)
		{
		case 1://1�������ϵ��
			addPerson(&abs);
			break;
		case 2://2����ʾ��ϵ��
			showPerson(&abs);
			break;
		case 3://3��ɾ����ϵ��
			deletePerson(&abs);
			break;
		case 4://4��������ϵ��
			findPerson(&abs);
			break;
		case 5://5���޸���ϵ��
			modifyPerson(&abs);
			break;
		case 6://6�������ϵ��
			cleanPerson(&abs);
			break;
		case 0://0���˳�ͨѶ¼
			cout << "��ӭ�´�ʹ��" << endl;
			system("pause");
			return 0;
			break;
		default:
			break;
		}
	}
	

	system("pause");
	return 0;
}