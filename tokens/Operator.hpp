#ifndef OPERATOR_HPP
# define OPERATOR_HPP

# include "../IToken.hpp"
# include <cstring>
# include <stack>
# include <sstream>

class Operator: public IToken {
    char const _op;

    static char const *_operators;

    Operator();
    Operator &operator =(Operator const &other);

public:
    Operator(char op);
    Operator(Operator const &src);

    ~Operator();

    char        getOp() const;
    std::string getOutput() const;

    class WrongOperatorException: public std::exception {
    public:
        virtual char const *what() const throw();
    };
};

#endif
