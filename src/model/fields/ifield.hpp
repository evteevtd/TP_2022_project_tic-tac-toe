#pragma once

#include "../basics/point.hpp"
#include "../basics/figure.hpp"

#include "../basics/iboard.hpp"

class IField {
public:
    std::vector<Figure> getFigures() const;
    void addFigure(const Figure&);
    void addFigures(const std::vector<Figure>&);

    const IBoard* getBoard() const;

    virtual bool hasMove() const;
    virtual bool isWinning(Symbol) const;
    virtual bool isWinningAt(Point, Symbol) const;

    virtual bool setCell(Point, Symbol) = 0; // возвращает был ли ход выполнен
    virtual IField* copy() const = 0;
    virtual void undoMove() = 0;
    virtual ~IField();
protected:
    std::vector<Figure> victorious_;
    IBoard* board_;
private:
    bool isFullFigure(const Figure&, Symbol) const; 
};
