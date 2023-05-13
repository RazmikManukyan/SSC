//
// Created by Cod_Republic_Lab on 5/13/23.
//

#ifndef SSC_TEST_H
#define SSC_TEST_H
#include "Spreadsheet.h"
#include "Cell.h"

class Test{
public:
    Test(const Spreadsheet&);
    void testSetCellAt(int, int, const Cell&);
    void testSetCellAt(int, int, const std::string&);
    void testAddRow(int);
    void testRemoveRow(int);
    void testAddColumn(int);
    void testRemoveColumn(int);
    void testSwapRows(int, int);
    void testSwapColumns(int, int);

private:
    Spreadsheet sh;
};

#endif //SSC_TEST_H
