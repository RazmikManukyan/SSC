#ifndef SSC_CELLL_H
#define SSC_CELLL_H

class Cell {
public:
    Cell();

    Cell(const std::string&);

    void set_value(const std::string& );

    [[nodiscard]] std::string getValue() const ;

private:
    std::string m_value;
};

#endif //SSC_CELLL_H
