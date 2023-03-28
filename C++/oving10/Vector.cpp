#include "Vector.h"
#include "Matrix.h"
#include<iostream>
#include <math.h>


Vector::Vector() :Matrix() {}

Vector::Vector(int nRows) : Matrix(nRows, 1, 0.0) {}

Vector::Vector(const Matrix & other) {
	if (other.Matrix::getColumns() == 1 && other.Matrix::isValid()) {
		Matrix::operator = (other);
	}
}

void Vector::set(int row, double value) {
	Matrix::set(row-1, 1, value);  //Her blir det -1 siden første element av en eller annen grunn blir referert til som -1!!!!
}

double Vector::get(int row) const {
	return Matrix::get(row, 0);
}

double Vector::dot(const Vector &rhs) const {
	if (Matrix::getRows() == rhs.Matrix::getRows() && Matrix::isValid() && rhs.isValid()) {
		double dotProduct = 0;
		for (int i = 0; i < Matrix::getRows(); i++) {
			dotProduct += this->get(i) * rhs.get(i);
		}
		return dotProduct;
	}
	else {
		return nan("");
	}
}

double Vector::lengthSquared() const {
	return this->dot(*this);
}

double Vector::length() const {
	return sqrt(this->lengthSquared());
}
