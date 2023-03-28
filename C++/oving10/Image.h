#pragma once

/////////////////////////////////////////////////////////////////////
//  NB! Include this file and the file ImageIO.cpp in your project.//
//  You should *NOT* do any changes to this file.                  //
//                                                                 //
//  Disclaimer: Provided as is etc. etc. No rights reserved.       //
/////////////////////////////////////////////////////////////////////

#include <string>

// Color struct, used to set and retrieve colors from the image.
struct Color {
	Color( unsigned char r, unsigned char g, unsigned char b ) : red( r ), green( g ), blue( b ) {
		/*Empty*/
	}
	Color() : red( 0 ), green( 0 ), blue( 0 ) {
		/*Empty*/
	}
	unsigned char red, green, blue;
};
using Pixel = Color; //In this aplication a Color and a Pixel are the same.

/** Image Class.
 *  All the functions in the class below must be implemented with the prototype provided.
 *  For more information on what each method should do, please consult the exercise text.
 *
 */
class Image {
public:
	Image( int width, int height );
	~Image();

	int getWidth() const;
	int getHeight() const;

	const Pixel *getScanLine(int line) const;
	Pixel *getScanLine(int line);

	Color getPixelColor( int x, int y ) const;
	void setPixelColor( int x, int y, const Color &color );

	void fill( const Color &color );

private:
	Pixel *data;
	int width, height;
};

// The following functions are provided in the file ImageIO.cpp and may be used as is.

/** SaveImage saves the data in image as a BMP file with the filename supplied.
 *  This function returns 0 if the image was saved correctly,
 *  otherwise it will return -1 and print an error message to std::cerr.
 */
int saveImage( const Image &image, const std::string &filename );

/** LoadImage loads an image from the BMP file with the filename supplied.
 *  This function returns a dynamically allocated image if the image was
 *  loaded successfully, otherwise it will return NULL, and print an error
 *  message to std::cerr. It is the caller's (read your) responsibility to
 *  delete the dynamically allocated image.
 */
Image *loadImage( const std::string &filename );

