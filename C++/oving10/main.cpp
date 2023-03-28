#include <iostream>
#include "Image.h"
#include "Matrix.h"
#include "Vector.h"
#include "Shape.h"
#include "Canvas.h"
//inkluder andre headerfiler du lager
using namespace std;

int main(){
//Skriv kode her
	// ***** OPPGAVE 2 *****
	Pixel testColor1 = Color(193, 2, 3);
	Pixel testColor2 = Color(0, 0, 0);
	Image picture = Image(105, 105);
	picture.fill(testColor1);
	picture.setPixelColor(3, 1,testColor2);
	saveImage(picture,"testPicture");

	// ***** OPPGAVE 3/4 *****
	Line line1 = Line(0, 100, 0, 50, testColor2);
	Line line2 = Line(0, 50, 0, 100, testColor2);
	line1.draw(picture);
	line2.draw(picture);
	saveImage(picture, "testPicture1");

	// ***** OPPGAVE 5 *****
	Rectangle square = Rectangle(70, 99, 20, 50, testColor2);
	square.draw(picture);
	saveImage(picture, "testPicture2");


	// ***** OPPGAVE 6 *****
	Pixel testColor3 = Color(250, 2, 200);
	Image picture3 = Image(105, 105);
	picture3.fill(testColor3);


	Canvas caravelle = Canvas();
	caravelle.addShape(&line1);
	caravelle.addShape(&line2);
	caravelle.addShape(&square);
	caravelle.rasterizeTo(picture3);
	saveImage(picture3,"testPicture3");

	// ***** OPPGAVE 1 *****
	Matrix matrix1 = Matrix(4);
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			matrix1.set(i, j, 5);
		}
	}

	Vector vector1 = Vector(4);
	vector1.set(0, 3.4);
	vector1.set(3, 0);
	Vector vector2 = Vector(4);
	vector2.set(0, 7.5);
	vector2.set(3, 4);

	for (int i = 0; i < 5; i++) {
		std::cout << vector2.get(i) << std::endl;
	}

	std::cout << matrix1.getRows() << std::endl;
	//std::cout << vector1.Matrix::getColumns() << std::endl;

	std::cout << vector1.dot(matrix1) << std::endl;
	std::cout << "Etter multiplisering" << std::endl;

	for (int i = 0; i < 4; i++) {
		std::cout << vector1.get(i) << std::endl;
	}

	std::cout << vector2.lengthSquared() << std::endl;
	std::cout << vector2.length() << std::endl;
	
	

return 0;
}
