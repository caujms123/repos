#include<stdio.h>
struct marks {
	int sub1;            //국어
	int sub2;            //수학
	int sub3;            //영어
	int total;           // 성적 합계
};
void main() {
	int i;
	struct marks student[3] = { {45,67,81,0},
							   {75,53,69,0},
							   {57,36,71,0} };	// 학생 3명
	struct marks total = {student[0].sub1 + student[1].sub1 + student[2].sub1,
						  student[0].sub2 + student[1].sub2 + student[2].sub2,		
					      student[0].sub3 + student[1].sub3 + student[2].sub3,0};
	for (i = 0; i < 3; i++) 
		student[i].total= student[i].sub1 + student[i].sub2 + student[i].sub3;
	printf("학생별 합계 \n");
	for (i = 0; i < 3; i++)
		printf("student%d : %d \n",i,student[i].total);
	printf("과목별 합계 \n");
	printf("sub1 : %d \nsub2 : %d \nsub3 : %d \n",total.sub1, total.sub2, total.sub3);
}