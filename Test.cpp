//
// Created by Cod_Republic_Lab on 5/13/23.
#include <iostream>
#include "Test.h"

Test::Test(const Spreadsheet & spreadsheet):sh(spreadsheet) {}

void Test::testSetCellAt(int r, int c, const Cell& cl) {
    try {
        sh.setCellAt(r, c, cl);
        std::cout << "Cell set at (" << r << ", " << c << ")" << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Exception:" << e.what() << std::endl;
    }
}

void Test::testSetCellAt(int r, int c, const std::string& str) {
    try {
        sh.setCellAt(r, c, str);
        std::cout << "Cell set at (" << r << ", " << c << ")" << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }
}

void Test::testAddRow(int r) {
    try {
        sh.addRow(r);
        if (r == 1) {
            std::cout << "Added " << r << "-st row: ";
        } else if (r == 2) {
            std::cout << "Added " << r << "-nd row: ";
        } else {
            std::cout << "Added " << r << "-th row: ";
        }
    } catch (const std::exception &e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }
}


void Test::testAddColumn(int c) {
    try {
        sh.addColumn(c);
        if (c == 1) {
            std::cout << "Added " << c << "-st row: ";
        } else if (c == 2) {
            std::cout << "Added " << c << "-nd row: ";
        } else {
            std::cout << "Added " << c << "-th row: ";
        }
    } catch (const std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }
}

void Test::testRemoveRow(int r) {
    try {
        sh.removeRow(r);
        if (r == 1) {
            std::cout << "Removed " << r << "-st row: ";
        } else if (r == 2) {
            std::cout << "Removed " << r << "-nd row: ";
        } else {
            std::cout << "Removed " << r << "-th row: ";
        }
    }catch (const std::exception &e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }
}

void Test::testRemoveColumn(int c) {
    try {
        sh.removeColumn(c);
        if (c == 1) {
            std::cout << "Removed " << c << "-st row: ";
        } else if (c == 2) {
            std::cout << "Removed " << c << "-nd row: ";
        } else {
            std::cout << "Removed " << c << "-th row: ";
        }
    }catch (const std::exception &e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }
}

void Test::testSwapRows(int r1, int r2) {
    try {
        sh.swapRows(r1, r2);
        std::cout << "Swapped" << r1 << " and " << r2;
    } catch (const std::exception& e) {
        std::cout << "Exception" << e.what() << std::endl;
    }
}

void Test::testSwapColumns(int c1, int c2) {
    try {
        sh.swapRows(c1, c2);
        std::cout << "Swapped" << c1 << " and " << c2;
    } catch (const std::exception& e) {
        std::cout << "Exception" << e.what() << std::endl;
    }
}


//
