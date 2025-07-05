#include <mysql.h>
#include <iostream>
#include <string>

int main()
{
	MYSQL Conn;             // MySQL ������ ���� ����ü
	MYSQL* ConnPtr = NULL;  // MySQL �ڵ�
	MYSQL_RES* Result;      // ���������� ����� ��� ����ü ������
	MYSQL_ROW Row;          // ���������� ����� ���� ���� ������ ��� ����ü
	int Stat;               // ������û �� ���(����, ����)

	mysql_init(&Conn);      // MySQL ���� �ʱ�ȭ

	// �����ͺ��̽��� ����
	// ConnPtr = mysql_real_connect(&Conn, "�����ͺ��̽������ּ�", "root", "��й�ȣ", "�����ҵ����ͺ��̽�", 3306, (char*)NULL, 0);
	ConnPtr = mysql_real_connect(&Conn, "127.0.0.1", "root", "yungaeng", "mygame_db", 3306, (char*)NULL, 0);

	if (ConnPtr == NULL)    // ���� ��� Ȯ��, NULL�� ��� ���� ������ ��
	{
		fprintf(stderr, "MySQL connection error : %s\n", mysql_error(&Conn));
		return 1;
	}


	std::string ID = "test id";
	int password = 1234;

	std::string insert_query
		= "INSERT INTO user_data (id, password) VALUES ('" + ID + "', " + std::to_string(password) + ")";

	if (mysql_query(ConnPtr, insert_query.c_str()))
	{
		std::cerr << "Query exectuion error: " << mysql_error(ConnPtr) << "\n";
		return 0;
	}

	std::cout << "New record added successfully\n";

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
		return 1;
	}

	Result = mysql_store_result(ConnPtr);           // ��� Ȯ���ϱ�
	while ((Row = mysql_fetch_row(Result)) != NULL) // ��� ����ϱ�
	{
		std::cout << Row[0] << ' ' << Row[1] << '\n';
	}
	mysql_free_result(Result);                      // ��� ����

	// �����ͺ��̽��� ��������
	mysql_close(ConnPtr);

	return 0;
}