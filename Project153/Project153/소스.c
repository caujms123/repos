#include <stdio.h>

typedef struct {
	float radius;
	float center_x;
	float center_y;
} circle;

#define PI 3.14


void print(circle c) { // 반지름, 중심 좌표 출력
	printf("radius = %f , x of center = %f , y of center = %f\n", c.radius, c.center_x, c.center_x); 
}

float area(circle c) { // 원의 넓이 계산 후 그 값을 반환
	return PI * c.radius*c.radius;
}

int equal(circle c1, circle c2) { // 원의 반지름의 길이와 중심 좌표가 같으면 1을 반환 다르면 0을 반환
	if ((c1.radius == c2.radius) && (c1.center_x == c2.center_x) && (c1.center_y == c2.center_y))
		return 1;
	else
		return 0;
}

float compare(circle c1, circle c2) { // 원의 넓이의 차 계산하여 이를 반환 (c1-c2)
	return area(c1) - area(c2);
}

void resize(circle *c, float ratio) { // 원의 반지름의 길이를 조정
	c->radius *= ratio;
}


int main()
{
	circle c1;
	circle c2 = { 2.0, 0.0, 0.0 };
	circle c3 = { 1.0, 1.0, 1.0 };

	if (equal(c2, c3)) //두 원이 동일한 원인지 비교
		printf("two circles are equal. \n");
	else
		printf("two circles are different. \n");

	if (compare(c2, c3) > 0.0) // 두 원의 크기 비교
		printf("the first is larger than the second. \n");
	else if (compare(c2, c3) < 0.0)
		printf("the first is smaller than the second. \n");
	else
		printf("two are the same in area. \n");

	print(c3); //반지름, 중심좌표 출력
	resize(&c3, 2.0); // 반지름 길이 조정 (반지름 2배로 늘림) 
	print(c3);
}