#include "evaluate.hpp"

static std::string addSpaces(std::string const &expression) {
    std::string expr = expression;
    expr.erase(std::remove_if(expr.begin(), expr.end(), isspace), expr.end());

    std::string res = "";

    std::string::const_iterator it;
    for (it = expr.begin(); it != expr.end(); it++) {
        if (std::isdigit(*it) || (std::strchr("+-", *it) && !std::isdigit(*(it - 1)) && *(it - 1) != ')')) {
            res += *it;
        } else {
            res += ' ';
            res += *it;
            res += ' ';
        }
    }

    res.erase(res.find_last_not_of(" \n\r\t") + 1);

    return (res);
}

static bool isInt(std::string token) {
    std::istringstream s(token);
    int                n;

    s >> std::noskipws >> n;
    return (s.eof() && !s.fail());
}

std::queue<IToken *> parseExpression(std::string const &expression) {
    std::queue<IToken *> queue;
    std::stringstream    ein(addSpaces(expression));
    std::string          token;
    int                  number;

    while (!ein.eof()) {
        ein >> token;

        try {
            if (isInt(token)) {
                std::stringstream(token) >> number;
                queue.push(new Number(number));
            } else if (token == "(") {
                queue.push(new ParenthesisOpen());
            } else if (token == ")") {
                queue.push(new ParenthesisClose());
            } else {
                queue.push(new Operator(token[0]));
            }
        } catch (Operator::WrongOperatorException &e) {
            deleteTokens(queue);
            throw e;
        }
    }

    return (queue);
}
