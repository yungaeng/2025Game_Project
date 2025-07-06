#pragma once
#include <mysql.h>
#include <iostream>
#include <string>
#include <vector>

struct logindata {
	int ID;
	std::string NAME;
};

class DB
{
public:
	MYSQL Conn;             // MySQL ������ ���� ����ü
	MYSQL* ConnPtr = NULL;  // MySQL �ڵ�
	MYSQL_RES* Result;      // ���������� ����� ��� ����ü ������
	MYSQL_ROW Row;          // ���������� ����� ���� ���� ������ ��� ����ü
	int Stat;               // ������û �� ���(����, ����)

	std::vector<logindata> userdata;
public:
	DB();
	~DB();

public:
	bool InitDB();
	bool InsertDB(logindata ld);
	void SelectDB();
	bool FindDB(std::string name);
	bool DeleteDB(int id);
};

