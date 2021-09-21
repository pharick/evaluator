#include "evaluate.hpp"

double evaluate(std::queue<IToken *> const &queue) {
    std::queue<IToken *> q = queue;
    std::stack<double>   nums;

    while (!q.empty()) {
        IToken *token = q.front();
        q.pop();

        std::cout << std::left << std::setw(16) << *token << " | " << std::setw(12);

        Number *n = dynamic_cast<Number *>(token);
        if (n) {
            nums.push(n->getValue());
            std::cout << "OP Push";
        }

        Operator *op = dynamic_cast<Operator *>(token);
        if (op) {
            if (nums.empty())
                throw EvaluationErrorException();
            double b = nums.top();
            nums.pop();

            if (nums.empty())
                throw EvaluationErrorException();
            double a = nums.top();
            nums.pop();

            if (op->getOp() == '+') {
                nums.push(a + b);
                std::cout << "OP Add";
            } else if (op->getOp() == '-') {
                nums.push(a - b);
                std::cout << "OP Substract";
            } else if (op->getOp() == '*') {
                nums.push(a * b);
                std::cout << "OP Multiply";
            } else if (op->getOp() == '/') {
                nums.push(a / b);
                std::cout << "OP Divide";
            }
        }

        std::cout << " | ST ";
        printStack(nums);
        std::cout << std::endl;
    }

    double result = nums.top();
    nums.pop();

    if (!nums.empty())
        throw EvaluationErrorException();
    return (result);
}
