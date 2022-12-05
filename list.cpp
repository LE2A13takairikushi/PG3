#include "list.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

List::List()
{
	head.next = nullptr;
}

void List::Create(CELL *endCell,const char* buf)
{
	CELL* newCell;

	newCell = (CELL*)malloc(sizeof(CELL));

	strcpy_s(newCell->str, 50, buf);
	newCell->next = nullptr;

	while (endCell->next != nullptr)
	{
		endCell = endCell->next;
	}

	endCell->next = newCell;
	listSize++;
}

void List::Index(CELL* head)
{
	int no = 0;
	while (head->next != nullptr)
	{
		head = head->next;
		printf("%d : %s\n",no, head->str);
		no++;
	}
	printf("\n—v‘f” : %d\n", listSize);
}

void List::Delete()
{
	CELL* delCell = &head;
	CELL* oldDelCell = nullptr;

	while (delCell->next != nullptr)
	{
		oldDelCell = delCell;
		delCell = delCell->next;
	}

	if (oldDelCell != nullptr)
	{
		oldDelCell->next = nullptr;
	}
	if (listSize > 0)
	{
		free(delCell);
		delCell = nullptr;

		listSize--;
	}
}