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
	ConnPtr = mysql_real_connect(&Conn, "127.0.0.1", "yungaeng", "yungaeng", "mygame_db", 3306, (char*)NULL, 0);

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
		= "INSERT INTO user_data (name, password) VALUES ('" + ld.NAME + "', '" + std::to_string(ld.ID) + "')";

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
	//mysql_query(ConnPtr, "set session character_set_connection=euckr;");
	//mysql_query(ConnPtr, "set session character_set_results=euckr;");
	//mysql_query(ConnPtr, "set session character_set_client=euckr;");

	char* Query = (char*)"SELECT * FROM user_data";    // �����ݷ��� ������ ������ �ۼ�
	Stat = mysql_query(ConnPtr, Query);             // ���� ��û �� �������� �޾ƿ���
	if (Stat != 0)
	{
		fprintf(stderr, "MySQL query error : %s\n", mysql_error(&Conn));
		return;
	}

	Result = mysql_store_result(ConnPtr);           // ��� Ȯ���ϱ�
	
	std::cout << "----���� DB ��Ȳ----" << std::endl;
	while ((Row = mysql_fetch_row(Result)) != NULL) 
	{
		std::cout << Row[0] << ' ' << Row[1] << '\n'; // ��� ����ϱ�
	}
	std::cout << "-------------------" << std::endl;
	mysql_free_result(Result);                      // ��� ����
}

bool DB::FindDB(std::string name)
{
	userdata.clear();

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
		return false;
	}

	Result = mysql_store_result(ConnPtr);           // ��� Ȯ���ϱ�
	while ((Row = mysql_fetch_row(Result)) != NULL)
	{
		logindata lg;
		lg.ID = int(Row[0]);
		lg.NAME = Row[1];
		userdata.emplace_back(lg);
	}
	mysql_free_result(Result);                      // ��� ����

	for (auto& data : userdata)
		if (data.NAME == name)
			return true;

	return false;
}


// ���̵� �ָ� DB���� �����ϴ� �Լ�
bool DB::DeleteDB(long long id)
{
	// DELETE ���� ���ڿ� ����
	std::string delete_query = "DELETE FROM user_data WHERE id = " + std::to_string(id);

	// ���� ����
	if (mysql_query(ConnPtr, delete_query.c_str()))
	{
		std::cerr << "Query execution error: " << mysql_error(ConnPtr) << "\n";
		return false;
	}

	// ������ ���� ���� ���� Ȯ���Ͽ� ���� ���� ���� �Ǵ�
	if (mysql_affected_rows(ConnPtr) > 0)
	{
		std::cout << "Record with ID " << id << " deleted successfully\n";
		return true;
	}
	else
	{
		std::cout << "No record found with ID " << id << "\n";
		return false;
	}
}