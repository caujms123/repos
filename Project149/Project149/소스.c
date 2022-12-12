#include<stdio.h>
#include<math.h>
int main() {
	int n;
	scanf("%d", &n);
	if (n > 1022) {
		printf("-1");
		return 0;
	}
	int count = 0;
	long long a;
	long long k;
	long long i = 0;
	while (1) {
		long long s = i;
		long long k = 0;
		//printf("%d %lld %lld\n",count,n,i);
		if (count > n) {
			printf("%lld",i-1);
			return 0;
		}
		else if (i >= 1000000000 && i < 10000000000) {
			k = 1000000000;
			while (1) {
				a = s / k;
				s %= k;
				k /= 10;
				if (a <= s / k) {
					i += k * 10;
					i = i - i % (k * 10);
					break;
				}
				if (k == 1) {
					count++;
					i++;
					break;
				}
			}
		}
		else if (i >= 100000000 && i < 1000000000) {
			k = 100000000;
			while (1) {
				a = s / k;
				s %= k;
				k /= 10;
				if (a <= s / k) {
					i += k * 10;
					i = i - i % (k * 10);
					break;
				}
				if (k == 1) {
					count++;
					i++;
					break;
				}
			}
		}
		else if (i >= 10000000 && i < 100000000) {
			k = 10000000;
			while (1) {
				a = s / k;
				s %= k;
				k /= 10;
				if (a <= s / k) {
					i += k * 10;
					i = i - i % (k * 10);
					break;
				}
				if (k == 1) {
					count++;
					i++;
					break;
				}
			}
		}
		else if (i >= 1000000 && i < 10000000) {
			k = 1000000;
			while (1) {
				a = s / k;
				s %= k;
				k /= 10;
				if (a <= s / k) {
					i += k * 10;
					i = i - i % (k * 10);
					break;
				}
				if (k == 1) {
					count++;
					i++;
					break;
				}
			}
		}
		else if (i>= 100000 &&i < 1000000) {
			k = 100000;
			while (1) {
				a = s / k;
				s %= k;
				k /= 10;
				if (a <= s / k) {
					i += k * 10;
					i = i - i % (k * 10);
					break;
				}
				if (k==1) {
					count++;
					i++;
					break;
				}
			}
		}
		else if (i >= 10000 && i < 100000) {
			k = 10000;
			while (1) {
				a = s / k;
				s %= k;
				k /= 10;
				if (a <= s / k) {
					i += k * 10;
					i = i - i % (k * 10);
					break;
				}
				if (k == 1) {
					count++;
					i++;
					break;
				}
			}
		}
		else if (i >= 1000 && i < 10000) {
			k = 1000;
			while (1) {
				a = s / k;
				s %= k;
				k /= 10;
				if (a <= s / k) {
					i += k * 10;
					i = i - i % (k * 10);
					break;
				}
				if (k == 1) {
					count++;
					i++;
					break;
				}
			}
		}
		else if (i >= 100 && i < 1000) {
			k = 100;
			while (1) {
				long long a = s / k;
				s %= k;
				k /= 10;
				if (a <= s / k) {
					i += k * 10;
					i = i - i % (k * 10);
					break;
				}
				if (k == 1) {
					count++;
					i++;
					break;
				}
			}
		}
		else if (i >= 10 && i < 100) {
			k = 10;
			while (1) {
				a = s / k;
				s %= k;
				k /= 10;
				//printf("zz%d %d \n", a, s / k);
				if (a <= s / k) {
					i += k * 10;
					i = i - i % (k * 10);
					break;
				}
				if (k == 1) {
					count++;
					i++;
					break;
				}
			}
		}
		else {
			count++;
			i++;
		}
	}
}