/*
1.�ּ� �׸���� �̸�, ��ȭ��ȣ�� �ݵ�� �����Ͽ��� �ϸ� �ʿ信 ���� �̸����̳� ��Ÿ ������ ������ �� �ִ�.
2.�ּҷ��� ũ��� �̸� �� �� ����.
3.���ο� �ּ� �׸��� �߰��ϰų� �����ϴ� �󵵼��� ������, �˻��� ������ ����ϰ� �߻��Ѵ�.
4.������ �̸��� �׸���� ����� ���� �ְ� ������� ���� ���� �ִ�. (���û���)
5.�ּҷ��� ����� ���� �̸� ������ ���ĵ� ������ ����Ͽ��� �Ѵ�.

C ���� �ۼ��� �ҽ��ڵ�(��)�� �Բ�, �� ���α׷��� � ������� �տ��� ������ �䱸������ �����ϴ���
A4 1-������ ���ܷ� �����ϴ� ������ �Բ� ������ ��.
*/

# include <stdio.h>
# include "Addrs.h"
# include <stdlib.h> 
# include <string.h>

int main() {
	int num;
	int k = 1;
	Record ** records = (Record **)malloc(sizeof(Record *) * 100), *record;
	int rec_count = 0;
	while (1) {
		print_info();
		printf("����� �Է��ϼ���. : ");
		scanf("%d", &num);
		while (getchar() != '\n');
		switch (num) {
		case 1: if (rec_count >= 100 * k) {
			k++;
			records = (Record **)realloc(records, sizeof(Record *) * 100 * k);
		}
				if ((record = Addrs_insert(&records[0], rec_count)) != NULL) {
					records[rec_count++] = record;
				}
				break;	//�ϼ�
		case 2: rec_count = Addrs_delete(&records[0], rec_count);
			break;	//�ϼ�
		case 3: qsort(records, rec_count, sizeof(Record *), Compare);
			for (int i = 0; i < rec_count; i++) {
				print_list(&records[i]);
			}
			break;	//�ϼ�
		case 4:
			Addrs_search(&records[0], rec_count); break;	//�ϼ�
		case 5: modify(&records[0], rec_count); break;	    //�ϼ�
		case 6: for (int i = 0; i < rec_count; i++)
			delete_all(&records[i]);
			rec_count = 0;
			printf("��� ����ó�� �����Ǿ����ϴ�.\n");
			break;     //�ϼ�
		case 0: printf("���α׷��� �����մϴ�. \n"); return 0;
		default: {
			printf("-----------------------------------\n");
			printf("�׷� ����� �����ϴ�.\n");
			break;
		}
		}
	}
}