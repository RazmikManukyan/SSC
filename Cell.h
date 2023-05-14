//
// Created by Cod_Republic_Lab on 5/13/23.
//

#ifndef SSC_CELL_H
#define SSC_CELL_H
#include <iostream>
#include <string>

class Cell {
public:
    virtual std::string getValue() const = 0;
    virtual void set_value(const std::string&) = 0;
    virtual void reset() = 0;
};
#endif //SSC_CELL_H
