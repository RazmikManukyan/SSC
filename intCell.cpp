//
// Created by Cod_Republic_Lab on 5/14/23.
//
#include <iostream>
#include "intCell.h"

intCell::intCell(int val):m_value(val) {}

intCell::intCell(const intCell &cl) {
    m_value = cl.m_value;
}

intCell &intCell::operator=(const intCell &oth) {
    if (this == &oth) {
        return *this;
    }
    m_value = oth.m_value;
}

std::string intCell::getValue() const {
    return std::to_string(m_value);
}

void intCell::reset() {
    m_value = 0;
}

void intCell::set_value(const std::string &str) {
    m_value = stoi(str);
}






