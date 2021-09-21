#ifndef NUMBER_HPP
# define NUMBER_HPP

# include "../IToken.hpp"
# include <stack>
# include <sstream>

class Number: public IToken {
    int const _value;

    Number();
    Number &operator =(Number const &other);

public:
    Number(int value);
    Number(Number const &src);

    ~Number();

    int         getValue() const;
    std::string getOutput() const;
};

#endif
