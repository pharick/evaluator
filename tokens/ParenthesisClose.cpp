#include "ParenthesisClose.hpp"

ParenthesisClose::ParenthesisClose(void) {}

ParenthesisClose::ParenthesisClose(ParenthesisClose const &src) {
    (void)src;
}

ParenthesisClose::~ParenthesisClose() {}

std::string ParenthesisClose::getOutput() const {
    return ("ParClose");
}
