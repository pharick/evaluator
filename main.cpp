#include "evaluate.hpp"

int main(int argc, char *argv[]) {
    if (argc != 2 || argv[1][0] == '\0') {
        std::cout << "Usage: ./evaluate \"expression\"" << std::endl;
        return (1);
    }

    std::string          expression = argv[1];
    std::queue<IToken *> queue;
    std::queue<IToken *> postfix;
    double               result;

    try {
        queue = parseExpression(expression);
    } catch (Operator::WrongOperatorException &e) {
        std::cout << e.what() << std::endl;
        return (1);
    }

    try {
        std::cout << "Tokens: ";
        printQueue(queue);
        std::cout << std::endl;

        postfix = convertToPostfix(queue);

        std::cout << "Postfix: ";
        printQueue(postfix);
        std::cout << std::endl;

        result = evaluate(postfix);
        std::cout << "Result: " << result << std::endl;
    } catch (EvaluationErrorException &e) {
        std::cout << e.what() << std::endl;
        deleteTokens(queue);
        return (1);
    }

    deleteTokens(queue);

    return (0);
}
