#include "Record.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
Record * makeRecord(const char *name,
	const char *phone,
	const char *addr,
	const char *etc) {
	Record *record = (Record *)malloc(sizeof(Record));
	record->name = (char *)malloc(strlen(name) + 1);
	strcpy(record->name, name);
	record->phone = (char *)malloc(strlen(phone) + 1);
	strcpy(record->phone, phone);
	record->addr = (char *)malloc(strlen(phone) + 1);
	strcpy(record->addr, addr);
	if (etc && *etc) {
		record->etc = (char *)malloc(strlen(etc) + 1);
		strcpy(record->etc, etc);
	}
	else
		record->etc = NULL;
	return record;
}
Record *readRecord(void)
{
	char buffer[256];
	if (fgets(buffer, sizeof(buffer), stdin) != NULL) {
		char name[32], phone[16], addr[128], etc[128];
		memset(name, 0, sizeof(name));
		memset(phone, 0, sizeof(phone));
		memset(addr, 0, sizeof(addr));
		memset(etc, 0, sizeof(etc));
		if (sscanf(buffer, "%s %s %s %s",
			name, phone, addr, etc) > 0)
			return makeRecord(name, phone, addr, etc);
		return NULL;
	}
	return NULL;
}
void freeRecord(Record *record) {
	if (record->etc == NULL) {
		free(record->name);
		free(record->phone);
		free(record->addr);
		free(record);
	}
	else {
		free(record->name);
		free(record->phone);
		free(record->addr);
		free(record->etc);
		free(record);
	}
}
void printRecord(Record *record) {
	if (record->etc == NULL)
		printf("%s %s %s \n", record->name, record->phone, record->addr);
	else
		printf("%s %s %s %s \n", record->name, record->phone, record->addr, record->etc);
}