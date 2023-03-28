#include"Canvas.h"
#include"Image.h"
#include"Shape.h"
#include<vector>


void Canvas::addShape(Shape *newShape) {
	shapesList.push_back(newShape);
}

void Canvas::rasterizeTo(Image &picture) {
	for (int i = 0; i < shapesList.size(); i++) {
		shapesList[i]->draw(picture);
	}
}