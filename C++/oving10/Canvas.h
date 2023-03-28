#pragma once
#include"Image.h"
#include"Shape.h"
#include<vector>

class Canvas {
	std::vector<Shape*> shapesList;
public:
	Canvas() {};
	void addShape(Shape *newShape);
	void rasterizeTo(Image &picture);
};