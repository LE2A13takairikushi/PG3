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

		printf("[要素の操作]\n");
		printf("1.要素の一覧表示\n");
		printf("2.最後尾に要素の挿入\n");
		printf("3.最後尾の要素の削除\n");
		printf("\n---------------------\n");
		printf("操作を選択してください\n");
		while (operatorNum != 1 && operatorNum != 2 && operatorNum != 3)
		{
			scanf_s("%d", &operatorNum);
			if (operatorNum != 1 && operatorNum != 2 && operatorNum != 3)
			{
				printf("不正な値が入力されました\n");
				printf("もう一度入力してください\n");
			}
		}

		if (operatorNum == 1)
		{
			printf("[要素の一覧表示]\n");
			list.Index(&list.head);

			printf("\n---------------------\n");
			printf("0.初期画面に戻る\n");
			while (operatorNum != 0)
			{
				scanf_s("%d", &operatorNum);
				if (operatorNum != 0)
				{
					printf("不正な値が入力されました\n");
					printf("もう一度入力してください\n");
				}
			};
		}
		if (operatorNum == 2)
		{
			char buf[50];

			printf("[リスト要素の挿入]\n");
			printf("\n追加する要素の値を入力してください\n");

			scanf_s("%s", buf, 50);
			list.Create(&list.head,buf);
			printf("要素「%s」がリストの最後尾に挿入されました\n",buf);

			printf("\n---------------------\n");
			printf("0.初期画面に戻る\n");
			while (operatorNum != 0)
			{
				scanf_s("%d", &operatorNum);
				if (operatorNum != 0)
				{
					printf("不正な値が入力されました\n");
					printf("もう一度入力してください\n");
				}
			}
		}
		if (operatorNum == 3)
		{
			printf("[要素の削除]\n");

			list.Delete();

			printf("最後尾の要素を削除しました\n");
			printf("\n---------------------\n");
			printf("0.初期画面に戻る\n");
			while (operatorNum != 0)
			{
				scanf_s("%d", &operatorNum);
				if (operatorNum != 0)
				{
					printf("不正な値が入力されました\n");
					printf("もう一度入力してください\n");
				}
			}
		}
	}

	system("pause");

	return 0;
}