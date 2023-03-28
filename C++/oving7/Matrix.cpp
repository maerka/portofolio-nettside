#include<iostream>
using namespace std;
#include"Matrix.h"

Matrix::Matrix() {
	table = nullptr;
}

Matrix::Matrix(int nRows, int nColumns){
	this->nRows = nRows;
	this->nColumns = nColumns;

	table = new double*[nRows] {};

	for (int i = 0; i < nRows; i++) {
		table[i] = new double[nColumns] {};
		for (int j = 0; j < nColumns; j++) {
			table[i][j] = 0;
		}
	}
}
Matrix::Matrix(int nRows):Matrix::Matrix(nRows, nRows) {
	Matrix::Matrix(nRows, nRows);
	for (int i = 0; i < nRows; i++) {
		table[i][i] = 1;
	}
}

Matrix::~Matrix() {


double Matrix::get(int row, int col) const {
	return table[row][col];
}
void Matrix::set(int row, int col, double value) {
	table[row][col] = value;
}

int Matrix::getHeigh() const {
	return nColumns;
}

int Matrix::getWidth() const {
	return nRows;
}

bool Matrix::isValid() const {
	if (table != nullptr) {
		return true;
	}
	else {
		return false;
	}
}

Matrix::Matrix(const Matrix &rhs) :Matrix(rhs.getWidth(), rhs.getHeigh()) {
	if (rhs.isValid() == false) {
		this->table = nullptr;
	}
	else {
		for (int i = 0; i < rhs.getWidth(); i++) {
			for (int j = 0; j < rhs.getHeigh(); j++) {
				this->table[i][j] = rhs.table[i][j];
			}
		}
	}
}

Matrix Matrix::operator = (const Matrix rhs) {
	swap(*table, *rhs.table);
	return *this;
}

// A-matrise er this
// rhs er B-matrise
Matrix Matrix::operator += (const Matrix rhs) {
	if (this->nRows == rhs.getWidth() && this->nColumns == rhs.getHeigh()) {
		for (int i = 0; i < rhs.getWidth(); i++) {
			for (int j = 0; j < rhs.getHeigh(); j++) {
				double rhsElement = rhs.get(i, j);
				this->table[i][j] = this->table[i][j] + rhsElement;
			}
		}
		return *this;
	}
	else {
		// Gir kjøretidsfeil
		delete[] table;
		this->table = nullptr;
		return *this;
	}
}

Matrix Matrix::operator+(Matrix rhs) {
	rhs += *this;
	return rhs;
}
				

ostream& operator<<(ostream& os, const Matrix& m) {
	if (m.isValid() == false) {
		os << "Ugyldig matrise" << endl;
	}
	else {
		for (int i = 0; i < m.getWidth();i++) {
			for (int j = 0; j < m.getHeigh();j++) {
				os << m.get(i,j) << " ";
			
			}
			os << endl;
		}
	}
	return os;
}

