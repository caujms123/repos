// ���� �����
# include<stdio.h>
int main(void) {
	int a = 0;
	int b, c;
	printf("�� ���� �Է��Ͻÿ�");
	scanf("%d %d", &b, &c);
	printf("1: ���� 2: ���� 3: ���� 4: ������");
	scanf("%d", &a);
	switch(a){
		case 1: printf("%d + %d = %d", b, c, b+c);
			break;
		case 2 : printf("%d - %d = %d", b, c, b-c);
			break;
		case 3 : printf("%d * %d = %d", b, c, b*c);
			break;
		case 4 : printf("%d / %d = %d", b, c, b/c);
			break;
	}
	
}

