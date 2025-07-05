#include "db.h"

DB::DB()
{
	
}

DB::~DB()
{
	// 데이터베이스와 연결해제
	mysql_close(ConnPtr);
}

bool DB::InitDB()
{
	mysql_init(&Conn);      // MySQL 정보 초기화

	// 데이터베이스와 연결
	// ConnPtr = mysql_real_connect(&Conn, "데이터베이스서버주소", "root", "비밀번호", "접속할데이터베이스", 3306, (char*)NULL, 0);
	ConnPtr = mysql_real_connect(&Conn, "127.0.0.1", "root", "yungaeng", "mygame_db", 3306, (char*)NULL, 0);

	if (ConnPtr == NULL)    // 연결 결과 확인, NULL일 경우 연결 실패한 것
	{
		fprintf(stderr, "MySQL connection error : %s\n", mysql_error(&Conn));
		return false;
	}

	return true;
}

bool DB::InsertDB(logindata ld)
{
	std::string insert_query
		= "INSERT INTO user_data (id, name) VALUES ('" + std::to_string(ld.ID) + "', '" + ld.NAME + "')";

	if (mysql_query(ConnPtr, insert_query.c_str()))
	{
		std::cerr << "Query exectuion error: " << mysql_error(ConnPtr) << "\n";
		return false;
	}

	std::cout << "New record added successfully\n";
	return true;
}

void DB::SelectDB()
{
	// 데이터베이스에 한글이 있다면 아래 3줄 추가
	// MySQL에서 사용하는 문자셋을 VS가 사용하는 문자셋인 euc-kr로 변경해주는 기능
	mysql_query(ConnPtr, "set session character_set_connection=euckr;");
	mysql_query(ConnPtr, "set session character_set_results=euckr;");
	mysql_query(ConnPtr, "set session character_set_client=euckr;");

	char* Query = (char*)"SELECT * FROM user_data";    // 세미콜론을 제외한 쿼리문 작성
	Stat = mysql_query(ConnPtr, Query);             // 쿼리 요청 및 성공여부 받아오기
	if (Stat != 0)
	{
		fprintf(stderr, "MySQL query error : %s\n", mysql_error(&Conn));
		return;
	}

	Result = mysql_store_result(ConnPtr);           // 결과 확인하기
	while ((Row = mysql_fetch_row(Result)) != NULL) // 결과 출력하기
	{
		std::cout << Row[0] << ' ' << Row[1] << '\n';
	}
	mysql_free_result(Result);                      // 결과 비우기
}
