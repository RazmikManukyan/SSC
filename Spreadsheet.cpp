//
// Created by Cod_Republic_Lab on 5/13/23.
#include <iostream>
#include <exception>
#include <string>
#include <utility>
#include "Celll.h"
#include "Spreadsheet.h"

Spreadsheet::Spreadsheet(int row, int column):m_row(row), m_column(column) {
    m_cell = new Cell*[m_row];
    for(int i = 0; i < m_row; ++i) {
        m_cell[i] = new Cell[m_column];
    }
}

Spreadsheet::Spreadsheet(const Spreadsheet& oth):m_row(oth.m_row), m_column(oth.m_column) {
    for(int i = 0; i < m_row; ++i) {
        for(int j = 0; j < m_column; ++j) {
            m_cell[i][j] = oth.m_cell[i][j];
        }
    }
}


Spreadsheet::Spreadsheet(Spreadsheet &&scr) noexcept {
    swap(*this, scr);
}

Spreadsheet& Spreadsheet::operator=(Spreadsheet &oth) {
    swap(*this, oth);
    return *this;
}

Spreadsheet& Spreadsheet::operator=(Spreadsheet &&oth) noexcept{
    if(this == &oth) {
        return *this;
    }

    cleanup();
    moveFrom(oth);
    return *this;
}

void Spreadsheet::print() {
    for(int i = 0; i < m_row; ++i) {
        for(int j = 0; j < m_column; ++j) {
            std::cout << m_cell[i][j].getValue() << " ";
        }
        std::cout << std::endl;
    }
}

bool Spreadsheet::inRange(int x, int y) const {
    if (x < 0 || x > y - 1) {
        return false;
    }
    return true;
}

void Spreadsheet::setCellAt(int r, int c, const std::string& str) {
    if (!inRange(r, m_row)) {
        throw "Invalid argument for Row! ";
    }
    if (!inRange(c, m_column)) {
        throw "Invalid argument for Column! ";
    }
    m_cell[r][c].set_value(str);
}

void Spreadsheet::setCellAt(int r, int c, const Cell& cl) {
    verifyCoordinate(r, c);
    m_cell[r][c] = cl;
}

[[maybe_unused]] Cell Spreadsheet::getCellAt(int r, int c) const {
    verifyCoordinate(r, c);
    return m_cell[r][c];
}

void Spreadsheet::verifyCoordinate(std::size_t r, std::size_t c) const {
    if (!inRange(r, m_row)) {
        throw "Invalid argument for Row! ";
    }
    if (!inRange(c, m_column)) {
        throw "Invalid argument for Column! ";
    }
}

void Spreadsheet::addRow(int r) {
    if (!inRange(r, m_row)) {
        throw std::invalid_argument("Invalid argument !");
    }

    if (r == 0) {
        Cell** tmp = new Cell*[m_row + 1];
        for (int i = 0; i < m_row + 1; ++i) {
            tmp[i] = new Cell[m_column];
        }
        for (int j = 0; j < m_column; ++j) {
            tmp[0][j] = Cell("0");
        }
        for (int i = 1; i < m_row + 1; ++i) {
            for(int j = 0; j < m_column; ++j) {
                tmp[i][j] = m_cell[i - 1][j];
            }
        }
        cleanup();
        m_cell = tmp;
        m_row += 1;
    }

    if (r > 0 && r < m_row) {
        Cell **tmp = new Cell *[m_row + 1];
        for (int i = 0; i < m_row + 1; ++i) {
            tmp[i] = new Cell[m_column];
        }
        for (int i = 0; i < r; ++i) {
            for (int j = 0; j < m_column; ++j) {
                tmp[i][j] = m_cell[i][j];
            }
        }
        for (int i = r, j = 0; j < m_column; ++j) {
            tmp[i][j] = Cell("0");
        }
        for (int i = r + 1; i < m_row + 1; ++i) {
            for (int j = 0; j < m_column; ++j) {
                tmp[i][j] = m_cell[i - 1][j];
            }
        }
        cleanup();
        m_cell = tmp;
        m_row += 1;
    }

    if (r == m_row) {
        Cell** tmp = new Cell *[m_row + 1];
        for (int i = 0; i < m_row + 1; ++i) {
            tmp[i] = new Cell[m_column];
        }

        for (int i = 0; i < m_row ; ++i) {
            for (int j = 0; j < m_column; ++j) {
                tmp[i][j] = m_cell[i][j];
            }
        }
        for (int j = 0; j < m_column;  ++j) {
            tmp[r][j] = Cell("0");
        }
        cleanup();
        m_cell = tmp;
        m_row += 1;
    }
}

void Spreadsheet::swapRows(int r1, int r2) {
    if (!inRange(r1, m_row) && !inRange(r2, m_row)) {
        throw std::invalid_argument("Invalid Argument! ");
    }
    Cell* tmp = m_cell[r1];
    m_cell[r1] = m_cell[r2];
    m_cell[r2] = tmp;
}

void Spreadsheet::removeRow(int r) {
    if (!inRange(r, m_row)) {
        throw std::invalid_argument("Invalid argument: Row index is out of range");
    }

    if (r == 0 || r == m_row - 1) {
        Cell** tmp = new Cell*[m_row - 1];
        for (int i = 0; i < m_row - 1; ++i) {
            tmp[i] = new Cell[m_column];
        }

        for (int i = 0; i < m_row - 1; ++i) {
            for (int j = 0; j < m_column; ++j) {
                if (i < r) {
                    tmp[i][j] = m_cell[i][j];
                } else {
                    tmp[i][j] = m_cell[i + 1][j];
                }
            }
        }

        cleanup();

        m_cell = tmp;
        m_row -= 1;
    } else {
        Cell** tmp = new Cell*[m_row - 1];
        for (int i = 0; i < m_row - 1; ++i) {
            tmp[i] = new Cell[m_column];
        }

        for (int i = 0; i < r; ++i) {
            for (int j = 0; j < m_column; ++j) {
                tmp[i][j] = m_cell[i][j];
            }
        }

        for (int i = r; i < m_row - 1; ++i) {
            for (int j = 0; j < m_column; ++j) {
                tmp[i][j] = m_cell[i + 1][j];
            }
        }

        cleanup();

        m_cell = tmp;
        m_row -= 1;
    }
}

void Spreadsheet::addColumn(int c) {
    if (!inRange(c, m_column)) {
        throw std::invalid_argument("Invalid argument: ");
    }

    if(c == 0) {
        Cell** tmp = new Cell*[m_row];
        for (int i = 0; i < m_row; ++i) {
            tmp[i] = new Cell[m_column + 1];
        }

        for (int i = 0; i < m_row; ++i) {
            tmp[i][c] = Cell("0");
        }

        for (int i = 0; i < m_row; ++i) {
            for(int j = 1; j < m_column + 1; ++j) {
                tmp[i][j] = m_cell[i][j - 1];
            }
        }
        cleanup();
        m_cell = tmp;
        m_column += 1;
    }

    if (c > 0 && c < m_column) {
        Cell** tmp = new Cell*[m_row];
        for (int i = 0; i < m_row; ++i) {
            tmp[i] = new Cell[m_column + 1];
        }
        for (int i = 0; i < m_row; ++i) {
            for (int j = 0; j < c; ++j) {
                tmp[i][j] = m_cell[i][j];
            }
        }
        for (int i = 0; i < m_row; ++i) {
            tmp[i][c] = Cell("0");
        }
        for (int i = 0; i < m_row; ++i) {
            for(int j = c + 1; j < m_column + 1; ++j) {
                tmp[i][j] = m_cell[i][j - 1];
            }
        }
        cleanup();
        m_cell = tmp;
        m_column += 1;
    }

    if (c == m_column) {
        Cell** tmp = new Cell*[m_row];
        for (int i = 0; i < m_row; ++i) {
            tmp[i] = new Cell[m_column + 1];
        }
        for(int i = 0; i < m_row; ++i) {
            for (int j = 0; j < m_column; ++j) {
                tmp[i][j] = m_cell[i][j];
            }
        }
        for(int i = 0; i < m_row; ++i) {
            tmp[i][c] = Cell("0");
        }
        cleanup();
        m_cell = tmp;
        m_column += 1;

    }
}

void Spreadsheet::swapColumns(int c1, int c2) {
    if (!inRange(c1, m_column) && !inRange(c2, m_column)) {
        throw std::invalid_argument("Invalid argument! ");
    }

    for (int i = 0; i < m_row; ++i) {
        Cell tmp = m_cell[i][c1];
        m_cell[i][c1] = m_cell[i][c2];
        m_cell[i][c2] = tmp;
    }
}

void Spreadsheet::removeColumn(int c) {
    if (!inRange(c, m_column)) {
        throw std::invalid_argument("Invalid argument: Column index is out of range");
    }

    if (c == 0 || c == m_column - 1) {
        Cell** tmp = new Cell*[m_row];
        for (int i = 0; i < m_row; ++i) {
            tmp[i] = new Cell[m_column - 1];
        }

        for (int i = 0; i < m_row; ++i) {
            for (int j = 0; j < m_column - 1; ++j) {
                if (j < c) {
                    tmp[i][j] = m_cell[i][j];
                } else {
                    tmp[i][j] = m_cell[i][j + 1];
                }
            }
        }

        cleanup();

        m_cell = tmp;
        m_column -= 1;
    } else {
        Cell** tmp = new Cell*[m_row];
        for (int i = 0; i < m_row; ++i) {
            tmp[i] = new Cell[m_column - 1];
        }

        for (int i = 0; i < m_row; ++i) {
            for (int j = 0; j < c; ++j) {
                tmp[i][j] = m_cell[i][j];
            }
            for (int j = c; j < m_column - 1; ++j) {
                tmp[i][j] = m_cell[i][j + 1];
            }
        }

        cleanup();

        m_cell = tmp;
        m_column -= 1;
    }
}


Spreadsheet::~Spreadsheet() {
    for(int i = 0; i < m_row; ++i) {
        delete[] m_cell[i];
    }
    delete[] m_cell;
    m_cell = nullptr;
}

void Spreadsheet::cleanup() noexcept{
    for(int i = 0; i < m_row; ++i) {
        delete[] m_cell[i];
    }
    delete[] m_cell;
    m_cell = nullptr;
    m_row = 0;
    m_column = 0;
}

void Spreadsheet::moveFrom(Spreadsheet &oth) noexcept {
    m_row = std::exchange(oth.m_row, 0);
    m_column = std::exchange(oth.m_column, 0);
    m_cell = std::exchange(oth.m_cell, nullptr);
}

void Spreadsheet::swap(Spreadsheet &oth) noexcept {
    std::swap(m_row, oth.m_row);
    std::swap(m_column, oth.m_column);
    std::swap(m_cell, oth.m_cell);
}

void Spreadsheet::swap(Spreadsheet& lhs, Spreadsheet& rhs) {
    lhs.swap(rhs);
}





//
