//
// Created by Cod_Republic_Lab on 5/13/23.
//

#ifndef SSC_SPREADSHEET_H
#define SSC_SPREADSHEET_H
#include "Cell.h"

class Spreadsheet {
public:
    Spreadsheet():m_row(0), m_column(0), m_cell(nullptr){}
    Spreadsheet(int, int);
    Spreadsheet(const Spreadsheet&);
    Spreadsheet& operator=(const Spreadsheet&);

    void print();
    void setCellAt(int, int, const std::string&);
    void setCellAt(int, int, const Cell&);
    Cell getCellAt(int, int) const;
    void addRow(int);
    void swapRows(int, int);
    void removeRow(int);
    void addColumn(int);
    void swapColumns(int, int);
    void removeColumn(int);
    void cleanup();

    ~Spreadsheet();
private:
    Cell** m_cell;
    int m_row;
    int m_column;
    bool inRange(int, int) const;
};
#endif //SSC_SPREADSHEET_H
