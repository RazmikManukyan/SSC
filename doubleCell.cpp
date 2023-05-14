//
// Created by Cod_Republic_Lab on 5/14/23.
//

#include <iostream>
#include "doubleCell.h"

doubleCell::doubleCell(double val):m_value(val) {}

void doubleCell::set_value(const std::string &str) {
    m_value = stod(str);
}

std::string doubleCell::getValue() const {
    return std::to_string(m_value);
}

void doubleCell::reset() {
    m_value = 0.0;
}


