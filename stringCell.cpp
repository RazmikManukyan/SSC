//
// Created by Cod_Republic_Lab on 5/14/23.
//
#include <iostream>
#include "stringCell.h"

stringCell::stringCell(const std::string &str):m_value(str) {}

void stringCell::set_value(const std::string &str) {
    m_value = str;
}

std::string stringCell::getValue() const {
    return m_value;
}

void stringCell::reset() {
    m_value = " ";
}
