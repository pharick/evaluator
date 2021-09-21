#ifndef PARENTHESIS_OPEN_HPP
# define PARENTHESIS_OPEN_HPP

# include "../IToken.hpp"

class ParenthesisOpen: public IToken {
    ParenthesisOpen &operator =(ParenthesisOpen const &other);

public:
    ParenthesisOpen(void);
    ParenthesisOpen(ParenthesisOpen const &src);

    ~ParenthesisOpen();

    std::string getOutput() const;
};

#endif
