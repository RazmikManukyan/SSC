//
// Created by Cod_Republic_Lab on 5/14/23.
//

#ifndef SSC_INTCELL_H
#define SSC_INTCELL_H
#include "Cell.h"

class intCell : public Cell {
public:
    intCell():m_value(0){}
    explicit intCell(int);
    intCell(const intCell&);
    intCell& operator=(const intCell&);

    void set_value(const std::string&) override;
    [[nodiscard]] std::string getValue() const override;
    void reset() override;
private:
    int m_value;
};

#endif //SSC_INTCELL_H
