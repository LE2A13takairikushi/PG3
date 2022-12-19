#include <stdio.h>
#include <stdlib.h>

const float PI = 3.141592;

class IShape
{
	virtual void draw() = 0;
};

class Circle : public IShape
{
public:
	//半径
	float radius;

	//変数の初期化
	void Initialize(float radius);
	//面積を算出
	float size();
	//変数の状態を表示
	void draw();
};

void Circle::Initialize(float radius)
{
	this->radius = radius;
}

float Circle::size()
{
	return radius * radius * PI;
}

void Circle::draw()
{
	printf("円の半径 %f\n", radius);
}

class Rectangle
{
public:
	//横の長さ
	float width;
	//縦の長さ
	float height;
	
	//変数の初期化
	void Initialize(float width, float height);
	//面積を算出
	float size();
	//変数の状態を表示
	void draw();
};

void Rectangle::Initialize(float width, float height)
{
	this->width = width;
	this->height = height;
}

float Rectangle::size()
{
	return width * height;
}

void Rectangle::draw()
{
	printf("縦の長さ %f\n", width);
	printf("縦の長さ %f\n", height);
}

int main()
{
	Circle circle;
	Rectangle rectangle;

	circle.Initialize(10);
	rectangle.Initialize(20, 30);

	circle.draw();
	rectangle.draw();

	printf("円の面積 %f\n", circle.size());
	printf("矩形の面積 %f\n", rectangle.size());

	system("pause");

	return 0;
}
