#include <iostream>
#include "Test.h"
#include "Spreadsheet.h"
#include "Cell.h"

int main() {
    Spreadsheet sh (3, 3);
    Cell cl1, cl2, cl3;
    cl1.set_value("1");
    cl2.set_value("5");
    cl3.set_value("9");
    sh.setCellAt(0, 0, cl1);
    sh.setCellAt(0, 1, "2");
    sh.setCellAt(0, 2, "3");
    sh.setCellAt(1, 1, cl2);
    sh.setCellAt(1, 0, "4");
    sh.setCellAt(1, 2, "6");
    sh.setCellAt(2, 2, cl3);
    sh.setCellAt(2, 0, "7");
    sh.setCellAt(2, 1, "8");
    //sh.addRow(0);
    //sh.addColumn(0);
    sh.print();

    return 0;
}