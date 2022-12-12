# include<stdio.h>
# include<stdlib.h>
# include<string.h>
char w[][10] = {
	"Write",
	"a",
	"test",
	"prigram",
	"of",
	"qsort",
	"for",
	"sorting",
	"this",
	"sentence",
	"in",
	"descending",
	"order"
};
# define NWORDS (sizeof(w)/sizeof(w[0]))
int cmpfunc(const void *a, const void *b) {
	return strcmp ( *(char**)a , *(char **)b ) ;
}
int main() {
	qsort(w, NWORDS, sizeof(w[0]), cmpfunc);
	for(int n=0;n<NWORDS;n++)
		printf("%s \n",w[n]);
}