#include "Image.h"

/*****************************************************
 * You _should_ change the functions in this file.   *
 * The following functions are provided so that      *
 * the code will compile, note however that the      *
 * program will not run before you have implemented  *
 * all the functions in this file.                   *
 *****************************************************/

Image::Image( int width, int height ) {
	this->width = width;
	this->height = height;

	data = new Pixel [height*width]{};
}

Image::~Image()  {
	delete[] data;
	data = nullptr;
	width = 0;
	height = 0;
}

int Image::getWidth() const {
	return width;
}
int Image::getHeight() const  {
	return height;
}

const Pixel * Image::getScanLine(int line) const  {
	return &data[width*line];
}
Pixel * Image::getScanLine(int line) {
	return &data[width*line];
}

Color Image::getPixelColor( int x, int y ) const {
	int index = y*width + x;
	return data[index];
}
void Image::setPixelColor( int x, int y, const Color &color ) {
	//int index = (y - 1)*width + (x - 1); // x-1 for å ta hensyn til at data[] sin index starter med 0. (y-1) for de linje nummer y IKKE har full bredde
	int index = y*width + x;
	data[index] = color;
}

void Image::fill( const Color &color ) {
	for (int i = 0; i < width*height; i++) {
		data[i] = color;
	}
}
