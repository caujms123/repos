/*#include "Record.h"
#include<stdio.h>
int main(int argc, char *argv[])
{
	Record *records[128], *record;
	int rec_count = 0;
	while ((record = readRecord()) != NULL)
		records[rec_count++] = record;
	for (int i = 0; i < rec_count; i++)
		printRecord(records[i]);
	for (int i = 0; i < rec_count; i++)
		freeRecord(records[i]);
}*/
#include<stdio.h>
#include<stdlib.h>

typedef struct {
	int name;
}Record;
int compare(const void *p1, const void *p2) {
	Record *pp1 = (Record *)p1;
	Record *pp2 = (Record *)p2;
	return pp2->name  - pp1->name;
};


int main() {
	Record **records=(Record **)malloc(sizeof(Record *)*128);
	Record record[128];
	for (int i= 0; i < 128; i++) {
		record[i].name = i+1;
		records[i] = &record[i];
	}
	qsort(records, 128, sizeof(Record *), compare);
	Record ** rec = &records[0];
	for (int i = 0; i < 128; i++)
		printf("%d\n", (*rec++)->name);
}