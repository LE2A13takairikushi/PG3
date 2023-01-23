﻿#include <stdio.h>
#include <list>
#include <vector>
#include <functional>

using namespace std;


//山手線駅名リスト
list<const char*> yamanoteLine{
	"Tokyo",
	"Kanda",
	"Akihabara",
	"Okachimachi",
	"Ueno",
	"Uguisudani",
	"Nippori",
	"Tabata",
	"Komagome",
	"Sugamo",
	"Otsuka",
	"Ikebukuro",
	"Mejiro",
	"Takadanobaba",
	"Shin-Okubo",
	"Shinjuku",
	"Yoyogi",
	"Harajuku",
	"Shibuya",
	"Ebisu",
	"Meguro",
	"Gotanda",
	"Osaki",
	"Shinagawa",
	"Tamachi",
	"Hamamatsucho",
	"Shimbashi",
	"Yurakucho"
};

//山手線駅名リストをprintfする関数
void StationNamePrint(const char* string)
{
	printf("%s", string);
	for (const char* stationname : yamanoteLine)
	{
		printf("%s\n", stationname);
	}
}

int main()
{
	StationNamePrint("\n1970年の駅一覧\n");

	//日暮里の後に西日暮里を追加
	for (list<const char*>::iterator itr = yamanoteLine.begin(); itr != yamanoteLine.end(); ++itr)
	{
		if (*itr == "Nippori")
		{
			++itr;
			itr = yamanoteLine.insert(itr, "Nishi-Nippori");
			break;
		}
	}

	StationNamePrint("\n2019年の駅一覧\n");

	//品川の後に高輪ゲートウェイを追加
	for (list<const char*>::iterator itr = yamanoteLine.begin(); itr != yamanoteLine.end(); ++itr)
	{
		if (*itr == "Shinagawa")
		{
			++itr;
			itr = yamanoteLine.insert(itr, "Takanawa-Gateway");
			break;
		}
	}

	StationNamePrint("\n2022年の駅一覧\n");

	yamanoteLine.clear();

	return 0;
}