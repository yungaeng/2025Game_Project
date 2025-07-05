#pragma once
#include <mysql.h>
#include <iostream>
#include <string>

struct logindata {
	std::string ID;
	int password;
};

class DB
{
	MYSQL Conn;             // MySQL ������ ���� ����ü
	MYSQL* ConnPtr = NULL;  // MySQL �ڵ�
	MYSQL_RES* Result;      // ���������� ����� ��� ����ü ������
	MYSQL_ROW Row;          // ���������� ����� ���� ���� ������ ��� ����ü
	int Stat;               // ������û �� ���(����, ����)
public:
	DB();
	~DB();

public:
	bool InitDB();
	bool InsertDB(logindata ld);
	void SelectDB();
};

