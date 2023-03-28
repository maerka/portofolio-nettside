#include <iostream>
#include "Minesweeper.h"
#include <vector>
#include <ctime>

Minesweeper::Minesweeper(int width, int height, int mines) {
	this->width = width;
	this->height = height;
	this->mines = mines;
	closedTiles = width*height;

	//Setter alle luker til lukket
	tile = new Tile*[height] {};
	for (int i = 0; i < height; i++) {
		tile[i] = new Tile[width]{};
		for (int j = 0; j < width; j++) {
			tile[i][j].open == false;
		}
	}
	//***** FORDELE MINER *****

	//Numererer hver brikke slik at de kun kan trekkes EN gang
	std::vector <int> vector1(width*height);
	for (int i = 0; i < width*height; i++) {
		vector1[i] = i;
	}
	 //Lager vector2 med tilfeldige tall. vekotren har lengde lik antall miner.
	std::vector<int> vector2;
	for (int i = 0; i < mines; i++) {
		//Plukker tilfeldige tall fra første vektor1. Dette elementet slettes, slik at vektor2 fylles med mines tilfeldige tall
		int ranNum = std::rand() % (vector1.size()); //tilfeldige tall 0- (height*width-1) Refererer til elementnr. i vector1
		vector2.push_back(vector1[ranNum]);
		vector1.erase(vector1.begin()+ranNum);

	}
	/*std::cout << "vector1" << std::endl;
	for (int i = 0; i < vector1.size(); i++) {
		std::cout << vector1[i] << std::endl;
	}
	std::cout << "vector2" << std::endl;
	for (int i = 0; i < vector2.size(); i++) {
		std::cout << vector2[i] << std::endl;
	}
	std::cout << "*********" << std::endl;*/

	for (int i = 0; i < mines; i++) {
		int rowNum = vector2[i] / width;
		int colNum = vector2[i] - width*rowNum;
		std::cout << "rowNum,colNum: (" <<rowNum<<", "<<colNum<<")"<< std::endl;
		tile[rowNum][colNum].mine = true;
		
	}
	//std::cout <<"height"<< height<<" width" << width << std::endl;
	//for (int i = 0; i < height; i++) {
	//	for (int j = 0; j < width; j++) {
	//		std::cout <<"i:"<<i<<" j:"<<j <<" Svar: "<<isTileMine(i,j)<< std::endl;
	//	}
	//}
}

Minesweeper::~Minesweeper() {
	for (int i = 0; i < width; i++) {
		delete[] tile[i];
	}
	delete[] tile;
	tile = nullptr;
}

bool Minesweeper::isGameOver() const {
	return isTileMine(row, col);
    //return false;
}

bool Minesweeper::isTileOpen(int row, int col) const {
	return tile[row][col].open;
    
}

bool Minesweeper::isTileMine(int row, int col) const {
	return tile[row][col].mine;
}

void Minesweeper::openTile(int row, int col) {
	tile[row][col].open = true;
	closedTiles -= 1;

	this->row = row; //oppdaterer den aktive brikken
	this->col = col;

	if (!isTileMine(row, col)) {
		//std::cout << numAdjacentMines(row, col) << std::endl;
		int numberOfMines = numAdjacentMines(row, col);

		
		if (numAdjacentMines(row, col) == 0) { //Hvis ingen miner i nærheten
			for (int i = row - 1; i <= row + 1; i++) {
				for (int j = col - 1; j <= col + 1; j++) {
					//Sjekker at brikke ikke er utenfor brettet
					if (i >= 0 && i < height && j >= 0 && j < width&&!isTileOpen(i,j)) {
						std::cout << "inni den rekursive | " <<i<<", "<<j <<std::endl;
						openTile(i, j);
					}
				}
			}
		}
	}
	else {
		tile[row][col].mine = true;
	}

}

int Minesweeper::numAdjacentMines(int row, int col) const {
	int nearbyMines = 0;
	/*Tar først de som ikke er i kantene
	if (row != 0 && row + 1 != height && col != 0 && col + 1 != width) {
	//	for (int i = row - 1; i <= row + 1; i++) {
	//		for (int j = col - 1; j <= col + 1; i++) {
	//			if (isTileMine(i, j)) {
	//				nearbyMines++;
	//			}
	//		}
	//	}
	//}

	else {*/
	for (int i = row - 1; i <= row + 1; i++) {
		for (int j = col - 1; j <= col + 1; j++) {
			//std::cout << "inni 'numAdjacentMines' ("<<i<<", "<<j<<")"<< std::endl;
			//Sjekker om tile[i][j] er utenfor brettet. Hvis ikke sjekker for mine
			if (i >= 0 && i < height && j >= 0 && j < width) {
				if (isTileMine(i, j)) {
					nearbyMines++;
					//std::cout << "nearbyMines: " << nearbyMines << std::endl;
				}
			}
		}
	}
	//std::cout << "*********************************************************** " << std::endl;
	return nearbyMines;
}

bool Minesweeper::allMinesFound() {
	if (closedTiles - mines == 0) { ////returnerer true hvis antall uåpnede luker = antall miner => alle miner funnet.
		return true;
	}
	else {
		return false;
	}
								
}