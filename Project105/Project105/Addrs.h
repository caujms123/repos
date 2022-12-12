
typedef struct {
	char *name;
	char *phone;
	char *email;
	char *etc;
} Record;

Record *makeRecord(const char *name,
	const char *phone,
	const char *email,
	const char *etc);
//����ó �߰��ϱ�
Record *Addrs_insert(Record **, int);
//����ó �����ϱ�
int Addrs_delete(Record **, int);
//����ó ��ü ����ϱ�
void print_list(Record **);
//����ó ã��
void Addrs_search(Record **, int);
//����ó �����ϱ�
void modify(Record **, int);
// ����ó �ʱ�ȭ
void delete_all(Record **);
// ó���� ��ɾ� �˷��ֱ�
void print_info();
// �����ϰ� ���� �� ����
void print_info2();
// ���Լ�
int Compare(const void **p1, const void **p2);