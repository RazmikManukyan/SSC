#include <string>
#include "Celll.h"

Cell::Cell() { m_value = " "; }

Cell::Cell(const std::string & value) {
    m_value = value;
}

void Cell::set_value(const std::string &value) {
    m_value = value;
}

std::string Cell::getValue() const {
    return m_value;
}

