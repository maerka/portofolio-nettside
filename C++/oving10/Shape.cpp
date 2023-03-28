#include "Shape.h"
#include "Image.h"


// ***** SHAPE *****
Shape::Shape(Color color) {
	this->color = color;
}

Color Shape::getColor() {
	return color;
}


// ***** LINE *****
Line::Line(int x0, int x1, int y0, int y1, Color color) :Shape(color) {
	this->x0 = x0;
	this->x1 = x1;
	this->y0 = y0;
	this->y1 = y1;
}

void Line::draw(Image & figure) {

	double teller = static_cast<double>(y1 - y0);

	figure.setPixelColor(10, 1, getColor());

	if (teller / (x1 - x0) > 1){
		int y;
		for (int x = 0; x < x1; x++) {
			y = (static_cast<double>(y1 - y0) / (x1 - x0))*(x - x0) + y0;
			figure.setPixelColor(x, y, getColor());
		}
	}
	else {
		int x;
		for (int y = 0; y < y1; y++) {
			x = (static_cast<double>(x1 - x0) / (y1 - y0))*(y - y0) + x0;
			figure.setPixelColor(x, y, getColor());
		}
	}

}


// ***** RECTANGLE *****
Rectangle::Rectangle(int x0, int x1, int y0, int y1, Color color) :Shape(color) {
	this->x0 = x0;
	this->x1 = x1;
	this->y0 = y0;
	this->y1 = y1;
}

void Rectangle::draw(Image & figure) {
	for (int x = x0; x < x1; x++) {
		for (int y = y0; y < y1; y++) {
			figure.setPixelColor(x, y, getColor());
		}
	}
}