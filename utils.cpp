#include "evaluate.hpp"

void printQueue(std::queue<IToken *> const &queue) {
    std::queue<IToken *> q = queue;

    while (!q.empty()) {
        std::cout << *q.front() << " ";
        q.pop();
    }
}

void printStack(std::stack<double> const &stack) {
    std::stack<double> s = stack;

    while (!s.empty()) {
        std::cout << s.top() << " ";
        s.pop();
    }
}

void deleteTokens(std::queue<IToken *> queue) {
    while (!queue.empty()) {
        IToken *token = queue.front();
        delete token;
        queue.pop();
    }
}

std::ostream &operator <<(std::ostream &o, IToken const &token) {
    o << token.getOutput();
    return (o);
}

char const *EvaluationErrorException::what() const throw() {
    return ("Evaluation error");
}
