#ifndef EVALUATE_HPP
# define EVALUATE_HPP

# include <iostream>
# include <iomanip>
# include <cstring>
# include <cctype>
# include <string>
# include <sstream>
# include <queue>
# include <stack>
# include <algorithm>
# include "tokens/Number.hpp"
# include "tokens/Operator.hpp"
# include "tokens/ParenthesisOpen.hpp"
# include "tokens/ParenthesisClose.hpp"

std::ostream &operator <<(std::ostream &o, IToken const &token);

class EvaluationErrorException: public std::exception {
public:
    virtual char const *what() const throw();
};

std::queue<IToken *> parseExpression(std::string const &expression);
std::queue<IToken *> convertToPostfix(std::queue<IToken *> const &queue);
double               evaluate(std::queue<IToken *> const &queue);
void                 printQueue(std::queue<IToken *> const &queue);
void                 printStack(std::stack<double> const &stack);
void                 deleteTokens(std::queue<IToken *> queue);

#endif
