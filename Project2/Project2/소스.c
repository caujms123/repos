#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main(void) {
	int x,y;
	scanf("%d%d",&x,&y);

		if (x==1||x==10) {
			if (y % 7 == 0) {printf("SUN");}
			else if (y % 7 == 1) { printf("MON"); }
			else if (y % 7 == 2) { printf("TUE"); }
			else if (y % 7 == 3) { printf("WED"); }
			else if (y % 7 == 4) { printf("THU"); }
			else if (y % 7 == 5) { printf("FRI"); }
			else if (y % 7 == 6) { printf("SAT"); }
			}
		else if (x==5){ 
			if (y % 7 == 6) { printf("SUN"); }
			else if (y % 7 == 0) { printf("MON"); }
			else if (y % 7 == 1) { printf("TUE"); }
			else if (y % 7 == 2) { printf("WED"); }
			else if (y % 7 == 3) { printf("THU"); }
			else if (y % 7 == 4) { printf("FRI"); }
			else if (y % 7 == 5) { printf("SAT"); }
		}
		else if (x==8 ) {
			if (y % 7 == 5) { printf("SUN"); }
			else if (y % 7 == 6) { printf("MON"); }
			else if (y % 7 == 0) { printf("TUE"); }
			else if (y % 7 == 1) { printf("WED"); }
			else if (y % 7 == 2) { printf("THU"); }
			else if (y % 7 == 3) { printf("FRI"); }
			else if (y % 7 == 4) { printf("SAT"); }
		}
		else if (x==2||x==3||x==11) {
			if (y % 7 ==4) { printf("SUN"); }
			else if (y % 7 == 5) { printf("MON"); }
			else if (y % 7 == 6) { printf("TUE"); }
			else if (y % 7 == 0) { printf("WED"); }
			else if (y % 7 == 1) { printf("THU"); }
			else if (y % 7 == 2) { printf("FRI"); }
			else if (y % 7 == 3) { printf("SAT"); }
		}
		else if (x==4||x == 7) {
			if (y % 7 == 1) { printf("SUN"); }
			else if (y % 7 == 2) { printf("MON"); }
			else if (y % 7 == 3) { printf("TUE"); }
			else if (y % 7 == 4) { printf("WED"); }
			else if (y % 7 == 5) { printf("THU"); }
			else if (y % 7 == 6) { printf("FRI"); }
			else if (y % 7 == 0) { printf("SAT"); }
		}
		else if (x == 6) {
			if (y % 7 == 3) { printf("SUN"); }
			else if (y % 7 == 4) { printf("MON"); }
			else if (y % 7 == 5) { printf("TUE"); }
			else if (y % 7 == 6) { printf("WED"); }
			else if (y % 7 == 0) { printf("THU"); }
			else if (y % 7 == 1) { printf("FRI"); }
			else if (y % 7 == 2) { printf("SAT"); }
		}
		else if (x == 9||x==12) {
			if (y % 7 == 2) { printf("SUN"); }
			else if (y % 7 == 3) { printf("MON"); }
			else if (y % 7 == 4) { printf("TUE"); }
			else if (y % 7 == 5) { printf("WED"); }
			else if (y % 7 == 6) { printf("THU"); }
			else if (y % 7 == 0) { printf("FRI"); }
			else if (y % 7 == 1) { printf("SAT"); }
		}
	return 0;
}


//���� �������Է¹޾� 90 ~100���� A, 80 ~89���� B, 70 ~79���� C, 60 ~69���� D, ������ ������ F�� ����ϴ� ���α׷��� �ۼ��Ͻÿ�.