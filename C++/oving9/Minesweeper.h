#pragma once

class Minesweeper {
private:
    // Legg til de medlemsvariablene og hjelpefunksjonene du trenger
	struct Tile {
		bool open;
		bool mine;
	};

	int width;
	int height;
	int mines;
	Tile **tile;

	int row; //De 'aktive' brikkene som brukes
	int col;
	int closedTiles;

public:
    Minesweeper(int width, int height, int mines);
    ~Minesweeper();

    bool isGameOver() const;
    bool isTileOpen(int row, int col) const;
    bool isTileMine(int row, int col) const;
    void openTile(int row, int col);
    int numAdjacentMines(int row, int col) const;
	bool allMinesFound();

    // Vi slår av autogenerert kopikonstruktør og tilordningsoperator for å unngå feil
    Minesweeper(const Minesweeper &) = delete;
    Minesweeper &operator=(const Minesweeper &) = delete;
};
