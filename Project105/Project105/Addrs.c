#include "Addrs.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int Compare(const void ** p1, const void ** p2) {
	Record ** pp1 = (Record **)p1;
	Record ** pp2 = (Record **)p2;
	return strcmp((*pp1)->name, (*pp2)->name);
};
Record *Addrs_insert(Record **record, int rec_count) {
	Record ** record1 = record;
	char name[33], phone[17], email[129], etc[129];
	int a = 0;
	int b = 0;
aaa:
	printf("이름을 입력하세요(32자 까지 입력됩니다): ");
	fgets(name, sizeof(name), stdin);
	if (name[0] == '\n') {
		printf("이름은 반드시 입력되어야 합니다. 다시 입력해주세요 \n");
		goto aaa;
	}
	if (rec_count != 0) {
		record1 = record;
		for (int i = 0; i < rec_count; i++) {
			if (strcmp((*record1++)->name, name) == 0) {
				printf("동일한 이름이 이미 주소록에 있습니다. 다른 이름으로 저장하세요\n");
				goto aaa;
			}
		}
	}
	bbb:
	printf("전화번호를 입력하세요(16자 이내):");
	fgets(phone, sizeof(phone), stdin);
	if (phone[0] == '\n') {
		printf("전화번호는 반드시 입력되어야 합니다. 다시 입력해주세요 \n");
		goto bbb;
	}
	printf("이메일을 입력하시려면 1을, 아니라면 0을 입력해 주세요 :");
	scanf("%d", &b);
	while (getchar() != '\n');
	if (b == 1) {
		printf("이메일을 입력하세요(128자 이내):");
		fgets(email, sizeof(email), stdin);
	}
	else {
		email[0] = '\0';
	}
	printf("기타 내용을 입력하시려면 1을, 아니라면 0을 입력해 주세요 :");
	scanf("%d", &a);
	while (getchar() != '\n');
	if (a == 1) {
		printf("기타 내용을 입력하세요(128자 이내):");
		fgets(etc, sizeof(etc), stdin);
	}
	else {
		etc[0] = '\0';
	}
	return makeRecord(name, phone, email, etc);
}
int Addrs_delete(Record ** record, int rec_count) {
	char name[33];
	printf("삭제하고 싶은 사람의 이름을 입력하세요 :");
	fgets(name, sizeof(name), stdin);
	for (int i = 0; i < rec_count; i++) {
		if (strcmp((*record)->name, name) == 0) {
			if (rec_count == 1) {
				(*record)->name[0] = '\0';
				(*record)->phone[0] = '\0';
				(*record)->email[0] = '\0';
				(*record)->etc[0] = '\0';
				printf("성공적으로 삭제가 완료되었습니다.\n");
				rec_count--;
				return rec_count;
			}
			for (int j = i; j < rec_count-1; j++) {
				strcpy((*record)->name,(*(record+1))->name);
				strcpy((*record)->phone, (*(record+1))->phone);
				strcpy((*record)->email, (*(record+1))->email);
				strcpy((*record)->etc, (*(record+1))->etc);
				record++;
			}
			(*record)->name[0] = '\0';
			(*record)->phone[0] = '\0';
			(*record)->email[0] = '\0';
			(*record)->etc[0] = '\0';
			printf("성공적으로 삭제가 완료되었습니다.\n");
			rec_count--;
			return rec_count;
		}
		record++;
	}
	printf("그런 사람은 없습니다.\n");
	return rec_count;
}
void print_list(Record ** record) {
	printf("이름: %s \n", (*record)->name);
	printf("전화번호: %s \n", (*record)->phone);
	printf("이메일: %s \n", (*record)->email);
	printf("기타사항: %s \n", (*record)->etc);
	printf("-----------------------------------\n");
}
void Addrs_search(Record ** record, int rec_count) {
	char name[33];
	printf("찾고 싶은 사람의 이름을 입력하세요 :");
	fgets(name, sizeof(name), stdin);
	for (int i = 0; i < rec_count; i++)
		if (strcmp((*record++)->name, name) == 0) {
			record--;
			print_list(record);
			return;
		}
	printf("그런 사람은 없습니다.\n");
}
void modify(Record ** record, int rec_count) {
	char name[33];
	Record **record1 = record;
	Record **record2 = record;
	int num;
	int check = 0;
	printf("수정하고 싶은 사람의 이름을 입력하세요 :");
	fgets(name, sizeof(name), stdin);
	for (int i = 0; i < rec_count; i++) {
		check = 1;
		if (strcmp((*record1++)->name, name) == 0) {
			record1--;
			check = 1;
			print_list(record1);
		}
	}
	if (check == 0) {
		printf("그런 사람은 없습니다.\n");
		return;
	}
	while (check) {
		char name[33], phone[17], email[129], etc[129];
		print_info2();
		printf("수정하고 싶은 항목을 선택하세요 :");
		scanf("%d", &num);
		while (getchar() != '\n');
		switch (num) {
		case 1: aaa:
		printf("이름을 입력하세요(32자 이내):");
		fgets(name, sizeof(name), stdin);
		record2 = record;
		for (int i = 0; i < rec_count; i++) {
			if (strcmp((*record2++)->name, name) == 0) {
				printf("동일한 이름이 이미 주소록에 있습니다. 다른 이름으로 저장하세요\n");
				goto aaa;
			}
		}
		strcpy((*record1)->name, name);
		break;
		//완성
		case 2:
			printf("전화번호를 입력하세요:(16자 이내)");
			fgets(phone, sizeof(phone), stdin);
			strcpy((*record1)->phone, phone);
			break;
			//완성
		case 3:
			printf("이메일을 입력하세요(128자 이내):");
			fgets(email, sizeof(email), stdin);
			strcpy((*record1)->email, email);
			break;
			//완성
		case 4:
			printf("기타 내용을 입력하세요(128자 이내):");
			fgets(etc, sizeof(etc), stdin);
			strcpy((*record1)->etc, etc);
			break;
			//완성
		case 0: return;
		default:
			printf("-----------------------------------\n");
			printf("그런 명령은 없습니다.\n");
			break;
		}
	}
}
void delete_all(Record ** record) {
	if ((*record)->etc == NULL) {
		free((*record)->name);
		free((*record)->phone);
		free((*record)->email);
		free((*record));
	}
	else {
		free((*record)->name);
		free((*record)->phone);
		free((*record)->email);
		free((*record)->etc);
		free((*record));
	}
}
Record *makeRecord(const char *name,
	const char *phone,
	const char *email,
	const char *etc) {
	Record *record = (Record *)malloc(sizeof(Record));
	record->name = (char *)malloc(strlen(name) + 1);
	strcpy(record->name, name);
	record->phone = (char *)malloc(strlen(phone) + 1);
	strcpy(record->phone, phone);
	record->email = (char *)malloc(strlen(phone) + 1);
	strcpy(record->email, email);
	record->etc = (char *)malloc(strlen(etc) + 1);
	strcpy(record->etc, etc);
	return record;
}
void print_info() {
	printf("-----------------------------------\n");
	printf("1. 연락처 추가하기\n");
	printf("2. 연락처 삭제하기\n");
	printf("3. 연락처 리스트 출력하기\n");
	printf("4. 연락처 검색하기\n");
	printf("5. 연락처 수정하기\n");
	printf("6. 연락처 초기화\n");
	printf("0. 프로그램 끝내기\n");
	printf("-----------------------------------\n");
}
void print_info2() {
	printf("-----------------------------------\n");
	printf("1. 이름 바꾸기\n");
	printf("2. 전화번호 바꾸기\n");
	printf("3. 이메일 바꾸기\n");
	printf("4. 기타 내용 바꾸기\n");
	printf("0. 수정 끝내기\n");
	printf("-----------------------------------\n");
}