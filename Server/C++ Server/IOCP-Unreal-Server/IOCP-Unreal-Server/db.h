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
	MYSQL Conn;             // MySQL 정보를 담을 구조체
	MYSQL* ConnPtr = NULL;  // MySQL 핸들
	MYSQL_RES* Result;      // 쿼리성공시 결과를 담는 구조체 포인터
	MYSQL_ROW Row;          // 쿼리성공시 결과로 나온 행의 정보를 담는 구조체
	int Stat;               // 쿼리요청 후 결과(성공, 실패)

	std::vector<logindata> userdata;
public:
	DB();
	~DB();

public:
	bool InitDB();
	bool InsertDB(logindata ld);
	void SelectDB();
	bool FindDB(std::string name);
	bool DeleteDB(long long id);
};

