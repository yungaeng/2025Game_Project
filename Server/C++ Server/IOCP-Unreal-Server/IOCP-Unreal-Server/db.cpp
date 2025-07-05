#include "db.h"

DB::DB()
{
	
}

DB::~DB()
{
	// �����ͺ��̽��� ��������
	mysql_close(ConnPtr);
}

bool DB::InitDB()
{
	mysql_init(&Conn);      // MySQL ���� �ʱ�ȭ

	// �����ͺ��̽��� ����
	// ConnPtr = mysql_real_connect(&Conn, "�����ͺ��̽������ּ�", "root", "��й�ȣ", "�����ҵ����ͺ��̽�", 3306, (char*)NULL, 0);
	ConnPtr = mysql_real_connect(&Conn, "127.0.0.1", "root", "yungaeng", "mygame_db", 3306, (char*)NULL, 0);

	if (ConnPtr == NULL)    // ���� ��� Ȯ��, NULL�� ��� ���� ������ ��
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
	// �����ͺ��̽��� �ѱ��� �ִٸ� �Ʒ� 3�� �߰�
	// MySQL���� ����ϴ� ���ڼ��� VS�� ����ϴ� ���ڼ��� euc-kr�� �������ִ� ���
	mysql_query(ConnPtr, "set session character_set_connection=euckr;");
	mysql_query(ConnPtr, "set session character_set_results=euckr;");
	mysql_query(ConnPtr, "set session character_set_client=euckr;");

	char* Query = (char*)"SELECT * FROM user_data";    // �����ݷ��� ������ ������ �ۼ�
	Stat = mysql_query(ConnPtr, Query);             // ���� ��û �� �������� �޾ƿ���
	if (Stat != 0)
	{
		fprintf(stderr, "MySQL query error : %s\n", mysql_error(&Conn));
		return;
	}

	Result = mysql_store_result(ConnPtr);           // ��� Ȯ���ϱ�
	while ((Row = mysql_fetch_row(Result)) != NULL) // ��� ����ϱ�
	{
		std::cout << Row[0] << ' ' << Row[1] << '\n';
	}
	mysql_free_result(Result);                      // ��� ����
}
