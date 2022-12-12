/*
1.주소 항목들은 이름, 전화번호를 반드시 포함하여야 하며 필요에 따라 이메일이나 기타 내용을 포함할 수 있다.
2.주소록의 크기는 미리 알 수 없다.
3.새로운 주소 항목을 추가하거나 삭제하는 빈도수는 적으며, 검색이 월등히 빈번하게 발생한다.
4.동일한 이름의 항목들은 허락할 수도 있고 허락하지 않을 수도 있다. (선택사항)
5.주소록을 출력할 때는 이름 순으로 정렬된 순서로 출력하여야 한다.

C 언어로 작성된 소스코드(들)와 함께, 이 프로그램이 어떤 방법으로 앞에서 설명한 요구사항을 만족하는지
A4 1-페이지 내외로 설명하는 문서와 함께 제출할 것.
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
		printf("명령을 입력하세요. : ");
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
				break;	//완성
		case 2: rec_count = Addrs_delete(&records[0], rec_count);
			break;	//완성
		case 3: qsort(records, rec_count, sizeof(Record *), Compare);
			for (int i = 0; i < rec_count; i++) {
				print_list(&records[i]);
			}
			break;	//완성
		case 4:
			Addrs_search(&records[0], rec_count); break;	//완성
		case 5: modify(&records[0], rec_count); break;	    //완성
		case 6: for (int i = 0; i < rec_count; i++)
			delete_all(&records[i]);
			rec_count = 0;
			printf("모든 연락처가 삭제되었습니다.\n");
			break;     //완성
		case 0: printf("프로그램을 종료합니다. \n"); return 0;
		default: {
			printf("-----------------------------------\n");
			printf("그런 명령은 없습니다.\n");
			break;
		}
		}
	}
}