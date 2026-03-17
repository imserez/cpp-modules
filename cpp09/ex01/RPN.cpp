#include "RPN.hpp"
#include <cctype>

RPN::RPN() {}
RPN::RPN(const RPN& obj) { *this = obj; }
RPN& RPN::operator=(const RPN& obj) {
    if (this != &obj) this->_stack = obj._stack;
    return *this;
}
RPN::~RPN() {}

bool RPN::_isOperator(const std::string& token) const {
    return (token == "+" || token == "-" || token == "*" || token == "/");
}

void RPN::_executeOperation(const std::string& op) {
    if (_stack.size() < 2) throw std::runtime_error("Error");

    int b = _stack.top(); _stack.pop();
    int a = _stack.top(); _stack.pop();

    if (op == "+") _stack.push(a + b);
    else if (op == "-") _stack.push(a - b);
    else if (op == "*") _stack.push(a * b);
    else if (op == "/") {
        if (b == 0) throw std::runtime_error("Error: division by zero");
        _stack.push(a / b);
    }
}

void RPN::calculate(const std::string& expression) {
    std::stringstream ss(expression);
    std::string token;

    while (ss >> token) {
        if (token.length() == 1 && isdigit(token[0])) {
            _stack.push(token[0] - '0');
        } else if (_isOperator(token)) {
            _executeOperation(token);
        } else {
            throw std::runtime_error("Error");
        }
    }

    if (_stack.size() != 1)
        throw std::runtime_error("Error");
    std::cout << _stack.top() << std::endl;
}