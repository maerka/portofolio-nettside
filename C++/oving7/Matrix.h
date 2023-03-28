#pragma once
#include<iostream>


class Matrix {
	int nRows;
	int nColumns;
	double **table;
	public:
		Matrix();
		Matrix(int nRows, int nColumns);
		explicit Matrix(int nRows);
		~Matrix();
		Matrix(const Matrix &rhs);

		double get(int row, int col) const;
		void set(int row, int col, double value);
		int getHeigh() const;
		int getWidth() const;
		bool isValid() const;
		
		Matrix operator = (const Matrix rhs);
		Matrix operator += (const Matrix rhs);
		Matrix operator + (const Matrix rhs);

};

std::ostream& operator<<(std::ostream& os, const Matrix& m);
