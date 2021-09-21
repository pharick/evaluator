#ifndef I_TOKEN_HPP
# define I_TOKEN_HPP

# include <ostream>

class IToken {
public:
    virtual ~IToken() {}

    virtual std::string getOutput() const = 0;
};

#endif
