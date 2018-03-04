#ifndef MINESWEEPER_HPP
#define MINESWEEPER_HPP


struct Tile
{
    bool open, mine;
    Tile(): open(false), mine(false) {}
};

class Minesweeper {
private:
    // Legg til de medlemsvariablene og hjelpefunksjonene du trenger
    int width, height, mines;
    Tile** tiles;
    void setMines(void);

public:
    Minesweeper(int width, int height, int mines);
    ~Minesweeper();

    bool isGameOver() const;

    bool isTileOpen(int row, int col) const;
    bool isTileMine(int row, int col) const;

    void openTile(int row, int col);

    int numAdjacentMines(int row, int col) const;

    // Vi slår av autogenerert kopikonstruktør og tilordningsoperator for å unngå feil
    Minesweeper(const Minesweeper &) = delete;
    Minesweeper &operator=(const Minesweeper &) = delete;
};

#endif // MINESWEEPER_HPP
