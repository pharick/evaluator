#include "Number.hpp"

Number::Number(int value): _value(value) {}

Number::Number(Number const &src): _value(src._value) {}

Number::~Number() {}

int Number::getValue() const {
    return (this->_value);
}

std::string Number::getOutput() const {
    std::stringstream output;
    output << "Num(" << this->getValue() << ")";
    return (output.str());
}
