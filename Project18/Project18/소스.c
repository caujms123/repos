// °è»ê±â ¸¸µé±â
# include<stdio.h>
int main(void) {
	int a = 0;
	int b, c;
	printf("µÎ ¼ö¸¦ ÀÔ·ÂÇÏ½Ã¿À");
	scanf("%d %d", &b, &c);
	printf("1: µ¡¼À 2: »¬¼À 3: °ö¼À 4: ³ª´°¼À");
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

