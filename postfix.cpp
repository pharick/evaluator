#include "evaluate.hpp"

static int getPrecendence(Operator const *op) {
    if (op->getOp() == '+' || op->getOp() == '-')
        return (1);
    if (op->getOp() == '*' || op->getOp() == '/')
        return (2);
    return (0);
}

static bool checkParenthesis(std::queue<IToken *> const postfix) {
    std::queue<IToken *> p = postfix;

    while (!p.empty()) {
        if (dynamic_cast<ParenthesisOpen *>(p.front()))
            return (false);
        p.pop();
    }

    return (true);
}

static bool checkTokens(std::queue<IToken *> const &queue) {
    std::queue<IToken *> q = queue;
    IToken               *token;
    IToken               *prev;

    prev = NULL;
    while (!q.empty()) {
        token = q.front();
        q.pop();
        if (dynamic_cast<ParenthesisClose *>(token) && !dynamic_cast<Number *>(prev) &&
                !dynamic_cast<ParenthesisClose *>(prev))
            return (false);
        prev = token;
    }

    return (true);
}

std::queue<IToken *> convertToPostfix(std::queue<IToken *> const &queue) {
    std::queue<IToken *> q = queue;
    std::queue<IToken *> postfix;
    std::stack<IToken *> ops;

    if (!checkTokens(q))
        throw EvaluationErrorException();

    while (!q.empty()) {
        IToken *token = q.front();
        q.pop();

        Number *n = dynamic_cast<Number *>(token);
        if (n)
            postfix.push(n);

        ParenthesisOpen *pOpen = dynamic_cast<ParenthesisOpen *>(token);
        if (pOpen)
            ops.push(pOpen);

        ParenthesisClose *pClose = dynamic_cast<ParenthesisClose *>(token);
        if (pClose) {
            while (!ops.empty() && !dynamic_cast<ParenthesisOpen *>(ops.top())) {
                postfix.push(ops.top());
                ops.pop();
            }

            if (ops.empty())
                throw EvaluationErrorException();

            ops.pop();
        }

        Operator *op = dynamic_cast<Operator *>(token);
        if (op) {
            while (!ops.empty() && !dynamic_cast<ParenthesisOpen *>(ops.top()) &&
                    getPrecendence(static_cast<Operator *>(ops.top())) >= getPrecendence(op)) {
                postfix.push(ops.top());
                ops.pop();
            }
            ops.push(op);
        }
    }

    while (!ops.empty()) {
        postfix.push(ops.top());
        ops.pop();
    }

    if (!checkParenthesis(postfix))
        throw EvaluationErrorException();

    return (postfix);
}
