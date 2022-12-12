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
	printf("�̸��� �Է��ϼ���(32�� ���� �Էµ˴ϴ�): ");
	fgets(name, sizeof(name), stdin);
	if (name[0] == '\n') {
		printf("�̸��� �ݵ�� �ԷµǾ�� �մϴ�. �ٽ� �Է����ּ��� \n");
		goto aaa;
	}
	if (rec_count != 0) {
		record1 = record;
		for (int i = 0; i < rec_count; i++) {
			if (strcmp((*record1++)->name, name) == 0) {
				printf("������ �̸��� �̹� �ּҷϿ� �ֽ��ϴ�. �ٸ� �̸����� �����ϼ���\n");
				goto aaa;
			}
		}
	}
	bbb:
	printf("��ȭ��ȣ�� �Է��ϼ���(16�� �̳�):");
	fgets(phone, sizeof(phone), stdin);
	if (phone[0] == '\n') {
		printf("��ȭ��ȣ�� �ݵ�� �ԷµǾ�� �մϴ�. �ٽ� �Է����ּ��� \n");
		goto bbb;
	}
	printf("�̸����� �Է��Ͻ÷��� 1��, �ƴ϶�� 0�� �Է��� �ּ��� :");
	scanf("%d", &b);
	while (getchar() != '\n');
	if (b == 1) {
		printf("�̸����� �Է��ϼ���(128�� �̳�):");
		fgets(email, sizeof(email), stdin);
	}
	else {
		email[0] = '\0';
	}
	printf("��Ÿ ������ �Է��Ͻ÷��� 1��, �ƴ϶�� 0�� �Է��� �ּ��� :");
	scanf("%d", &a);
	while (getchar() != '\n');
	if (a == 1) {
		printf("��Ÿ ������ �Է��ϼ���(128�� �̳�):");
		fgets(etc, sizeof(etc), stdin);
	}
	else {
		etc[0] = '\0';
	}
	return makeRecord(name, phone, email, etc);
}
int Addrs_delete(Record ** record, int rec_count) {
	char name[33];
	printf("�����ϰ� ���� ����� �̸��� �Է��ϼ��� :");
	fgets(name, sizeof(name), stdin);
	for (int i = 0; i < rec_count; i++) {
		if (strcmp((*record)->name, name) == 0) {
			if (rec_count == 1) {
				(*record)->name[0] = '\0';
				(*record)->phone[0] = '\0';
				(*record)->email[0] = '\0';
				(*record)->etc[0] = '\0';
				printf("���������� ������ �Ϸ�Ǿ����ϴ�.\n");
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
			printf("���������� ������ �Ϸ�Ǿ����ϴ�.\n");
			rec_count--;
			return rec_count;
		}
		record++;
	}
	printf("�׷� ����� �����ϴ�.\n");
	return rec_count;
}
void print_list(Record ** record) {
	printf("�̸�: %s \n", (*record)->name);
	printf("��ȭ��ȣ: %s \n", (*record)->phone);
	printf("�̸���: %s \n", (*record)->email);
	printf("��Ÿ����: %s \n", (*record)->etc);
	printf("-----------------------------------\n");
}
void Addrs_search(Record ** record, int rec_count) {
	char name[33];
	printf("ã�� ���� ����� �̸��� �Է��ϼ��� :");
	fgets(name, sizeof(name), stdin);
	for (int i = 0; i < rec_count; i++)
		if (strcmp((*record++)->name, name) == 0) {
			record--;
			print_list(record);
			return;
		}
	printf("�׷� ����� �����ϴ�.\n");
}
void modify(Record ** record, int rec_count) {
	char name[33];
	Record **record1 = record;
	Record **record2 = record;
	int num;
	int check = 0;
	printf("�����ϰ� ���� ����� �̸��� �Է��ϼ��� :");
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
		printf("�׷� ����� �����ϴ�.\n");
		return;
	}
	while (check) {
		char name[33], phone[17], email[129], etc[129];
		print_info2();
		printf("�����ϰ� ���� �׸��� �����ϼ��� :");
		scanf("%d", &num);
		while (getchar() != '\n');
		switch (num) {
		case 1: aaa:
		printf("�̸��� �Է��ϼ���(32�� �̳�):");
		fgets(name, sizeof(name), stdin);
		record2 = record;
		for (int i = 0; i < rec_count; i++) {
			if (strcmp((*record2++)->name, name) == 0) {
				printf("������ �̸��� �̹� �ּҷϿ� �ֽ��ϴ�. �ٸ� �̸����� �����ϼ���\n");
				goto aaa;
			}
		}
		strcpy((*record1)->name, name);
		break;
		//�ϼ�
		case 2:
			printf("��ȭ��ȣ�� �Է��ϼ���:(16�� �̳�)");
			fgets(phone, sizeof(phone), stdin);
			strcpy((*record1)->phone, phone);
			break;
			//�ϼ�
		case 3:
			printf("�̸����� �Է��ϼ���(128�� �̳�):");
			fgets(email, sizeof(email), stdin);
			strcpy((*record1)->email, email);
			break;
			//�ϼ�
		case 4:
			printf("��Ÿ ������ �Է��ϼ���(128�� �̳�):");
			fgets(etc, sizeof(etc), stdin);
			strcpy((*record1)->etc, etc);
			break;
			//�ϼ�
		case 0: return;
		default:
			printf("-----------------------------------\n");
			printf("�׷� ����� �����ϴ�.\n");
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
	printf("1. ����ó �߰��ϱ�\n");
	printf("2. ����ó �����ϱ�\n");
	printf("3. ����ó ����Ʈ ����ϱ�\n");
	printf("4. ����ó �˻��ϱ�\n");
	printf("5. ����ó �����ϱ�\n");
	printf("6. ����ó �ʱ�ȭ\n");
	printf("0. ���α׷� ������\n");
	printf("-----------------------------------\n");
}
void print_info2() {
	printf("-----------------------------------\n");
	printf("1. �̸� �ٲٱ�\n");
	printf("2. ��ȭ��ȣ �ٲٱ�\n");
	printf("3. �̸��� �ٲٱ�\n");
	printf("4. ��Ÿ ���� �ٲٱ�\n");
	printf("0. ���� ������\n");
	printf("-----------------------------------\n");
}