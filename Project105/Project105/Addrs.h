
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
//연락처 추가하기
Record *Addrs_insert(Record **, int);
//연락처 삭제하기
int Addrs_delete(Record **, int);
//연락처 전체 출력하기
void print_list(Record **);
//연락처 찾기
void Addrs_search(Record **, int);
//연락처 수정하기
void modify(Record **, int);
// 연락처 초기화
void delete_all(Record **);
// 처음에 명령어 알려주기
void print_info();
// 수정하고 싶은 거 묻기
void print_info2();
// 비교함수
int Compare(const void **p1, const void **p2);