#pragma once
#include "Image.h"

class Shape {
	Color color;
public:
	Shape(Color color);
	Color getColor();

	virtual void draw(Image & figure)=0;
};



class Line : public Shape {
	int x0, x1, y0, y1;
public:
	Line(int x0, int x1, int y0, int y1, Color color);
	void draw(Image & figure);
};




class Rectangle : public Shape {
	int x0, x1, y0, y1;
public:
	Rectangle(int x0, int x1, int y0, int y1, Color color);
	void draw(Image & figure);
};
