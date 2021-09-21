#include "ParenthesisOpen.hpp"

ParenthesisOpen::ParenthesisOpen(void) {}

ParenthesisOpen::ParenthesisOpen(ParenthesisOpen const &src) {
    (void)src;
}

ParenthesisOpen::~ParenthesisOpen() {}

std::string ParenthesisOpen::getOutput() const {
    return ("ParOpen");
}
