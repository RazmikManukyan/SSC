//
// Created by Cod_Republic_Lab on 5/14/23.
//

#ifndef SSC_DOUBLECELL_H
#define SSC_DOUBLECELL_H
#include "Cell.h"

class doubleCell : public Cell {
public:
    doubleCell():m_value(0){}
    explicit doubleCell(double);

    void set_value(const std::string&) override;
    [[nodiscard]] std::string getValue() const override;
    void reset() override;

private:
    double m_value;
};
#endif //SSC_DOUBLECELL_H
