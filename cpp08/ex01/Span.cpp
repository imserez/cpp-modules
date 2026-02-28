#include "Span.hpp"

#include "Span.hpp"
#include <algorithm>
#include <limits>

Span::Span() : _maxN(0) {}
Span::Span(unsigned int N) : _maxN(N) {}
Span::Span(const Span &obj) : _maxN(obj._maxN), _nums(obj._nums) {}
Span& Span::operator=(const Span &obj) {
    if (this != &obj) {
        this->_maxN = obj._maxN;
        this->_nums = obj._nums;
    }
    return *this;
}
Span::~Span() {}

void Span::addNumber(int num) {
    if (_nums.size() >= _maxN) {
        throw SpanFullException();
    }
    _nums.push_back(num);
}

int Span::shortestSpan() const {
    if (_nums.size() < 2) {
        throw NoSpanFoundException();
    }
    std::vector<int> sorted = _nums;
    std::sort(sorted.begin(), sorted.end());

    int minDistance = std::numeric_limits<int>::max();

    for (size_t i = 1; i < sorted.size(); ++i) {
        int diff = sorted[i] - sorted[i - 1];
        if (diff < minDistance) {
            minDistance = diff;
        }
    }
    return minDistance;
}

int Span::longestSpan() const {
    if (_nums.size() < 2) {
        throw NoSpanFoundException();
    }
    int minVal = *std::min_element(_nums.begin(), _nums.end());
    int maxVal = *std::max_element(_nums.begin(), _nums.end());

    return maxVal - minVal;
}