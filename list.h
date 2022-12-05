#pragma once

typedef struct cell
{
	char str[50];
	struct cell* next;
}CELL;

class List
{
public:
	CELL head;
	int listSize = 0;

	List();
	void Create(CELL* endCell, const char* buf);
	void Index(CELL* head);
	void Delete();
};

