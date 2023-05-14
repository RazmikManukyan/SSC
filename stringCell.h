//
// Created by Cod_Republic_Lab on 5/14/23.
//

#ifndef SSC_STRINGCELL_H
#define SSC_STRINGCELL_H
#include "Cell.h"

class stringCell : public Cell {
public:
    stringCell():m_value(" "){}
    explicit stringCell(const std::string&);

    void set_value(const std::string&) override;
    std::string getValue() const override;
    void reset() override;
private:
    std::string m_value;
};

#endif //SSC_STRINGCELL_H
