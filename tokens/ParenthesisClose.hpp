#ifndef PARENTHESIS_CLOSE_HPP
# define PARENTHESIS_CLOSE_HPP

# include "../IToken.hpp"

class ParenthesisClose: public IToken {
    ParenthesisClose &operator =(ParenthesisClose const &other);

public:
    ParenthesisClose(void);
    ParenthesisClose(ParenthesisClose const &src);

    ~ParenthesisClose();

    std::string getOutput() const;
};

#endif
