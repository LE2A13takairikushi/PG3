#include <stdio.h>
#include "list.h"
#include <stdlib.h>

int main()
{
	List list;
	int operatorNum = 0;

	list.Create(&list.head, "banana");
	list.Create(&list.head, "apple");
	list.Create(&list.head, "orange");

	while (true)
	{
		operatorNum = 0;

		printf("[�v�f�̑���]\n");
		printf("1.�v�f�̈ꗗ�\��\n");
		printf("2.�Ō���ɗv�f�̑}��\n");
		printf("3.�Ō���̗v�f�̍폜\n");
		printf("\n---------------------\n");
		printf("�����I�����Ă�������\n");
		while (operatorNum != 1 && operatorNum != 2 && operatorNum != 3)
		{
			scanf_s("%d", &operatorNum);
			if (operatorNum != 1 && operatorNum != 2 && operatorNum != 3)
			{
				printf("�s���Ȓl�����͂���܂���\n");
				printf("������x���͂��Ă�������\n");
			}
		}

		if (operatorNum == 1)
		{
			printf("[�v�f�̈ꗗ�\��]\n");
			list.Index(&list.head);

			printf("\n---------------------\n");
			printf("0.������ʂɖ߂�\n");
			while (operatorNum != 0)
			{
				scanf_s("%d", &operatorNum);
				if (operatorNum != 0)
				{
					printf("�s���Ȓl�����͂���܂���\n");
					printf("������x���͂��Ă�������\n");
				}
			};
		}
		if (operatorNum == 2)
		{
			char buf[50];

			printf("[���X�g�v�f�̑}��]\n");
			printf("\n�ǉ�����v�f�̒l����͂��Ă�������\n");

			scanf_s("%s", buf, 50);
			list.Create(&list.head,buf);
			printf("�v�f�u%s�v�����X�g�̍Ō���ɑ}������܂���\n",buf);

			printf("\n---------------------\n");
			printf("0.������ʂɖ߂�\n");
			while (operatorNum != 0)
			{
				scanf_s("%d", &operatorNum);
				if (operatorNum != 0)
				{
					printf("�s���Ȓl�����͂���܂���\n");
					printf("������x���͂��Ă�������\n");
				}
			}
		}
		if (operatorNum == 3)
		{
			printf("[�v�f�̍폜]\n");

			list.Delete();

			printf("�Ō���̗v�f���폜���܂���\n");
			printf("\n---------------------\n");
			printf("0.������ʂɖ߂�\n");
			while (operatorNum != 0)
			{
				scanf_s("%d", &operatorNum);
				if (operatorNum != 0)
				{
					printf("�s���Ȓl�����͂���܂���\n");
					printf("������x���͂��Ă�������\n");
				}
			}
		}
	}

	system("pause");

	return 0;
}