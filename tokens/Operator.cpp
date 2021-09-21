#include "Operator.hpp"
#include <iostream>

Operator::Operator(char op): _op(op) {
    if (!std::strchr(Operator::_operators, this->_op))
        throw WrongOperatorException();
}

Operator::Operator(Operator const &src): _op(src._op) {}

Operator::~Operator() {}

char Operator::getOp() const {
    return (this->_op);
}

std::string Operator::getOutput() const {
    std::stringstream output;
    output << "Op(" << this->getOp() << ")";
    return (output.str());
}

char const *Operator::WrongOperatorException::what() const throw() {
    return ("Wrong operator");
}

char const *Operator::_operators = "+-*/";
