#include <iostream>
#include <windows.h>
using namespace std;

struct Point
{
	int x;
	int y;
};

struct Image
{
	Point top_left; // верхний левый угол
	int width; // ширина картинки
	int height; // высота картинки
};

// функция проверяет пересечение двух текстур (например героя и платформы)
bool intersect(Image& one, Image& two)
{
	int x = one.top_left.x;
	int y = one.top_left.y + one.height;

	if (x >= two.top_left.x && x <= two.top_left.x + two.width &&
		y >= two.top_left.y && y <= two.top_left.y + two.height)
		return true;

	return false;
}

void main()
{
	Image platform; // картинка с платформой
	Image gg; // картинка с главным героем


	// координаты верхнего левого угла картинки главного героя в точке 50-60
	gg.top_left.x = 60;
	gg.top_left.y = 50;
	gg.width = 140;
	gg.height = 200;

	platform.top_left.x = 50;
	platform.top_left.y = 250;
	platform.width = 170;
	platform.height = 60;

	if (intersect(gg, platform)) {
		cout << "INTERSECT!\n";
	}
	
}