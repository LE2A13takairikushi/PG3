#include <stdio.h>
#include <list>
#include <vector>
#include <functional>

using namespace std;

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

	for (list<const char*>::iterator itr = yamanoteLine.begin(); itr != yamanoteLine.end(); ++itr)
	{
		if (*itr == "Nippori")
		{
			++itr;
			itr = yamanoteLine.insert(itr, "Nishi-Nippori");
		}
	}

	StationNamePrint("\n2019年の駅一覧\n");

	for (list<const char*>::iterator itr = yamanoteLine.begin(); itr != yamanoteLine.end(); ++itr)
	{
		if (*itr == "Shinagawa")
		{
			++itr;
			itr = yamanoteLine.insert(itr, "Takanawa-Gateway");
		}
	}

	StationNamePrint("\n2022年の駅一覧\n");

	yamanoteLine.clear();

	return 0;
}