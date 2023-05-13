//
// Created by Cod_Republic_Lab on 5/13/23.
//

#ifndef SSC_CELL_H
#define SSC_CELL_H
#include <iostream>
#include <string>

class Cell {
public:
    Cell():m_value(" "){}
    Cell(std::string);
    Cell(const Cell&);
    ~Cell() = default;

    std::string getValue() const;
    int toInt();
    double toDouble();
    std::string toString();
    void set_value(const int);
    void set_value(const double);
    void set_value(const std::string&);


private:
    std::string m_value;
};
#endif //SSC_CELL_H
