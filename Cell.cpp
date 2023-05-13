//
// Created by Cod_Republic_Lab on 5/13/23.
#include <iostream>
#include <string>
#include <exception>
#include "Cell.h"

Cell::Cell(std::string s):m_value(s) {}

Cell::Cell(const Cell& oth):m_value(oth.m_value){}

void Cell::set_value(const int i) {
    m_value = std::to_string(i);
}

void Cell::set_value(const double d) {
    m_value = std::to_string(d);
}

void Cell::set_value(const std::string& str) {
    m_value = str;
}

std::string Cell::getValue() const {
    return m_value;
}

int Cell::toInt() {
    try{
        return std::stoi(m_value);
    } catch (const std::invalid_argument& e) {
        throw std::runtime_error("Invalid argument");
    } catch (const std::out_of_range& e) {
        throw std::runtime_error("Out of range");
    }
}

double Cell::toDouble() {
    try{
        return std::stod(m_value);
    } catch (const std::invalid_argument& e) {
        throw std::runtime_error("Invalid argument" + std::string(e.what()));
    } catch (const std::out_of_range& e) {
        throw std::runtime_error("Out of range" + std::string(e.what()));
    }
}

std::string Cell::toString() {
    return std::string();
}


//
